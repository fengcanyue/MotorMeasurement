/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Dec 6 20:25:04 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   38,   38,   38, 0x0a,
      39,   38,   38,   38, 0x0a,
      60,   38,   38,   38, 0x0a,
      83,   38,   38,   38, 0x0a,
     106,   38,   38,   38, 0x0a,
     130,   38,   38,   38, 0x0a,
     147,  170,   38,   38, 0x0a,
     175,   38,   38,   38, 0x0a,
     186,   38,   38,   38, 0x0a,
     211,  234,   38,   38, 0x0a,
     248,  265,   38,   38, 0x0a,
     271,   38,   38,   38, 0x0a,
     284,   38,   38,   38, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0resizeEvent(QResizeEvent*)\0"
    "\0drawButton_clicked()\0statusButton_clicked()\0"
    "configButton_clicked()\0pdfEditButton_clicked()\0"
    "showDAtestPage()\0saveWorkerNum(QString)\0"
    "arg1\0showHelp()\0closeEvent(QCloseEvent*)\0"
    "getData(double,double)\0torsion,speed\0"
    "changeLabel(int)\0index\0updateTime()\0"
    "showOutPutPage()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
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

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
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
    }
    return _id;
}
QT_END_MOC_NAMESPACE
