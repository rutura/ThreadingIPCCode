/****************************************************************************
** Meta object code from reading C++ file 'calculatoradaptor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../clientserver/Server/calculatoradaptor.h"
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
    QByteArrayData data[12];
    char stringdata0[633];
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
QT_MOC_LITERAL(4, 95, 487), // "  <interface name=\"com.bliko..."
QT_MOC_LITERAL(5, 533, 6), // "divide"
QT_MOC_LITERAL(6, 540, 0), // ""
QT_MOC_LITERAL(7, 541, 8), // "divident"
QT_MOC_LITERAL(8, 550, 7), // "divisor"
QT_MOC_LITERAL(9, 558, 8), // "multiply"
QT_MOC_LITERAL(10, 567, 7), // "factor1"
QT_MOC_LITERAL(11, 575, 7) // "factor2"

    },
    "CalculatorInterfaceAdaptor\0D-Bus Interface\0"
    "com.blikoon.CalculatorInterface\0"
    "D-Bus Introspection\0"
    "  <interface name=\"com.blikoon.CalculatorInterface\">\n    <method na"
    "me=\"multiply\">\n      <arg direction=\"out\" type=\"d\"/>\n      <ar"
    "g direction=\"in\" type=\"d\" name=\"factor1\"/>\n      <arg direction"
    "=\"in\" type=\"d\" name=\"factor2\"/>\n    </method>\n    <method name"
    "=\"divide\">\n      <arg direction=\"out\" type=\"d\"/>\n      <arg di"
    "rection=\"in\" type=\"d\" name=\"divident\"/>\n      <arg direction=\""
    "in\" type=\"d\" name=\"divisor\"/>\n    </method>\n  </interface>\n\0"
    "divide\0\0divident\0divisor\0multiply\0"
    "factor1\0factor2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorInterfaceAdaptor[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
       2,   18, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // slots: name, argc, parameters, tag, flags
       5,    2,   28,    6, 0x0a /* Public */,
       9,    2,   33,    6, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,
    QMetaType::Double, QMetaType::Double, QMetaType::Double,   10,   11,

       0        // eod
};

void CalculatorInterfaceAdaptor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorInterfaceAdaptor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { double _r = _t->divide((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 1: { double _r = _t->multiply((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
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
