#ifndef ALUNO_H
#define ALUNO_H

#include <QObject>

#define MEDIA 70

class Aluno
{

private:
    QString nome;
    float media;
    bool status;

public:
    explicit Aluno();

    QString getNome() const;
    void setNome(const QString &value);

    float getMedia() const;
    void setMedia(float value);

    QString getStatus() const;


signals:

public slots:
};

#endif // ALUNO_H
