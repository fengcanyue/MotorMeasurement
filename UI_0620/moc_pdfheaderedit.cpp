/****************************************************************************
** Meta object code from reading C++ file 'pdfheaderedit.h'
**
** Created: Sun Dec 6 20:25:42 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pdfheaderedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pdfheaderedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pdfHeaderEdit[] = {

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
      14,   40,   40,   40, 0x0a,
      41,   40,   40,   40, 0x0a,
      59,   86,   88,   40, 0x0a,
      93,   40,   40,   40, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pdfHeaderEdit[] = {
    "pdfHeaderEdit\0on_exportButton_clicked()\0"
    "\0exportDataChart()\0exportDAtestChart(QPixmap)\0"
    "p\0bool\0resizeEvent(QResizeEvent*)\0"
};

void pdfHeaderEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        pdfHeaderEdit *_t = static_cast<pdfHeaderEdit *>(_o);
        switch (_id) {
        case 0: _t->on_exportButton_clicked(); break;
        case 1: _t->exportDataChart(); break;
        case 2: { bool _r = _t->exportDAtestChart((*reinterpret_cast< QPixmap(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData pdfHeaderEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject pdfHeaderEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pdfHeaderEdit,
      qt_meta_data_pdfHeaderEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pdfHeaderEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pdfHeaderEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pdfHeaderEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pdfHeaderEdit))
        return static_cast<void*>(const_cast< pdfHeaderEdit*>(this));
    return QWidget::qt_metacast(_clname);
}

int pdfHeaderEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
