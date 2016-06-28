/****************************************************************************
** Meta object code from reading C++ file 'keyboard.h'
**
** Created: Fri May 29 02:52:04 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "keyboard.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyboard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_keyBoard[] = {

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
       9,   21,   21,   21, 0x0a,
      22,   21,   21,   21, 0x08,
      40,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_keyBoard[] = {
    "keyBoard\0gainFocus()\0\0on_lock_clicked()\0"
    "resizeEvent(QResizeEvent*)\0"
};

void keyBoard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        keyBoard *_t = static_cast<keyBoard *>(_o);
        switch (_id) {
        case 0: _t->gainFocus(); break;
        case 1: _t->on_lock_clicked(); break;
        case 2: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData keyBoard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject keyBoard::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_keyBoard,
      qt_meta_data_keyBoard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &keyBoard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *keyBoard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *keyBoard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_keyBoard))
        return static_cast<void*>(const_cast< keyBoard*>(this));
    return QWidget::qt_metacast(_clname);
}

int keyBoard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
