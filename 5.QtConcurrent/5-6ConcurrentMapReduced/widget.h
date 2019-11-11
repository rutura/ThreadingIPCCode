#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFuture>
#include <QFutureWatcher>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


    //Utility function that recursivily searches for files.
    QStringList findFiles(const QString &startDir, const QStringList &filters);


    //Single threaded
    QMap<QString, int> singleThreadedWordCount(const QStringList &files);


    // countWords counts the words in a single file. This function is
    // called in parallel by several threads and must be thread
    // safe.This is the map function
    static QMap<QString, int> countWords(const QString &file);


    // reduce adds the results from map to the final
    // result. This functor will only be called by one thread
    // at a time.
    static void reduce(QMap<QString, int> &result, const QMap<QString, int> &w);

private slots:
    void on_chooseDirButton_clicked();

    void on_singleThreadedButton_clicked();

    void on_mapReducedButton_clicked();

    void on_findFilesButton_clicked();

private:
    Ui::Widget *ui;
    QString chosenDir;
    QStringList files;
    QFuture<QMap<QString, int>> future;

};

#endif // WIDGET_H
