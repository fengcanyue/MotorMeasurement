/****************************************************************************
** Meta object code from reading C++ file 'receiver_thread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/receiver_thread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receiver_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_receiver_thread_t {
    QByteArrayData data[14];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_receiver_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_receiver_thread_t qt_meta_stringdata_receiver_thread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "receiver_thread"
QT_MOC_LITERAL(1, 16, 15), // "newDataReceived"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "torsion"
QT_MOC_LITERAL(4, 41, 5), // "speed"
QT_MOC_LITERAL(5, 47, 3), // "run"
QT_MOC_LITERAL(6, 51, 3), // "max"
QT_MOC_LITERAL(7, 55, 13), // "QList<double>"
QT_MOC_LITERAL(8, 69, 1), // "L"
QT_MOC_LITERAL(9, 71, 3), // "min"
QT_MOC_LITERAL(10, 75, 8), // "getValue"
QT_MOC_LITERAL(11, 84, 1), // "l"
QT_MOC_LITERAL(12, 86, 1), // "r"
QT_MOC_LITERAL(13, 88, 5) // "total"

    },
    "receiver_thread\0newDataReceived\0\0"
    "torsion\0speed\0run\0max\0QList<double>\0"
    "L\0min\0getValue\0l\0r\0total"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_receiver_thread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x0a /* Public */,
       6,    1,   45,    2, 0x0a /* Public */,
       9,    1,   48,    2, 0x0a /* Public */,
      10,    4,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 7,    8,
    QMetaType::Int, 0x80000000 | 7,    8,
    QMetaType::Double, 0x80000000 | 7, QMetaType::Double, QMetaType::Double, QMetaType::Double,    8,   11,   12,   13,

       0        // eod
};

void receiver_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        receiver_thread *_t = static_cast<receiver_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDataReceived((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->run(); break;
        case 2: { int _r = _t->max((*reinterpret_cast< QList<double>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->min((*reinterpret_cast< QList<double>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->getValue((*reinterpret_cast< QList<double>(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (receiver_thread::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&receiver_thread::newDataReceived)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject receiver_thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_receiver_thread.data,
      qt_meta_data_receiver_thread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *receiver_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *receiver_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_receiver_thread.stringdata0))
        return static_cast<void*>(const_cast< receiver_thread*>(this));
    return QThread::qt_metacast(_clname);
}

int receiver_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void receiver_thread::newDataReceived(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
