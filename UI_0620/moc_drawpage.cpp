/****************************************************************************
** Meta object code from reading C++ file 'drawpage.h'
**
** Created: Sun Dec 6 20:24:43 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "drawpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DrawPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,   24,   28,   28, 0x0a,
      29,   51,   28,   28, 0x0a,
      56,   28,   28,   28, 0x08,
      83,   28,   28,   28, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DrawPage[] = {
    "DrawPage\0changPage(int)\0arg\0\0"
    "getYmax(QList<qreal>)\0list\0"
    "resizeEvent(QResizeEvent*)\0collectData()\0"
};

void DrawPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DrawPage *_t = static_cast<DrawPage *>(_o);
        switch (_id) {
        case 0: _t->changPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->getYmax((*reinterpret_cast< QList<qreal>(*)>(_a[1]))); break;
        case 2: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 3: _t->collectData(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DrawPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DrawPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DrawPage,
      qt_meta_data_DrawPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DrawPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DrawPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DrawPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DrawPage))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
