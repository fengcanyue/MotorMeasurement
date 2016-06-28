/****************************************************************************
** Meta object code from reading C++ file 'configpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/configpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigPage_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigPage_t qt_meta_stringdata_ConfigPage = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ConfigPage"
QT_MOC_LITERAL(1, 11, 16), // "configureChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "torsion_max"
QT_MOC_LITERAL(4, 41, 8), // "duration"
QT_MOC_LITERAL(5, 50, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 74, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(7, 94, 12), // "torsion2zero"
QT_MOC_LITERAL(8, 107, 11), // "resizeEvent"
QT_MOC_LITERAL(9, 119, 13) // "QResizeEvent*"

    },
    "ConfigPage\0configureChanged\0\0torsion_max\0"
    "duration\0on_cancelButton_clicked\0"
    "on_okButton_clicked\0torsion2zero\0"
    "resizeEvent\0QResizeEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    0,   46,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,

       0        // eod
};

void ConfigPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigPage *_t = static_cast<ConfigPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->configureChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->on_okButton_clicked(); break;
        case 3: _t->torsion2zero(); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ConfigPage::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ConfigPage::configureChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ConfigPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConfigPage.data,
      qt_meta_data_ConfigPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ConfigPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigPage.stringdata0))
        return static_cast<void*>(const_cast< ConfigPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConfigPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ConfigPage::configureChanged(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
