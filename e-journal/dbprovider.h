#ifndef DBPROVIDER_H
#define DBPROVIDER_H

#include <QtSql>

enum Tables {
    USERS = 0,
    TEACHERS,
    STUDENTS,
    MARKS
};

class DBProvider
{
 public:

    DBProvider(const Tables table);

    DBProvider* select(const QString columns);

    DBProvider* where(const QString condition);
    bool exec();//QString query);

    QSqlQuery query() const;

    QString currentTabel() const;
    QString buildingQuery() const;

private:
    const QString m_PathToDB;
    const Tables m_currentTabel;
    QSqlDatabase m_dbase;
    QSqlQuery m_query;
    QString m_buildingQuery;
};

#endif // DBPROVIDER_H