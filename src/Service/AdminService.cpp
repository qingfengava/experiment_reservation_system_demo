#include "Service/AdminService.h"
#include "Model/DataModel.h"
#include <algorithm>

// 实验管理
bool AdminService::addExperiment(const Experiment &exp) {
  auto it =
      std::find_if(g_experiments.begin(), g_experiments.end(),
                   [&](const Experiment &e) { return e.expId == exp.expId; });

  if (it != g_experiments.end())
    return false; // 实验编号已存在

  g_experiments.push_back(exp);
  return true;
}

bool AdminService::updateExperiment(const QString &expId,
                                    const Experiment &newExp) {
  for (auto &e : g_experiments) {
    if (e.expId == expId) {
      if (e.published)
        return false;

      e = newExp;
      return true;
    }
  }
  return false;
}

bool AdminService::deleteExperiment(const QString &expId) {
  auto it = std::remove_if(
      g_experiments.begin(), g_experiments.end(),
      [&](const Experiment &e) { return e.expId == expId && !e.published; });

  if (it == g_experiments.end())
    return false;

  g_experiments.erase(it, g_experiments.end());
  return true;
}

bool AdminService::publishExperiment(const QString &expId) {
  for (auto &e : g_experiments) {
    if (e.expId == expId) {
      if (e.published) {
        return false;
      }
      e.published = true;
      return true;
    }
  }
  return false;
}

std::vector<Experiment> AdminService::getAllExperiments() {
  return g_experiments;
}
// 学生管理
bool AdminService::addStudent(const Student &stu) {
  auto it =
      std::find_if(g_students.begin(), g_students.end(), [&](const Student &s) {
        return s.studentId == stu.studentId;
      });

  if (it != g_students.end())
    return false; // 学生编号已存在

  g_students.push_back(stu);
  return true;
}

bool AdminService::updateStudent(const QString &studentId,
                                 const Student &newStu) {
  for (auto &s : g_students) {
    if (s.studentId == studentId) {
      s = newStu;
      return true;
    }
  }
  return false;
}

bool AdminService::deleteStudent(const QString &studentId) {
  auto it = std::remove_if(
      g_students.begin(), g_students.end(),
      [&](const Student &s) { return s.studentId == studentId; });

  if (it == g_students.end())
    return false;

  g_students.erase(it, g_students.end());
  return true;
}

std::vector<Student> AdminService::getAllStudents() { return g_students; }

// 教师管理
bool AdminService::addTeacher(const Teacher &tea) {
  auto it =
      std::find_if(g_teachers.begin(), g_teachers.end(), [&](const Teacher &t) {
        return t.teacherId == tea.teacherId;
      });

  if (it != g_teachers.end())
    return false; // 教师编号已存在

  g_teachers.push_back(tea);
  return true;
}

bool AdminService::updateTeacher(const QString &teacherId,
                                 const Teacher &newTea) {
  for (auto &t : g_teachers) {
    if (t.teacherId == teacherId) {
      t = newTea;
      return true;
    }
  }
  return false;
}

bool AdminService::deleteTeacher(const QString &teacherId) {
  auto it = std::remove_if(
      g_teachers.begin(), g_teachers.end(),
      [&](const Teacher &t) { return t.teacherId == teacherId; });

  if (it == g_teachers.end())
    return false;

  g_teachers.erase(it, g_teachers.end());
  return true;
}

std::vector<Teacher> AdminService::getAllTeachers() { return g_teachers; }