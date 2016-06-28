/****************************************************************************
** Meta object code from reading C++ file 'picture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/picture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Picture_t {
    QByteArrayData data[15];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Picture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Picture_t qt_meta_stringdata_Picture = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Picture"
QT_MOC_LITERAL(1, 8, 10), // "paintEvent"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "QPaintEvent*"
QT_MOC_LITERAL(4, 33, 29), // "on_xRange_currentIndexChanged"
QT_MOC_LITERAL(5, 63, 33), // "on_y1Property_currentIndexCha..."
QT_MOC_LITERAL(6, 97, 13), // "keyPressEvent"
QT_MOC_LITERAL(7, 111, 10), // "QKeyEvent*"
QT_MOC_LITERAL(8, 122, 11), // "resizeEvent"
QT_MOC_LITERAL(9, 134, 13), // "QResizeEvent*"
QT_MOC_LITERAL(10, 148, 12), // "drawDataLine"
QT_MOC_LITERAL(11, 161, 9), // "QPainter&"
QT_MOC_LITERAL(12, 171, 1), // "p"
QT_MOC_LITERAL(13, 173, 2), // "dx"
QT_MOC_LITERAL(14, 176, 2) // "dy"

    },
    "Picture\0paintEvent\0\0QPaintEvent*\0"
    "on_xRange_currentIndexChanged\0"
    "on_y1Property_currentIndexChanged\0"
    "keyPressEvent\0QKeyEvent*\0resizeEvent\0"
    "QResizeEvent*\0drawDataLine\0QPainter&\0"
    "p\0dx\0dy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Picture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       6,    1,   53,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      10,    3,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Double, QMetaType::Double,   12,   13,   14,

       0        // eod
};

void Picture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Picture *_t = static_cast<Picture *>(_o);
        Q_UNUSED(_t)
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

const QMetaObject Picture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Picture.data,
      qt_meta_data_Picture,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Picture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Picture::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Picture.stringdata0))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
