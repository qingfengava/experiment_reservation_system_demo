#include "Service/TeacherService.h"
#include <QFile>
#include <QRegularExpression>
#include <QTextStream>
#include <algorithm>

std::vector<Experiment>
TeacherService::queryMyExperiments(const QString &teacherId) {
  std::vector<Experiment> result;

  for (const auto &exp : g_experiments) {
    if (exp.teacherId == teacherId) {
      result.push_back(exp);
    }
  }

  std::sort(result.begin(), result.end(),
            [](const Experiment &a, const Experiment &b) {
              return a.startTime < b.startTime;
            });

  return result;
}

std::vector<Reservation>
TeacherService::queryExperimentStudents(const QString &expId) {
  std::vector<Reservation> result;

  for (const auto &r : g_reservations) {
    if (r.expId == expId) {
      result.push_back(r);
    }
  }

  return result;
}

bool TeacherService::importScoresFromFile(const QString &expId,
                                          const QString &filePath) {
  QFile file(filePath);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return false;

  QTextStream in(&file);
  bool updated = false;

  while (!in.atEnd()) {
    QString line = in.readLine().trimmed();
    if (line.isEmpty())
      continue;

    QStringList parts = line.split(QRegularExpression("\\s+"));
    if (parts.size() != 2)
      continue;

    QString studentId = parts[0];
    bool ok = false;
    int score = parts[1].toInt(&ok);
    if (!ok)
      continue;

    // 更新预约表中的成绩
    for (auto &r : g_reservations) {
      if (r.expId == expId && r.studentId == studentId) {
        r.score = score;
        updated = true;
        break;
      }
    }
  }

  file.close();
  return updated;
}

bool TeacherService::updateScore(const QString &expId, const QString &studentId,
                                 int score) {
  for (auto &r : g_reservations) {
    if (r.expId == expId && r.studentId == studentId) {
      r.score = score;
      return true;
    }
  }
  return false;
}
