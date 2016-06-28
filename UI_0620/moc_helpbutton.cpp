/****************************************************************************
** Meta object code from reading C++ file 'helpbutton.h'
**
** Created: Fri May 29 02:51:51 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "helpbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'helpbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_helpButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   38,   38,   38, 0x0a,
      39,   38,   38,   38, 0x0a,
      67,   38,   38,   38, 0x0a,
      95,  121,   38,   38, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_helpButton[] = {
    "helpButton\0focusInEvent(QFocusEvent*)\0"
    "\0focusOutEvent(QFocusEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0k\0"
};

void helpButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        helpButton *_t = static_cast<helpButton *>(_o);
        switch (_id) {
        case 0: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 1: _t->focusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 2: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 3: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData helpButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject helpButton::staticMetaObject = {
    { &myButton::staticMetaObject, qt_meta_stringdata_helpButton,
      qt_meta_data_helpButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &helpButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *helpButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *helpButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_helpButton))
        return static_cast<void*>(const_cast< helpButton*>(this));
    return myButton::qt_metacast(_clname);
}

int helpButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = myButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
