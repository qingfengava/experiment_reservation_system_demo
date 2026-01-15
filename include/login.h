#pragma once
#include "data.h"

/* ========== 登录验证 ========== */

// 管理员登录验证
int login_admin(const char *username, const char *password);

// 学生登录验证
int login_student(const char *stuId, const char *password);

// 教师登录验证
int login_teacher(const char *teacherId, const char *password);


/* ========== 登录界面 ========== */

// 系统登录入口
void login_system(void);
