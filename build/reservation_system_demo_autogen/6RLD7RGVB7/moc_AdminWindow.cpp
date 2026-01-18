/****************************************************************************
** Meta object code from reading C++ file 'AdminWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/UI/AdminWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AdminWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AdminWindow_t {
    const uint offsetsAndSize[42];
    char stringdata0[360];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_AdminWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_AdminWindow_t qt_meta_stringdata_AdminWindow = {
    {
QT_MOC_LITERAL(0, 11), // "AdminWindow"
QT_MOC_LITERAL(12, 15), // "onAddExperiment"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 18), // "onUpdateExperiment"
QT_MOC_LITERAL(48, 18), // "onDeleteExperiment"
QT_MOC_LITERAL(67, 19), // "onPublishExperiment"
QT_MOC_LITERAL(87, 20), // "onRefreshExperiments"
QT_MOC_LITERAL(108, 12), // "onAddStudent"
QT_MOC_LITERAL(121, 15), // "onUpdateStudent"
QT_MOC_LITERAL(137, 15), // "onDeleteStudent"
QT_MOC_LITERAL(153, 17), // "onRefreshStudents"
QT_MOC_LITERAL(171, 12), // "onAddTeacher"
QT_MOC_LITERAL(184, 15), // "onUpdateTeacher"
QT_MOC_LITERAL(200, 15), // "onDeleteTeacher"
QT_MOC_LITERAL(216, 17), // "onRefreshTeachers"
QT_MOC_LITERAL(234, 22), // "onExportExperimentsCSV"
QT_MOC_LITERAL(257, 22), // "onExportExperimentsTXT"
QT_MOC_LITERAL(280, 19), // "onExportStudentsCSV"
QT_MOC_LITERAL(300, 19), // "onExportStudentsTXT"
QT_MOC_LITERAL(320, 19), // "onExportTeachersCSV"
QT_MOC_LITERAL(340, 19) // "onExportTeachersTXT"

    },
    "AdminWindow\0onAddExperiment\0\0"
    "onUpdateExperiment\0onDeleteExperiment\0"
    "onPublishExperiment\0onRefreshExperiments\0"
    "onAddStudent\0onUpdateStudent\0"
    "onDeleteStudent\0onRefreshStudents\0"
    "onAddTeacher\0onUpdateTeacher\0"
    "onDeleteTeacher\0onRefreshTeachers\0"
    "onExportExperimentsCSV\0onExportExperimentsTXT\0"
    "onExportStudentsCSV\0onExportStudentsTXT\0"
    "onExportTeachersCSV\0onExportTeachersTXT"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdminWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    0,  133,    2, 0x08,    6 /* Private */,
       8,    0,  134,    2, 0x08,    7 /* Private */,
       9,    0,  135,    2, 0x08,    8 /* Private */,
      10,    0,  136,    2, 0x08,    9 /* Private */,
      11,    0,  137,    2, 0x08,   10 /* Private */,
      12,    0,  138,    2, 0x08,   11 /* Private */,
      13,    0,  139,    2, 0x08,   12 /* Private */,
      14,    0,  140,    2, 0x08,   13 /* Private */,
      15,    0,  141,    2, 0x08,   14 /* Private */,
      16,    0,  142,    2, 0x08,   15 /* Private */,
      17,    0,  143,    2, 0x08,   16 /* Private */,
      18,    0,  144,    2, 0x08,   17 /* Private */,
      19,    0,  145,    2, 0x08,   18 /* Private */,
      20,    0,  146,    2, 0x08,   19 /* Private */,

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

void AdminWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AdminWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAddExperiment(); break;
        case 1: _t->onUpdateExperiment(); break;
        case 2: _t->onDeleteExperiment(); break;
        case 3: _t->onPublishExperiment(); break;
        case 4: _t->onRefreshExperiments(); break;
        case 5: _t->onAddStudent(); break;
        case 6: _t->onUpdateStudent(); break;
        case 7: _t->onDeleteStudent(); break;
        case 8: _t->onRefreshStudents(); break;
        case 9: _t->onAddTeacher(); break;
        case 10: _t->onUpdateTeacher(); break;
        case 11: _t->onDeleteTeacher(); break;
        case 12: _t->onRefreshTeachers(); break;
        case 13: _t->onExportExperimentsCSV(); break;
        case 14: _t->onExportExperimentsTXT(); break;
        case 15: _t->onExportStudentsCSV(); break;
        case 16: _t->onExportStudentsTXT(); break;
        case 17: _t->onExportTeachersCSV(); break;
        case 18: _t->onExportTeachersTXT(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject AdminWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_AdminWindow.offsetsAndSize,
    qt_meta_data_AdminWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AdminWindow_t
, QtPrivate::TypeAndForceComplete<AdminWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AdminWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdminWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AdminWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AdminWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
