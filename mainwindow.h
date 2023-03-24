#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <QImage>
#include <QElapsedTimer>
#include <QVBoxLayout>
#include <fstream>
#include <string>
#include <math.h>
#include <QTextStream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void fltroImagen(QString srcDir, QString destDir);

    void elevador(QString srcFile, QString destFile);

private slots:

    void on_srcFileBtn_clicked();

    void on_destFileBtn_clicked();

    void on_srcDirBtn_clicked();

    void on_destDirBtn_clicked();

    void on_execImageBtn_clicked();

    void on_execDataBtn_clicked();

private:
    Ui::MainWindow *ui;

    QString srcFile;
    QString destFile;

    QString srcDir;
    QString destDir;

};
#endif // MAINWINDOW_H
