/****************************************************************************
** Meta object code from reading C++ file 'datestpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/datestpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datestpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DATestPage_t {
    QByteArrayData data[14];
    char stringdata[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DATestPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DATestPage_t qt_meta_stringdata_DATestPage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "DATestPage"
QT_MOC_LITERAL(1, 11, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "sendmsg"
QT_MOC_LITERAL(4, 42, 10), // "paintEvent"
QT_MOC_LITERAL(5, 53, 12), // "QPaintEvent*"
QT_MOC_LITERAL(6, 66, 11), // "resizeEvent"
QT_MOC_LITERAL(7, 78, 13), // "QResizeEvent*"
QT_MOC_LITERAL(8, 92, 27), // "on_exportCharButton_clicked"
QT_MOC_LITERAL(9, 120, 14), // "back_translate"
QT_MOC_LITERAL(10, 135, 2), // "uc"
QT_MOC_LITERAL(11, 138, 10), // "appendData"
QT_MOC_LITERAL(12, 149, 4), // "arg1"
QT_MOC_LITERAL(13, 154, 4) // "arg2"

    },
    "DATestPage\0on_pushButton_clicked\0\0"
    "sendmsg\0paintEvent\0QPaintEvent*\0"
    "resizeEvent\0QResizeEvent*\0"
    "on_exportCharButton_clicked\0back_translate\0"
    "uc\0appendData\0arg1\0arg2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DATestPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    1,   58,    2, 0x08 /* Private */,
      11,    2,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Char, QMetaType::UChar,   10,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   12,   13,

       0        // eod
};

void DATestPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DATestPage *_t = static_cast<DATestPage *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->sendmsg(); break;
        case 2: _t->paintEvent((*reinterpret_cast< QPaintEvent*(*)>(_a[1]))); break;
        case 3: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 4: _t->on_exportCharButton_clicked(); break;
        case 5: { char _r = _t->back_translate((*reinterpret_cast< unsigned char(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        case 6: _t->appendData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject DATestPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DATestPage.data,
      qt_meta_data_DATestPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DATestPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DATestPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DATestPage.stringdata))
        return static_cast<void*>(const_cast< DATestPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int DATestPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
