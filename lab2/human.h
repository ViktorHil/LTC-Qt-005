#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int age READ age)
    Q_PROPERTY(char sex READ sex)

public:
    explicit Human(QObject *parent = nullptr);
    virtual ~Human();

    int age() const { return m_age; }
    char sex() const { return m_sex; }
    void setAge( int a) { m_age = a; }
    void setSex( char s) { m_sex = s; }

signals:

private:
    int m_age;
    char m_sex;
};

#endif // HUMAN_H
