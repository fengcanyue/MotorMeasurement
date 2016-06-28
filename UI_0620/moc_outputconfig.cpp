/****************************************************************************
** Meta object code from reading C++ file 'outputconfig.h'
**
** Created: Sun Dec 6 20:25:25 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "outputconfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'outputconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OutPutConfig[] = {

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
      13,   35,   35,   35, 0x08,
      36,   35,   35,   35, 0x08,
      63,   93,   96,   35, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_OutPutConfig[] = {
    "OutPutConfig\0on_okbutton_clicked()\0\0"
    "resizeEvent(QResizeEvent*)\0"
    "back_translate(unsigned char)\0uc\0char\0"
};

void OutPutConfig::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData OutPutConfig::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OutPutConfig::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OutPutConfig,
      qt_meta_data_OutPutConfig, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OutPutConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OutPutConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OutPutConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OutPutConfig))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
