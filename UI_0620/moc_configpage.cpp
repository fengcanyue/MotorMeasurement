/****************************************************************************
** Meta object code from reading C++ file 'configpage.h'
**
** Created: Sun Dec 6 19:53:17 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "configpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConfigPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   43,   64,   64, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   64,   64,   64, 0x0a,
      91,   64,   64,   64, 0x0a,
     113,   64,   64,   64, 0x0a,
     128,   64,   64,   64, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ConfigPage[] = {
    "ConfigPage\0configureChanged(double,double)\0"
    "torsion_max,duration\0\0on_cancelButton_clicked()\0"
    "on_okButton_clicked()\0torsion2zero()\0"
    "resizeEvent(QResizeEvent*)\0"
};

void ConfigPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConfigPage *_t = static_cast<ConfigPage *>(_o);
        switch (_id) {
        case 0: _t->configureChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_cancelButton_clicked(); break;
        case 2: _t->on_okButton_clicked(); break;
        case 3: _t->torsion2zero(); break;
        case 4: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConfigPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConfigPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConfigPage,
      qt_meta_data_ConfigPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConfigPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConfigPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConfigPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigPage))
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
    }
    return _id;
}

// SIGNAL 0
void ConfigPage::configureChanged(double _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
