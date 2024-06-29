#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <Qdir>
#include <QString>

using namespace std;

bool type1= 0;
bool type2 = 0;
bool type3 = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    QCoreApplication::addLibraryPath(pluginsDir.absolutePath());

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Order.db");
    if(!db.open()){
        ui->textEdit->setText( "Error:" + QString( db.lastError().text()));
        return;
    }
    QSqlQuery query;

    if(!query.exec("SELECT * FROM Flower")){
        ui->textEdit->setText("Error with query");
    }else{
        QString final ="";
        while(query.next()){
           final+=(QString(query.value(1).toString()) + " " + QString(query.value(2).toString()) + " " + QString(query.value(3).toString()) + "\n");
        }
        ui->textEdit->setText(final);
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    QCoreApplication::addLibraryPath(pluginsDir.absolutePath());

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Order.db");
    if(!db.open()){
        ui->textEdit->setText( "Error:" + QString( db.lastError().text()));
        return;
    }
    QSqlQuery query;

    if(!query.exec("SELECT * FROM Composition")){
        ui->textEdit_2->setText("Error with query");
    }else{
        QString final ="";
        while(query.next()){
            final+=(QString(query.value(1).toString()) + " " + QString(query.value(2).toString()) + " " + QString(query.value(3).toString()) + "\n");
        }
        ui->textEdit_2->setText(final);
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QDir pluginsDir = QDir(QCoreApplication::applicationDirPath());
    pluginsDir.cd("plugins");
    QCoreApplication::addLibraryPath(pluginsDir.absolutePath());

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Order.db");
    if(!db.open()){
        ui->textEdit_3->setText( "Error:" + QString( db.lastError().text()));
        return;
    }
    QSqlQuery query;

    if(!query.exec("SELECT * FROM User")){
        ui->textEdit_3->setText("Error with query");
    }else{
        QString final ="";
        while(query.next()){
            final+=(QString(query.value(1).toString()) + " " + QString(query.value(2).toString()) + " " + QString(query.value(3).toString()) + "\n");
        }
        ui->textEdit_3->setText(final);
    }
}


void MainWindow::on_textEdit_textChanged()
{
    QString field1="", field2="", field3="";
    if(type1 == true){
        ui->textEdit_4->setPlainText(field1);
        ui->textEdit_5->setPlainText(field2);
        ui->textEdit_6->setPlainText(field3);

    }else{
        if(type2 == true){
            ui->textEdit_4->setPlainText(field1);
            ui->textEdit_5->setPlainText(field2);
        }else{
            if(type3 == true){
                ui->textEdit_4->setPlainText(field1);
                ui->textEdit_5->setPlainText(field2);
            }
        }
    }
}


void MainWindow::on_radioButton_clicked()
{

    type1 = true;
    type2 = false;
    type3 = false;
    ui->textEdit_4->setVisible(1);
    ui->textEdit_5->setVisible(1);
    ui->textEdit_6 -> setVisible(1);
    ui->label->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(1);
}


void MainWindow::on_radioButton_2_clicked()
{
    type1 = false;
    type2 = true;
    type3 = false;
    ui->textEdit_4->setVisible(1);
    ui->textEdit_5->setVisible(1);
    ui->textEdit_6 -> setVisible(0);
    ui->label->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(0);

}


void MainWindow::on_radioButton_3_clicked()
{
    type1 = false;
    type2 = false;
    type3 = true;
    ui->textEdit_4->setVisible(1);
    ui->textEdit_5->setVisible(1);
    ui->textEdit_6 -> setVisible(0);
    ui->label->setVisible(1);
    ui->label_2->setVisible(1);
    ui->label_3->setVisible(0);
}


void MainWindow::on_pushButton_5_clicked()
{

}

