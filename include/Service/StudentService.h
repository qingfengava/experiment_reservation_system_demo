#pragma once
#include "Model/DataModel.h"

class StudentService {
public:
    // 查询当前可预约实验（已发布 & 本月）
    static vector<Experiment> queryAvailableExperiments();

    // 预约实验
    static bool reserveExperiment(const QString& studentId,
                                  const QString& studentName,
                                  const QString& expId);

    // 取消预约实验
    static bool cancelReservation(const QString& studentId,
                                  const QString& expId);

    // 查询学生已预约实验
    static vector<Reservation> queryMyReservations(const QString& studentId);

    // 修改学生个人信息
    static bool updateStudentInfo(const QString& studentId,
                                  const Student& newInfo);

    // 查询实验成绩
    static vector<Reservation> queryScores(const QString& studentId);
};
