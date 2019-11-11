#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QtConcurrent>
#include <QDebug>
#include <QTime>
#include <QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "Ui thread : " << QThread::currentThread();
}

Widget::~Widget()
{
    delete ui;
}

QStringList Widget::findFiles(const QString &startDir, const QStringList &filters)
{
    QStringList names;
    QDir dir(startDir);

    const auto files = dir.entryList(filters, QDir::Files);
    for (const QString &file : files)
        names += startDir + '/' + file;

    const auto subdirs =  dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
    for (const QString &subdir : subdirs)
        names += findFiles(startDir + '/' + subdir, filters);
    return names;

}

QMap<QString, int> Widget::singleThreadedWordCount(const QStringList &files)
{
    QMap<QString, int> wordCount;
    for (const QString &file : files) {
        QFile f(file);
        f.open(QIODevice::ReadOnly);
        QTextStream textStream(&f);
        while (!textStream.atEnd()) {
            const auto words =  textStream.readLine().split(' ');
            for (const QString &word : words)
                wordCount[word] += 1;
        }
    }
    return wordCount;

}

QMap<QString, int> Widget::countWords(const QString &file)
{
    qDebug() << "countWords method running in thread : " << QThread::currentThread();
    QFile f(file);
    f.open(QIODevice::ReadOnly);
    QTextStream textStream(&f);
    QMap<QString, int> wordCount;

    while (!textStream.atEnd()) {
        const auto words =  textStream.readLine().split(' ');
        for (const QString &word : words)
            wordCount[word] += 1;
    }
    return wordCount;

}

void Widget::reduce(QMap<QString, int> &result, const QMap<QString, int> &w)
{
    QMapIterator<QString, int> i(w);
    while (i.hasNext()) {
        i.next();
        result[i.key()] += i.value();
    }
}

void Widget::on_chooseDirButton_clicked()
{
    chosenDir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks);
    if(!chosenDir.isNull()){
        qDebug() << "Chosen dir : " << chosenDir;
        ui->dirLineEdit->setText(chosenDir);
    }else{
        qDebug() << "Didn't choose any file";
    }

}


void Widget::on_singleThreadedButton_clicked()
{
    if(!files.isEmpty()){
        QTime time;
        time.start();
        QMap<QString, int> wordCount = singleThreadedWordCount(files);
        int timeEllapsed = time.elapsed();
        QString message = " Single Threaded \n Word count : "+ QString::number(wordCount.keys().count()) +
                " \n Time ellapsed : " + QString::number(timeEllapsed);
        ui->singleThreadedLabel->setText(message);
    }
}

void Widget::on_mapReducedButton_clicked()
{


    QTime time;
    time.start();

    future = QtConcurrent::mappedReduced(files, countWords, reduce);
    future.waitForFinished();

    int timeEllapsed = time.elapsed();

    QMap<QString, int> total = future.result();

       QString message = " Map Reduced \n Word count : "+
               QString::number(total.keys().count()) +
               " \n Time ellapsed : " + QString::number(timeEllapsed);
       ui->mapReducedLabel->setText(message);

}

void Widget::on_findFilesButton_clicked()
{
    if(!chosenDir.isNull()){
        ui->foundFilesLabel->setText("Finding files...");
        files = findFiles(chosenDir,QStringList() << "*.cpp" << "*.h");
        int fileCount = files.count();
        ui->foundFilesLabel->setText("Found " + QString::number(fileCount) + " files");
    }else{
        ui->foundFilesLabel->setText("No valid dir selected");
    }
}
