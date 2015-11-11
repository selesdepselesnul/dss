/**
 * author : Moch Deden (https://github.com/selesdepselesnul)
 */
#ifndef TELLER
#define TELLER
#include <QObject>
#include <QDateTime>
#include <QFile>
#include <QDataStream>
#include <QString>


class Teller {
public:
    static const QString LOG_FILE;

    Teller() {};

    Teller(qint32 tellerNumber, qint32 queueNumber, QDateTime servedDateTime) {
        this->tellerNumber = tellerNumber;
        this->queueNumber = queueNumber;
        this->servedDateTime = servedDateTime;
    }

    qint32 tellerNumber;
    qint32 queueNumber;
    QDateTime servedDateTime;
    friend QDataStream &operator << (QDataStream &stream, const Teller &teller) {

        stream<< teller.tellerNumber;
        stream<< teller.queueNumber;
        stream<< teller.servedDateTime;

        return stream;

    }
    friend QDataStream &operator >> (QDataStream &stream, Teller &teller) {

        stream >> teller.tellerNumber;
        stream >> teller.queueNumber;
        stream >> teller.servedDateTime;
        return stream;

    }
};



#endif // TELLER

