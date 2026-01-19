#pragma once
#include "Service/StudentService.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class StudentWindow;
}
QT_END_NAMESPACE

class StudentWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit StudentWindow(const QString &studentId, QWidget *parent = nullptr);
  ~StudentWindow();

protected:
  void closeEvent(QCloseEvent *event) override;

private slots:
  // 查询可预约实验
  void onQueryAvailableExperiments();

  // 预约实验
  void onReserveExperiment();

  // 取消预约
  void onCancelReservation();

  // 查询我的预约
  void onQueryMyReservations();

  // 修改个人信息
  void onUpdateProfile();

  // 查询成绩
  void onQueryScores();

  // 导出我的预约
  void onExportMyReservationsCSV();
  void onExportMyReservationsTXT();

private:
  Ui::StudentWindow *ui;
  QString m_studentId;
};
