/****************************************************************************
** Meta object code from reading C++ file 'receiver_thread.h'
**
** Created: Fri May 29 02:53:18 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "receiver_thread.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'receiver_thread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_receiver_thread[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   47,   61,   61, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   61,   61,   61, 0x0a,
      68,   87,   89,   61, 0x0a,
      93,   87,   89,   61, 0x0a,
     112,  157,  169,   61, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_receiver_thread[] = {
    "receiver_thread\0newDataReceived(double,double)\0"
    "torsion,speed\0\0run()\0max(QList<double>)\0"
    "L\0int\0min(QList<double>)\0"
    "getValue(QList<double>,double,double,double)\0"
    "L,l,r,total\0double\0"
};

void receiver_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        receiver_thread *_t = static_cast<receiver_thread *>(_o);
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
    }
}

const QMetaObjectExtraData receiver_thread::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject receiver_thread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_receiver_thread,
      qt_meta_data_receiver_thread, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &receiver_thread::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *receiver_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *receiver_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_receiver_thread))
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
    }
    return _id;
}

// SIGNAL 0
void receiver_thread::newDataReceived(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
