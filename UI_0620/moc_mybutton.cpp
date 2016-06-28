/****************************************************************************
** Meta object code from reading C++ file 'mybutton.h'
**
** Created: Fri May 29 02:52:22 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mybutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,   36,   36,   36, 0x0a,
      37,   36,   36,   36, 0x0a,
      65,   91,   36,   36, 0x0a,
      93,   91,   36,   36, 0x0a,
     121,   36,   36,   36, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myButton[] = {
    "myButton\0focusInEvent(QFocusEvent*)\0"
    "\0focusOutEvent(QFocusEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0k\0"
    "keyReleaseEvent(QKeyEvent*)\0"
    "resizeEvent(QResizeEvent*)\0"
};

void myButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myButton *_t = static_cast<myButton *>(_o);
        switch (_id) {
        case 0: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 1: _t->focusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 2: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_myButton,
      qt_meta_data_myButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myButton))
        return static_cast<void*>(const_cast< myButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int myButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
