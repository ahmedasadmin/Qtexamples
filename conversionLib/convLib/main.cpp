#include <QCoreApplication>
#include <QDebug>
#include <QtMath>
#include <QDateTime>
#include <QTextCodec>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int numberA = 2;
    QString numberB = "4";
    qDebug() <<"1) " "2 + 5" << numberA + numberB.toInt();

    float numberC = 10.25;
    float numberD = 2;
    QString result = QString::number(numberC * numberD);

    qDebug() << "2) " << "10.25 * 2 =" << result;


    float numberE = 10.3;
    float numberF = qFloor(numberE);
    qDebug() <<"4) " << "Floor of 10.3 is" << numberF;

    float numberG = 10.3;
    float numberH = qCeil(numberG);
    qDebug() << "4) " << "Ceil of 10.3 is " << numberH;


    // most important thing is comming
    QString dataTimeAString = "2024-03-03 12:06:00";
    QDateTime dateTimeA =
            QDateTime::fromString(dataTimeAString, "yyyy-MM-dd hh:mm:ss");
    qDebug() << "5) " << dateTimeA;

    QString hello1 = "hello world!";
    qDebug() << "7) " << hello1.toUpper();

    QString hello2 = "HELLO WORLD!";
    qDebug() << "8) " << hello2.toLower();

    QVariant aNumber = QVariant(3.14159);
    QVariant aResult = 12.5 * aNumber.toDouble();
    qDebug() << "9) 12.5 * 3.14159= " << aResult;

    qDebug() << "10) ";
    QVariant myData = QVariant(10);
    qDebug() << myData;

    myData  = true;
    myData = QDateTime::currentDateTime();
    qDebug() << myData;
    myData = "Good bye!";
    qDebug() << myData;

   return a.exec();
}
