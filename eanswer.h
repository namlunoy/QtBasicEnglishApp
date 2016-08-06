#ifndef EANSWER_H
#define EANSWER_H

#include <QtCore>

class EAnswer
{
public:
    EAnswer();

    QString text() const;
    void setText(const QString &text);

    bool isCorrect() const;
    void setIsCorrect(bool isCorrect);

    QString hint() const;
    void setHint(const QString &hint);

    int getId() const;
    void setId(int value);

    int getId_quest() const;
    void setId_quest(int value);

    QString toString();
private:
    int id;
    int id_quest;
    QString m_text;
    bool m_isCorrect;
    QString m_hint;

};

#endif // EANSWER_H

