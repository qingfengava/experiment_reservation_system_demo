#pragma once
#include <QString>

class FileService {
public:
  /* ================== 数据加载（程序启动 / 登录前） ================== */

  /// 加载学生数据
  static bool loadStudents(const QString &filePath);

  /// 加载教师数据
  static bool loadTeachers(const QString &filePath);

  /// 加载实验数据
  static bool loadExperiments(const QString &filePath);

  /// 加载预约与成绩数据
  static bool loadReservations(const QString &filePath);

  /// 一键加载 input 目录下的所有数据
  static bool loadAll(void);

  /* ================== 数据保存（程序退出前） ================== */

  /// 保存学生数据
  static bool saveStudents(const QString &filePath);

  /// 保存教师数据
  static bool saveTeachers(const QString &filePath);

  /// 保存实验数据
  static bool saveExperiments(const QString &filePath);

  /// 保存预约与成绩数据
  static bool saveReservations(const QString &filePath);

  /// 一键保存所有数据
  static bool saveAll(void);

  /* ================== 数据导出（结果输出） ================== */

  /// 导出学生信息为 CSV
  static bool exportStudentsToCSV(const QString &filePath);

  /// 导出教师信息为 CSV
  static bool exportTeachersToCSV(const QString &filePath);

  /// 导出实验信息为 CSV
  static bool exportExperimentsToCSV(const QString &filePath);

  /// 导出预约与成绩为 CSV
  static bool exportReservationsToCSV(const QString &filePath);

  /// 导出学生信息为 TXT
  static bool exportStudentsToTXT(const QString &filePath);

  /// 导出教师信息为 TXT
  static bool exportTeachersToTXT(const QString &filePath);

  /// 导出实验信息为 TXT
  static bool exportExperimentsToTXT(const QString &filePath);

  /// 导出预约与成绩为 TXT
  static bool exportReservationsToTXT(const QString &filePath);
};
