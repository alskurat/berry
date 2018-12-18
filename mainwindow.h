#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFileDialog>
#include <QDataStream>
#include <QTextStream>
#include <QDebug>
#include <QTextCodec>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hideButton_clicked();

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;

    void processWord(uint word);
};

#endif // MAINWINDOW_H
