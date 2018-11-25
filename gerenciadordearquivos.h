#ifndef GERENCIADORDEARQUIVOS_H
#define GERENCIADORDEARQUIVOS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <fstream>
#include <QDebug>

#include "turma.h"
#include "aluno.h"


class GerenciadorDeArquivos
{
public:
    GerenciadorDeArquivos();
    static bool salvarTurma(QString &arquivo, Turma &turma);
    static bool carregarTurma(QString &arquivo, Turma &turma);
};

#endif // GERENCIADORDEARQUIVOS_H
