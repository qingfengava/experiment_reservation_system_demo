#pragma once
#include "Model/DataModel.h"

class TeacherService {
public:
  // 查询本教师所指导的实验
  static std::vector<Experiment> queryMyExperiments(const QString &teacherId);

  // 查询某实验的全部预约学生
  static std::vector<Reservation> queryExperimentStudents(const QString &expId);

  // 导入实验成绩（TXT 文件）
  static bool importScoresFromFile(const QString &expId,
                                   const QString &filePath);

  // 手动录入或修改成绩
  static bool updateScore(const QString &expId, const QString &studentId,
                          int score);
};
