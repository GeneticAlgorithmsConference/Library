/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Examples/Cars/mainmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainMenu_t {
    QByteArrayData data[21];
    char stringdata[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainMenu_t qt_meta_stringdata_MainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 10),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 12),
QT_MOC_LITERAL(4, 34, 4),
QT_MOC_LITERAL(5, 39, 18),
QT_MOC_LITERAL(6, 58, 19),
QT_MOC_LITERAL(7, 78, 19),
QT_MOC_LITERAL(8, 98, 11),
QT_MOC_LITERAL(9, 110, 8),
QT_MOC_LITERAL(10, 119, 14),
QT_MOC_LITERAL(11, 134, 15),
QT_MOC_LITERAL(12, 150, 12),
QT_MOC_LITERAL(13, 163, 8),
QT_MOC_LITERAL(14, 172, 8),
QT_MOC_LITERAL(15, 181, 10),
QT_MOC_LITERAL(16, 192, 15),
QT_MOC_LITERAL(17, 208, 5),
QT_MOC_LITERAL(18, 214, 15),
QT_MOC_LITERAL(19, 230, 23),
QT_MOC_LITERAL(20, 254, 26)
    },
    "MainMenu\0screenshot\0\0showMainMenu\0"
    "tick\0showNewGameOptions\0showSaveGameOptions\0"
    "showLoadGameOptions\0showOptions\0"
    "showHelp\0continueAction\0backButtonClick\0"
    "startNewGame\0saveGame\0loadGame\0"
    "deleteGame\0minDeltaYUpdate\0value\0"
    "maxDeltaYUpdate\0vehiclePointsNumChanged\0"
    "vehicleMaxWheelsNumChanged\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a,
       3,    0,  105,    2, 0x0a,
       4,    0,  106,    2, 0x0a,
       5,    0,  107,    2, 0x0a,
       6,    0,  108,    2, 0x0a,
       7,    0,  109,    2, 0x0a,
       8,    0,  110,    2, 0x0a,
       9,    0,  111,    2, 0x0a,
      10,    0,  112,    2, 0x0a,
      11,    0,  113,    2, 0x0a,
      12,    0,  114,    2, 0x0a,
      13,    0,  115,    2, 0x0a,
      14,    0,  116,    2, 0x0a,
      15,    0,  117,    2, 0x0a,
      16,    1,  118,    2, 0x0a,
      18,    1,  121,    2, 0x0a,
      19,    1,  124,    2, 0x0a,
      20,    1,  127,    2, 0x0a,

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
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenu *_t = static_cast<MainMenu *>(_o);
        switch (_id) {
        case 0: _t->screenshot(); break;
        case 1: _t->showMainMenu(); break;
        case 2: _t->tick(); break;
        case 3: _t->showNewGameOptions(); break;
        case 4: _t->showSaveGameOptions(); break;
        case 5: _t->showLoadGameOptions(); break;
        case 6: _t->showOptions(); break;
        case 7: _t->showHelp(); break;
        case 8: _t->continueAction(); break;
        case 9: _t->backButtonClick(); break;
        case 10: _t->startNewGame(); break;
        case 11: _t->saveGame(); break;
        case 12: _t->loadGame(); break;
        case 13: _t->deleteGame(); break;
        case 14: _t->minDeltaYUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->maxDeltaYUpdate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->vehiclePointsNumChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->vehicleMaxWheelsNumChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainMenu::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainMenu.data,
      qt_meta_data_MainMenu,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenu.stringdata))
        return static_cast<void*>(const_cast< MainMenu*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
