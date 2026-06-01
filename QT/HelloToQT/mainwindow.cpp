#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    QString text = QStringLiteral("Hello ") + ui->lineEdit->text();
    QMessageBox::information(this, "Information", text);
    QMessageBox::question(this, "Soru", "Emin misin?", QMessageBox::Yes | QMessageBox::No);
}

