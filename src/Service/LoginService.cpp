#include "Service/LoginService.h"
#include "Model/DataModel.h"
#include "Service/FileService.h"

static bool g_dataInitialized = false;

bool LoginService::initData(const QString &inputDir) {
  if (g_dataInitialized)
    return true;

  bool ok = true;
  ok &= FileService::loadStudents(inputDir + "/students.txt");
  ok &= FileService::loadTeachers(inputDir + "/teachers.txt");
  ok &= FileService::loadExperiments(inputDir + "/experiments.txt");
  ok &= FileService::loadReservations(inputDir + "/reservations.txt");

  g_dataInitialized = ok;
  return ok;
}

LoginResult LoginService::login(const QString &id, const QString &password,
                                UserRole role) {
  // 基本输入验证
  if (id.isEmpty() || password.isEmpty()) {
    return {false, UserRole::Invalid, "", "用户名或密码不能为空"};
  }

  // 初始化数据验证
  if (!initData("input")) {
    return {false, UserRole::Invalid, "", "数据初始化失败"};
  }

  // 管理员
  if (role == UserRole::Admin) {
    if (id == "admin" && password == "admin") {
      return {true, UserRole::Admin, id, "管理员登录成功"};
    } else {
      return {false, UserRole::Invalid, "", "管理员用户名或密码错误"};
    }
  }

  // 学生
  if (role == UserRole::Student) {
    for (const auto &student : g_students) {
      if (student.studentId == id && student.password == password) {
        return {true, UserRole::Student, id, "学生登录成功"};
      }
    }
    return {false, UserRole::Invalid, "", "学生用户名或密码错误"};
  }

  // 教师
  if (role == UserRole::Teacher) {
    for (const auto &teacher : g_teachers) {
      if (teacher.teacherId == id && teacher.password == password) {
        return {true, UserRole::Teacher, id, "教师登录成功"};
      }
    }
    return {false, UserRole::Invalid, "", "教师用户名或密码错误"};
  }

  return {false, UserRole::Invalid, "", "非法用户身份"};
}