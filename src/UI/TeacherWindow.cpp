#include "UI/TeacherWindow.h"
#include "ui_TeacherWindow.h"

#include "Service/FileService.h"
#include "Service/TeacherService.h"
#include <QCloseEvent>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>

TeacherWindow::TeacherWindow(const QString &teacherId, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TeacherWindow), m_teacherId(teacherId) {
  ui->setupUi(this);

  onRefreshMyExperiments();

  connect(ui->btnRefreshMyExperiments, &QPushButton::clicked, this,
          &TeacherWindow::onRefreshMyExperiments);
  connect(ui->btnViewExperimentStudents, &QPushButton::clicked, this,
          &TeacherWindow::onViewExperimentStudents);
  connect(ui->btnImportScores, &QPushButton::clicked, this,
          &TeacherWindow::onImportScores);
  connect(ui->btnUpdateScore, &QPushButton::clicked, this,
          &TeacherWindow::onUpdateScore);
  connect(ui->btnExportReservationsCSV, &QPushButton::clicked, this,
          &TeacherWindow::onExportReservationsCSV);
  connect(ui->btnExportReservationsTXT, &QPushButton::clicked, this,
          &TeacherWindow::onExportReservationsTXT);
}

TeacherWindow::~TeacherWindow() { delete ui; }

/* ================== 窗口关闭自动保存 ================== */
void TeacherWindow::closeEvent(QCloseEvent *event) {
  FileService::saveAll();
  event->accept();
}

/* ================== 查询教师实验 ================== */
void TeacherWindow::onRefreshMyExperiments() {
  ui->tableMyExperiments->setRowCount(0);

  auto list = TeacherService::queryMyExperiments(m_teacherId);
  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableMyExperiments->insertRow(i);
    ui->tableMyExperiments->setItem(i, 0, new QTableWidgetItem(list[i].expId));
    ui->tableMyExperiments->setItem(i, 1,
                                    new QTableWidgetItem(list[i].expName));
    ui->tableMyExperiments->setItem(
        i, 2, new QTableWidgetItem(list[i].startTime.toString()));
    ui->tableMyExperiments->setItem(
        i, 3, new QTableWidgetItem(list[i].endTime.toString()));
    ui->tableMyExperiments->setItem(
        i, 4, new QTableWidgetItem(QString::number(list[i].totalSeats)));
    ui->tableMyExperiments->setItem(
        i, 5, new QTableWidgetItem(QString::number(list[i].reservedCount)));
  }
}

/* ================== 查询实验学生 ================== */
void TeacherWindow::onViewExperimentStudents() {
  auto selectedItems = ui->tableMyExperiments->selectedItems();
  if (selectedItems.isEmpty()) {
    QMessageBox::warning(this, "提示", "请先选择实验");
    return;
  }
  QString expId = selectedItems[0]->text();

  ui->tableExperimentStudents->setRowCount(0);
  auto list = TeacherService::queryExperimentStudents(expId);

  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableExperimentStudents->insertRow(i);
    ui->tableExperimentStudents->setItem(
        i, 0, new QTableWidgetItem(list[i].studentId));
    ui->tableExperimentStudents->setItem(
        i, 1, new QTableWidgetItem(list[i].studentName));
    ui->tableExperimentStudents->setItem(
        i, 2, new QTableWidgetItem(QString::number(list[i].score)));
  }
}

/* ================== 导入成绩 TXT ================== */
void TeacherWindow::onImportScores() {
  auto selectedItems = ui->tableMyExperiments->selectedItems();
  if (selectedItems.isEmpty()) {
    QMessageBox::warning(this, "提示", "请先选择实验");
    return;
  }
  QString expId = selectedItems[0]->text();

  QString filePath = QFileDialog::getOpenFileName(this, "选择成绩文件", "",
                                                  "TXT 文件 (*.txt)");
  if (filePath.isEmpty())
    return;

  if (TeacherService::importScoresFromFile(expId, filePath)) {
    QMessageBox::information(this, "成功", "成绩导入成功");
  } else {
    QMessageBox::warning(this, "失败", "成绩导入失败");
  }
}

/* ================== 手动修改成绩 ================== */
void TeacherWindow::onUpdateScore() {
  auto expItems = ui->tableMyExperiments->selectedItems();
  auto stuItems = ui->tableExperimentStudents->selectedItems();

  if (expItems.isEmpty() || stuItems.isEmpty()) {
    QMessageBox::warning(this, "提示", "请选择实验和学生");
    return;
  }

  QString expId = expItems[0]->text();
  QString studentId = stuItems[0]->text();
  bool ok;
  int score =
      QInputDialog::getInt(this, "修改成绩", "输入成绩：", 0, 0, 100, 1, &ok);
  if (!ok)
    return;

  if (TeacherService::updateScore(expId, studentId, score)) {
    QMessageBox::information(this, "成功", "成绩修改成功");
    onViewExperimentStudents();
  } else {
    QMessageBox::warning(this, "失败", "修改失败");
  }
}

/* ================== 导出实验成绩 ================== */
void TeacherWindow::onExportReservationsCSV() {
  auto selectedItems = ui->tableMyExperiments->selectedItems();
  if (selectedItems.isEmpty()) {
    QMessageBox::warning(this, "提示", "请选择实验");
    return;
  }
  QString expId = selectedItems[0]->text();
  QString filePath = "reservations.csv";

  auto students = TeacherService::queryExperimentStudents(expId);
  FileService::exportReservationsToCSV(filePath);
  QMessageBox::information(this, "导出", "成绩已导出 CSV");
}

void TeacherWindow::onExportReservationsTXT() {
  auto selectedItems = ui->tableMyExperiments->selectedItems();
  if (selectedItems.isEmpty()) {
    QMessageBox::warning(this, "提示", "请选择实验");
    return;
  }
  QString expId = selectedItems[0]->text();
  QString filePath = "reservations.txt";

  auto students = TeacherService::queryExperimentStudents(expId);
  FileService::exportReservationsToTXT(filePath);
  QMessageBox::information(this, "导出", "成绩已导出 TXT");
}
