/****************************************************************************
** Meta object code from reading C++ file 'userprofilewin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../userprofilewin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userprofilewin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_userProfileWin_t {
    const uint offsetsAndSize[24];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_userProfileWin_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_userProfileWin_t qt_meta_stringdata_userProfileWin = {
    {
QT_MOC_LITERAL(0, 14), // "userProfileWin"
QT_MOC_LITERAL(15, 14), // "signalExitProf"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 23), // "on_pushButton_5_clicked"
QT_MOC_LITERAL(55, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(79, 36), // "on_pushButton_downloadToFile_..."
QT_MOC_LITERAL(116, 29), // "on_pushButton_newName_clicked"
QT_MOC_LITERAL(146, 32), // "on_pushButton_newSurname_clicked"
QT_MOC_LITERAL(179, 29), // "on_pushButton_newPass_clicked"
QT_MOC_LITERAL(209, 30), // "on_pushButton_addCateg_clicked"
QT_MOC_LITERAL(240, 36), // "on_pushButton_addCategToPost_..."
QT_MOC_LITERAL(277, 36) // "on_pushButton_downloadToPost_..."

    },
    "userProfileWin\0signalExitProf\0\0"
    "on_pushButton_5_clicked\0on_pushButton_3_clicked\0"
    "on_pushButton_downloadToFile_clicked\0"
    "on_pushButton_newName_clicked\0"
    "on_pushButton_newSurname_clicked\0"
    "on_pushButton_newPass_clicked\0"
    "on_pushButton_addCateg_clicked\0"
    "on_pushButton_addCategToPost_clicked\0"
    "on_pushButton_downloadToPost_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_userProfileWin[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   75,    2, 0x08,    2 /* Private */,
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // signals: parameters
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

void userProfileWin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<userProfileWin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signalExitProf(); break;
        case 1: _t->on_pushButton_5_clicked(); break;
        case 2: _t->on_pushButton_3_clicked(); break;
        case 3: _t->on_pushButton_downloadToFile_clicked(); break;
        case 4: _t->on_pushButton_newName_clicked(); break;
        case 5: _t->on_pushButton_newSurname_clicked(); break;
        case 6: _t->on_pushButton_newPass_clicked(); break;
        case 7: _t->on_pushButton_addCateg_clicked(); break;
        case 8: _t->on_pushButton_addCategToPost_clicked(); break;
        case 9: _t->on_pushButton_downloadToPost_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (userProfileWin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&userProfileWin::signalExitProf)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject userProfileWin::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_userProfileWin.offsetsAndSize,
    qt_meta_data_userProfileWin,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_userProfileWin_t
, QtPrivate::TypeAndForceComplete<userProfileWin, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *userProfileWin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *userProfileWin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_userProfileWin.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int userProfileWin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void userProfileWin::signalExitProf()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
