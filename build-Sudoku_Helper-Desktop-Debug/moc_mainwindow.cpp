/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Sudoku_Helper/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[33];
    char stringdata0[466];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "newGameRequested"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "showHomePage"
QT_MOC_LITERAL(4, 42, 8), // "quitGame"
QT_MOC_LITERAL(5, 51, 19), // "colouredHelpChanged"
QT_MOC_LITERAL(6, 71, 7), // "enabled"
QT_MOC_LITERAL(7, 79, 25), // "on_actionReturnToHomePage"
QT_MOC_LITERAL(8, 105, 17), // "on_actionQuitGame"
QT_MOC_LITERAL(9, 123, 14), // "onLevelChanged"
QT_MOC_LITERAL(10, 138, 5), // "level"
QT_MOC_LITERAL(11, 144, 21), // "updateCompletedLevels"
QT_MOC_LITERAL(12, 166, 19), // "handleGridSelection"
QT_MOC_LITERAL(13, 186, 5), // "index"
QT_MOC_LITERAL(14, 192, 12), // "startNewGame"
QT_MOC_LITERAL(15, 205, 10), // "setVolume0"
QT_MOC_LITERAL(16, 216, 11), // "setVolume20"
QT_MOC_LITERAL(17, 228, 11), // "setVolume40"
QT_MOC_LITERAL(18, 240, 11), // "setVolume50"
QT_MOC_LITERAL(19, 252, 11), // "setVolume60"
QT_MOC_LITERAL(20, 264, 11), // "setVolume80"
QT_MOC_LITERAL(21, 276, 12), // "setVolume100"
QT_MOC_LITERAL(22, 289, 25), // "handleMusicEnabledChanged"
QT_MOC_LITERAL(23, 315, 17), // "handleTranslation"
QT_MOC_LITERAL(24, 333, 8), // "language"
QT_MOC_LITERAL(25, 342, 23), // "handleSoundLevelChanged"
QT_MOC_LITERAL(26, 366, 27), // "onActionColouredHelpToggled"
QT_MOC_LITERAL(27, 394, 7), // "checked"
QT_MOC_LITERAL(28, 402, 18), // "solvePuzzleRequest"
QT_MOC_LITERAL(29, 421, 11), // "pausePlayer"
QT_MOC_LITERAL(30, 433, 10), // "playPlayer"
QT_MOC_LITERAL(31, 444, 8), // "playNext"
QT_MOC_LITERAL(32, 453, 12) // "playPrevious"

    },
    "MainWindow\0newGameRequested\0\0showHomePage\0"
    "quitGame\0colouredHelpChanged\0enabled\0"
    "on_actionReturnToHomePage\0on_actionQuitGame\0"
    "onLevelChanged\0level\0updateCompletedLevels\0"
    "handleGridSelection\0index\0startNewGame\0"
    "setVolume0\0setVolume20\0setVolume40\0"
    "setVolume50\0setVolume60\0setVolume80\0"
    "setVolume100\0handleMusicEnabledChanged\0"
    "handleTranslation\0language\0"
    "handleSoundLevelChanged\0"
    "onActionColouredHelpToggled\0checked\0"
    "solvePuzzleRequest\0pausePlayer\0"
    "playPlayer\0playNext\0playPrevious"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,
       5,    1,  147,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  150,    2, 0x08 /* Private */,
       8,    0,  151,    2, 0x08 /* Private */,
       9,    1,  152,    2, 0x08 /* Private */,
      11,    0,  155,    2, 0x08 /* Private */,
      12,    1,  156,    2, 0x08 /* Private */,
      14,    0,  159,    2, 0x08 /* Private */,
      15,    0,  160,    2, 0x08 /* Private */,
      16,    0,  161,    2, 0x08 /* Private */,
      17,    0,  162,    2, 0x08 /* Private */,
      18,    0,  163,    2, 0x08 /* Private */,
      19,    0,  164,    2, 0x08 /* Private */,
      20,    0,  165,    2, 0x08 /* Private */,
      21,    0,  166,    2, 0x08 /* Private */,
      22,    1,  167,    2, 0x08 /* Private */,
      23,    1,  170,    2, 0x08 /* Private */,
      25,    1,  173,    2, 0x08 /* Private */,
      26,    1,  176,    2, 0x08 /* Private */,
      28,    0,  179,    2, 0x0a /* Public */,
      29,    0,  180,    2, 0x0a /* Public */,
      30,    0,  181,    2, 0x0a /* Public */,
      31,    0,  182,    2, 0x0a /* Public */,
      32,    0,  183,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Bool,   27,
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
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newGameRequested(); break;
        case 1: _t->showHomePage(); break;
        case 2: _t->quitGame(); break;
        case 3: _t->colouredHelpChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_actionReturnToHomePage(); break;
        case 5: _t->on_actionQuitGame(); break;
        case 6: _t->onLevelChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->updateCompletedLevels(); break;
        case 8: _t->handleGridSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->startNewGame(); break;
        case 10: _t->setVolume0(); break;
        case 11: _t->setVolume20(); break;
        case 12: _t->setVolume40(); break;
        case 13: _t->setVolume50(); break;
        case 14: _t->setVolume60(); break;
        case 15: _t->setVolume80(); break;
        case 16: _t->setVolume100(); break;
        case 17: _t->handleMusicEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->handleTranslation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->handleSoundLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->onActionColouredHelpToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->solvePuzzleRequest(); break;
        case 22: _t->pausePlayer(); break;
        case 23: _t->playPlayer(); break;
        case 24: _t->playNext(); break;
        case 25: _t->playPrevious(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::newGameRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showHomePage)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::quitGame)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::colouredHelpChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<IWindowInterface::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return IWindowInterface::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IWindowInterface::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::newGameRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::showHomePage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::quitGame()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::colouredHelpChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
