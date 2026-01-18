#include <QApplication>
#include "UI/LoginWindow.h"
#include "Service/LoginService.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序基本信息（可选，但很规范）
    QApplication::setApplicationName("实验预约系统");
    QApplication::setOrganizationName("University");
    QApplication::setApplicationVersion("1.0");

    QDir::setCurrent(QCoreApplication::applicationDirPath() + "/..");
    LoginService::initData("input");

    // 启动登录窗口
    LoginWindow loginWindow;
    loginWindow.show();

    return app.exec();
}
