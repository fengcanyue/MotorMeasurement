/****************************************************************************
** Meta object code from reading C++ file 'mylineedit.h'
**
** Created: Sat May 30 08:09:03 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mylineedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mylineedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_myLineEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   32,   37,   37, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   64,   37,   37, 0x0a,
      66,   37,   37,   37, 0x0a,
      93,   37,   37,   37, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_myLineEdit[] = {
    "myLineEdit\0enterPushed(QString)\0arg1\0"
    "\0keyPressEvent(QKeyEvent*)\0k\0"
    "focusInEvent(QFocusEvent*)\0"
    "focusOutEvent(QFocusEvent*)\0"
};

void myLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        myLineEdit *_t = static_cast<myLineEdit *>(_o);
        switch (_id) {
        case 0: _t->enterPushed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->focusInEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        case 3: _t->focusOutEvent((*reinterpret_cast< QFocusEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData myLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject myLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_myLineEdit,
      qt_meta_data_myLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &myLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *myLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *myLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_myLineEdit))
        return static_cast<void*>(const_cast< myLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int myLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void myLineEdit::enterPushed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
