/****************************************************************************
** Meta object code from reading C++ file 'slavecalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../clientserver/Server/slavecalculator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slavecalculator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlaveCalculator_t {
    QByteArrayData data[10];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlaveCalculator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlaveCalculator_t qt_meta_stringdata_SlaveCalculator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SlaveCalculator"
QT_MOC_LITERAL(1, 16, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 32, 31), // "com.blikoon.CalculatorInterface"
QT_MOC_LITERAL(3, 64, 8), // "multiply"
QT_MOC_LITERAL(4, 73, 0), // ""
QT_MOC_LITERAL(5, 74, 7), // "factor1"
QT_MOC_LITERAL(6, 82, 7), // "factor2"
QT_MOC_LITERAL(7, 90, 6), // "divide"
QT_MOC_LITERAL(8, 97, 8), // "divident"
QT_MOC_LITERAL(9, 106, 7) // "divisor"

    },
    "SlaveCalculator\0D-Bus Interface\0"
    "com.blikoon.CalculatorInterface\0"
    "multiply\0\0factor1\0factor2\0divide\0"
    "divident\0divisor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlaveCalculator[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       2,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    2,   26,    4, 0x0a /* Public */,
       7,    2,   31,    4, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Double, QMetaType::Double, QMetaType::Double,    5,    6,
    QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,    9,

       0        // eod
};

void SlaveCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlaveCalculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { double _r = _t->multiply((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->divide((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SlaveCalculator::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_SlaveCalculator.data,
    qt_meta_data_SlaveCalculator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlaveCalculator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlaveCalculator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlaveCalculator.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SlaveCalculator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
