/****************************************************************************
** Meta object code from reading C++ file 'slavecalculator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/slavecalculator.h"
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
    QByteArrayData data[14];
    char stringdata0[160];
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
QT_MOC_LITERAL(3, 64, 13), // "productResult"
QT_MOC_LITERAL(4, 78, 0), // ""
QT_MOC_LITERAL(5, 79, 7), // "product"
QT_MOC_LITERAL(6, 87, 14), // "divisionResult"
QT_MOC_LITERAL(7, 102, 8), // "quotient"
QT_MOC_LITERAL(8, 111, 8), // "multiply"
QT_MOC_LITERAL(9, 120, 7), // "factor1"
QT_MOC_LITERAL(10, 128, 7), // "factor2"
QT_MOC_LITERAL(11, 136, 6), // "divide"
QT_MOC_LITERAL(12, 143, 8), // "divident"
QT_MOC_LITERAL(13, 152, 7) // "divisor"

    },
    "SlaveCalculator\0D-Bus Interface\0"
    "com.blikoon.CalculatorInterface\0"
    "productResult\0\0product\0divisionResult\0"
    "quotient\0multiply\0factor1\0factor2\0"
    "divide\0divident\0divisor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlaveCalculator[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    1,   36,    4, 0x06 /* Public */,
       6,    1,   39,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,   42,    4, 0x0a /* Public */,
      11,    2,   47,    4, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,

 // slots: parameters
    QMetaType::Double, QMetaType::Double, QMetaType::Double,    9,   10,
    QMetaType::Double, QMetaType::Double, QMetaType::Double,   12,   13,

       0        // eod
};

void SlaveCalculator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlaveCalculator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->productResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->divisionResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: { double _r = _t->multiply((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->divide((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SlaveCalculator::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlaveCalculator::productResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SlaveCalculator::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SlaveCalculator::divisionResult)) {
                *result = 1;
                return;
            }
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void SlaveCalculator::productResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SlaveCalculator::divisionResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
