#include <QCoreApplication>
#include <QString>
#include <QList>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString names = "One Longest Two Three Four Five Six Seven ";
    qDebug() << names;

    QStringList list = names.split(" ", QString::SkipEmptyParts);

    std::sort( list.begin(), list.end(),
        [](const QString& first, const QString& second)
         { return first.length() < second.length(); });

    QListIterator<QString> javaIterator(list);
    while( javaIterator.hasNext()) {
        qDebug() << javaIterator.next();
    }

    qDebug() << QString("Longest  name: %1").arg( list.last());
    qDebug() << QString(list.first()).prepend("Shortest name: ");

    qDebug() << list.join(',');

    for( QList<QString>::reverse_iterator i = list.rbegin(); i != list.rend(); i++) {
        qDebug() << *i;
    }
    return a.exec();
}
