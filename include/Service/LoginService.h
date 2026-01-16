#pragma once
#include <QString>

/* 用户角色枚举 */
enum class UserRole {
    Admin,
    Student,
    Teacher,
    Invalid
};

/* 登录结果 */
struct LoginResult {
    bool success;
    UserRole role;
    QString userId;
};

class LoginService {
public:
    // 管理员登录
    static LoginResult adminLogin(const QString& id, const QString& password);

    // 学生登录
    static LoginResult studentLogin(const QString& studentId, const QString& password);

    // 教师登录
    static LoginResult teacherLogin(const QString& teacherId, const QString& password);
};
