#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_output_clicked();


    void on_dateTime_dateTimeChanged(const QDateTime &dateTime);

    void updatetime();

private:
    Ui::MainWindow *ui;
    QTimer *clock;

};

#endif // MAINWINDOW_H
