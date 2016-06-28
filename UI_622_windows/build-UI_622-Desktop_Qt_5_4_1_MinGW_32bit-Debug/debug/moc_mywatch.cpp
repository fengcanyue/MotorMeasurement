/****************************************************************************
** Meta object code from reading C++ file 'mywatch.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/mywatch.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywatch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myWatch_t {
    QByteArrayData data[20];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myWatch_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myWatch_t qt_meta_stringdata_myWatch = {
    {
QT_MOC_LITERAL(0, 0, 7), // "myWatch"
QT_MOC_LITERAL(1, 8, 10), // "maxChanged"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "paintEvent"
QT_MOC_LITERAL(4, 31, 12), // "QPaintEvent*"
QT_MOC_LITERAL(5, 44, 12), // "paintPointer"
QT_MOC_LITERAL(6, 57, 9), // "QPainter&"
QT_MOC_LITERAL(7, 67, 1), // "p"
QT_MOC_LITERAL(8, 69, 11), // "resizeEvent"
QT_MOC_LITERAL(9, 81, 13), // "QResizeEvent*"
QT_MOC_LITERAL(10, 95, 8), // "setValue"
QT_MOC_LITERAL(11, 104, 3), // "arg"
QT_MOC_LITERAL(12, 108, 12), // "displayValue"
QT_MOC_LITERAL(13, 121, 2), // "vu"
QT_MOC_LITERAL(14, 124, 12), // "isAutoAdjust"
QT_MOC_LITERAL(15, 137, 13), // "setAutoAdjust"
QT_MOC_LITERAL(16, 151, 1), // "t"
QT_MOC_LITERAL(17, 153, 6), // "setMax"
QT_MOC_LITERAL(18, 160, 1), // "m"
QT_MOC_LITERAL(19, 162, 3) // "Max"

    },
    "myWatch\0maxChanged\0\0paintEvent\0"
    "QPaintEvent*\0paintPointer\0QPainter&\0"
    "p\0resizeEvent\0QResizeEvent*\0setValue\0"
    "arg\0displayValue\0vu\0isAutoAdjust\0"
    "setAutoAdjust\0t\0setMax\0m\0Max"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myWatch[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   67,    2, 0x0a /* Public */,
       5,    1,   70,    2, 0x0a /* Public */,
       8,    1,   73,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      12,    1,   79,    2, 0x0a /* Public */,
      14,    0,   82,    2, 0x0a /* Public */,
      15,    1,   83,    2, 0x0a /* Public */,
      17,    1,   86,    2, 0x0a /* Public */,
      19,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   13,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Double,

       0        // eod
};

void myWatch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (myWatch::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&myWatch::maxChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject myWatch::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_myWatch.data,
      qt_meta_data_myWatch,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myWatch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myWatch::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myWatch.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void myWatch::maxChanged(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
