#include "gerenciadordearquivos.h"

GerenciadorDeArquivos::GerenciadorDeArquivos()
{

}

bool GerenciadorDeArquivos::salvarTurma(QString &arquivo, Turma &turma)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }

    QTextStream out(&file);

    for(int i=0;i<turma.size();i++){
        out << turma[i].getNome()<<","<<turma[i].getMedia()<<"\n";
    }

    file.close();
    return true;
}

bool GerenciadorDeArquivos::carregarTurma(QString &arquivo, Turma &turma)
{
    QFile file(arquivo);

    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);

    QString linha;

    while(!in.atEnd()){
        linha = in.readLine();

        QStringList dados = linha.split(",");

        Aluno a(dados[0],dados[1].toFloat());
        turma.inserirAluno(a);

    }
    return true;
}
