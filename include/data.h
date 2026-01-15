#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* ================= 常量定义 ================= */

#define MAX_EXPERIMENTS   200
#define MAX_STUDENTS      500
#define MAX_TEACHERS      100
#define MAX_RESERVATIONS  1000

#define PASSWORD_LEN      10
#define NAME_LEN          30
#define ID_LEN            20
#define TIME_LEN          20
#define COLLEGE_LEN       40
#define MAJOR_LEN         40

/* 发布状态 */
#define NOT_PUBLISHED 0
#define PUBLISHED     1

/* 成绩状态 */
#define SCORE_EMPTY   -1

/* ================= 数据结构定义 ================= */

/* ---------- 实验信息 ---------- */
typedef struct {
    char expId[ID_LEN];            // 实验编号 YYYYMMDD + 序号
    char expName[NAME_LEN];        // 实验名称
    char startTime[TIME_LEN];      // 开始时间 yyyy-mm-dd hh:mm
    char endTime[TIME_LEN];        // 结束时间 yyyy-mm-dd hh:mm
    int totalSeats;                // 总席位
    int reservedCount;             // 已预约人数
    int published;                 // 是否发布 0/1
    char teacherId[ID_LEN];        // 教师编号
    char teacherName[NAME_LEN];    // 教师姓名
} Experiment;


/* ---------- 学生信息 ---------- */
typedef struct {
    char stuId[ID_LEN];            // 学号
    char name[NAME_LEN];           // 姓名
    char college[COLLEGE_LEN];     // 学院
    char major[MAJOR_LEN];         // 专业
    char password[PASSWORD_LEN];   // 密码
} Student;


/* ---------- 教师信息 ---------- */
typedef struct {
    char teacherId[ID_LEN];        // 工号
    char name[NAME_LEN];           // 姓名
    char college[COLLEGE_LEN];     // 学院
    char password[PASSWORD_LEN];   // 密码
} Teacher;


/* ---------- 预约信息 ---------- */
typedef struct {
    char expId[ID_LEN];            // 实验编号
    char expName[NAME_LEN];        // 实验名称
    char stuId[ID_LEN];            // 学号
    char stuName[NAME_LEN];        // 学生姓名
    char teacherId[ID_LEN];        // 教师编号
    char teacherName[NAME_LEN];    // 教师姓名
    int score;                     // 成绩 -1 表示未录入
} Reservation;


/* ================= 全局数据声明 ================= */
/* 在 data.c 中定义，这里 extern */

extern Experiment experiments[MAX_EXPERIMENTS];
extern int experimentCount;

extern Student students[MAX_STUDENTS];
extern int studentCount;

extern Teacher teachers[MAX_TEACHERS];
extern int teacherCount;

extern Reservation reservations[MAX_RESERVATIONS];
extern int reservationCount;


/* ================= 工具函数声明 ================= */

/* ---------- 查找函数 ---------- */
int findExperimentById(const char *expId);
int findStudentById(const char *stuId);
int findTeacherById(const char *teacherId);

/* 判断学生是否已预约某实验（同课程不同批次） */
int studentHasReserved(const char *stuId, const char *expName);

/* ---------- 时间处理 ---------- */

// 字符串转 time_t
time_t strToTime(const char *timeStr);

// 距离实验开始的小时数
double hoursBeforeStart(const char *startTime);

// 是否是本月实验
int isExperimentInCurrentMonth(const char *startTime);


/* ---------- 文件读写 ---------- */

// 加载数据
void loadExperiments(void);
void loadStudents(void);
void loadTeachers(void);
void loadReservations(void);

// 保存数据
void saveExperiments(void);
void saveStudents(void);
void saveTeachers(void);
void saveReservations(void);


/* ---------- 显示工具 ---------- */

void printExperiment(const Experiment *exp);
void printStudent(const Student *stu);
void printTeacher(const Teacher *teacher);
void printReservation(const Reservation *res);


/* ---------- 通用输入 ---------- */

// 清空输入缓冲
void clearInputBuffer(void);

// 安全输入字符串
void inputString(const char *prompt, char *buf, int len);
