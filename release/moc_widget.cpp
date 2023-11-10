/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[21];
    char stringdata0[474];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 24), // "on_pushButtonAdd_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 31), // "on_HorSliderVolume_valueChanged"
QT_MOC_LITERAL(4, 65, 5), // "value"
QT_MOC_LITERAL(5, 71, 25), // "on_pushButtonPlay_clicked"
QT_MOC_LITERAL(6, 97, 26), // "on_pushButtonPause_clicked"
QT_MOC_LITERAL(7, 124, 25), // "on_pushButtonStop_clicked"
QT_MOC_LITERAL(8, 150, 19), // "on_duration_changed"
QT_MOC_LITERAL(9, 170, 8), // "duration"
QT_MOC_LITERAL(10, 179, 19), // "on_position_changed"
QT_MOC_LITERAL(11, 199, 8), // "position"
QT_MOC_LITERAL(12, 208, 40), // "on_horizontalSliderProgress_v..."
QT_MOC_LITERAL(13, 249, 25), // "on_pushButtonMute_clicked"
QT_MOC_LITERAL(14, 275, 25), // "on_pushButtonPrev_clicked"
QT_MOC_LITERAL(15, 301, 25), // "on_pushButtonNext_clicked"
QT_MOC_LITERAL(16, 327, 26), // "on_pushButtonClear_clicked"
QT_MOC_LITERAL(17, 354, 24), // "on_pushButtonRem_clicked"
QT_MOC_LITERAL(18, 379, 39), // "on_horizontalSliderProgress_s..."
QT_MOC_LITERAL(19, 419, 25), // "on_pushButtonLoop_clicked"
QT_MOC_LITERAL(20, 445, 28) // "on_pushButtonShuffle_clicked"

    },
    "Widget\0on_pushButtonAdd_clicked\0\0"
    "on_HorSliderVolume_valueChanged\0value\0"
    "on_pushButtonPlay_clicked\0"
    "on_pushButtonPause_clicked\0"
    "on_pushButtonStop_clicked\0on_duration_changed\0"
    "duration\0on_position_changed\0position\0"
    "on_horizontalSliderProgress_valueChanged\0"
    "on_pushButtonMute_clicked\0"
    "on_pushButtonPrev_clicked\0"
    "on_pushButtonNext_clicked\0"
    "on_pushButtonClear_clicked\0"
    "on_pushButtonRem_clicked\0"
    "on_horizontalSliderProgress_sliderMoved\0"
    "on_pushButtonLoop_clicked\0"
    "on_pushButtonShuffle_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    1,  101,    2, 0x08 /* Private */,
      10,    1,  104,    2, 0x08 /* Private */,
      12,    1,  107,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    1,  115,    2, 0x08 /* Private */,
      19,    0,  118,    2, 0x08 /* Private */,
      20,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonAdd_clicked(); break;
        case 1: _t->on_HorSliderVolume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonPlay_clicked(); break;
        case 3: _t->on_pushButtonPause_clicked(); break;
        case 4: _t->on_pushButtonStop_clicked(); break;
        case 5: _t->on_duration_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 6: _t->on_position_changed((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->on_horizontalSliderProgress_valueChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_pushButtonMute_clicked(); break;
        case 9: _t->on_pushButtonPrev_clicked(); break;
        case 10: _t->on_pushButtonNext_clicked(); break;
        case 11: _t->on_pushButtonClear_clicked(); break;
        case 12: _t->on_pushButtonRem_clicked(); break;
        case 13: _t->on_horizontalSliderProgress_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_pushButtonLoop_clicked(); break;
        case 15: _t->on_pushButtonShuffle_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
