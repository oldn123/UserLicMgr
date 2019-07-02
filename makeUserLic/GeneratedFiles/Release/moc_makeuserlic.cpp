/****************************************************************************
** Meta object code from reading C++ file 'makeuserlic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../makeuserlic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'makeuserlic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_makeUserLic_t {
    QByteArrayData data[5];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_makeUserLic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_makeUserLic_t qt_meta_stringdata_makeUserLic = {
    {
QT_MOC_LITERAL(0, 0, 11), // "makeUserLic"
QT_MOC_LITERAL(1, 12, 10), // "OnSoftMenu"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "OnLicMenu"
QT_MOC_LITERAL(4, 34, 13) // "OnTabViewSize"

    },
    "makeUserLic\0OnSoftMenu\0\0OnLicMenu\0"
    "OnTabViewSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_makeUserLic[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x08 /* Private */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void makeUserLic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        makeUserLic *_t = static_cast<makeUserLic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnSoftMenu(); break;
        case 1: _t->OnLicMenu(); break;
        case 2: _t->OnTabViewSize(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject makeUserLic::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_makeUserLic.data,
      qt_meta_data_makeUserLic,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *makeUserLic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *makeUserLic::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_makeUserLic.stringdata0))
        return static_cast<void*>(const_cast< makeUserLic*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int makeUserLic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
struct qt_meta_stringdata_CNewSoftDlg_t {
    QByteArrayData data[3];
    char stringdata0[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNewSoftDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNewSoftDlg_t qt_meta_stringdata_CNewSoftDlg = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CNewSoftDlg"
QT_MOC_LITERAL(1, 12, 7), // "OnBtnOk"
QT_MOC_LITERAL(2, 20, 0) // ""

    },
    "CNewSoftDlg\0OnBtnOk\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNewSoftDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CNewSoftDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CNewSoftDlg *_t = static_cast<CNewSoftDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnBtnOk(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CNewSoftDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CNewSoftDlg.data,
      qt_meta_data_CNewSoftDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CNewSoftDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNewSoftDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CNewSoftDlg.stringdata0))
        return static_cast<void*>(const_cast< CNewSoftDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CNewSoftDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_CNewLicDlg_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CNewLicDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CNewLicDlg_t qt_meta_stringdata_CNewLicDlg = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CNewLicDlg"
QT_MOC_LITERAL(1, 11, 12), // "OnBtnMakeLic"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "CNewLicDlg\0OnBtnMakeLic\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CNewLicDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void CNewLicDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CNewLicDlg *_t = static_cast<CNewLicDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OnBtnMakeLic(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CNewLicDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CNewLicDlg.data,
      qt_meta_data_CNewLicDlg,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CNewLicDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CNewLicDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CNewLicDlg.stringdata0))
        return static_cast<void*>(const_cast< CNewLicDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int CNewLicDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
