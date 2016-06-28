/****************************************************************************
** Meta object code from reading C++ file 'datestpage.h'
**
** Created: Sun Dec 6 20:24:25 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datestpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datestpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DATestPage[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   35,   35,   35, 0x08,
      36,   35,   35,   35, 0x08,
      46,   35,   35,   35, 0x08,
      71,   35,   35,   35, 0x08,
      98,   35,   35,   35, 0x08,
     128,  158,  161,   35, 0x08,
     166,  192,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DATestPage[] = {
    "DATestPage\0on_pushButton_clicked()\0\0"
    "sendmsg()\0paintEvent(QPaintEvent*)\0"
    "resizeEvent(QResizeEvent*)\0"
    "on_exportCharButton_clicked()\0"
    "back_translate(unsigned char)\0uc\0char\0"
    "appendData(double,double)\0arg1,arg2\0"
};

void DATestPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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

const QMetaObjectExtraData DATestPage::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DATestPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DATestPage,
      qt_meta_data_DATestPage, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DATestPage::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DATestPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DATestPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DATestPage))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
