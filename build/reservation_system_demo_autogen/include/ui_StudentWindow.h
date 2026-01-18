/********************************************************************************
** Form generated from reading UI file 'StudentWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTWINDOW_H
#define UI_STUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAvailableExperiments;
    QVBoxLayout *vboxAvailable;
    QTableWidget *tableAvailableExperiments;
    QHBoxLayout *hboxAvailableButtons;
    QPushButton *btnQueryAvailable;
    QPushButton *btnReserve;
    QPushButton *btnExportMyReservationsCSV;
    QWidget *tabMyReservations;
    QVBoxLayout *vboxMyReservations;
    QTableWidget *tableMyReservations;
    QHBoxLayout *hboxMyReservationButtons;
    QPushButton *btnQueryMyReservations;
    QPushButton *btnCancelReservation;
    QPushButton *btnExportMyReservationsTXT;
    QWidget *tabProfile;
    QFormLayout *formProfile;
    QLabel *labelName;
    QLineEdit *editName;
    QLabel *labelCollege;
    QLineEdit *editCollege;
    QLabel *labelMajor;
    QLineEdit *editMajor;
    QLabel *labelPassword;
    QLineEdit *editPassword;
    QPushButton *btnUpdateProfile;
    QWidget *tabScores;
    QVBoxLayout *vboxScores;
    QTableWidget *tableScores;
    QPushButton *btnQueryScores;

    void setupUi(QMainWindow *StudentWindow)
    {
        if (StudentWindow->objectName().isEmpty())
            StudentWindow->setObjectName(QString::fromUtf8("StudentWindow"));
        StudentWindow->resize(900, 700);
        centralwidget = new QWidget(StudentWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabAvailableExperiments = new QWidget();
        tabAvailableExperiments->setObjectName(QString::fromUtf8("tabAvailableExperiments"));
        vboxAvailable = new QVBoxLayout(tabAvailableExperiments);
        vboxAvailable->setObjectName(QString::fromUtf8("vboxAvailable"));
        tableAvailableExperiments = new QTableWidget(tabAvailableExperiments);
        if (tableAvailableExperiments->columnCount() < 7)
            tableAvailableExperiments->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableAvailableExperiments->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableAvailableExperiments->setObjectName(QString::fromUtf8("tableAvailableExperiments"));
        tableAvailableExperiments->setColumnCount(7);
        tableAvailableExperiments->setRowCount(0);

        vboxAvailable->addWidget(tableAvailableExperiments);

        hboxAvailableButtons = new QHBoxLayout();
        hboxAvailableButtons->setObjectName(QString::fromUtf8("hboxAvailableButtons"));
        btnQueryAvailable = new QPushButton(tabAvailableExperiments);
        btnQueryAvailable->setObjectName(QString::fromUtf8("btnQueryAvailable"));

        hboxAvailableButtons->addWidget(btnQueryAvailable);

        btnReserve = new QPushButton(tabAvailableExperiments);
        btnReserve->setObjectName(QString::fromUtf8("btnReserve"));

        hboxAvailableButtons->addWidget(btnReserve);

        btnExportMyReservationsCSV = new QPushButton(tabAvailableExperiments);
        btnExportMyReservationsCSV->setObjectName(QString::fromUtf8("btnExportMyReservationsCSV"));

        hboxAvailableButtons->addWidget(btnExportMyReservationsCSV);


        vboxAvailable->addLayout(hboxAvailableButtons);

        tabWidget->addTab(tabAvailableExperiments, QString());
        tabMyReservations = new QWidget();
        tabMyReservations->setObjectName(QString::fromUtf8("tabMyReservations"));
        vboxMyReservations = new QVBoxLayout(tabMyReservations);
        vboxMyReservations->setObjectName(QString::fromUtf8("vboxMyReservations"));
        tableMyReservations = new QTableWidget(tabMyReservations);
        if (tableMyReservations->columnCount() < 4)
            tableMyReservations->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableMyReservations->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableMyReservations->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableMyReservations->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableMyReservations->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        tableMyReservations->setObjectName(QString::fromUtf8("tableMyReservations"));
        tableMyReservations->setColumnCount(4);
        tableMyReservations->setRowCount(0);

        vboxMyReservations->addWidget(tableMyReservations);

        hboxMyReservationButtons = new QHBoxLayout();
        hboxMyReservationButtons->setObjectName(QString::fromUtf8("hboxMyReservationButtons"));
        btnQueryMyReservations = new QPushButton(tabMyReservations);
        btnQueryMyReservations->setObjectName(QString::fromUtf8("btnQueryMyReservations"));

        hboxMyReservationButtons->addWidget(btnQueryMyReservations);

        btnCancelReservation = new QPushButton(tabMyReservations);
        btnCancelReservation->setObjectName(QString::fromUtf8("btnCancelReservation"));

        hboxMyReservationButtons->addWidget(btnCancelReservation);

        btnExportMyReservationsTXT = new QPushButton(tabMyReservations);
        btnExportMyReservationsTXT->setObjectName(QString::fromUtf8("btnExportMyReservationsTXT"));

        hboxMyReservationButtons->addWidget(btnExportMyReservationsTXT);


        vboxMyReservations->addLayout(hboxMyReservationButtons);

        tabWidget->addTab(tabMyReservations, QString());
        tabProfile = new QWidget();
        tabProfile->setObjectName(QString::fromUtf8("tabProfile"));
        formProfile = new QFormLayout(tabProfile);
        formProfile->setObjectName(QString::fromUtf8("formProfile"));
        labelName = new QLabel(tabProfile);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        formProfile->setWidget(0, QFormLayout::LabelRole, labelName);

        editName = new QLineEdit(tabProfile);
        editName->setObjectName(QString::fromUtf8("editName"));

        formProfile->setWidget(0, QFormLayout::FieldRole, editName);

        labelCollege = new QLabel(tabProfile);
        labelCollege->setObjectName(QString::fromUtf8("labelCollege"));

        formProfile->setWidget(1, QFormLayout::LabelRole, labelCollege);

        editCollege = new QLineEdit(tabProfile);
        editCollege->setObjectName(QString::fromUtf8("editCollege"));

        formProfile->setWidget(1, QFormLayout::FieldRole, editCollege);

        labelMajor = new QLabel(tabProfile);
        labelMajor->setObjectName(QString::fromUtf8("labelMajor"));

        formProfile->setWidget(2, QFormLayout::LabelRole, labelMajor);

        editMajor = new QLineEdit(tabProfile);
        editMajor->setObjectName(QString::fromUtf8("editMajor"));

        formProfile->setWidget(2, QFormLayout::FieldRole, editMajor);

        labelPassword = new QLabel(tabProfile);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        formProfile->setWidget(3, QFormLayout::LabelRole, labelPassword);

        editPassword = new QLineEdit(tabProfile);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        formProfile->setWidget(3, QFormLayout::FieldRole, editPassword);

        btnUpdateProfile = new QPushButton(tabProfile);
        btnUpdateProfile->setObjectName(QString::fromUtf8("btnUpdateProfile"));

        formProfile->setWidget(4, QFormLayout::FieldRole, btnUpdateProfile);

        tabWidget->addTab(tabProfile, QString());
        tabScores = new QWidget();
        tabScores->setObjectName(QString::fromUtf8("tabScores"));
        vboxScores = new QVBoxLayout(tabScores);
        vboxScores->setObjectName(QString::fromUtf8("vboxScores"));
        tableScores = new QTableWidget(tabScores);
        if (tableScores->columnCount() < 3)
            tableScores->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableScores->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableScores->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableScores->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        tableScores->setObjectName(QString::fromUtf8("tableScores"));
        tableScores->setColumnCount(3);
        tableScores->setRowCount(0);

        vboxScores->addWidget(tableScores);

        btnQueryScores = new QPushButton(tabScores);
        btnQueryScores->setObjectName(QString::fromUtf8("btnQueryScores"));

        vboxScores->addWidget(btnQueryScores);

        tabWidget->addTab(tabScores, QString());

        verticalLayout->addWidget(tabWidget);

        StudentWindow->setCentralWidget(centralwidget);

        retranslateUi(StudentWindow);

        QMetaObject::connectSlotsByName(StudentWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StudentWindow)
    {
        StudentWindow->setWindowTitle(QCoreApplication::translate("StudentWindow", "\345\255\246\347\224\237\345\256\236\351\252\214\351\242\204\347\272\246\347\263\273\347\273\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableAvailableExperiments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StudentWindow", "\345\256\236\351\252\214\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableAvailableExperiments->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StudentWindow", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableAvailableExperiments->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StudentWindow", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableAvailableExperiments->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StudentWindow", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableAvailableExperiments->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StudentWindow", "\346\200\273\345\270\255\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableAvailableExperiments->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StudentWindow", "\351\242\204\347\272\246\344\272\272\346\225\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableAvailableExperiments->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("StudentWindow", "\346\225\231\345\270\210\345\247\223\345\220\215", nullptr));
        btnQueryAvailable->setText(QCoreApplication::translate("StudentWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        btnReserve->setText(QCoreApplication::translate("StudentWindow", "\351\242\204\347\272\246\345\256\236\351\252\214", nullptr));
        btnExportMyReservationsCSV->setText(QCoreApplication::translate("StudentWindow", "\345\257\274\345\207\272\345\267\262\351\242\204\347\272\246\345\256\236\351\252\214 CSV", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAvailableExperiments), QCoreApplication::translate("StudentWindow", "\345\217\257\351\242\204\347\272\246\345\256\236\351\252\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableMyReservations->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("StudentWindow", "\345\256\236\351\252\214\347\274\226\345\217\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableMyReservations->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("StudentWindow", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableMyReservations->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("StudentWindow", "\346\225\231\345\270\210\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableMyReservations->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("StudentWindow", "\346\210\220\347\273\251", nullptr));
        btnQueryMyReservations->setText(QCoreApplication::translate("StudentWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", nullptr));
        btnCancelReservation->setText(QCoreApplication::translate("StudentWindow", "\345\217\226\346\266\210\351\242\204\347\272\246", nullptr));
        btnExportMyReservationsTXT->setText(QCoreApplication::translate("StudentWindow", "\345\257\274\345\207\272\345\267\262\351\242\204\347\272\246\345\256\236\351\252\214 TXT", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMyReservations), QCoreApplication::translate("StudentWindow", "\346\210\221\347\232\204\351\242\204\347\272\246", nullptr));
        labelName->setText(QCoreApplication::translate("StudentWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelCollege->setText(QCoreApplication::translate("StudentWindow", "\345\255\246\351\231\242\357\274\232", nullptr));
        labelMajor->setText(QCoreApplication::translate("StudentWindow", "\344\270\223\344\270\232\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("StudentWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        btnUpdateProfile->setText(QCoreApplication::translate("StudentWindow", "\346\233\264\346\226\260\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabProfile), QCoreApplication::translate("StudentWindow", "\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableScores->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("StudentWindow", "\345\256\236\351\252\214\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableScores->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("StudentWindow", "\346\225\231\345\270\210\345\247\223\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableScores->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("StudentWindow", "\346\210\220\347\273\251", nullptr));
        btnQueryScores->setText(QCoreApplication::translate("StudentWindow", "\346\237\245\350\257\242\346\210\220\347\273\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabScores), QCoreApplication::translate("StudentWindow", "\346\210\220\347\273\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentWindow: public Ui_StudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTWINDOW_H
