#pragma once
#include "data.h"

/* ========== 实验查询 ========== */

// 查询当前可预约实验
void student_queryAvailableExperiments(void);

// 查询本人已预约实验
void student_queryMyReservations(const char *stuId);


/* ========== 实验预约 ========== */

// 预约实验
void student_reserveExperiment(const char *stuId);

// 取消预约实验
void student_cancelReservation(const char *stuId);


/* ========== 学生信息管理 ========== */

// 修改个人信息
void student_modifyInfo(const char *stuId);


/* ========== 成绩查询 ========== */

// 查询实验成绩
void student_queryScores(const char *stuId);


/* ========== 学生主菜单 ========== */

// 学生功能菜单
void student_menu(const char *stuId);
