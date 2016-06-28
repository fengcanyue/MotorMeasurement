/****************************************************************************
** Meta object code from reading C++ file 'page_1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/page_1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'page_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Page_1_t {
    QByteArrayData data[26];
    char stringdata[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Page_1_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Page_1_t qt_meta_stringdata_Page_1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Page_1"
QT_MOC_LITERAL(1, 7, 13), // "changeTorsion"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "torion"
QT_MOC_LITERAL(4, 29, 11), // "changeSpeed"
QT_MOC_LITERAL(5, 41, 5), // "speed"
QT_MOC_LITERAL(6, 47, 11), // "changePower"
QT_MOC_LITERAL(7, 59, 5), // "power"
QT_MOC_LITERAL(8, 65, 11), // "getTestData"
QT_MOC_LITERAL(9, 77, 7), // "torsion"
QT_MOC_LITERAL(10, 85, 11), // "resizeEvent"
QT_MOC_LITERAL(11, 97, 13), // "QResizeEvent*"
QT_MOC_LITERAL(12, 111, 13), // "keyPressEvent"
QT_MOC_LITERAL(13, 125, 10), // "QKeyEvent*"
QT_MOC_LITERAL(14, 136, 1), // "k"
QT_MOC_LITERAL(15, 138, 14), // "setWatchValues"
QT_MOC_LITERAL(16, 153, 10), // "paintEvent"
QT_MOC_LITERAL(17, 164, 12), // "QPaintEvent*"
QT_MOC_LITERAL(18, 177, 22), // "setTorsionMaxandPeriod"
QT_MOC_LITERAL(19, 200, 3), // "dur"
QT_MOC_LITERAL(20, 204, 9), // "updateMax"
QT_MOC_LITERAL(21, 214, 3), // "mmm"
QT_MOC_LITERAL(22, 218, 19), // "startButton_clicked"
QT_MOC_LITERAL(23, 238, 18), // "stopButton_clicked"
QT_MOC_LITERAL(24, 257, 9), // "refreshUI"
QT_MOC_LITERAL(25, 267, 8) // "resetAll"

    },
    "Page_1\0changeTorsion\0\0torion\0changeSpeed\0"
    "speed\0changePower\0power\0getTestData\0"
    "torsion\0resizeEvent\0QResizeEvent*\0"
    "keyPressEvent\0QKeyEvent*\0k\0setWatchValues\0"
    "paintEvent\0QPaintEvent*\0setTorsionMaxandPeriod\0"
    "dur\0updateMax\0mmm\0startButton_clicked\0"
    "stopButton_clicked\0refreshUI\0resetAll"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Page_1[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,
       8,    2,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   98,    2, 0x0a /* Public */,
      12,    1,  101,    2, 0x0a /* Public */,
      15,    2,  104,    2, 0x0a /* Public */,
      16,    1,  109,    2, 0x0a /* Public */,
      18,    2,  112,    2, 0x0a /* Public */,
      20,    1,  117,    2, 0x0a /* Public */,
      22,    0,  120,    2, 0x0a /* Public */,
      23,    0,  121,    2, 0x0a /* Public */,
      24,    0,  122,    2, 0x0a /* Public */,
      25,    0,  123,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    9,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    9,    5,
    QMetaType::Void, 0x80000000 | 17,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    9,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Page_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Page_1::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Page_1::changeTorsion)) {
                *result = 0;
            }
        }
        {
            typedef void (Page_1::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Page_1::changeSpeed)) {
                *result = 1;
            }
        }
        {
            typedef void (Page_1::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Page_1::changePower)) {
                *result = 2;
            }
        }
        {
            typedef void (Page_1::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Page_1::getTestData)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Page_1::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Page_1.data,
      qt_meta_data_Page_1,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Page_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Page_1::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Page_1.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Page_1::changeTorsion(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Page_1::changeSpeed(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Page_1::changePower(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Page_1::getTestData(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
