/****************************************************************************
** Meta object code from reading C++ file 'picture.h'
**
** Created: Sun Dec 6 20:26:00 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "picture.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Picture[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,   33,   33,   33, 0x0a,
      34,   33,   33,   33, 0x08,
      69,   33,   33,   33, 0x08,
     108,   33,   33,   33, 0x08,
     134,   33,   33,   33, 0x08,
     161,  199,   33,   33, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Picture[] = {
    "Picture\0paintEvent(QPaintEvent*)\0\0"
    "on_xRange_currentIndexChanged(int)\0"
    "on_y1Property_currentIndexChanged(int)\0"
    "keyPressEvent(QKeyEvent*)\0"
    "resizeEvent(QResizeEvent*)\0"
    "drawDataLine(QPainter&,double,double)\0"
    "p,dx,dy\0"
};

void Picture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Picture *_t = static_cast<Picture *>(_o);
        switch (_id) {
        case 0: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 1: _t->on_xRange_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_y1Property_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 5: _t->drawDataLine((*reinterpret_cast< QPainter(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Picture::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Picture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Picture,
      qt_meta_data_Picture, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Picture::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Picture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Picture::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Picture))
        return static_cast<void*>(const_cast< Picture*>(this));
    return QWidget::qt_metacast(_clname);
}

int Picture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
