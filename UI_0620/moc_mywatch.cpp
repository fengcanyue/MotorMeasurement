/****************************************************************************
** Meta object code from reading C++ file 'mywatch.h'
**
** Created: Fri May 29 02:52:48 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mywatch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myWatch[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,   27,   27,   27, 0x05,

 // slots: signature, parameters, type, tag, flags
      28,   27,   27,   27, 0x0a,
      53,   77,   27,   27, 0x0a,
      79,   27,   27,   27, 0x0a,
     106,  123,   27,   27, 0x0a,
     127,  148,   27,   27, 0x0a,
     151,   27,  166,   27, 0x0a,
     171,  191,   27,   27, 0x0a,
     193,  208,   27,   27, 0x0a,
     210,   27,  216,   27, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myWatch[] = {
    "myWatch\0maxChanged(double)\0\0"
    "paintEvent(QPaintEvent*)\0"
    "paintPointer(QPainter&)\0p\0"
    "resizeEvent(QResizeEvent*)\0setValue(double)\0"
    "arg\0displayValue(double)\0vu\0isAutoAdjust()\0"
    "bool\0setAutoAdjust(bool)\0t\0setMax(double)\0"
    "m\0Max()\0double\0"
};

void myWatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myWatch *_t = static_cast<myWatch *>(_o);
        switch (_id) {
        case 0: _t->maxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 2: _t->paintPointer((*reinterpret_cast< QPainter(*)>(_a[1]))); break;
        case 3: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->displayValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: { bool _r = _t->isAutoAdjust();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->setAutoAdjust((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: { double _r = _t->Max();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myWatch::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myWatch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myWatch,
      qt_meta_data_myWatch, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myWatch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myWatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myWatch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myWatch))
        return static_cast<void*>(const_cast< myWatch*>(this));
    return QWidget::qt_metacast(_clname);
}

int myWatch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void myWatch::maxChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
