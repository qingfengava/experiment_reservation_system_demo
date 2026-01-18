#pragma once
#include "Service/TeacherService.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TeacherWindow;
}
QT_END_NAMESPACE

class TeacherWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit TeacherWindow(const QString &teacherId, QWidget *parent = nullptr);
  ~TeacherWindow();

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  // 查询我的实验
  void onRefreshMyExperiments();

  // 查看某实验学生
  void onViewExperimentStudents();

  // 从 TXT 导入成绩
  void onImportScores();

  // 手动修改成绩
  void onUpdateScore();

  // 导出成绩
  void onExportReservationsCSV();
  void onExportReservationsTXT();

private:
  Ui::TeacherWindow *ui;
  QString m_teacherId;
};
