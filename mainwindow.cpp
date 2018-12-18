#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hideButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open File"), "D:\\workspace_edu", tr("Any Files ()"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString newFileName = fileName.insert(fileName.lastIndexOf("."), "X");
    QFile newFile(newFileName);
    if (!newFile.open(QIODevice::WriteOnly))
    {
        file.close();
        return;
    }

    QDataStream in(&file);
    QDataStream out(&file);
    uint word;
    uint xWord;
    while (!in.atEnd())
    {
        in >> word;
        //processWord(word);
        xWord = word^5;
        qDebug() << word << xWord << "\n";
        out << word;
    }
    file.close();
    newFile.close();
}
void MainWindow::processWord(uint word)
{
    qDebug() << word;
   //Qstring
}

void MainWindow::on_showButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
          tr("Open File"), "D:\\workspace_edu", tr("Any Files ()"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString newFileName = fileName.insert(fileName.lastIndexOf("."), "O");
    QFile newFile(newFileName);
    if (!newFile.open(QIODevice::WriteOnly))
    {
        file.close();
        return;
    }

    QDataStream in(&file);
    QDataStream out(&file);
    uint word;
    uint oWord;
    while (!in.atEnd())
    {
        in >> word;
        //processWord(word);
        oWord = word^5;
        qDebug() << word << oWord << "\n";
        out << word;
    }
    file.close();
    newFile.close();
}
