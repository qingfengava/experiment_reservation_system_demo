#pragma once
#include "data.h"

/* ========== 教师查询功能 ========== */

// 查询本人指导的实验
void teacher_queryMyExperiments(const char *teacherId);

// 查询某实验的预约学生
void teacher_queryExperimentStudents(const char *expId);


/* ========== 成绩管理 ========== */

// 导入实验成绩（文本文件）
void teacher_importScores(const char *expId, const char *filename);


/* ========== 教师主菜单 ========== */

// 教师功能菜单
void teacher_menu(const char *teacherId);
