#include <QApplication>
#include "UI/LoginWindow.h"
#include "Service/LoginService.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QApplication::setApplicationName("实验预约系统");
    QApplication::setOrganizationName("University");
    QApplication::setApplicationVersion("1.0");

    // 设置当前工作目录为可执行文件所在目录的上一级目录
    QDir::setCurrent(QCoreApplication::applicationDirPath() + "/..");
    LoginService::initData("input");

    // 启动登录窗口
    LoginWindow loginWindow;
    loginWindow.show();

    return app.exec();
}
