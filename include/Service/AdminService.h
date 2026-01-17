#pragma once
#include "Model/DataModel.h"

class AdminService {
public:
    /* ===== 实验管理 ===== */

    // 添加实验
    static bool addExperiment(const Experiment& exp);

    // 修改实验
    static bool updateExperiment(const QString& expId, const Experiment& newExp);

    // 删除实验
    static bool deleteExperiment(const QString& expId);

    // 发布实验
    static bool publishExperiment(const QString& expId);

    // 查询全部实验
    static std::vector<Experiment> getAllExperiments();

    /* ===== 学生管理 ===== */

    static bool addStudent(const Student& stu);
    static bool updateStudent(const QString& studentId, const Student& newStu);
    static bool deleteStudent(const QString& studentId);
    static std::vector<Student> getAllStudents();

    /* ===== 教师管理 ===== */

    static bool addTeacher(const Teacher& tea);
    static bool updateTeacher(const QString& teacherId, const Teacher& newTea);
    static bool deleteTeacher(const QString& teacherId);
    static std::vector<Teacher> getAllTeachers();
};
