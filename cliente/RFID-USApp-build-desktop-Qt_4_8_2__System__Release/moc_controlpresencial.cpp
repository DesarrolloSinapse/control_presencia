/****************************************************************************
** Meta object code from reading C++ file 'controlpresencial.h'
**
** Created: Mon Oct 6 16:35:57 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RFID-USApp/controlpresencial.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controlpresencial.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ControlPresencial[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   29,   29,   29, 0x08,
      30,   29,   29,   29, 0x08,
      49,   29,   29,   29, 0x08,
      71,   29,   29,   29, 0x08,
      99,   29,   29,   29, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ControlPresencial[] = {
    "ControlPresencial\0showTime()\0\0"
    "RellenaDatosAula()\0showModified(QString)\0"
    "MonitorizaFicheros(QString)\0LimpiaError()\0"
};

void ControlPresencial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ControlPresencial *_t = static_cast<ControlPresencial *>(_o);
        switch (_id) {
        case 0: _t->showTime(); break;
        case 1: _t->RellenaDatosAula(); break;
        case 2: _t->showModified((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->MonitorizaFicheros((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->LimpiaError(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ControlPresencial::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ControlPresencial::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ControlPresencial,
      qt_meta_data_ControlPresencial, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ControlPresencial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ControlPresencial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ControlPresencial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ControlPresencial))
        return static_cast<void*>(const_cast< ControlPresencial*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ControlPresencial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
