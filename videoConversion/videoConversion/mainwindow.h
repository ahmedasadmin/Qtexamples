#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>
#include <QScrollBar>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QProcess* process;
    QString outputText;
    QString outputFileName;


private slots:
    void on_btnConverter_clicked();
    void on_btnBrowser_clicked();
    void processStarted();
    void readyReadStandardOutput();
    void processFinished();




private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
