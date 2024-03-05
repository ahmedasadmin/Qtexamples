#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    process = new QProcess(this);
    connect(process, SIGNAL(started()), this,
            SLOT(processStarted()));
    connect(process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(readyReadStandardOutput()));
    connect(process, SIGNAL(finished(int)), this, SLOT(processFinished()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnConverter_clicked()
{
    QString ffmpeg = "ffmpeg";
    QStringList arguments;

    QString fileName = ui->lineEdit->text();
    if (fileName != ""){
        QFileInfo fileInfo = QFile(fileName);
        outputFileName = fileInfo.path() + "/" + fileInfo.completeBaseName();

        if (QFile::exists(fileName)){
                // 0 AVI
                // 1 MP4
                // 2 MOV
            int format = ui->comboBox->currentIndex();
            if (format == 0){
                outputFileName += ".avi";
            }
            else if(format == 1){
                outputFileName += ".mp4";
            }
            else if(format == 2){
                outputFileName += ".mov";
            }

            qDebug()<< outputFileName << format<< endl;
            arguments << "-i" << fileName << outputFileName;

            qDebug() << arguments;

            process->setProcessChannelMode(QProcess::MergedChannels);
            process->start(ffmpeg,arguments);


    }
        else{
            QMessageBox::warning(this, "Failed", "Failed to open video file.");

        }

}
    else{
            QMessageBox::warning(this, "Failed", "No file is selected");
    }

}
void MainWindow::on_btnBrowser_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    "Open Video", "", "Video Files (*.avi *.mp4 *.mov)");
    ui->lineEdit->setText(fileName);

}

void MainWindow::processStarted()
{
    qDebug() << "Process Started";
    ui->btnBrowser->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->btnConverter->setEnabled(false);
}

void MainWindow::readyReadStandardOutput()
{
    outputText += process->readAllStandardOutput();
    ui->textEdit->setText(outputText);

    ui->textEdit->verticalScrollBar()->setSliderPosition((ui->textEdit->verticalScrollBar()->maximum()));

}

void MainWindow::processFinished()
{
    qDebug() << "Process finished.";
    if (QFile::exists(outputFileName))
    {
    QMessageBox::information(this, "Success",
    "Video successfully converted.");
    }
    else
    {
    QMessageBox::information(this, "Failed",
    "Failed to convert video.");
    }
    ui->btnBrowser->setEnabled(true);
    ui->comboBox->setEditable(true);
    ui->btnConverter->setEnabled(true);

}

