/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hokuyo/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[483];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "on_Background_clicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "timer_slot"
QT_MOC_LITERAL(4, 45, 18), // "on_scale_1_clicked"
QT_MOC_LITERAL(5, 64, 18), // "on_scale_2_clicked"
QT_MOC_LITERAL(6, 83, 31), // "on_actionSave_to_File_triggered"
QT_MOC_LITERAL(7, 115, 29), // "on_actionSave_Image_triggered"
QT_MOC_LITERAL(8, 145, 37), // "on_actionBackground_Color_1_t..."
QT_MOC_LITERAL(9, 183, 37), // "on_actionBackground_Color_2_t..."
QT_MOC_LITERAL(10, 221, 30), // "on_actionLaser_Color_triggered"
QT_MOC_LITERAL(11, 252, 30), // "on_actionForms_Color_triggered"
QT_MOC_LITERAL(12, 283, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(13, 307, 33), // "on_actionDefault_Colors_trigg..."
QT_MOC_LITERAL(14, 341, 27), // "on_actionOpen_Log_triggered"
QT_MOC_LITERAL(15, 369, 30), // "on_actionDelete_Logs_triggered"
QT_MOC_LITERAL(16, 400, 35), // "on_actionOpen_Logs_Folder_tri..."
QT_MOC_LITERAL(17, 436, 30), // "on_actionBackup_Logs_triggered"
QT_MOC_LITERAL(18, 467, 15) // "on_Stop_clicked"

    },
    "MainWindow\0on_Background_clicked\0\0"
    "timer_slot\0on_scale_1_clicked\0"
    "on_scale_2_clicked\0on_actionSave_to_File_triggered\0"
    "on_actionSave_Image_triggered\0"
    "on_actionBackground_Color_1_triggered\0"
    "on_actionBackground_Color_2_triggered\0"
    "on_actionLaser_Color_triggered\0"
    "on_actionForms_Color_triggered\0"
    "on_actionExit_triggered\0"
    "on_actionDefault_Colors_triggered\0"
    "on_actionOpen_Log_triggered\0"
    "on_actionDelete_Logs_triggered\0"
    "on_actionOpen_Logs_Folder_triggered\0"
    "on_actionBackup_Logs_triggered\0"
    "on_Stop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->on_Background_clicked(); break;
        case 1: _t->timer_slot(); break;
        case 2: _t->on_scale_1_clicked(); break;
        case 3: _t->on_scale_2_clicked(); break;
        case 4: _t->on_actionSave_to_File_triggered(); break;
        case 5: _t->on_actionSave_Image_triggered(); break;
        case 6: _t->on_actionBackground_Color_1_triggered(); break;
        case 7: _t->on_actionBackground_Color_2_triggered(); break;
        case 8: _t->on_actionLaser_Color_triggered(); break;
        case 9: _t->on_actionForms_Color_triggered(); break;
        case 10: _t->on_actionExit_triggered(); break;
        case 11: _t->on_actionDefault_Colors_triggered(); break;
        case 12: _t->on_actionOpen_Log_triggered(); break;
        case 13: _t->on_actionDelete_Logs_triggered(); break;
        case 14: _t->on_actionOpen_Logs_Folder_triggered(); break;
        case 15: _t->on_actionBackup_Logs_triggered(); break;
        case 16: _t->on_Stop_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
