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

    QString text = QString("srcDir: %1\n").arg(srcDir);

    ui->textEdit_Image->append(text);
}

void MainWindow::on_destDirBtn_clicked()
{
    destDir = QFileDialog::getExistingDirectory(nullptr, "Select Directory", QDir::currentPath());

    QString text = QString("destDir: %1\n").arg(destDir);

    ui->textEdit_Image->append(text);
}

void MainWindow::fltroImagen(QString srcDir, QString destDir){

    QDir directory(srcDir);

    QFileInfoList fileList = directory.entryInfoList(QDir::Files);

    int i = 0;

    foreach (QFileInfo fileInfo, fileList) {

        QString filePath = fileInfo.absoluteFilePath();

        QImage image(filePath);

        // Convert the image to grayscale
        image = image.convertToFormat(QImage::Format_Grayscale8);

        // Loop through every pixel in the image
        for (int x = 0; x < image.width(); x++) {
            for (int y = 0; y < image.height(); y++) {
                // Get the color of the pixel
                QRgb pixel = image.pixel(x, y);

                // Get the grayscale value of the pixel
                int gray = qGray(pixel);

                // Set the new color of the pixel
                image.setPixel(x, y, qRgb(gray, gray, gray));
            }
        }

        //prueba de funcionamiento

//        QLabel *imageLabel = new QLabel();
//        imageLabel->setPixmap(QPixmap::fromImage(image));

//        QDialog *dialog = new QDialog();
//        QVBoxLayout *layout = new QVBoxLayout(dialog);
//        layout->addWidget(imageLabel);
//        dialog->setLayout(layout);

//        dialog->show();




        QString dest = destDir + "/" + QString::number(i) + ".png";
        image.save(dest);
        i++;
    }
}

void MainWindow::on_execImageBtn_clicked()
{
    double totalTime = 0;
    for(int i = 1; i <= 5; i++){
        QElapsedTimer timer;
        timer.start();
        fltroImagen(srcDir, destDir);
        double time = timer.elapsed();
        totalTime += time;

        QString text = QString("execution %1 time %2\n").arg(i).arg(time);

        ui->textEdit_Image->append(text);

    }

    double avgTime = totalTime/5;

    QString text = QString("average time %1\n").arg(avgTime);

    ui->textEdit_Image->append(text);
}

