/********************************************************************************
** Form generated from reading UI file 'TeacherWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHERWINDOW_H
#define UI_TEACHERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeacherWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupExperiments;
    QVBoxLayout *vboxMyExperiments;
    QTableWidget *tableMyExperiments;
    QHBoxLayout *hboxMyExperimentsButtons;
    QPushButton *btnRefreshMyExperiments;
    QPushButton *btnViewExperimentStudents;
    QGroupBox *groupStudents;
    QVBoxLayout *vboxExperimentStudents;
    QTableWidget *tableExperimentStudents;
    QHBoxLayout *hboxStudentButtons;
    QPushButton *btnImportScores;
    QPushButton *btnUpdateScore;
    QPushButton *btnExportReservationsCSV;
    QPushButton *btnExportReservationsTXT;

    void setupUi(QMainWindow *TeacherWindow)
    {
        if (TeacherWindow->objectName().isEmpty())
            TeacherWindow->setObjectName(QString::fromUtf8("TeacherWindow"));
        TeacherWindow->resize(900, 700);
        centralwidget = new QWidget(TeacherWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupExperiments = new QGroupBox(centralwidget);
        groupExperiments->setObjectName(QString::fromUtf8("groupExperiments"));
        vboxMyExperiments = new QVBoxLayout(groupExperiments);
        vboxMyExperiments->setObjectName(QString::fromUtf8("vboxMyExperiments"));
        tableMyExperiments = new QTableWidget(groupExperiments);
        if (tableMyExperiments->columnCount() < 6)
            tableMyExperiments->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableMyExperiments->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableMyExperiments->setObjectName(QString::fromUtf8("tableMyExperiments"));
        tableMyExperiments->setColumnCount(6);
        tableMyExperiments->setRowCount(0);

        vboxMyExperiments->addWidget(tableMyExperiments);

        hboxMyExperimentsButtons = new QHBoxLayout();
        hboxMyExperimentsButtons->setObjectName(QString::fromUtf8("hboxMyExperimentsButtons"));
        btnRefreshMyExperiments = new QPushButton(groupExperiments);
        btnRefreshMyExperiments->setObjectName(QString::fromUtf8("btnRefreshMyExperiments"));

        hboxMyExperimentsButtons->addWidget(btnRefreshMyExperiments);

        btnViewExperimentStudents = new QPushButton(groupExperiments);
        btnViewExperimentStudents->setObjectName(QString::fromUtf8("btnViewExperimentStudents"));

        hboxMyExperimentsButtons->addWidget(btnViewExperimentStudents);


        vboxMyExperiments->addLayout(hboxMyExperimentsButtons);


        verticalLayout->addWidget(groupExperiments);

        groupStudents = new QGroupBox(centralwidget);
        groupStudents->setObjectName(QString::fromUtf8("groupStudents"));
        vboxExperimentStudents = new QVBoxLayout(groupStudents);
        vboxExperimentStudents->setObjectName(QString::fromUtf8("vboxExperimentStudents"));
        tableExperimentStudents = new QTableWidget(groupStudents);
        if (tableExperimentStudents->columnCount() < 3)
            tableExperimentStudents->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableExperimentStudents->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableExperimentStudents->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableExperimentStudents->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        tableExperimentStudents->setObjectName(QString::fromUtf8("tableExperimentStudents"));
        tableExperimentStudents->setColumnCount(3);
        tableExperimentStudents->setRowCount(0);

        vboxExperimentStudents->addWidget(tableExperimentStudents);

        hboxStudentButtons = new QHBoxLayout();
        hboxStudentButtons->setObjectName(QString::fromUtf8("hboxStudentButtons"));
        btnImportScores = new QPushButton(groupStudents);
        btnImportScores->setObjectName(QString::fromUtf8("btnImportScores"));

        hboxStudentButtons->addWidget(btnImportScores);

        btnUpdateScore = new QPushButton(groupStudents);
        btnUpdateScore->setObjectName(QString::fromUtf8("btnUpdateScore"));

        hboxStudentButtons->addWidget(btnUpdateScore);

        btnExportReservationsCSV = new QPushButton(groupStudents);
        btnExportReservationsCSV->setObjectName(QString::fromUtf8("btnExportReservationsCSV"));

        hboxStudentButtons->addWidget(btnExportReservationsCSV);

        btnExportReservationsTXT = new QPushButton(groupStudents);
        btnExportReservationsTXT->setObjectName(QString::fromUtf8("btnExportReservationsTXT"));

        hboxStudentButtons->addWidget(btnExportReservationsTXT);


        vboxExperimentStudents->addLayout(hboxStudentButtons);


        verticalLayout->addWidget(groupStudents);

        TeacherWindow->setCentralWidget(centralwidget);

        retranslateUi(TeacherWindow);

        QMetaObject::connectSlotsByName(TeacherWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TeacherWindow)
    {
        TeacherWindow->setWindowTitle(QCoreApplication::translate("TeacherWindow", "\346\225\231\345\270\210\345\256\236\351\252\214\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        groupExperiments->setTitle(QCoreApplication::translate("TeacherWindow", "\346\210\221\347\232\204\345\256\236\351\252\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableMyExperiments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TeacherWindow", "\345\256\236\351\252\214\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableMyExperiments->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TeacherWindow", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMyExperiments->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TeacherWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMyExperiments->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TeacherWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableMyExperiments->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TeacherWindow", "\346\200\273\345\270\255\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableMyExperiments->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TeacherWindow", "\351\242\204\347\272\246\344\272\272\346\225\260", nullptr));
        btnRefreshMyExperiments->setText(QCoreApplication::translate("TeacherWindow", "\345\210\267\346\226\260\345\256\236\351\252\214\345\210\227\350\241\250", nullptr));
        btnViewExperimentStudents->setText(QCoreApplication::translate("TeacherWindow", "\346\237\245\347\234\213\345\255\246\347\224\237", nullptr));
        groupStudents->setTitle(QCoreApplication::translate("TeacherWindow", "\345\256\236\351\252\214\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableExperimentStudents->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TeacherWindow", "\345\255\246\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableExperimentStudents->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("TeacherWindow", "\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableExperimentStudents->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("TeacherWindow", "\346\210\220\347\273\251", nullptr));
        btnImportScores->setText(QCoreApplication::translate("TeacherWindow", "\345\257\274\345\205\245\346\210\220\347\273\251 TXT", nullptr));
        btnUpdateScore->setText(QCoreApplication::translate("TeacherWindow", "\346\211\213\345\212\250\344\277\256\346\224\271\346\210\220\347\273\251", nullptr));
        btnExportReservationsCSV->setText(QCoreApplication::translate("TeacherWindow", "\345\257\274\345\207\272\346\210\220\347\273\251 CSV", nullptr));
        btnExportReservationsTXT->setText(QCoreApplication::translate("TeacherWindow", "\345\257\274\345\207\272\346\210\220\347\273\251 TXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TeacherWindow: public Ui_TeacherWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHERWINDOW_H
