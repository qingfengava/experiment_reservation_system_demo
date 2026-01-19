#pragma once
#include <QDateTime>
#include <QString>
#include <vector>

/* 实验信息 */
struct Experiment {
  QString expId;       // 实验编号
  QString expName;     // 实验名称
  QDateTime startTime; // 开始时间
  QDateTime endTime;   // 结束时间
  int totalSeats;      // 总席位
  int reservedCount;   // 已预约人数
  bool published;      // 是否已发布
  QString teacherId;   // 教师编号
  QString teacherName; // 教师姓名
  Experiment(QString aexpId = "", QString aexpName = "",
             QDateTime astartTime = QDateTime(),
             QDateTime aendTime = QDateTime(), int atotalSeats = 0,
             int areservedCount = 0, bool apublished = false,
             QString ateacherId = "", QString ateacherName = "")
      : expId(aexpId), expName(aexpName), startTime(astartTime),
        endTime(aendTime), totalSeats(atotalSeats),
        reservedCount(areservedCount), published(apublished),
        teacherId(ateacherId), teacherName(ateacherName) {}
};

/* 学生信息 */
struct Student {
  QString studentId;
  QString name;
  QString college;
  QString major;
  QString password;
  Student(QString astudentId = "", QString aname = "",
          QString acollege = "武汉科技大学", QString amajor = "",
          QString apassword = "")
      : studentId(astudentId), name(aname), college(acollege), major(amajor),
        password(apassword) {}
};

/* 教师信息 */
struct Teacher {
  QString teacherId;
  QString name;
  QString college;
  QString password;
  Teacher(QString ateacherId = "", QString aname = "",
          QString acollege = "武汉科技大学", QString apassword = "")
      : teacherId(ateacherId), name(aname), college(acollege),
        password(apassword) {}
};

/* 预约信息 */
struct Reservation {
  QString expId;
  QString expName;
  QString studentId;
  QString studentName;
  QString teacherId;
  QString teacherName;
  int score; // -1 表示未录入成绩
  Reservation(QString aexpId = "", QString aexpName = "",
              QString astudentId = "", QString astudentName = "",
              QString ateacherId = "", QString ateacherName = "",
              int ascore = -1)
      : expId(aexpId), expName(aexpName), studentId(astudentId),
        studentName(astudentName), teacherId(ateacherId),
        teacherName(ateacherName), score(ascore) {}
};

/* 全局数据容器声明 */
extern std::vector<Experiment> g_experiments;
extern std::vector<Student> g_students;
extern std::vector<Teacher> g_teachers;
extern std::vector<Reservation> g_reservations;