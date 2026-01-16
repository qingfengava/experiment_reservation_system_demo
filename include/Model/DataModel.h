#pragma once
#include <QString>
#include <QDateTime>
#include <vector>

/* 实验信息 */
struct Experiment {
    QString expId;        // 实验编号
    QString expName;      // 实验名称
    QDateTime startTime;  // 开始时间
    QDateTime endTime;    // 结束时间
    int totalSeats;       // 总席位
    int reservedCount;    // 已预约人数
    bool published;       // 是否已发布
    QString teacherId;    // 教师编号
    QString teacherName;  // 教师姓名
};

/* 学生信息 */
struct Student {
    QString studentId;
    QString name;
    QString college;
    QString major;
    QString password;
};

/* 教师信息 */
struct Teacher {
    QString teacherId;
    QString name;
    QString college;
    QString password;
};

/* 预约信息 */
struct Reservation {
    QString expId;
    QString expName;
    QString studentId;
    QString studentName;
    QString teacherId;
    QString teacherName;
    int score;   // -1 表示未录入成绩
};

/* 全局数据容器声明 */
extern std::vector<Experiment> g_experiments;
extern std::vector<Student> g_students;
extern std::vector<Teacher> g_teachers;
extern std::vector<Reservation> g_reservations;