/****************************************************************************
** Meta object code from reading C++ file 'Track_info.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/model/Track_info.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Track_info.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Track_info_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Track_info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Track_info_t qt_meta_stringdata_Track_info = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Track_info"
QT_MOC_LITERAL(1, 11, 13), // "title_changed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "artist_changed"
QT_MOC_LITERAL(4, 41, 21), // "album_art_uri_changed"
QT_MOC_LITERAL(5, 63, 17), // "track_uri_changed"
QT_MOC_LITERAL(6, 81, 5), // "title"
QT_MOC_LITERAL(7, 87, 6), // "artist"
QT_MOC_LITERAL(8, 94, 13), // "album_art_uri"
QT_MOC_LITERAL(9, 108, 9) // "track_uri"

    },
    "Track_info\0title_changed\0\0artist_changed\0"
    "album_art_uri_changed\0track_uri_changed\0"
    "title\0artist\0album_art_uri\0track_uri"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Track_info[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::QString, 0x00495003,
       7, QMetaType::QString, 0x00495003,
       8, QMetaType::QString, 0x00495003,
       9, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void Track_info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Track_info *_t = static_cast<Track_info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->title_changed(); break;
        case 1: _t->artist_changed(); break;
        case 2: _t->album_art_uri_changed(); break;
        case 3: _t->track_uri_changed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Track_info::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Track_info::title_changed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Track_info::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Track_info::artist_changed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Track_info::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Track_info::album_art_uri_changed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Track_info::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Track_info::track_uri_changed)) {
                *result = 3;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Track_info *_t = static_cast<Track_info *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->title(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->artist(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->album_art_uri(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->track_uri(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Track_info *_t = static_cast<Track_info *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->set_title(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->set_artist(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->set_album_art_uri(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->set_track_uri(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject Track_info::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Track_info.data,
      qt_meta_data_Track_info,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Track_info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Track_info::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Track_info.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Track_info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Track_info::title_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Track_info::artist_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Track_info::album_art_uri_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Track_info::track_uri_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
