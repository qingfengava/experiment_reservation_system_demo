#include "Service/StudentService.h"
#include "Model/DataModel.h"
#include <algorithm>

std::vector<Experiment> StudentService::queryAvailableExperiments() {
  std::vector<Experiment> result;
  QDateTime now = QDateTime::currentDateTime();

  for (const auto &exp : g_experiments) {
    if (!exp.published)
      continue;

    if (exp.reservedCount >= exp.totalSeats)
      continue;

    if (now.secsTo(exp.startTime) < 4 * 3600)
      continue;

    if (now.date().month() != exp.startTime.date().month())
      continue;

    result.push_back(exp);
  }

  return result;
}

bool StudentService::reserveExperiment(const QString &studentId,
                                       const QString &studentName,
                                       const QString &expId) {
  auto expIt =
      std::find_if(g_experiments.begin(), g_experiments.end(),
                   [&](const Experiment &exp) { return exp.expId == expId; });

  if (expIt == g_experiments.end()) {
    return false;
  }

  Experiment &exp = *expIt;

  if (!exp.published || exp.reservedCount >= exp.totalSeats ||
      QDateTime::currentDateTime().secsTo(exp.startTime) < 4 * 3600) {
    return false;
  }

  for (const auto &r : g_reservations) {
    if (r.expId == expId && r.studentId == studentId) {
      return false;
    }
  }

  Reservation r;
  r.expId = exp.expId;
  r.expName = exp.expName;
  r.studentId = studentId;
  r.studentName = studentName;
  r.teacherId = exp.teacherId;
  r.teacherName = exp.teacherName;
  r.score = -1;

  g_reservations.push_back(r);
  exp.reservedCount++;

  return true;
}

bool StudentService::cancelReservation(const QString &studentId,
                                       const QString &expId) {
  auto resIt = std::find_if(
      g_reservations.begin(), g_reservations.end(), [&](const Reservation &r) {
        return r.studentId == studentId && r.expId == expId;
      });

  if (resIt == g_reservations.end())
    return false;

  auto expIt =
      std::find_if(g_experiments.begin(), g_experiments.end(),
                   [&](const Experiment &e) { return e.expId == expId; });

  if (expIt == g_experiments.end())
    return false;

  if (QDateTime::currentDateTime().secsTo(expIt->startTime) < 2 * 3600)
    return false;

  expIt->reservedCount--;

  auto it = std::remove_if(
      g_reservations.begin(), g_reservations.end(), [&](const Reservation &r) {
        return r.studentId == studentId && r.expId == expId;
      });

  if (it == g_reservations.end())
    return false;

  g_reservations.erase(resIt);

  return true;
}

std::vector<Reservation>
StudentService::queryMyReservations(const QString &studentId) {
  std::vector<Reservation> result;

  for (const auto &r : g_reservations) {
    if (r.studentId == studentId)
      result.push_back(r);
  }

  return result;
}

bool StudentService::updateStudentInfo(const QString &studentId,
                                       const Student &newInfo) {
  for (auto &stu : g_students) {
    if (stu.studentId == studentId) {
      stu = newInfo;
      return true;
    }
  }
  return false;
}

std::vector<Reservation> StudentService::queryScores(const QString &studentId) {
  std::vector<Reservation> result;

  for (const auto &r : g_reservations) {
    if (r.studentId == studentId && r.score >= 0)
      result.push_back(r);
  }

  return result;
}
