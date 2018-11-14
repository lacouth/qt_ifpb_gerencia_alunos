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

void MainWindow::atualizarEstatisticas()
{
    ui->lbl_avg->setText(QString::number(engenharia.mediaDaTurma(),'f',2));
    ui->lbl_highest->setText(QString::number(engenharia.maiorNota(),'f',2));
    ui->lbl_lowest->setText(QString::number(engenharia.menorNota(),'f',2));

    QString color = engenharia.mediaDaTurma() < 70 ? "red" : "black";
    ui->lbl_avg->setStyleSheet("color: "+color);

}

void MainWindow::on_btn_insert_clicked()
{

    int qnt_row = ui->tbl_data->rowCount();

    if(ui->le_nameInput->text().size() != 0 && ui->le_avgInput->text().size() != 0){
        aluno = new Aluno();

        aluno->setNome(ui->le_nameInput->text());
        aluno->setMedia(ui->le_avgInput->text().toFloat());

        ui->tbl_data->insertRow(qnt_row);

        ui->tbl_data->setItem(qnt_row,0,new QTableWidgetItem(aluno->getNome()));
        ui->tbl_data->setItem(qnt_row,1,new QTableWidgetItem(QString::number(aluno->getMedia())));
        ui->tbl_data->setItem(qnt_row,2,new QTableWidgetItem(aluno->getStatus()));

        ui->le_nameInput->clear();
        ui->le_avgInput->clear();

        engenharia.inserirAluno(*aluno);
        atualizarEstatisticas();

        delete aluno;
    }
}
