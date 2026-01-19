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

  // 绑定按钮
  connect(ui->btnAddExp, &QPushButton::clicked, this,
          &AdminWindow::onAddExperiment);
  connect(ui->btnUpdateExp, &QPushButton::clicked, this,
          &AdminWindow::onUpdateExperiment);
  connect(ui->btnDeleteExp, &QPushButton::clicked, this,
          &AdminWindow::onDeleteExperiment);
  connect(ui->btnPublishExp, &QPushButton::clicked, this,
          &AdminWindow::onPublishExperiment);
  connect(ui->btnExportExpCSV, &QPushButton::clicked, this,
          &AdminWindow::onExportExperimentsCSV);
  connect(ui->btnExportExpTXT, &QPushButton::clicked, this,
          &AdminWindow::onExportExperimentsTXT);

  connect(ui->btnAddStu, &QPushButton::clicked, this,
          &AdminWindow::onAddStudent);
  connect(ui->btnUpdateStu, &QPushButton::clicked, this,
          &AdminWindow::onUpdateStudent);
  connect(ui->btnDeleteStu, &QPushButton::clicked, this,
          &AdminWindow::onDeleteStudent);
  connect(ui->btnExportStuCSV, &QPushButton::clicked, this,
          &AdminWindow::onExportStudentsCSV);
  connect(ui->btnExportStuTXT, &QPushButton::clicked, this,
          &AdminWindow::onExportStudentsTXT);

  connect(ui->btnAddTea, &QPushButton::clicked, this,
          &AdminWindow::onAddTeacher);
  connect(ui->btnUpdateTea, &QPushButton::clicked, this,
          &AdminWindow::onUpdateTeacher);
  connect(ui->btnDeleteTea, &QPushButton::clicked, this,
          &AdminWindow::onDeleteTeacher);
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

  ui->tableExperiments->setColumnCount(7);
  ui->tableExperiments->setHorizontalHeaderLabels(
      {"实验ID", "实验名称", "开始时间", "结束时间", "总座位数", "已预约数",
       "是否发布"});

  // 清空原有行
  ui->tableExperiments->setRowCount(0);

  // 获取实验列表
  auto list = AdminService::getAllExperiments();
  qDebug() << "获取到的实验数量：" << list.size();

  // 遍历填充数据
  for (int i = 0; i < (int)list.size(); ++i) {
    const auto &exp = list[i]; //
    ui->tableExperiments->insertRow(i);

    // 列0：实验ID
    ui->tableExperiments->setItem(
        i, 0, new QTableWidgetItem(exp.expId.isEmpty() ? "空ID" : exp.expId));
    // 列1：实验名称
    ui->tableExperiments->setItem(
        i, 1,
        new QTableWidgetItem(exp.expName.isEmpty() ? "空名称" : exp.expName));
    // 列2：开始时间（验证有效性）
    QString startTimeStr = exp.startTime.isValid()
                               ? exp.startTime.toString("yyyy-MM-dd HH:mm:ss")
                               : "无效时间";
    ui->tableExperiments->setItem(i, 2, new QTableWidgetItem(startTimeStr));
    // 列3：结束时间
    QString endTimeStr = exp.endTime.isValid()
                             ? exp.endTime.toString("yyyy-MM-dd HH:mm:ss")
                             : "无效时间";
    ui->tableExperiments->setItem(i, 3, new QTableWidgetItem(endTimeStr));
    // 列4：总座位数
    ui->tableExperiments->setItem(
        i, 4, new QTableWidgetItem(QString::number(exp.totalSeats)));
    // 列5：已预约数
    ui->tableExperiments->setItem(
        i, 5, new QTableWidgetItem(QString::number(exp.reservedCount)));
    // 列6：是否发布
    ui->tableExperiments->setItem(
        i, 6, new QTableWidgetItem(exp.published ? "是" : "否"));
  }

  for (int col = 0; col < ui->tableExperiments->columnCount(); ++col) {
    ui->tableExperiments->setColumnHidden(col, false);
  }

  ui->tableExperiments->resizeColumnsToContents();
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
  ui->tableStudents->setColumnCount(
      4); // 学生表需要4列（学号、姓名、学院、专业）
  ui->tableStudents->setHorizontalHeaderLabels(
      {"学号", "姓名", "学院", "专业"});
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
  ui->tableTeachers->setColumnCount(3); // 教师表需要3列（教师ID、姓名、学院）
  ui->tableTeachers->setHorizontalHeaderLabels({"教师ID", "姓名", "学院"});
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
