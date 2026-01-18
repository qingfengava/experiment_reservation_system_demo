/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabExperiments;
    QVBoxLayout *verticalLayout_Exp;
    QTableWidget *tableExperiments;
    QGridLayout *gridLayout_ExpForm;
    QLabel *labelExpId;
    QLineEdit *editExpId;
    QLabel *labelExpName;
    QLineEdit *editExpName;
    QLabel *labelStartTime;
    QDateTimeEdit *startDateTime;
    QLabel *labelEndTime;
    QDateTimeEdit *endDateTime;
    QLabel *labelTotalSeats;
    QSpinBox *spinTotalSeats;
    QLabel *labelTeacherId;
    QLineEdit *editTeacherId;
    QLabel *labelTeacherName;
    QLineEdit *editTeacherName;
    QPushButton *btnAddExp;
    QPushButton *btnUpdateExp;
    QPushButton *btnDeleteExp;
    QPushButton *btnPublishExp;
    QPushButton *btnExportExpCSV;
    QPushButton *btnExportExpTXT;
    QWidget *tabStudents;
    QVBoxLayout *verticalLayout_Stu;
    QTableWidget *tableStudents;
    QGridLayout *gridLayout_StuForm;
    QLabel *labelStuId;
    QLineEdit *editStuId;
    QLabel *labelStuName;
    QLineEdit *editStuName;
    QLabel *labelStuCollege;
    QLineEdit *editStuCollege;
    QLabel *labelStuMajor;
    QLineEdit *editStuMajor;
    QLabel *labelStuPassword;
    QLineEdit *editStuPassword;
    QPushButton *btnAddStu;
    QPushButton *btnUpdateStu;
    QPushButton *btnDeleteStu;
    QPushButton *btnRefreshStu;
    QPushButton *btnExportStuCSV;
    QPushButton *btnExportStuTXT;
    QWidget *tabTeachers;
    QVBoxLayout *verticalLayout_Tea;
    QTableWidget *tableTeachers;
    QGridLayout *gridLayout_TeaForm;
    QLabel *labelTeaId;
    QLineEdit *editTeaId;
    QLabel *labelTeaName;
    QLineEdit *editTeaName;
    QLabel *labelTeaCollege;
    QLineEdit *editTeaCollege;
    QLabel *labelTeaPassword;
    QLineEdit *editTeaPassword;
    QPushButton *btnAddTea;
    QPushButton *btnUpdateTea;
    QPushButton *btnDeleteTea;
    QPushButton *btnRefreshTea;
    QPushButton *btnExportTeaCSV;
    QPushButton *btnExportTeaTXT;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(900, 600);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabExperiments = new QWidget();
        tabExperiments->setObjectName(QString::fromUtf8("tabExperiments"));
        verticalLayout_Exp = new QVBoxLayout(tabExperiments);
        verticalLayout_Exp->setObjectName(QString::fromUtf8("verticalLayout_Exp"));
        tableExperiments = new QTableWidget(tabExperiments);
        tableExperiments->setObjectName(QString::fromUtf8("tableExperiments"));

        verticalLayout_Exp->addWidget(tableExperiments);

        gridLayout_ExpForm = new QGridLayout();
        gridLayout_ExpForm->setObjectName(QString::fromUtf8("gridLayout_ExpForm"));
        labelExpId = new QLabel(tabExperiments);
        labelExpId->setObjectName(QString::fromUtf8("labelExpId"));

        gridLayout_ExpForm->addWidget(labelExpId, 0, 0, 1, 1);

        editExpId = new QLineEdit(tabExperiments);
        editExpId->setObjectName(QString::fromUtf8("editExpId"));

        gridLayout_ExpForm->addWidget(editExpId, 0, 1, 1, 1);

        labelExpName = new QLabel(tabExperiments);
        labelExpName->setObjectName(QString::fromUtf8("labelExpName"));

        gridLayout_ExpForm->addWidget(labelExpName, 1, 0, 1, 1);

        editExpName = new QLineEdit(tabExperiments);
        editExpName->setObjectName(QString::fromUtf8("editExpName"));

        gridLayout_ExpForm->addWidget(editExpName, 1, 1, 1, 1);

        labelStartTime = new QLabel(tabExperiments);
        labelStartTime->setObjectName(QString::fromUtf8("labelStartTime"));

        gridLayout_ExpForm->addWidget(labelStartTime, 2, 0, 1, 1);

        startDateTime = new QDateTimeEdit(tabExperiments);
        startDateTime->setObjectName(QString::fromUtf8("startDateTime"));

        gridLayout_ExpForm->addWidget(startDateTime, 2, 1, 1, 1);

        labelEndTime = new QLabel(tabExperiments);
        labelEndTime->setObjectName(QString::fromUtf8("labelEndTime"));

        gridLayout_ExpForm->addWidget(labelEndTime, 3, 0, 1, 1);

        endDateTime = new QDateTimeEdit(tabExperiments);
        endDateTime->setObjectName(QString::fromUtf8("endDateTime"));

        gridLayout_ExpForm->addWidget(endDateTime, 3, 1, 1, 1);

        labelTotalSeats = new QLabel(tabExperiments);
        labelTotalSeats->setObjectName(QString::fromUtf8("labelTotalSeats"));

        gridLayout_ExpForm->addWidget(labelTotalSeats, 4, 0, 1, 1);

        spinTotalSeats = new QSpinBox(tabExperiments);
        spinTotalSeats->setObjectName(QString::fromUtf8("spinTotalSeats"));

        gridLayout_ExpForm->addWidget(spinTotalSeats, 4, 1, 1, 1);

        labelTeacherId = new QLabel(tabExperiments);
        labelTeacherId->setObjectName(QString::fromUtf8("labelTeacherId"));

        gridLayout_ExpForm->addWidget(labelTeacherId, 5, 0, 1, 1);

        editTeacherId = new QLineEdit(tabExperiments);
        editTeacherId->setObjectName(QString::fromUtf8("editTeacherId"));

        gridLayout_ExpForm->addWidget(editTeacherId, 5, 1, 1, 1);

        labelTeacherName = new QLabel(tabExperiments);
        labelTeacherName->setObjectName(QString::fromUtf8("labelTeacherName"));

        gridLayout_ExpForm->addWidget(labelTeacherName, 6, 0, 1, 1);

        editTeacherName = new QLineEdit(tabExperiments);
        editTeacherName->setObjectName(QString::fromUtf8("editTeacherName"));

        gridLayout_ExpForm->addWidget(editTeacherName, 6, 1, 1, 1);

        btnAddExp = new QPushButton(tabExperiments);
        btnAddExp->setObjectName(QString::fromUtf8("btnAddExp"));

        gridLayout_ExpForm->addWidget(btnAddExp, 7, 0, 1, 1);

        btnUpdateExp = new QPushButton(tabExperiments);
        btnUpdateExp->setObjectName(QString::fromUtf8("btnUpdateExp"));

        gridLayout_ExpForm->addWidget(btnUpdateExp, 7, 1, 1, 1);

        btnDeleteExp = new QPushButton(tabExperiments);
        btnDeleteExp->setObjectName(QString::fromUtf8("btnDeleteExp"));

        gridLayout_ExpForm->addWidget(btnDeleteExp, 8, 0, 1, 1);

        btnPublishExp = new QPushButton(tabExperiments);
        btnPublishExp->setObjectName(QString::fromUtf8("btnPublishExp"));

        gridLayout_ExpForm->addWidget(btnPublishExp, 8, 1, 1, 1);

        btnExportExpCSV = new QPushButton(tabExperiments);
        btnExportExpCSV->setObjectName(QString::fromUtf8("btnExportExpCSV"));

        gridLayout_ExpForm->addWidget(btnExportExpCSV, 9, 0, 1, 2);

        btnExportExpTXT = new QPushButton(tabExperiments);
        btnExportExpTXT->setObjectName(QString::fromUtf8("btnExportExpTXT"));

        gridLayout_ExpForm->addWidget(btnExportExpTXT, 10, 0, 1, 2);


        verticalLayout_Exp->addLayout(gridLayout_ExpForm);

        tabWidget->addTab(tabExperiments, QString());
        tabStudents = new QWidget();
        tabStudents->setObjectName(QString::fromUtf8("tabStudents"));
        verticalLayout_Stu = new QVBoxLayout(tabStudents);
        verticalLayout_Stu->setObjectName(QString::fromUtf8("verticalLayout_Stu"));
        tableStudents = new QTableWidget(tabStudents);
        tableStudents->setObjectName(QString::fromUtf8("tableStudents"));

        verticalLayout_Stu->addWidget(tableStudents);

        gridLayout_StuForm = new QGridLayout();
        gridLayout_StuForm->setObjectName(QString::fromUtf8("gridLayout_StuForm"));
        labelStuId = new QLabel(tabStudents);
        labelStuId->setObjectName(QString::fromUtf8("labelStuId"));

        gridLayout_StuForm->addWidget(labelStuId, 0, 0, 1, 1);

        editStuId = new QLineEdit(tabStudents);
        editStuId->setObjectName(QString::fromUtf8("editStuId"));

        gridLayout_StuForm->addWidget(editStuId, 0, 1, 1, 1);

        labelStuName = new QLabel(tabStudents);
        labelStuName->setObjectName(QString::fromUtf8("labelStuName"));

        gridLayout_StuForm->addWidget(labelStuName, 1, 0, 1, 1);

        editStuName = new QLineEdit(tabStudents);
        editStuName->setObjectName(QString::fromUtf8("editStuName"));

        gridLayout_StuForm->addWidget(editStuName, 1, 1, 1, 1);

        labelStuCollege = new QLabel(tabStudents);
        labelStuCollege->setObjectName(QString::fromUtf8("labelStuCollege"));

        gridLayout_StuForm->addWidget(labelStuCollege, 2, 0, 1, 1);

        editStuCollege = new QLineEdit(tabStudents);
        editStuCollege->setObjectName(QString::fromUtf8("editStuCollege"));

        gridLayout_StuForm->addWidget(editStuCollege, 2, 1, 1, 1);

        labelStuMajor = new QLabel(tabStudents);
        labelStuMajor->setObjectName(QString::fromUtf8("labelStuMajor"));

        gridLayout_StuForm->addWidget(labelStuMajor, 3, 0, 1, 1);

        editStuMajor = new QLineEdit(tabStudents);
        editStuMajor->setObjectName(QString::fromUtf8("editStuMajor"));

        gridLayout_StuForm->addWidget(editStuMajor, 3, 1, 1, 1);

        labelStuPassword = new QLabel(tabStudents);
        labelStuPassword->setObjectName(QString::fromUtf8("labelStuPassword"));

        gridLayout_StuForm->addWidget(labelStuPassword, 4, 0, 1, 1);

        editStuPassword = new QLineEdit(tabStudents);
        editStuPassword->setObjectName(QString::fromUtf8("editStuPassword"));

        gridLayout_StuForm->addWidget(editStuPassword, 4, 1, 1, 1);

        btnAddStu = new QPushButton(tabStudents);
        btnAddStu->setObjectName(QString::fromUtf8("btnAddStu"));

        gridLayout_StuForm->addWidget(btnAddStu, 5, 0, 1, 1);

        btnUpdateStu = new QPushButton(tabStudents);
        btnUpdateStu->setObjectName(QString::fromUtf8("btnUpdateStu"));

        gridLayout_StuForm->addWidget(btnUpdateStu, 5, 1, 1, 1);

        btnDeleteStu = new QPushButton(tabStudents);
        btnDeleteStu->setObjectName(QString::fromUtf8("btnDeleteStu"));

        gridLayout_StuForm->addWidget(btnDeleteStu, 6, 0, 1, 1);

        btnRefreshStu = new QPushButton(tabStudents);
        btnRefreshStu->setObjectName(QString::fromUtf8("btnRefreshStu"));

        gridLayout_StuForm->addWidget(btnRefreshStu, 6, 1, 1, 1);

        btnExportStuCSV = new QPushButton(tabStudents);
        btnExportStuCSV->setObjectName(QString::fromUtf8("btnExportStuCSV"));

        gridLayout_StuForm->addWidget(btnExportStuCSV, 7, 0, 1, 2);

        btnExportStuTXT = new QPushButton(tabStudents);
        btnExportStuTXT->setObjectName(QString::fromUtf8("btnExportStuTXT"));

        gridLayout_StuForm->addWidget(btnExportStuTXT, 8, 0, 1, 2);


        verticalLayout_Stu->addLayout(gridLayout_StuForm);

        tabWidget->addTab(tabStudents, QString());
        tabTeachers = new QWidget();
        tabTeachers->setObjectName(QString::fromUtf8("tabTeachers"));
        verticalLayout_Tea = new QVBoxLayout(tabTeachers);
        verticalLayout_Tea->setObjectName(QString::fromUtf8("verticalLayout_Tea"));
        tableTeachers = new QTableWidget(tabTeachers);
        tableTeachers->setObjectName(QString::fromUtf8("tableTeachers"));

        verticalLayout_Tea->addWidget(tableTeachers);

        gridLayout_TeaForm = new QGridLayout();
        gridLayout_TeaForm->setObjectName(QString::fromUtf8("gridLayout_TeaForm"));
        labelTeaId = new QLabel(tabTeachers);
        labelTeaId->setObjectName(QString::fromUtf8("labelTeaId"));

        gridLayout_TeaForm->addWidget(labelTeaId, 0, 0, 1, 1);

        editTeaId = new QLineEdit(tabTeachers);
        editTeaId->setObjectName(QString::fromUtf8("editTeaId"));

        gridLayout_TeaForm->addWidget(editTeaId, 0, 1, 1, 1);

        labelTeaName = new QLabel(tabTeachers);
        labelTeaName->setObjectName(QString::fromUtf8("labelTeaName"));

        gridLayout_TeaForm->addWidget(labelTeaName, 1, 0, 1, 1);

        editTeaName = new QLineEdit(tabTeachers);
        editTeaName->setObjectName(QString::fromUtf8("editTeaName"));

        gridLayout_TeaForm->addWidget(editTeaName, 1, 1, 1, 1);

        labelTeaCollege = new QLabel(tabTeachers);
        labelTeaCollege->setObjectName(QString::fromUtf8("labelTeaCollege"));

        gridLayout_TeaForm->addWidget(labelTeaCollege, 2, 0, 1, 1);

        editTeaCollege = new QLineEdit(tabTeachers);
        editTeaCollege->setObjectName(QString::fromUtf8("editTeaCollege"));

        gridLayout_TeaForm->addWidget(editTeaCollege, 2, 1, 1, 1);

        labelTeaPassword = new QLabel(tabTeachers);
        labelTeaPassword->setObjectName(QString::fromUtf8("labelTeaPassword"));

        gridLayout_TeaForm->addWidget(labelTeaPassword, 3, 0, 1, 1);

        editTeaPassword = new QLineEdit(tabTeachers);
        editTeaPassword->setObjectName(QString::fromUtf8("editTeaPassword"));

        gridLayout_TeaForm->addWidget(editTeaPassword, 3, 1, 1, 1);

        btnAddTea = new QPushButton(tabTeachers);
        btnAddTea->setObjectName(QString::fromUtf8("btnAddTea"));

        gridLayout_TeaForm->addWidget(btnAddTea, 4, 0, 1, 1);

        btnUpdateTea = new QPushButton(tabTeachers);
        btnUpdateTea->setObjectName(QString::fromUtf8("btnUpdateTea"));

        gridLayout_TeaForm->addWidget(btnUpdateTea, 4, 1, 1, 1);

        btnDeleteTea = new QPushButton(tabTeachers);
        btnDeleteTea->setObjectName(QString::fromUtf8("btnDeleteTea"));

        gridLayout_TeaForm->addWidget(btnDeleteTea, 5, 0, 1, 1);

        btnRefreshTea = new QPushButton(tabTeachers);
        btnRefreshTea->setObjectName(QString::fromUtf8("btnRefreshTea"));

        gridLayout_TeaForm->addWidget(btnRefreshTea, 5, 1, 1, 1);

        btnExportTeaCSV = new QPushButton(tabTeachers);
        btnExportTeaCSV->setObjectName(QString::fromUtf8("btnExportTeaCSV"));

        gridLayout_TeaForm->addWidget(btnExportTeaCSV, 6, 0, 1, 2);

        btnExportTeaTXT = new QPushButton(tabTeachers);
        btnExportTeaTXT->setObjectName(QString::fromUtf8("btnExportTeaTXT"));

        gridLayout_TeaForm->addWidget(btnExportTeaTXT, 7, 0, 1, 2);


        verticalLayout_Tea->addLayout(gridLayout_TeaForm);

        tabWidget->addTab(tabTeachers, QString());

        verticalLayout->addWidget(tabWidget);

        AdminWindow->setCentralWidget(centralwidget);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QCoreApplication::translate("AdminWindow", "\345\256\236\351\252\214\351\242\204\347\272\246\347\263\273\347\273\237 - \347\256\241\347\220\206\345\221\230", nullptr));
        labelExpId->setText(QCoreApplication::translate("AdminWindow", "\345\256\236\351\252\214\347\274\226\345\217\267", nullptr));
        labelExpName->setText(QCoreApplication::translate("AdminWindow", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        labelStartTime->setText(QCoreApplication::translate("AdminWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        labelEndTime->setText(QCoreApplication::translate("AdminWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        labelTotalSeats->setText(QCoreApplication::translate("AdminWindow", "\346\200\273\345\270\255\344\275\215", nullptr));
        labelTeacherId->setText(QCoreApplication::translate("AdminWindow", "\346\225\231\345\270\210\347\274\226\345\217\267", nullptr));
        labelTeacherName->setText(QCoreApplication::translate("AdminWindow", "\346\225\231\345\270\210\345\247\223\345\220\215", nullptr));
        btnAddExp->setText(QCoreApplication::translate("AdminWindow", "\346\267\273\345\212\240", nullptr));
        btnUpdateExp->setText(QCoreApplication::translate("AdminWindow", "\344\277\256\346\224\271", nullptr));
        btnDeleteExp->setText(QCoreApplication::translate("AdminWindow", "\345\210\240\351\231\244", nullptr));
        btnPublishExp->setText(QCoreApplication::translate("AdminWindow", "\345\217\221\345\270\203", nullptr));
        btnExportExpCSV->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\345\256\236\351\252\214CSV", nullptr));
        btnExportExpTXT->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\345\256\236\351\252\214TXT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExperiments), QCoreApplication::translate("AdminWindow", "\345\256\236\351\252\214\347\256\241\347\220\206", nullptr));
        labelStuId->setText(QCoreApplication::translate("AdminWindow", "\345\255\246\345\217\267", nullptr));
        labelStuName->setText(QCoreApplication::translate("AdminWindow", "\345\247\223\345\220\215", nullptr));
        labelStuCollege->setText(QCoreApplication::translate("AdminWindow", "\345\255\246\351\231\242", nullptr));
        labelStuMajor->setText(QCoreApplication::translate("AdminWindow", "\344\270\223\344\270\232", nullptr));
        labelStuPassword->setText(QCoreApplication::translate("AdminWindow", "\345\257\206\347\240\201", nullptr));
        btnAddStu->setText(QCoreApplication::translate("AdminWindow", "\346\267\273\345\212\240", nullptr));
        btnUpdateStu->setText(QCoreApplication::translate("AdminWindow", "\344\277\256\346\224\271", nullptr));
        btnDeleteStu->setText(QCoreApplication::translate("AdminWindow", "\345\210\240\351\231\244", nullptr));
        btnRefreshStu->setText(QCoreApplication::translate("AdminWindow", "\345\210\267\346\226\260", nullptr));
        btnExportStuCSV->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\345\255\246\347\224\237CSV", nullptr));
        btnExportStuTXT->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\345\255\246\347\224\237TXT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStudents), QCoreApplication::translate("AdminWindow", "\345\255\246\347\224\237\347\256\241\347\220\206", nullptr));
        labelTeaId->setText(QCoreApplication::translate("AdminWindow", "\345\267\245\345\217\267", nullptr));
        labelTeaName->setText(QCoreApplication::translate("AdminWindow", "\345\247\223\345\220\215", nullptr));
        labelTeaCollege->setText(QCoreApplication::translate("AdminWindow", "\345\255\246\351\231\242", nullptr));
        labelTeaPassword->setText(QCoreApplication::translate("AdminWindow", "\345\257\206\347\240\201", nullptr));
        btnAddTea->setText(QCoreApplication::translate("AdminWindow", "\346\267\273\345\212\240", nullptr));
        btnUpdateTea->setText(QCoreApplication::translate("AdminWindow", "\344\277\256\346\224\271", nullptr));
        btnDeleteTea->setText(QCoreApplication::translate("AdminWindow", "\345\210\240\351\231\244", nullptr));
        btnRefreshTea->setText(QCoreApplication::translate("AdminWindow", "\345\210\267\346\226\260", nullptr));
        btnExportTeaCSV->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\346\225\231\345\270\210CSV", nullptr));
        btnExportTeaTXT->setText(QCoreApplication::translate("AdminWindow", "\345\257\274\345\207\272\346\225\231\345\270\210TXT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTeachers), QCoreApplication::translate("AdminWindow", "\346\225\231\345\270\210\347\256\241\347\220\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
