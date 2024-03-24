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
    QByteArrayData data[30];
    char stringdata0[410];
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
QT_MOC_LITERAL(5, 51, 25), // "on_actionReturnToHomePage"
QT_MOC_LITERAL(6, 77, 17), // "on_actionQuitGame"
QT_MOC_LITERAL(7, 95, 14), // "onLevelChanged"
QT_MOC_LITERAL(8, 110, 5), // "level"
QT_MOC_LITERAL(9, 116, 21), // "updateCompletedLevels"
QT_MOC_LITERAL(10, 138, 19), // "handleGridSelection"
QT_MOC_LITERAL(11, 158, 5), // "index"
QT_MOC_LITERAL(12, 164, 12), // "startNewGame"
QT_MOC_LITERAL(13, 177, 10), // "setVolume0"
QT_MOC_LITERAL(14, 188, 11), // "setVolume20"
QT_MOC_LITERAL(15, 200, 11), // "setVolume40"
QT_MOC_LITERAL(16, 212, 11), // "setVolume50"
QT_MOC_LITERAL(17, 224, 11), // "setVolume60"
QT_MOC_LITERAL(18, 236, 11), // "setVolume80"
QT_MOC_LITERAL(19, 248, 12), // "setVolume100"
QT_MOC_LITERAL(20, 261, 25), // "handleMusicEnabledChanged"
QT_MOC_LITERAL(21, 287, 7), // "enabled"
QT_MOC_LITERAL(22, 295, 17), // "handleTranslation"
QT_MOC_LITERAL(23, 313, 8), // "language"
QT_MOC_LITERAL(24, 322, 23), // "handleSoundLevelChanged"
QT_MOC_LITERAL(25, 346, 18), // "solvePuzzleRequest"
QT_MOC_LITERAL(26, 365, 11), // "pausePlayer"
QT_MOC_LITERAL(27, 377, 10), // "playPlayer"
QT_MOC_LITERAL(28, 388, 8), // "playNext"
QT_MOC_LITERAL(29, 397, 12) // "playPrevious"

    },
    "MainWindow\0newGameRequested\0\0showHomePage\0"
    "quitGame\0on_actionReturnToHomePage\0"
    "on_actionQuitGame\0onLevelChanged\0level\0"
    "updateCompletedLevels\0handleGridSelection\0"
    "index\0startNewGame\0setVolume0\0setVolume20\0"
    "setVolume40\0setVolume50\0setVolume60\0"
    "setVolume80\0setVolume100\0"
    "handleMusicEnabledChanged\0enabled\0"
    "handleTranslation\0language\0"
    "handleSoundLevelChanged\0solvePuzzleRequest\0"
    "pausePlayer\0playPlayer\0playNext\0"
    "playPrevious"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  134,    2, 0x06 /* Public */,
       3,    0,  135,    2, 0x06 /* Public */,
       4,    0,  136,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  137,    2, 0x08 /* Private */,
       6,    0,  138,    2, 0x08 /* Private */,
       7,    1,  139,    2, 0x08 /* Private */,
       9,    0,  142,    2, 0x08 /* Private */,
      10,    1,  143,    2, 0x08 /* Private */,
      12,    0,  146,    2, 0x08 /* Private */,
      13,    0,  147,    2, 0x08 /* Private */,
      14,    0,  148,    2, 0x08 /* Private */,
      15,    0,  149,    2, 0x08 /* Private */,
      16,    0,  150,    2, 0x08 /* Private */,
      17,    0,  151,    2, 0x08 /* Private */,
      18,    0,  152,    2, 0x08 /* Private */,
      19,    0,  153,    2, 0x08 /* Private */,
      20,    1,  154,    2, 0x08 /* Private */,
      22,    1,  157,    2, 0x08 /* Private */,
      24,    1,  160,    2, 0x08 /* Private */,
      25,    0,  163,    2, 0x0a /* Public */,
      26,    0,  164,    2, 0x0a /* Public */,
      27,    0,  165,    2, 0x0a /* Public */,
      28,    0,  166,    2, 0x0a /* Public */,
      29,    0,  167,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Int,    8,
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
        case 3: _t->on_actionReturnToHomePage(); break;
        case 4: _t->on_actionQuitGame(); break;
        case 5: _t->onLevelChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->updateCompletedLevels(); break;
        case 7: _t->handleGridSelection((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->startNewGame(); break;
        case 9: _t->setVolume0(); break;
        case 10: _t->setVolume20(); break;
        case 11: _t->setVolume40(); break;
        case 12: _t->setVolume50(); break;
        case 13: _t->setVolume60(); break;
        case 14: _t->setVolume80(); break;
        case 15: _t->setVolume100(); break;
        case 16: _t->handleMusicEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->handleTranslation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->handleSoundLevelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->solvePuzzleRequest(); break;
        case 20: _t->pausePlayer(); break;
        case 21: _t->playPlayer(); break;
        case 22: _t->playNext(); break;
        case 23: _t->playPrevious(); break;
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
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
