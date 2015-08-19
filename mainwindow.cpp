#include "mainwindow.h"
#include "ui_mainwindow.h"

QTime datingtime;
QString day;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTime time;
        time = time.currentTime();
        clock = new QTimer;
        clock->setInterval(1000);
        connect(clock,SIGNAL(timeout()),this,SLOT(updatetime()));
        clock->start();


        datingtime=time.addSecs(+1800);
        QString notistime = datingtime.toString("yyyy-MM-dd-hh:mm:ss");
    if(notistime==day)
    {
        ui->textBrowser->append("it's time to have a date ");
        QFile file("savedata.txt");
        if(file.open(QIODevice::ReadOnly))
        {
            QString line;
            QTextStream in(&file);
            while (!in.atEnd()) {
                line = in.readLine();
                ui->textBrowser->append(line);
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_output_clicked()
{
   QString  workthing = ui->textEdit->toPlainText();
   ui->textBrowser->append(workthing);
   ui->textBrowser->append(day);
   QFile file("savedata.txt");
   if(file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text))
   {
       QTextStream out(&file);
       out<<day<<"  ";
       out<<workthing<<endl;
   }
   else
   {
       qDebug()<<"fail";
   }


}


void MainWindow::on_dateTime_dateTimeChanged(const QDateTime &dateTime)
{
    day=dateTime.toString("yyyy-MM-dd-hh:mm:ss");
}

void MainWindow::updatetime()
{
    QTime time;
    time = time.currentTime();
    qDebug() << time.toString("hh:mm:ss");
    QDateTime date;
    date = date.currentDateTime();
    qDebug() << date.toString("yyyy-MM-dd");

}
