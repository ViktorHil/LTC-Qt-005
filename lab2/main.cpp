#include <QCoreApplication>
#include <QDebug>
#include "human.h"

#define info_table \
    X(0, "Lucas    Grey",  54, 'm', _root) \
    X(1, "Mary     Grey",  28, 'f', 0) \
    X(2, "Jason    Grey",  32, 'm', 0) \
    X(3, "Fred    Smith",   2, 'm', 1) \
    X(4, "Jane    Smith",   2, 'f', 1) \
    X(5, "Sean     Grey",   5, 'm', 2) \
    X(6, "Jessica  Grey",   1, 'm', 2) \
    X(7, "Hannah   Grey",   1, 'm', 2)


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* p_root = nullptr;
#define X(a,b,c,d,e) Human* p##a = new Human( p##e); \
                            p##a->setObjectName( b); \
                            p##a->setAge( c); \
                            p##a->setSex( d); \
                            qDebug() << p##a->objectName() << " was created";
    info_table
    p_root = p0;
#undef X

    qDebug() << "--- Dumping tree ----------------";
    p_root->dumpObjectTree();
    qDebug() << "---------------------------------";

    Human* human = qobject_cast<Human*>(p_root);
    qDebug() << p_root->objectName()
             << "age:" << human->age()
             << "sex:" << human->sex();
    qDebug() << "---------------------------------";

    delete p_root;
    return a.exec();
}
