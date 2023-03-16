#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_srcFileBtn_clicked()
{
    srcFile = QFileDialog::getOpenFileName();
    if(srcFile.isEmpty()){

        QMessageBox::warning(this, "ERROR", "file not valid");

    }
}

void MainWindow::on_destFileBtn_clicked()
{
    destFile = QFileDialog::getOpenFileName();
}


void MainWindow::on_srcDirBtn_clicked()
{
    srcDir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::currentPath());
    if (srcDir.isEmpty()) {

        QMessageBox::warning(this, "ERROR", "directory not valid");

    }
}

void MainWindow::on_destDirBtn_clicked()
{
    destDir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::currentPath());
}

