#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QVector>
#include "aluno.h"
#include "turma.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Turma engenharia;
    Aluno *aluno;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void atualizarEstatisticas();

private slots:
    void on_btn_insert_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
