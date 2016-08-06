#include "elesson.h"

ELesson::ELesson()
{

}

int ELesson::getId() const
{
    return id;
}

void ELesson::setId(int value)
{
    id = value;
}

QString ELesson::getText() const
{
    return text;
}

void ELesson::setText(const QString &value)
{
    text = value;
}

QString ELesson::getUrl() const
{
    return url;
}

void ELesson::setUrl(const QString &value)
{
    url = value;
}
