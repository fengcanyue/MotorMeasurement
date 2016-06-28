/****************************************************************************
** Meta object code from reading C++ file 'drawpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/drawpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DrawPage_t {
    QByteArrayData data[10];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawPage_t qt_meta_stringdata_DrawPage = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DrawPage"
QT_MOC_LITERAL(1, 9, 9), // "changPage"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 3), // "arg"
QT_MOC_LITERAL(4, 24, 7), // "getYmax"
QT_MOC_LITERAL(5, 32, 12), // "QList<qreal>"
QT_MOC_LITERAL(6, 45, 4), // "list"
QT_MOC_LITERAL(7, 50, 11), // "resizeEvent"
QT_MOC_LITERAL(8, 62, 13), // "QResizeEvent*"
QT_MOC_LITERAL(9, 76, 11) // "collectData"

    },
    "DrawPage\0changPage\0\0arg\0getYmax\0"
    "QList<qreal>\0list\0resizeEvent\0"
    "QResizeEvent*\0collectData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       7,    1,   40,    2, 0x08 /* Private */,
       9,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,

       0        // eod
};

void DrawPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DrawPage *_t = static_cast<DrawPage *>(_o);
        switch (_id) {
        case 0: _t->changPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getYmax((*reinterpret_cast< QList<qreal>(*)>(_a[1]))); break;
        case 2: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 3: _t->collectData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<qreal> >(); break;
            }
            break;
        }
    }
}

const QMetaObject DrawPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawPage.data,
      qt_meta_data_DrawPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DrawPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DrawPage.stringdata))
        return static_cast<void*>(const_cast< DrawPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int DrawPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
