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

void MainWindow::inserirAlunoNaTabela(Aluno aluno, int row)
{
    ui->tbl_data->setItem(row,0,new QTableWidgetItem(aluno.getNome()));
    ui->tbl_data->setItem(row,1,new QTableWidgetItem(QString::number(aluno.getMedia())));
    ui->tbl_data->setItem(row,2,new QTableWidgetItem(aluno.getStatus()));
}

void MainWindow::on_btn_insert_clicked()
{

    if(ui->le_nameInput->text().size() != 0 && ui->le_avgInput->text().size() != 0){
        Aluno aluno;
        aluno.setNome(ui->le_nameInput->text());
        aluno.setMedia(ui->le_avgInput->text().toFloat());

        int qnt_row = ui->tbl_data->rowCount();
        ui->tbl_data->insertRow(qnt_row);

        inserirAlunoNaTabela(aluno, qnt_row);

        ui->le_nameInput->clear();
        ui->le_avgInput->clear();

        engenharia.inserirAluno(aluno);
        atualizarEstatisticas();
    }
}

void MainWindow::on_btn_NameSort_clicked()
{
    ui->tbl_data->clearContents();

    engenharia.ordenarPorNome();
    for(int i = 0; i<engenharia.size(); i++){
        inserirAlunoNaTabela(engenharia[i], i);
    }
}

void MainWindow::on_btn_GradeSort_clicked()
{
    ui->tbl_data->clearContents();
    engenharia.ordenarPorMedia();
    for(int i = 0; i<engenharia.size();i++){
        inserirAlunoNaTabela(engenharia[i],i);
    }
}
