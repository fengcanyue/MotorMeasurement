/****************************************************************************
** Meta object code from reading C++ file 'pdfheaderedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/pdfheaderedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pdfheaderedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_pdfHeaderEdit_t {
    QByteArrayData data[8];
    char stringdata[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pdfHeaderEdit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pdfHeaderEdit_t qt_meta_stringdata_pdfHeaderEdit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "pdfHeaderEdit"
QT_MOC_LITERAL(1, 14, 23), // "on_exportButton_clicked"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 15), // "exportDataChart"
QT_MOC_LITERAL(4, 55, 17), // "exportDAtestChart"
QT_MOC_LITERAL(5, 73, 1), // "p"
QT_MOC_LITERAL(6, 75, 11), // "resizeEvent"
QT_MOC_LITERAL(7, 87, 13) // "QResizeEvent*"

    },
    "pdfHeaderEdit\0on_exportButton_clicked\0"
    "\0exportDataChart\0exportDAtestChart\0p\0"
    "resizeEvent\0QResizeEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pdfHeaderEdit[] = {

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
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       6,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QPixmap,    5,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void pdfHeaderEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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

const QMetaObject pdfHeaderEdit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pdfHeaderEdit.data,
      qt_meta_data_pdfHeaderEdit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *pdfHeaderEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pdfHeaderEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_pdfHeaderEdit.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
