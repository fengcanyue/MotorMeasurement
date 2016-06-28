/****************************************************************************
** Meta object code from reading C++ file 'mycombobox.h'
**
** Created: Sat May 30 08:08:57 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mycombobox.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mycombobox.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myComboBox[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   37,   39,   39, 0x0a,
      40,   39,   39,   39, 0x0a,
      67,   39,   39,   39, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myComboBox[] = {
    "myComboBox\0keyPressEvent(QKeyEvent*)\0"
    "k\0\0focusInEvent(QFocusEvent*)\0"
    "focusOutEvent(QFocusEvent*)\0"
};

void myComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myComboBox *_t = static_cast<myComboBox *>(_o);
        switch (_id) {
        case 0: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 2: _t->focusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myComboBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_myComboBox,
      qt_meta_data_myComboBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myComboBox))
        return static_cast<void*>(const_cast< myComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int myComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
