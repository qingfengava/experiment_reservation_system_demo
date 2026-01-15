#pragma once
#include <QWidget>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
class QComboBox;
QT_END_NAMESPACE

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();
    void onExitClicked();

private:
    QLineEdit   *editUser;
    QLineEdit   *editPwd;
    QComboBox   *comboRole;
    QPushButton *btnLogin;
    QPushButton *btnExit;

    void setupUI();
    void setupConnections();
};
