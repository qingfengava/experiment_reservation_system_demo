#include "UI/AdminWindow.h"
#include "ui_AdminWindow.h"

#include <QCloseEvent>
#include <QMessageBox>

#include "Service/AdminService.h"
#include "Service/FileService.h"

AdminWindow::AdminWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::AdminWindow) {
  ui->setupUi(this);

  // 初始化界面数据
  onRefreshExperiments();
  onRefreshStudents();
  onRefreshTeachers();

  // 绑定导出按钮
  connect(ui->btnExportExpCSV, &QPushButton::clicked, this,
          &AdminWindow::onExportExperimentsCSV);
  connect(ui->btnExportExpTXT, &QPushButton::clicked, this,
          &AdminWindow::onExportExperimentsTXT);
  connect(ui->btnExportStuCSV, &QPushButton::clicked, this,
          &AdminWindow::onExportStudentsCSV);
  connect(ui->btnExportStuTXT, &QPushButton::clicked, this,
          &AdminWindow::onExportStudentsTXT);
  connect(ui->btnExportTeaCSV, &QPushButton::clicked, this,
          &AdminWindow::onExportTeachersCSV);
  connect(ui->btnExportTeaTXT, &QPushButton::clicked, this,
          &AdminWindow::onExportTeachersTXT);
}

AdminWindow::~AdminWindow() { delete ui; }

// 自动保存数据
void AdminWindow::closeEvent(QCloseEvent *event) {
  FileService::saveAll();
  event->accept();
}

/* ================== 实验管理 ================== */
void AdminWindow::onAddExperiment() {
  Experiment e;
  e.expId = ui->editExpId->text();
  e.expName = ui->editExpName->text();
  e.startTime = ui->startDateTime->dateTime();
  e.endTime = ui->endDateTime->dateTime();
  e.totalSeats = ui->spinTotalSeats->value();
  e.reservedCount = 0;
  e.published = false;
  e.teacherId = ui->editTeacherId->text();
  e.teacherName = ui->editTeacherName->text();

  if (!AdminService::addExperiment(e)) {
    QMessageBox::warning(this, "失败", "实验编号已存在");
    return;
  }
  onRefreshExperiments();
}

void AdminWindow::onUpdateExperiment() {
  Experiment e;
  e.expId = ui->editExpId->text();
  e.expName = ui->editExpName->text();
  e.startTime = ui->startDateTime->dateTime();
  e.endTime = ui->endDateTime->dateTime();
  e.totalSeats = ui->spinTotalSeats->value();
  e.teacherId = ui->editTeacherId->text();
  e.teacherName = ui->editTeacherName->text();

  if (!AdminService::updateExperiment(e.expId, e)) {
    QMessageBox::warning(this, "失败", "无法修改");
    return;
  }
  onRefreshExperiments();
}

void AdminWindow::onDeleteExperiment() {
  if (!AdminService::deleteExperiment(ui->editExpId->text())) {
    QMessageBox::warning(this, "失败", "删除失败");
    return;
  }
  onRefreshExperiments();
}

void AdminWindow::onPublishExperiment() {
  if (!AdminService::publishExperiment(ui->editExpId->text())) {
    QMessageBox::warning(this, "失败", "发布失败");
    return;
  }
  onRefreshExperiments();
}

void AdminWindow::onRefreshExperiments() {
  ui->tableExperiments->setRowCount(0);
  auto list = AdminService::getAllExperiments();
  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableExperiments->insertRow(i);
    ui->tableExperiments->setItem(i, 0, new QTableWidgetItem(list[i].expId));
    ui->tableExperiments->setItem(i, 1, new QTableWidgetItem(list[i].expName));
    ui->tableExperiments->setItem(
        i, 2, new QTableWidgetItem(list[i].startTime.toString()));
    ui->tableExperiments->setItem(
        i, 3, new QTableWidgetItem(list[i].endTime.toString()));
    ui->tableExperiments->setItem(
        i, 4, new QTableWidgetItem(QString::number(list[i].totalSeats)));
    ui->tableExperiments->setItem(
        i, 5, new QTableWidgetItem(QString::number(list[i].reservedCount)));
    ui->tableExperiments->setItem(
        i, 6, new QTableWidgetItem(list[i].published ? "是" : "否"));
  }
}

/* ================== 学生管理 ================== */
void AdminWindow::onAddStudent() {
  Student s;
  s.studentId = ui->editStuId->text();
  s.name = ui->editStuName->text();
  s.college = ui->editStuCollege->text();
  s.major = ui->editStuMajor->text();
  s.password = ui->editStuPassword->text();

  if (!AdminService::addStudent(s)) {
    QMessageBox::warning(this, "失败", "学生已存在");
    return;
  }
  onRefreshStudents();
}

void AdminWindow::onUpdateStudent() {
  Student s;
  s.studentId = ui->editStuId->text();
  s.name = ui->editStuName->text();
  s.college = ui->editStuCollege->text();
  s.major = ui->editStuMajor->text();
  s.password = ui->editStuPassword->text();

  if (!AdminService::updateStudent(s.studentId, s)) {
    QMessageBox::warning(this, "失败", "修改失败");
    return;
  }
  onRefreshStudents();
}

void AdminWindow::onDeleteStudent() {
  if (!AdminService::deleteStudent(ui->editStuId->text())) {
    QMessageBox::warning(this, "失败", "删除失败");
    return;
  }
  onRefreshStudents();
}

void AdminWindow::onRefreshStudents() {
  ui->tableStudents->setRowCount(0);
  auto list = AdminService::getAllStudents();
  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableStudents->insertRow(i);
    ui->tableStudents->setItem(i, 0, new QTableWidgetItem(list[i].studentId));
    ui->tableStudents->setItem(i, 1, new QTableWidgetItem(list[i].name));
    ui->tableStudents->setItem(i, 2, new QTableWidgetItem(list[i].college));
    ui->tableStudents->setItem(i, 3, new QTableWidgetItem(list[i].major));
  }
}

/* ================== 教师管理 ================== */
void AdminWindow::onAddTeacher() {
  Teacher t;
  t.teacherId = ui->editTeaId->text();
  t.name = ui->editTeaName->text();
  t.college = ui->editTeaCollege->text();
  t.password = ui->editTeaPassword->text();

  if (!AdminService::addTeacher(t)) {
    QMessageBox::warning(this, "失败", "教师已存在");
    return;
  }
  onRefreshTeachers();
}

void AdminWindow::onUpdateTeacher() {
  Teacher t;
  t.teacherId = ui->editTeaId->text();
  t.name = ui->editTeaName->text();
  t.college = ui->editTeaCollege->text();
  t.password = ui->editTeaPassword->text();

  if (!AdminService::updateTeacher(t.teacherId, t)) {
    QMessageBox::warning(this, "失败", "修改失败");
    return;
  }
  onRefreshTeachers();
}

void AdminWindow::onDeleteTeacher() {
  if (!AdminService::deleteTeacher(ui->editTeaId->text())) {
    QMessageBox::warning(this, "失败", "删除失败");
    return;
  }
  onRefreshTeachers();
}

void AdminWindow::onRefreshTeachers() {
  ui->tableTeachers->setRowCount(0);
  auto list = AdminService::getAllTeachers();
  for (int i = 0; i < (int)list.size(); ++i) {
    ui->tableTeachers->insertRow(i);
    ui->tableTeachers->setItem(i, 0, new QTableWidgetItem(list[i].teacherId));
    ui->tableTeachers->setItem(i, 1, new QTableWidgetItem(list[i].name));
    ui->tableTeachers->setItem(i, 2, new QTableWidgetItem(list[i].college));
  }
}

/* ================== 导出功能 ================== */
void AdminWindow::onExportExperimentsCSV() {
  FileService::exportExperimentsToCSV("experiments.csv");
  QMessageBox::information(this, "导出", "实验信息已导出 CSV");
}

void AdminWindow::onExportExperimentsTXT() {
  FileService::exportExperimentsToTXT("experiments.txt");
  QMessageBox::information(this, "导出", "实验信息已导出 TXT");
}

void AdminWindow::onExportStudentsCSV() {
  FileService::exportStudentsToCSV("students.csv");
  QMessageBox::information(this, "导出", "学生信息已导出 CSV");
}

void AdminWindow::onExportStudentsTXT() {
  FileService::exportStudentsToTXT("students.txt");
  QMessageBox::information(this, "导出", "学生信息已导出 TXT");
}

void AdminWindow::onExportTeachersCSV() {
  FileService::exportTeachersToCSV("teachers.csv");
  QMessageBox::information(this, "导出", "教师信息已导出 CSV");
}

void AdminWindow::onExportTeachersTXT() {
  FileService::exportTeachersToTXT("teachers.txt");
  QMessageBox::information(this, "导出", "教师信息已导出 TXT");
}
