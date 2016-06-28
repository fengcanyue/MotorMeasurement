/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI_622_windows/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "resizeEvent"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "QResizeEvent*"
QT_MOC_LITERAL(4, 38, 18), // "drawButton_clicked"
QT_MOC_LITERAL(5, 57, 20), // "statusButton_clicked"
QT_MOC_LITERAL(6, 78, 20), // "configButton_clicked"
QT_MOC_LITERAL(7, 99, 21), // "pdfEditButton_clicked"
QT_MOC_LITERAL(8, 121, 14), // "showDAtestPage"
QT_MOC_LITERAL(9, 136, 13), // "saveWorkerNum"
QT_MOC_LITERAL(10, 150, 4), // "arg1"
QT_MOC_LITERAL(11, 155, 8), // "showHelp"
QT_MOC_LITERAL(12, 164, 10), // "closeEvent"
QT_MOC_LITERAL(13, 175, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 188, 7), // "getData"
QT_MOC_LITERAL(15, 196, 7), // "torsion"
QT_MOC_LITERAL(16, 204, 5), // "speed"
QT_MOC_LITERAL(17, 210, 11), // "changeLabel"
QT_MOC_LITERAL(18, 222, 5), // "index"
QT_MOC_LITERAL(19, 228, 10), // "updateTime"
QT_MOC_LITERAL(20, 239, 14) // "showOutPutPage"

    },
    "MainWindow\0resizeEvent\0\0QResizeEvent*\0"
    "drawButton_clicked\0statusButton_clicked\0"
    "configButton_clicked\0pdfEditButton_clicked\0"
    "showDAtestPage\0saveWorkerNum\0arg1\0"
    "showHelp\0closeEvent\0QCloseEvent*\0"
    "getData\0torsion\0speed\0changeLabel\0"
    "index\0updateTime\0showOutPutPage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x0a /* Public */,
       5,    0,   83,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    1,   87,    2, 0x0a /* Public */,
      11,    0,   90,    2, 0x0a /* Public */,
      12,    1,   91,    2, 0x0a /* Public */,
      14,    2,   94,    2, 0x0a /* Public */,
      17,    1,   99,    2, 0x0a /* Public */,
      19,    0,  102,    2, 0x0a /* Public */,
      20,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   15,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< QResizeEvent*(*)>(_a[1]))); break;
        case 1: _t->drawButton_clicked(); break;
        case 2: _t->statusButton_clicked(); break;
        case 3: _t->configButton_clicked(); break;
        case 4: _t->pdfEditButton_clicked(); break;
        case 5: _t->showDAtestPage(); break;
        case 6: _t->saveWorkerNum((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->showHelp(); break;
        case 8: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: _t->getData((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->changeLabel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateTime(); break;
        case 12: _t->showOutPutPage(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
