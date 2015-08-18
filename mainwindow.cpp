#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString day;

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
    day=dateTime.toString();
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
