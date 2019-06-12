/****************************************************************************
** Meta object code from reading C++ file 'Player_state.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/model/Player_state.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Player_state.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_state_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_state_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_state_t qt_meta_stringdata_Player_state = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Player_state"
QT_MOC_LITERAL(1, 13, 15), // "bitrate_changed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "time_total_changed"
QT_MOC_LITERAL(4, 49, 20), // "time_elapsed_changed"
QT_MOC_LITERAL(5, 70, 7), // "bitrate"
QT_MOC_LITERAL(6, 78, 10), // "time_total"
QT_MOC_LITERAL(7, 89, 12) // "time_elapsed"

    },
    "Player_state\0bitrate_changed\0\0"
    "time_total_changed\0time_elapsed_changed\0"
    "bitrate\0time_total\0time_elapsed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player_state[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       3,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    0,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Int, 0x00495003,
       6, QMetaType::Int, 0x00495003,
       7, QMetaType::Int, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,

       0        // eod
};

void Player_state::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player_state *_t = static_cast<Player_state *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bitrate_changed(); break;
        case 1: _t->time_total_changed(); break;
        case 2: _t->time_elapsed_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Player_state::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player_state::bitrate_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Player_state::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player_state::time_total_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Player_state::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player_state::time_elapsed_changed)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Player_state *_t = static_cast<Player_state *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->bitrate(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->time_total(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->time_elapsed(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Player_state *_t = static_cast<Player_state *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_bitrate(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->set_time_total(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->set_time_elapsed(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Player_state::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Player_state.data,
      qt_meta_data_Player_state,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Player_state::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player_state::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player_state.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Player_state::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Player_state::bitrate_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Player_state::time_total_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Player_state::time_elapsed_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
