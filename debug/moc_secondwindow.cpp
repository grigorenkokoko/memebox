/****************************************************************************
** Meta object code from reading C++ file 'secondwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../secondwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'secondwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SecondWindow_t {
    const uint offsetsAndSize[26];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SecondWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SecondWindow_t qt_meta_stringdata_SecondWindow = {
    {
QT_MOC_LITERAL(0, 12), // "SecondWindow"
QT_MOC_LITERAL(13, 10), // "signalExit"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 13), // "signalUserWin"
QT_MOC_LITERAL(39, 26), // "on_pushButton_exit_clicked"
QT_MOC_LITERAL(66, 28), // "on_pushButton_addBox_clicked"
QT_MOC_LITERAL(95, 31), // "slot_on_pushButton_like_clicked"
QT_MOC_LITERAL(127, 34), // "slot_on_pushButton_dislike_cl..."
QT_MOC_LITERAL(162, 35), // "slot_on_pushButton_download_c..."
QT_MOC_LITERAL(198, 31), // "slot_on_pushButton_plus_clicked"
QT_MOC_LITERAL(230, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(252, 12), // "slotExitProf"
QT_MOC_LITERAL(265, 16) // "slotAreaMaxValue"

    },
    "SecondWindow\0signalExit\0\0signalUserWin\0"
    "on_pushButton_exit_clicked\0"
    "on_pushButton_addBox_clicked\0"
    "slot_on_pushButton_like_clicked\0"
    "slot_on_pushButton_dislike_clicked\0"
    "slot_on_pushButton_download_clicked\0"
    "slot_on_pushButton_plus_clicked\0"
    "on_pushButton_clicked\0slotExitProf\0"
    "slotAreaMaxValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SecondWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    1 /* Public */,
       3,    0,   81,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   82,    2, 0x08,    3 /* Private */,
       5,    0,   83,    2, 0x08,    4 /* Private */,
       6,    0,   84,    2, 0x08,    5 /* Private */,
       7,    0,   85,    2, 0x08,    6 /* Private */,
       8,    0,   86,    2, 0x08,    7 /* Private */,
       9,    0,   87,    2, 0x08,    8 /* Private */,
      10,    0,   88,    2, 0x08,    9 /* Private */,
      11,    0,   89,    2, 0x0a,   10 /* Public */,
      12,    0,   90,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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

       0        // eod
};

void SecondWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SecondWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalExit(); break;
        case 1: _t->signalUserWin(); break;
        case 2: _t->on_pushButton_exit_clicked(); break;
        case 3: _t->on_pushButton_addBox_clicked(); break;
        case 4: _t->slot_on_pushButton_like_clicked(); break;
        case 5: _t->slot_on_pushButton_dislike_clicked(); break;
        case 6: _t->slot_on_pushButton_download_clicked(); break;
        case 7: _t->slot_on_pushButton_plus_clicked(); break;
        case 8: _t->on_pushButton_clicked(); break;
        case 9: _t->slotExitProf(); break;
        case 10: _t->slotAreaMaxValue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SecondWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SecondWindow::signalExit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SecondWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SecondWindow::signalUserWin)) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject SecondWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_SecondWindow.offsetsAndSize,
    qt_meta_data_SecondWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SecondWindow_t
, QtPrivate::TypeAndForceComplete<SecondWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SecondWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SecondWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SecondWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SecondWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SecondWindow::signalExit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SecondWindow::signalUserWin()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
