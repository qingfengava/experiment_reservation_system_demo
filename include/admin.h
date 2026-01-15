#pragma once
#include "data.h"

/* ========== 实验管理 ========== */

// 录入实验信息
void admin_addExperiment(void);

// 修改实验信息（仅未发布）
void admin_modifyExperiment(void);

// 删除实验信息（仅未发布）
void admin_deleteExperiment(void);

// 发布实验
void admin_publishExperiment(void);

// 显示所有实验信息
void admin_listExperiments(void);


/* ========== 学生管理 ========== */

// 录入学生信息
void admin_addStudent(void);

// 修改学生信息
void admin_modifyStudent(void);

// 删除学生信息
void admin_deleteStudent(void);

// 查询学生信息
void admin_listStudents(void);


/* ========== 教师管理 ========== */

// 录入教师信息
void admin_addTeacher(void);

// 修改教师信息
void admin_modifyTeacher(void);

// 删除教师信息
void admin_deleteTeacher(void);

// 查询教师信息
void admin_listTeachers(void);


/* ========== 管理员主菜单 ========== */

// 管理员功能菜单
void admin_menu(void);
