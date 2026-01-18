#pragma once
#include "Service/LoginService.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit LoginWindow(QWidget *parent = nullptr);
  ~LoginWindow();

private slots:
  // 点击“登录”
  void onLoginClicked();

private:
  Ui::LoginWindow *ui;

  // 登录成功后跳转
  void openAdminWindow();
  void openTeacherWindow(const QString &teacherId);
  void openStudentWindow(const QString &studentId);
};
