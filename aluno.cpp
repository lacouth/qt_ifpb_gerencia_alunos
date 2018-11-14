#include "aluno.h"

QString Aluno::getNome() const
{
    return nome;
}

void Aluno::setNome(const QString &value)
{
    nome = value;
}

float Aluno::getMedia() const
{
    return media;
}

void Aluno::setMedia(float value)
{
    media = value;
}

QString Aluno::getStatus() const
{
    return media >= MEDIA ? "Aprovado" : "Reprovado";
}

Aluno::Aluno()
{

}
