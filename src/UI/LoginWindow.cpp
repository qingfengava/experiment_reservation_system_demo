#include "UI/LoginWindow.h"
#include "ui_LoginWindow.h"

#include <QMessageBox>

#include "Service/LoginService.h"
#include "UI/AdminWindow.h"
#include "UI/StudentWindow.h"
#include "UI/TeacherWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::LoginWindow) {
  ui->setupUi(this);

  // 角色选择
  ui->comboRole->addItem("系统管理员", static_cast<int>(UserRole::Admin));
  ui->comboRole->addItem("教师", static_cast<int>(UserRole::Teacher));
  ui->comboRole->addItem("学生", static_cast<int>(UserRole::Student));

  // 密码隐藏
  ui->lineEditPassword->setEchoMode(QLineEdit::Password);

  // 登录按钮
  connect(ui->btnLogin, &QPushButton::clicked, this,
          &LoginWindow::onLoginClicked);

  // ===== 程序启动时加载 input 目录数据 =====
  if (!LoginService::initData("input")) {
    QMessageBox::critical(this, "初始化失败",
                          "无法加载系统数据，请检查 input 目录");
  }
}

LoginWindow::~LoginWindow() { delete ui; }

void LoginWindow::onLoginClicked() {
  QString id = ui->lineEditUserId->text().trimmed();
  QString password = ui->lineEditPassword->text().trimmed();

  if (id.isEmpty() || password.isEmpty()) {
    QMessageBox::warning(this, "提示", "请输入账号和密码");
    return;
  }

  UserRole role = static_cast<UserRole>(ui->comboRole->currentData().toInt());

  // 调用 LoginService
  LoginResult result = LoginService::login(id, password, role);

  if (!result.success) {
    QMessageBox::warning(this, "登录失败", result.message);
    return;
  }

  QMessageBox::information(this, "登录成功", result.message);

  // 根据角色打开对应窗口
  switch (result.role) {
  case UserRole::Admin:
    openAdminWindow();
    break;
  case UserRole::Teacher:
    openTeacherWindow(result.userId);
    break;
  case UserRole::Student:
    openStudentWindow(result.userId);
    break;
  default:
    QMessageBox::warning(this, "错误", "未知用户角色");
    return;
  }

  this->close();
}

void LoginWindow::openAdminWindow() {
  AdminWindow *win = new AdminWindow();
  win->show();
}

void LoginWindow::openTeacherWindow(const QString &teacherId) {
  TeacherWindow *win = new TeacherWindow(teacherId);
  win->show();
}

void LoginWindow::openStudentWindow(const QString &studentId) {
  StudentWindow *win = new StudentWindow(studentId);
  win->show();
}
