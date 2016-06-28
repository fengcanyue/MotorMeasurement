/****************************************************************************
** Meta object code from reading C++ file 'serialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/serialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialPort_t {
    QByteArrayData data[14];
    char stringdata[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPort_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPort_t qt_meta_stringdata_SerialPort = {
    {
QT_MOC_LITERAL(0, 0, 10), // "SerialPort"
QT_MOC_LITERAL(1, 11, 8), // "datacome"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "set_opt"
QT_MOC_LITERAL(4, 29, 24), // "QSerialPort::FlowControl"
QT_MOC_LITERAL(5, 54, 9), // "flow_ctrl"
QT_MOC_LITERAL(6, 64, 21), // "QSerialPort::BaudRate"
QT_MOC_LITERAL(7, 86, 6), // "nSpeed"
QT_MOC_LITERAL(8, 93, 21), // "QSerialPort::DataBits"
QT_MOC_LITERAL(9, 115, 5), // "nBits"
QT_MOC_LITERAL(10, 121, 19), // "QSerialPort::Parity"
QT_MOC_LITERAL(11, 141, 6), // "parity"
QT_MOC_LITERAL(12, 148, 21), // "QSerialPort::StopBits"
QT_MOC_LITERAL(13, 170, 5) // "nStop"

    },
    "SerialPort\0datacome\0\0set_opt\0"
    "QSerialPort::FlowControl\0flow_ctrl\0"
    "QSerialPort::BaudRate\0nSpeed\0"
    "QSerialPort::DataBits\0nBits\0"
    "QSerialPort::Parity\0parity\0"
    "QSerialPort::StopBits\0nStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    5,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12,    5,    7,    9,   11,   13,

       0        // eod
};

void SerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPort *_t = static_cast<SerialPort *>(_o);
        switch (_id) {
        case 0: _t->datacome(); break;
        case 1: { bool _r = _t->set_opt((*reinterpret_cast< QSerialPort::FlowControl(*)>(_a[1])),(*reinterpret_cast< QSerialPort::BaudRate(*)>(_a[2])),(*reinterpret_cast< QSerialPort::DataBits(*)>(_a[3])),(*reinterpret_cast< QSerialPort::Parity(*)>(_a[4])),(*reinterpret_cast< QSerialPort::StopBits(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialPort::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialPort::datacome)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SerialPort::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_SerialPort.data,
      qt_meta_data_SerialPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPort.stringdata))
        return static_cast<void*>(const_cast< SerialPort*>(this));
    return QSerialPort::qt_metacast(_clname);
}

int SerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SerialPort::datacome()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
