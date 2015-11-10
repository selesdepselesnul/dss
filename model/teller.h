/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#ifndef TELLER
#define TELLER
#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDataStream>


class Teller {
public:
    Teller() {};

    Teller(qint32 tellerNumber, qint32 queueNumber, QDateTime servedDateTime) {
        this->tellerNumber = tellerNumber;
        this->queueNumber = queueNumber;
        this->servedDateTime = servedDateTime;
    }

    qint32 tellerNumber;
    qint32 queueNumber;
    QDateTime servedDateTime;
};

QDataStream & operator <<(QDataStream &out, const Teller &teller) {
    return out << teller.tellerNumber << teller.queueNumber
               << teller.servedDateTime;
}

QDataStream &operator>>(QDataStream &in, Teller &teller) {
    return in >> teller.tellerNumber >> teller.queueNumber
              >> teller.servedDateTime;
}


#endif // TELLER

