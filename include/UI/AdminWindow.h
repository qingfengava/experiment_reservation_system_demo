#pragma once
#include "Service/AdminService.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class AdminWindow;
}
QT_END_NAMESPACE

class AdminWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit AdminWindow(QWidget *parent = nullptr);
  ~AdminWindow();

protected:
  // 关闭窗口时自动保存
  void closeEvent(QCloseEvent *event) override;

private slots:
  /* ===== 实验管理 ===== */
  void onAddExperiment();
  void onUpdateExperiment();
  void onDeleteExperiment();
  void onPublishExperiment();
  void onRefreshExperiments();

  /* ===== 学生管理 ===== */
  void onAddStudent();
  void onUpdateStudent();
  void onDeleteStudent();
  void onRefreshStudents();

  /* ===== 教师管理 ===== */
  void onAddTeacher();
  void onUpdateTeacher();
  void onDeleteTeacher();
  void onRefreshTeachers();

  /* ===== 文件操作 ===== */
  void onExportExperimentsCSV();
  void onExportExperimentsTXT();
  void onExportStudentsCSV();
  void onExportStudentsTXT();
  void onExportTeachersCSV();
  void onExportTeachersTXT();

private:
  Ui::AdminWindow *ui;

  void loadAllDataToUI();
};
