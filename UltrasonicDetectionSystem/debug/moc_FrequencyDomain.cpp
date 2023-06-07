/****************************************************************************
** Meta object code from reading C++ file 'FrequencyDomain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UltrasonicDetectionSystem/FrequencyDomain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrequencyDomain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FrequencyDomain_t {
    QByteArrayData data[20];
    char stringdata0[272];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FrequencyDomain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FrequencyDomain_t qt_meta_stringdata_FrequencyDomain = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FrequencyDomain"
QT_MOC_LITERAL(1, 16, 7), // "Display"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "ShowMessage"
QT_MOC_LITERAL(4, 37, 8), // "uint16_t"
QT_MOC_LITERAL(5, 46, 12), // "StartConfirm"
QT_MOC_LITERAL(6, 59, 17), // "DisplayTimeDomain"
QT_MOC_LITERAL(7, 77, 15), // "DisplayDatabase"
QT_MOC_LITERAL(8, 93, 25), // "Draw_FrequencyDomain_Wave"
QT_MOC_LITERAL(9, 119, 10), // "TimeUpDate"
QT_MOC_LITERAL(10, 130, 10), // "ClearWaves"
QT_MOC_LITERAL(11, 141, 15), // "ChangeWaveStyle"
QT_MOC_LITERAL(12, 157, 12), // "LoadTimeData"
QT_MOC_LITERAL(13, 170, 16), // "ReadAndCalculate"
QT_MOC_LITERAL(14, 187, 15), // "InquiryMaterial"
QT_MOC_LITERAL(15, 203, 11), // "ConfirmHarm"
QT_MOC_LITERAL(16, 215, 8), // "FindHarm"
QT_MOC_LITERAL(17, 224, 13), // "RecSampleData"
QT_MOC_LITERAL(18, 238, 15), // "QVector<double>"
QT_MOC_LITERAL(19, 254, 17) // "SaveFrequencyData"

    },
    "FrequencyDomain\0Display\0\0ShowMessage\0"
    "uint16_t\0StartConfirm\0DisplayTimeDomain\0"
    "DisplayDatabase\0Draw_FrequencyDomain_Wave\0"
    "TimeUpDate\0ClearWaves\0ChangeWaveStyle\0"
    "LoadTimeData\0ReadAndCalculate\0"
    "InquiryMaterial\0ConfirmHarm\0FindHarm\0"
    "RecSampleData\0QVector<double>\0"
    "SaveFrequencyData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FrequencyDomain[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    2,   97,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    2,  114,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    2,    2,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort, 0x80000000 | 18,    2,    2,
    QMetaType::Void,

       0        // eod
};

void FrequencyDomain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FrequencyDomain *_t = static_cast<FrequencyDomain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Display((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ShowMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 2: _t->StartConfirm(); break;
        case 3: _t->DisplayTimeDomain(); break;
        case 4: _t->DisplayDatabase(); break;
        case 5: _t->Draw_FrequencyDomain_Wave(); break;
        case 6: _t->TimeUpDate(); break;
        case 7: _t->ClearWaves(); break;
        case 8: _t->ChangeWaveStyle(); break;
        case 9: _t->LoadTimeData(); break;
        case 10: _t->ReadAndCalculate(); break;
        case 11: _t->InquiryMaterial(); break;
        case 12: _t->ConfirmHarm(); break;
        case 13: _t->FindHarm(); break;
        case 14: _t->RecSampleData((*reinterpret_cast< quint16(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 15: _t->SaveFrequencyData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (FrequencyDomain::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrequencyDomain::Display)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FrequencyDomain::*_t)(QString , uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrequencyDomain::ShowMessage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FrequencyDomain::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FrequencyDomain::StartConfirm)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FrequencyDomain::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_FrequencyDomain.data,
      qt_meta_data_FrequencyDomain,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *FrequencyDomain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FrequencyDomain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FrequencyDomain.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FrequencyDomain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void FrequencyDomain::Display(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FrequencyDomain::ShowMessage(QString _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FrequencyDomain::StartConfirm()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
