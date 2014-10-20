#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <SpritePackager.h>
#include <Rectangle.h>
#include <QPainter>
#include <QImage>
#include <vector>
#include <Packer.h>
#include <QDirIterator>
#include <QDebug>
#include <SpriteCompiler.h>
#include <QFileDialog>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSettings s("settings.ini",QSettings::IniFormat);
    ui->lineEdit_spritesXMLFile->setText(s.value("lastxmlSprites",QString("")).toString());
    ui->lineEdit_spritesXMLFile_2->setText(s.value("lastoutSprites",QString("")).toString());

    /*
    SpritePackager packer;
    QDirIterator dirIt("D:/Dropbox/nGod/Art Edits/",QDirIterator::Subdirectories);
    while (dirIt.hasNext()) {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
            if (QFileInfo(dirIt.filePath()).suffix() == "png") {
                    SpriteDefinition *s = new SpriteDefinition("spr01");
                    SpriteSubimageDefinition *subimg = new SpriteSubimageDefinition(dirIt.filePath().toStdString());
                    s->AddSubimage(subimg);
                packer.AddSprite(s);

            }
    }

    packer.Pack("sheet%1.png");
    */



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QSettings s("settings.ini",QSettings::IniFormat);

    QString fileName = QFileDialog::getOpenFileName(this,"Open XML",ui->lineEdit_spritesXMLFile->text(),"XML Files(*.xml)");
    ui->lineEdit_spritesXMLFile->setText(fileName);
    s.setValue("lastxmlSprites",fileName);

}

void MainWindow::on_pushButton_2_clicked()
{

    SpriteCompiler c;
    c.Compile(ui->lineEdit_spritesXMLFile->text().toStdString(),ui->lineEdit_spritesXMLFile_2->text().toStdString());
}

void MainWindow::on_pushButton_3_clicked()
{
    QSettings s("settings.ini",QSettings::IniFormat);
    ui->lineEdit_spritesXMLFile_2->setText(QFileDialog::getExistingDirectory(this,"Output directory",ui->lineEdit_spritesXMLFile_2->text()));
    s.setValue("lastoutSprites",ui->lineEdit_spritesXMLFile_2->text());
}
