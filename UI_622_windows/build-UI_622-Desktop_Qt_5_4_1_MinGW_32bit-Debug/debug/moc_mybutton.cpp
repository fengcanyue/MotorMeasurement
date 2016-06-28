/****************************************************************************
** Meta object code from reading C++ file 'mybutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/mybutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myButton_t {
    QByteArrayData data[11];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myButton_t qt_meta_stringdata_myButton = {
    {
QT_MOC_LITERAL(0, 0, 8), // "myButton"
QT_MOC_LITERAL(1, 9, 12), // "focusInEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QFocusEvent*"
QT_MOC_LITERAL(4, 36, 13), // "focusOutEvent"
QT_MOC_LITERAL(5, 50, 13), // "keyPressEvent"
QT_MOC_LITERAL(6, 64, 10), // "QKeyEvent*"
QT_MOC_LITERAL(7, 75, 1), // "k"
QT_MOC_LITERAL(8, 77, 15), // "keyReleaseEvent"
QT_MOC_LITERAL(9, 93, 11), // "resizeEvent"
QT_MOC_LITERAL(10, 105, 13) // "QResizeEvent*"

    },
    "myButton\0focusInEvent\0\0QFocusEvent*\0"
    "focusOutEvent\0keyPressEvent\0QKeyEvent*\0"
    "k\0keyReleaseEvent\0resizeEvent\0"
    "QResizeEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       8,    1,   48,    2, 0x0a /* Public */,
       9,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 10,    2,

       0        // eod
};

void myButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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

const QMetaObject myButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_myButton.data,
      qt_meta_data_myButton,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myButton::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myButton.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
