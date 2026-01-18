#include "Service/FileService.h"

bool FileService ::loadStudents(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_in(load_file_path);

    if (!file_in.open(QFileDevice::ReadOnly | QFileDevice::Text))
    // 只读文本模式打开
    {
        qDebug() << "loadStudents中读取文件出错" << filePath;
        return false;
    }

    QTextStream in(&file_in); // 格式化文本读写流

    g_students.clear(); // 清除数据

    in.readLine(); // 跳过首行

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed(); // 去除首尾空格
        if (line.isEmpty())                     // 判断是否为空
        {
            continue;
        }

        QStringList lines = line.split(",", Qt::SkipEmptyParts);
        // 分割进链表

        if (lines.size() != 5)
        {
            qDebug() << "CSV格式错误，跳过" << line;
            continue;
        }

        g_students.emplace_back(lines[0], lines[1], lines[2], lines[3], lines[4]);
    }

    file_in.close();
    qDebug() << "loadStudents成功,共读取" << g_students.size() << "条账户";

    return true;
}

bool FileService ::loadTeachers(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_in(load_file_path);

    if (!file_in.open(QFileDevice::ReadOnly | QFileDevice::Text))
    // 只读文本模式打开
    {
        qDebug() << "loadTeachers中读取文件出错" << filePath;
        return false;
    }

    QTextStream in(&file_in); // 格式化文本读写流

    g_teachers.clear(); // 清除数据

    in.readLine(); // 跳过首行

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed(); // 去除首尾空格
        if (line.isEmpty())                     // 判断是否为空
        {
            continue;
        }

        QStringList lines = line.split(",", Qt::SkipEmptyParts);
        // 分割进链表

        if (lines.size() != 4)
        {
            qDebug() << "CSV格式错误，跳过" << line;
            continue;
        }

        g_teachers.emplace_back(lines[0], lines[1], lines[2], lines[3]);
    }

    file_in.close();
    qDebug() << "loadTeachers成功,共读取" << g_teachers.size() << "条账户";

    return true;
}

bool FileService ::loadExperiments(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_in(load_file_path);

    if (!file_in.open(QFileDevice::ReadOnly | QFileDevice::Text))
    // 只读文本模式打开
    {
        qDebug() << "loadExperiments中读取文件出错" << filePath;
        return false;
    }

    QTextStream in(&file_in); // 格式化文本读写流

    g_experiments.clear(); // 清除数据

    const QString TIME_FORMAT = "yyyy-MM-dd HH:mm:ss"; // 初始化格式

    in.readLine(); // 跳过首行

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed(); // 去除首尾空格
        if (line.isEmpty())                     // 判断是否为空
        {
            continue;
        }

        QStringList lines = line.split(",", Qt::SkipEmptyParts);
        // 分割进链表

        if (lines.size() != 9)
        {
            qDebug() << "CSV格式错误，跳过" << line;
            continue;
        }

        QString expId = lines[0];
        QString expName = lines[1];
        QString teacherId = lines[7];
        QString teacherName = lines[8];

        QDateTime StartTime = QDateTime::fromString(lines[2], TIME_FORMAT);
        QDateTime EndTime = QDateTime::fromString(lines[3], TIME_FORMAT);

        // 校验时间解析是否有效
        if (!StartTime.isValid() || !EndTime.isValid())
        {
            qDebug() << "时间解析失败，跳过该行：" << line
                     << "| 开始时间：" << lines[2] << "| 结束时间：" << lines[3];
            continue;
        }

        // 整数字段：字符串→int（处理转换失败）
        bool totalSeatsOk = false;
        int totalSeats = lines[4].toInt(&totalSeatsOk);
        bool reservedCountOk = false;
        int reservedCount = lines[5].toInt(&reservedCountOk);
        if (!totalSeatsOk || !reservedCountOk)
        {
            qDebug() << "数字转换失败，跳过该行：" << line
                     << "| 总席位：" << lines[4] << "| 已预约：" << lines[5];
            continue;
        }

        // 布尔字段：字符串→bool（支持"true"/"false"或"1"/"0"）
        bool published = false;
        QString publishStr = lines[6].toLower(); // 转小写，兼容True/TRUE等
        if (publishStr == "true" || publishStr == "1")
        {
            published = true;
        }
        else if (publishStr != "false" && publishStr != "0")
        {
            qDebug() << "发布状态格式错误，跳过该行：" << line << "| 状态：" << lines[6];
            continue;
        }

        // ========== 构造Experiment对象并加入容器 ==========
        g_experiments.emplace_back(
            expId,         // 0: 实验编号
            expName,       // 1: 实验名称
            StartTime,     // 2: 开始时间
            EndTime,       // 3: 结束时间
            totalSeats,    // 4: 总席位
            reservedCount, // 5: 已预约人数
            published,     // 6: 是否已发布
            teacherId,     // 7: 教师编号
            teacherName    // 8: 教师姓名
        );
    }

    file_in.close();
    qDebug() << "loadExperiments成功,共读取" << g_experiments.size() << "条账户";

    return true;
}

bool FileService ::loadReservations(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_in(load_file_path);

    if (!file_in.open(QFileDevice::ReadOnly | QFileDevice::Text))
    // 只读文本模式打开
    {
        qDebug() << "loadReservations中读取文件出错" << filePath;
        return false;
    }

    QTextStream in(&file_in); // 格式化文本读写流

    g_reservations.clear(); // 清除数据

    in.readLine(); // 跳过首行

    while (!in.atEnd())
    {
        QString line = in.readLine().trimmed(); // 去除首尾空格
        if (line.isEmpty())                     // 判断是否为空
        {
            continue;
        }

        QStringList lines = line.split(",", Qt::SkipEmptyParts);
        // 分割进链表

        if (lines.size() != 7)
        {
            qDebug() << "CSV格式错误，跳过" << line;
            continue;
        }

        bool scoreOk = false;
        int Score = lines[6].toInt(&scoreOk);
        if (!scoreOk)
        {
            qDebug() << "数字转换失败，跳过该行：" << line
                     << "| 成绩：" << lines[6];
            continue;
        }

        g_reservations.emplace_back(lines[0], lines[1], lines[2], lines[3], lines[4], lines[5], Score);
    }

    file_in.close();
    qDebug() << "loadReservations成功,共读取" << g_reservations.size() << "条账户";

    return true;
}

bool FileService ::loadAll(void)
{
    if (FileService ::loadStudents("Students.txt") && FileService ::loadTeachers("Teachers.txt") && FileService ::loadExperiments("Experiments.txt") && FileService ::loadReservations("Reservations.txt"))
        return true;

    return false;
}

bool FileService ::saveStudents(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "saveStudents文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "studentId,name,college,major,password\n";

    for (auto index : g_students)
    {
        out << index.studentId << "," << index.name << "," << index.college << "," << index.major << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "saveStudents成功写入" << g_students.size() << "条数据";

    return true;
}

bool FileService ::saveTeachers(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "saveTeachers文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "teacherId,name,college,password\n";

    for (auto index : g_teachers)
    {
        out << index.teacherId << "," << index.name << "," << index.college << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "saveTeachers成功写入" << g_teachers.size() << "条数据";

    return true;
}

bool FileService ::saveExperiments(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "saveExperiments文件打开失败" << filePath;
        return false;
    }

    const QString TIME_FORMAT = "yyyy-MM-dd HH:mm:ss"; // 初始化格式

    QTextStream out(&file_out);

    out << "expId,expName,startTime,endTime,totalSeats,reservedCount,published,teacherId,teacherName\n";

    for (auto index : g_experiments)
    {
        QString StartTime;
        QString EndTime;
        QString TotalSeats;
        QString ReservedCount;
        QString Published;

        if (!index.startTime.isValid())
        {
            qDebug() << "[转换失败] startTime对应的QDateTime对象无效(未初始化/解析错误)";
            StartTime = "无效时间";
        }
        if (!index.endTime.isValid())
        {
            qDebug() << "[转换失败] endTime对应的QDateTime对象无效(未初始化/解析错误)";
            EndTime = "无效时间";
        }

        StartTime = index.startTime.toString(TIME_FORMAT);
        EndTime = index.endTime.toString(TIME_FORMAT);

        TotalSeats = QString::number(index.totalSeats);
        ReservedCount = QString::number(index.reservedCount);
        Published = QString::number(index.published);

        out << index.expId << "," << index.expName << "," << StartTime << "," << EndTime << "," << TotalSeats << "," << ReservedCount << "," << Published << "," << index.teacherId << "," << index.teacherName << "\n";
    }

    file_out.close();

    qDebug() << "saveExperiments成功写入" << g_experiments.size() << "条数据";

    return true;
}

bool FileService ::saveReservations(const QString &filePath)
{
    const QString LOAD_PATH = "input/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "saveReservations文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "expId,expName,studentId,studentName,teacherId,teacherName,score\n";

    for (auto index : g_reservations)
    {
        QString Score = QString::number(index.score);

        out << index.expId << "," << index.expName << "," << index.studentId << "," << index.studentName << index.teacherId << "," << index.teacherName << "," << Score << "\n";
    }

    file_out.close();

    qDebug() << "saveReservations成功写入" << g_reservations.size() << "条数据";

    return true;
}

bool FileService ::saveAll(void)
{
    if (FileService ::saveStudents("Students.txt") && FileService ::saveTeachers("Teachers.txt") && FileService ::saveExperiments("Experiments.txt") && FileService ::saveReservations("Reservations.txt"))
        return true;

    return false;
}

bool FileService ::exportStudentsToCSV(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportStudentsToCSV文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "studentId,name,college,major,password\n";

    for (auto index : g_students)
    {
        out << index.studentId << "," << index.name << "," << index.college << "," << index.major << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "exportStudentsToCSV成功写入" << g_students.size() << "条数据";

    return true;
}
bool FileService ::exportTeachersToCSV(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportTeachersToCSV文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "teacherId,name,college,password\n";

    for (auto index : g_teachers)
    {
        out << index.teacherId << "," << index.name << "," << index.college << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "exportTeachersToCSV成功写入" << g_teachers.size() << "条数据";

    return true;
}
bool FileService ::exportExperimentsToCSV(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportExperimentsToCSV文件打开失败" << filePath;
        return false;
    }

    const QString TIME_FORMAT = "yyyy-MM-dd HH:mm:ss"; // 初始化格式

    QTextStream out(&file_out);

    out << "expId,expName,startTime,endTime,totalSeats,reservedCount,published,teacherId,teacherName\n";

    for (auto index : g_experiments)
    {
        QString StartTime;
        QString EndTime;
        QString TotalSeats;
        QString ReservedCount;
        QString Published;

        if (!index.startTime.isValid())
        {
            qDebug() << "[转换失败] startTime对应的QDateTime对象无效(未初始化/解析错误)";
            StartTime = "无效时间";
        }
        if (!index.endTime.isValid())
        {
            qDebug() << "[转换失败] endTime对应的QDateTime对象无效(未初始化/解析错误)";
            EndTime = "无效时间";
        }

        StartTime = index.startTime.toString(TIME_FORMAT);
        EndTime = index.endTime.toString(TIME_FORMAT);

        TotalSeats = QString::number(index.totalSeats);
        ReservedCount = QString::number(index.reservedCount);
        Published = QString::number(index.published);

        out << index.expId << "," << index.expName << "," << StartTime << "," << EndTime << "," << TotalSeats << "," << ReservedCount << "," << Published << "," << index.teacherId << "," << index.teacherName << "\n";
    }

    file_out.close();

    qDebug() << "exportExperimentsToCSV成功写入" << g_experiments.size() << "条数据";

    return true;
}
bool FileService ::exportReservationsToCSV(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportReservationsToCSV文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "expId,expName,studentId,studentName,teacherId,teacherName,score\n";

    for (auto index : g_reservations)
    {
        QString Score = QString::number(index.score);

        out << index.expId << "," << index.expName << "," << index.studentId << "," << index.studentName << index.teacherId << "," << index.teacherName << "," << Score << "\n";
    }

    file_out.close();

    qDebug() << "exportReservationsToCSV成功写入" << g_reservations.size() << "条数据";

    return true;
}
bool FileService ::exportStudentsToTXT(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportStudentsToTXT文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "studentId,name,college,major,password\n";

    for (auto index : g_students)
    {
        out << index.studentId << "," << index.name << "," << index.college << "," << index.major << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "exportStudentsToTXT成功写入" << g_students.size() << "条数据";

    return true;
}
bool FileService ::exportTeachersToTXT(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportTeachersToTXT文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "teacherId,name,college,password\n";

    for (auto index : g_teachers)
    {
        out << index.teacherId << "," << index.name << "," << index.college << "," << index.password << "\n";
    }

    file_out.close();

    qDebug() << "exportTeachersToTXT成功写入" << g_teachers.size() << "条数据";

    return true;
}
bool FileService ::exportExperimentsToTXT(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportExperimentsToTXT文件打开失败" << filePath;
        return false;
    }

    const QString TIME_FORMAT = "yyyy-MM-dd HH:mm:ss"; // 初始化格式

    QTextStream out(&file_out);

    out << "expId,expName,startTime,endTime,totalSeats,reservedCount,published,teacherId,teacherName\n";

    for (auto index : g_experiments)
    {
        QString StartTime;
        QString EndTime;
        QString TotalSeats;
        QString ReservedCount;
        QString Published;

        if (!index.startTime.isValid())
        {
            qDebug() << "[转换失败] startTime对应的QDateTime对象无效(未初始化/解析错误)";
            StartTime = "无效时间";
        }
        if (!index.endTime.isValid())
        {
            qDebug() << "[转换失败] endTime对应的QDateTime对象无效(未初始化/解析错误)";
            EndTime = "无效时间";
        }

        StartTime = index.startTime.toString(TIME_FORMAT);
        EndTime = index.endTime.toString(TIME_FORMAT);

        TotalSeats = QString::number(index.totalSeats);
        ReservedCount = QString::number(index.reservedCount);
        Published = QString::number(index.published);

        out << index.expId << "," << index.expName << "," << StartTime << "," << EndTime << "," << TotalSeats << "," << ReservedCount << "," << Published << "," << index.teacherId << "," << index.teacherName << "\n";
    }

    file_out.close();

    qDebug() << "exportExperimentsToTXT成功写入" << g_experiments.size() << "条数据";

    return true;
}
bool FileService ::exportReservationsToTXT(const QString &filePath)
{
    const QString LOAD_PATH = "output/"; // 相对路径

    QString load_file_path = QDir::fromNativeSeparators(LOAD_PATH + filePath); // 拼接路径，处理路径分隔符

    QFile file_out(load_file_path);
    if (!file_out.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    // 只写 文本 覆写
    {
        qDebug() << "exportReservationsToTXT文件打开失败" << filePath;
        return false;
    }

    QTextStream out(&file_out);

    out << "expId,expName,studentId,studentName,teacherId,teacherName,score\n";

    for (auto index : g_reservations)
    {
        QString Score = QString::number(index.score);

        out << index.expId << "," << index.expName << "," << index.studentId << "," << index.studentName << index.teacherId << "," << index.teacherName << "," << Score << "\n";
    }

    file_out.close();

    qDebug() << "exportReservationsToTXT成功写入" << g_reservations.size() << "条数据";

    return true;
}