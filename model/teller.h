#ifndef TELLER
#define TELLER
#include <QDateTime>
#include <QObject>

class Teller : public QObject {
    Q_OBJECT
public:

    Teller(int tellerNumber, int servedQueueNumber,
           QDateTime *dateTimeServing) {
        this->tellerNumber = tellerNumber;
        this->servedQueueNumber = servedQueueNumber;
        this->dateTimeServing = dateTimeServing;
    }

    int getTellerNumber() {
        return this->tellerNumber;
    }

    int servedQueueNumber() {
        return this->servedQueueNumber();
    }

    QDateTime* getDateTimeServing() {
        return this->dateTimeServing;
    }

private:
    int tellerNumber;
    int servedQueueNumber;
    QDateTime* dateTimeServing;
};

#endif // TELLER

