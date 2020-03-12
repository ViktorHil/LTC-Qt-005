#include <QDebug>
#include <iostream>
#include "human.h"

Human::Human(QObject *parent) : QObject(parent) {}

Human::~Human() {
    qDebug() << this->objectName() << " was destroyed";
}
