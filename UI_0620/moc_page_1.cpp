/****************************************************************************
** Meta object code from reading C++ file 'page_1.h'
**
** Created: Sun Dec 6 19:24:21 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "page_1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Page_1[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,   29,   36,   36, 0x05,
      37,   57,   36,   36, 0x05,
      63,   83,   36,   36, 0x05,
      89,  116,   36,   36, 0x05,

 // slots: signature, parameters, type, tag, flags
     130,   36,   36,   36, 0x0a,
     157,  183,   36,   36, 0x0a,
     185,  116,   36,   36, 0x0a,
     215,   36,   36,   36, 0x0a,
     240,  278,   36,   36, 0x0a,
     290,  308,   36,   36, 0x0a,
     312,   36,   36,   36, 0x0a,
     334,   36,   36,   36, 0x0a,
     355,   36,   36,   36, 0x0a,
     367,   36,   36,   36, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Page_1[] = {
    "Page_1\0changeTorsion(double)\0torion\0"
    "\0changeSpeed(double)\0speed\0"
    "changePower(double)\0power\0"
    "getTestData(double,double)\0torsion,speed\0"
    "resizeEvent(QResizeEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0k\0"
    "setWatchValues(double,double)\0"
    "paintEvent(QPaintEvent*)\0"
    "setTorsionMaxandPeriod(double,double)\0"
    "torsion,dur\0updateMax(double)\0mmm\0"
    "startButton_clicked()\0stopButton_clicked()\0"
    "refreshUI()\0resetAll()\0"
};

void Page_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Page_1 *_t = static_cast<Page_1 *>(_o);
        switch (_id) {
        case 0: _t->changeTorsion((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changePower((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->getTestData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->setWatchValues((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 8: _t->setTorsionMaxandPeriod((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->updateMax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->startButton_clicked(); break;
        case 11: _t->stopButton_clicked(); break;
        case 12: _t->refreshUI(); break;
        case 13: _t->resetAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Page_1::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Page_1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Page_1,
      qt_meta_data_Page_1, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Page_1::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Page_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Page_1::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Page_1))
        return static_cast<void*>(const_cast< Page_1*>(this));
    return QWidget::qt_metacast(_clname);
}

int Page_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Page_1::changeTorsion(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Page_1::changeSpeed(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Page_1::changePower(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Page_1::getTestData(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
