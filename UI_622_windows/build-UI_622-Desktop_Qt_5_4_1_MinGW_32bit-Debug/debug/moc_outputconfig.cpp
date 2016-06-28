/****************************************************************************
** Meta object code from reading C++ file 'outputconfig.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/outputconfig.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outputconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OutPutConfig_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OutPutConfig_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OutPutConfig_t qt_meta_stringdata_OutPutConfig = {
    {
QT_MOC_LITERAL(0, 0, 12), // "OutPutConfig"
QT_MOC_LITERAL(1, 13, 19), // "on_okbutton_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "resizeEvent"
QT_MOC_LITERAL(4, 46, 13), // "QResizeEvent*"
QT_MOC_LITERAL(5, 60, 14), // "back_translate"
QT_MOC_LITERAL(6, 75, 2) // "uc"

    },
    "OutPutConfig\0on_okbutton_clicked\0\0"
    "resizeEvent\0QResizeEvent*\0back_translate\0"
    "uc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OutPutConfig[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    1,   30,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Char, QMetaType::UChar,    6,

       0        // eod
};

void OutPutConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OutPutConfig *_t = static_cast<OutPutConfig *>(_o);
        switch (_id) {
        case 0: _t->on_okbutton_clicked(); break;
        case 1: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 2: { char _r = _t->back_translate((*reinterpret_cast< unsigned char(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject OutPutConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OutPutConfig.data,
      qt_meta_data_OutPutConfig,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OutPutConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OutPutConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OutPutConfig.stringdata))
        return static_cast<void*>(const_cast< OutPutConfig*>(this));
    return QWidget::qt_metacast(_clname);
}

int OutPutConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
