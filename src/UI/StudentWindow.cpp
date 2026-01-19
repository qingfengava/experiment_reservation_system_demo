#include "UI/StudentWindow.h"
#include "ui_StudentWindow.h"

#include "Service/FileService.h"
#include "Service/StudentService.h"
#include <QMessageBox>
#include <QCloseEvent>


StudentWindow::StudentWindow(const QString &studentId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::StudentWindow), m_studentId(studentId) {
  ui->setupUi(this);

  // 初始化表格数据
  onQueryAvailableExperiments();
  onQueryMyReservations();

  // 按钮绑定
  connect(ui->btnReserve, &QPushButton::clicked, this,
          &StudentWindow::onReserveExperiment);
  connect(ui->btnCancelReservation, &QPushButton::clicked, this,
          &StudentWindow::onCancelReservation);
  connect(ui->btnQueryAvailable, &QPushButton::clicked, this,
          &StudentWindow::onQueryAvailableExperiments);
  connect(ui->btnQueryMyReservations, &QPushButton::clicked, this,
          &StudentWindow::onQueryMyReservations);
  connect(ui->btnUpdateProfile, &QPushButton::clicked, this,
          &StudentWindow::onUpdateProfile);
  connect(ui->btnQueryScores, &QPushButton::clicked, this,
          &StudentWindow::onQueryScores);
  connect(ui->btnExportMyReservationsCSV, &QPushButton::clicked, this,
          &StudentWindow::onExportMyReservationsCSV);
  connect(ui->btnExportMyReservationsTXT, &QPushButton::clicked, this,
          &StudentWindow::onExportMyReservationsTXT);
}

StudentWindow::~StudentWindow() { delete ui; }

// 自动保存
void StudentWindow::closeEvent(QCloseEvent *event) {
  FileService::saveAll();
  event->accept();
}

/* ================== 查询当前可预约实验 ================== */
void StudentWindow::onQueryAvailableExperiments() {
  ui->tableAvailableExperiments->setRowCount(0);
  auto list = StudentService::queryAvailableExperiments();

  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableAvailableExperiments->insertRow(i);
    ui->tableAvailableExperiments->setItem(i, 0,
                                           new QTableWidgetItem(list[i].expId));
    ui->tableAvailableExperiments->setItem(i, 1,
                                           new QTableWidgetItem(list[i].expName));
    ui->tableAvailableExperiments->setItem(
        i, 2, new QTableWidgetItem(list[i].startTime.toString()));
    ui->tableAvailableExperiments->setItem(
        i, 3, new QTableWidgetItem(list[i].endTime.toString()));
    ui->tableAvailableExperiments->setItem(
        i, 4, new QTableWidgetItem(QString::number(list[i].totalSeats)));
    ui->tableAvailableExperiments->setItem(
        i, 5, new QTableWidgetItem(QString::number(list[i].reservedCount)));
    ui->tableAvailableExperiments->setItem(
        i, 6, new QTableWidgetItem(list[i].teacherName));
  }
}

/* ================== 预约实验 ================== */
void StudentWindow::onReserveExperiment() {
  int row = ui->tableAvailableExperiments->currentRow();
  if (row < 0) {
    QMessageBox::warning(this, "提示", "请选择要预约的实验");
    return;
  }
  QString expId = ui->tableAvailableExperiments->item(row, 0)->text();
  QString expName = ui->tableAvailableExperiments->item(row, 1)->text();

  if (!StudentService::reserveExperiment(m_studentId, "学生", expId)) {
    QMessageBox::warning(this, "失败",
                         "预约失败，实验已满或距离开始不足2小时");
    return;
  }
  QMessageBox::information(this, "成功",
                           QString("已预约实验: %1").arg(expName));
  onQueryAvailableExperiments();
  onQueryMyReservations();
}

/* ================== 取消预约 ================== */
void StudentWindow::onCancelReservation() {
  int row = ui->tableMyReservations->currentRow();
  if (row < 0) {
    QMessageBox::warning(this, "提示", "请选择要取消的预约");
    return;
  }
  QString expId = ui->tableMyReservations->item(row, 0)->text();

  if (!StudentService::cancelReservation(m_studentId, expId)) {
    QMessageBox::warning(this, "失败", "取消预约失败，距离开始不足2小时");
    return;
  }
  QMessageBox::information(this, "成功", "已取消预约");
  onQueryAvailableExperiments();
  onQueryMyReservations();
}

/* ================== 查询已预约实验 ================== */
void StudentWindow::onQueryMyReservations() {
  ui->tableMyReservations->setRowCount(0);
  auto list = StudentService::queryMyReservations(m_studentId);

  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableMyReservations->insertRow(i);
    ui->tableMyReservations->setItem(
        i, 0, new QTableWidgetItem(list[i].expId));
    ui->tableMyReservations->setItem(
        i, 1, new QTableWidgetItem(list[i].expName));
    ui->tableMyReservations->setItem(i, 2,
                                     new QTableWidgetItem(list[i].teacherName));
    ui->tableMyReservations->setItem(
        i, 3, new QTableWidgetItem(QString::number(list[i].score)));
  }
}

/* ================== 修改个人信息 ================== */
void StudentWindow::onUpdateProfile() {
  Student s;
  s.studentId = m_studentId;
  s.name = ui->editName->text();
  s.college = ui->editCollege->text();
  s.major = ui->editMajor->text();
  s.password = ui->editPassword->text();

  if (!StudentService::updateStudentInfo(m_studentId, s)) {
    QMessageBox::warning(this, "失败", "更新个人信息失败");
    return;
  }
  QMessageBox::information(this, "成功", "个人信息已更新");
}

/* ================== 查询成绩 ================== */
void StudentWindow::onQueryScores() {
  auto list = StudentService::queryScores(m_studentId);
  ui->tableScores->setRowCount(0);

  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableScores->insertRow(i);
    ui->tableScores->setItem(i, 0,
                             new QTableWidgetItem(list[i].expName));
    ui->tableScores->setItem(i, 1, new QTableWidgetItem(list[i].teacherName));
    ui->tableScores->setItem(
        i, 2, new QTableWidgetItem(QString::number(list[i].score)));
  }
}

/* ================== 导出已预约实验 TXT ================== */
/* ================== 导出可预约实验 CSV ================== */
void StudentWindow::onExportMyReservationsCSV() {
  FileService::exportReservationsToCSV("reservations.csv");
  QMessageBox::information(this, "导出", "已预约实验已导出 CSV");
}

void StudentWindow::onExportMyReservationsTXT() {
  FileService::exportReservationsToTXT("reservations.txt");
  QMessageBox::information(this, "导出", "已预约实验已导出 TXT");
}