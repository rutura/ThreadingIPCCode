/****************************************************************************
** Meta object code from reading C++ file 'calculatoradaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/calculatoradaptor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatoradaptor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorInterfaceAdaptor_t {
    QByteArrayData data[16];
    char stringdata0[905];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorInterfaceAdaptor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorInterfaceAdaptor_t qt_meta_stringdata_CalculatorInterfaceAdaptor = {
    {
QT_MOC_LITERAL(0, 0, 26), // "CalculatorInterfaceAdaptor"
QT_MOC_LITERAL(1, 27, 15), // "D-Bus Interface"
QT_MOC_LITERAL(2, 43, 31), // "com.blikoon.CalculatorInterface"
QT_MOC_LITERAL(3, 75, 19), // "D-Bus Introspection"
QT_MOC_LITERAL(4, 95, 713), // "  <interface name=\"com.bliko..."
QT_MOC_LITERAL(5, 737, 14), // "divisionResult"
QT_MOC_LITERAL(6, 752, 0), // ""
QT_MOC_LITERAL(7, 753, 8), // "quotient"
QT_MOC_LITERAL(8, 762, 13), // "productResult"
QT_MOC_LITERAL(9, 776, 7), // "product"
QT_MOC_LITERAL(10, 784, 6), // "divide"
QT_MOC_LITERAL(11, 791, 8), // "divident"
QT_MOC_LITERAL(12, 800, 7), // "divisor"
QT_MOC_LITERAL(13, 808, 8), // "multiply"
QT_MOC_LITERAL(14, 817, 7), // "factor1"
QT_MOC_LITERAL(15, 825, 7) // "factor2"

    },
    "CalculatorInterfaceAdaptor\0D-Bus Interface\0"
    "com.blikoon.CalculatorInterface\0"
    "D-Bus Introspection\0"
    "  <interface name=\"com.blikoon.CalculatorInterface\">\n    <signal na"
    "me=\"productResult\">\n      <arg direction=\"out\" type=\"d\" name=\""
    "product\"/>\n    </signal>\n    <signal name=\"divisionResult\">\n    "
    "  <arg direction=\"out\" type=\"d\" name=\"quotient\"/>\n    </signal>"
    "\n    <method name=\"multiply\">\n      <arg direction=\"out\" type=\""
    "d\"/>\n      <arg direction=\"in\" type=\"d\" name=\"factor1\"/>\n    "
    "  <arg direction=\"in\" type=\"d\" name=\"factor2\"/>\n    </method>\n"
    "    <method name=\"divide\">\n      <arg direction=\"out\" type=\"d\"/"
    ">\n      <arg direction=\"in\" type=\"d\" name=\"divident\"/>\n      <"
    "arg direction=\"in\" type=\"d\" name=\"divisor\"/>\n    </method>\n  <"
    "/interface>\n\0"
    "divisionResult\0\0quotient\0productResult\0"
    "product\0divide\0divident\0divisor\0"
    "multiply\0factor1\0factor2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorInterfaceAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       4,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    1,   38,    6, 0x06 /* Public */,
       8,    1,   41,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   44,    6, 0x0a /* Public */,
      13,    2,   49,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,

 // slots: parameters
    QMetaType::Double, QMetaType::Double, QMetaType::Double,   11,   12,
    QMetaType::Double, QMetaType::Double, QMetaType::Double,   14,   15,

       0        // eod
};

void CalculatorInterfaceAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorInterfaceAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->divisionResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->productResult((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: { double _r = _t->divide((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 3: { double _r = _t->multiply((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CalculatorInterfaceAdaptor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculatorInterfaceAdaptor::divisionResult)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CalculatorInterfaceAdaptor::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CalculatorInterfaceAdaptor::productResult)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalculatorInterfaceAdaptor::staticMetaObject = { {
    &QDBusAbstractAdaptor::staticMetaObject,
    qt_meta_stringdata_CalculatorInterfaceAdaptor.data,
    qt_meta_data_CalculatorInterfaceAdaptor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalculatorInterfaceAdaptor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorInterfaceAdaptor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorInterfaceAdaptor.stringdata0))
        return static_cast<void*>(this);
    return QDBusAbstractAdaptor::qt_metacast(_clname);
}

int CalculatorInterfaceAdaptor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDBusAbstractAdaptor::qt_metacall(_c, _id, _a);
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
void CalculatorInterfaceAdaptor::divisionResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CalculatorInterfaceAdaptor::productResult(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
