#ifndef ELESSON_H
#define ELESSON_H

#include <QtCore>

class ELesson
{
public:
    ELesson();
    int getId() const;
    void setId(int value);

    QString getText() const;
    void setText(const QString &value);

    QString getUrl() const;
    void setUrl(const QString &value);

private:
    int id;
    QString text;
    QString url;
};

#endif // ELESSON_H
