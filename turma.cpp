#include "turma.h"

Turma::Turma(QObject *parent) : QObject(parent)
{

}

void Turma::inserirAluno(const Aluno a)
{
    turma.push_back(a);
}

float Turma::mediaDaTurma()
{
    return std::accumulate(turma.begin(),turma.end(),0.0, [](float acc, Aluno a){return acc+=a.getMedia();})/turma.size();
}

float Turma::maiorNota()
{
    Aluno *maior = std::max_element(turma.begin(),turma.end(),[](Aluno a, Aluno b){ return a.getMedia() < b.getMedia();});
    return maior->getMedia();
}

float Turma::menorNota()
{
    Aluno *menor = std::min_element(turma.begin(),turma.end(),[](Aluno a, Aluno b){return a.getMedia() < b.getMedia();});
    return menor->getMedia();
}

void Turma::ordenarPorNome()
{
    std::sort(turma.begin(), turma.end(), [](Aluno a, Aluno b){return a.getNome()<b.getNome();});
}

void Turma::ordenarPorMedia()
{
    ordenarPorNome();
    std::stable_sort(turma.begin(),turma.end(),[](Aluno a, Aluno b){return a.getMedia()<b.getMedia();});
}

int Turma::size()
{
    return turma.size();
}

Aluno Turma::operator[](int i)
{
    return turma[i];
}
