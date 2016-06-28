/****************************************************************************
** Meta object code from reading C++ file 'uartthread.h'
**
** Created: Sat Jun 6 13:23:49 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uartthread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uartthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UartThread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   17,   17,   17, 0x0a,
      18,   34,   36,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UartThread[] = {
    "UartThread\0run()\0\0translate(char)\0c\0"
    "int\0"
};

void UartThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UartThread *_t = static_cast<UartThread *>(_o);
        switch (_id) {
        case 0: _t->run(); break;
        case 1: { int _r = _t->translate((*reinterpret_cast< char(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UartThread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UartThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_UartThread,
      qt_meta_data_UartThread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UartThread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UartThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UartThread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UartThread))
        return static_cast<void*>(const_cast< UartThread*>(this));
    return QThread::qt_metacast(_clname);
}

int UartThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
