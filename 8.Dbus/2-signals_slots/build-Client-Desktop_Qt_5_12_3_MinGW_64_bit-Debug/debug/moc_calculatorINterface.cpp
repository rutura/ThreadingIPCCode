/****************************************************************************
** Meta object code from reading C++ file 'calculatorINterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Client/calculatorINterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatorINterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface_t qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface = {
    {
QT_MOC_LITERAL(0, 0, 38), // "ComBlikoonCalculatorInterface..."
QT_MOC_LITERAL(1, 39, 14), // "divisionResult"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 8), // "quotient"
QT_MOC_LITERAL(4, 64, 13), // "productResult"
QT_MOC_LITERAL(5, 78, 7), // "product"
QT_MOC_LITERAL(6, 86, 6), // "divide"
QT_MOC_LITERAL(7, 93, 25), // "QDBusPendingReply<double>"
QT_MOC_LITERAL(8, 119, 8), // "divident"
QT_MOC_LITERAL(9, 128, 7), // "divisor"
QT_MOC_LITERAL(10, 136, 8), // "multiply"
QT_MOC_LITERAL(11, 145, 7), // "factor1"
QT_MOC_LITERAL(12, 153, 7) // "factor2"

    },
    "ComBlikoonCalculatorInterfaceInterface\0"
    "divisionResult\0\0quotient\0productResult\0"
    "product\0divide\0QDBusPendingReply<double>\0"
    "divident\0divisor\0multiply\0factor1\0"
    "factor2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComBlikoonCalculatorInterfaceInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   40,    2, 0x0a /* Public */,
      10,    2,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,

 // slots: parameters
    0x80000000 | 7, QMetaType::Double, QMetaType::Double,    8,    9,
    0x80000000 | 7, QMetaType::Double, QMetaType::Double,   11,   12,

       0        // eod
};

void ComBlikoonCalculatorInterfaceInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ComBlikoonCalculatorInterfaceInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->divisionResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->productResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: { QDBusPendingReply<double> _r = _t->divide((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<double>*>(_a[0]) = std::move(_r); }  break;
        case 3: { QDBusPendingReply<double> _r = _t->multiply((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QDBusPendingReply<double>*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComBlikoonCalculatorInterfaceInterface::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBlikoonCalculatorInterfaceInterface::divisionResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComBlikoonCalculatorInterfaceInterface::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComBlikoonCalculatorInterfaceInterface::productResult)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ComBlikoonCalculatorInterfaceInterface::staticMetaObject = { {
    &QDBusAbstractInterface::staticMetaObject,
    qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface.data,
    qt_meta_data_ComBlikoonCalculatorInterfaceInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ComBlikoonCalculatorInterfaceInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComBlikoonCalculatorInterfaceInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComBlikoonCalculatorInterfaceInterface.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractInterface::qt_metacast(_clname);
}

int ComBlikoonCalculatorInterfaceInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractInterface::qt_metacall(_c, _id, _a);
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
void ComBlikoonCalculatorInterfaceInterface::divisionResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComBlikoonCalculatorInterfaceInterface::productResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
