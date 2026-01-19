#pragma once
#include <QString>

/* 用户角色枚举 */
enum class UserRole { Admin, Student, Teacher, Invalid };

/* 登录结果 */
struct LoginResult {
  bool success;
  UserRole role;
  QString userId;
  QString message;
};

class LoginService {
public:
  static LoginResult login(const QString &id, const QString &password,
                           UserRole role);

  static bool initData(const QString &inputDir);
};