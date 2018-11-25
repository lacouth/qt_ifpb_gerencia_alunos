#ifndef TURMA_H
#define TURMA_H

#include <QObject>
#include <QVector>
#include <numeric>
#include <algorithm>

#include "aluno.h"

class Turma : public QObject
{
    Q_OBJECT
private:
    QVector<Aluno> turma;

public:
    explicit Turma(QObject *parent = nullptr);
    void inserirAluno(const Aluno a);
    float mediaDaTurma();
    float maiorNota();
    float menorNota();
    void ordenarPorNome();
    void ordenarPorMedia();

    int size();

    Aluno operator[](int i);


signals:

public slots:
};

#endif // TURMA_H
