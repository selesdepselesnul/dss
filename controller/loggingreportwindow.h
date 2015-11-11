#ifndef LOGGINGREPORTWINDOW_H
#define LOGGINGREPORTWINDOW_H

#include <QWidget>

namespace Ui {
class LoggingReportWindow;
}

class LoggingReportWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoggingReportWindow(QWidget *parent = 0);
    ~LoggingReportWindow();

private:
    Ui::LoggingReportWindow *ui;
};

#endif // LOGGINGREPORTWINDOW_H
