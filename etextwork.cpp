#include "etextwork.h"
#include <QDir>
#include <QFile>

ETextWork::ETextWork()
{

}

QString ETextWork::getSampleData()
{
    QDir dir;
    while(!dir.absolutePath().endsWith("Qt"))
        dir.cdUp();
    QFile file(dir.absoluteFilePath("QtBasicEnglishApp/data.html"));
    file.open(QIODevice::Text | QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString content = stream.readAll();
    file.close();
    return content;
}

QStringList ETextWork::splitQuestion(const QString& input)
{
    QString key = "<div class='mtq_question mtq_scroll_item-1'";
    QStringList list = input.split(key);
    list.pop_front();
    return list;
}

/*<span style=\"color: #000000;\"><span style=\"color: #000000;\">
What will happen if we __________ water</span></span>?*/

QString ETextWork::correctString(const QString& input2)
{
    QString input(input2);
    int start = input.indexOf('<');
    int end = -1;

    // 1. Get rid of < >
    while(start >= 0){
        end = input.indexOf('>');
        if(end < 0)
            break;
        input.remove(start,end - start + 1);
        qDebug() << input;
        start = input.indexOf('<');
    }

    // 2. Get rid of &nbsp;
    start = input.indexOf("&nbsp;");
    if(start >= 0)
    {
        input.remove(start,6);
    }

    // 3. Trim
    input = input.trimmed();
    return input;
}

QString ETextWork::getQuestion(const QString& input)
{
    QString question = input.split("'mtq_question_text'>")[1].split("</div>")[0];
    question = ETextWork::correctString(question);
    return question;
}

QList<EAnswer> ETextWork::getAnswers(const QString& input)
{
    QList<EAnswer> results;
    QString key = "'mtq_answer_text'>";
    QStringList list = input.split(key);
    for (int i = 1; i < list.count(); ++i) {
        QString s = list[i];

        EAnswer answer;
        answer.setText(s.split("</div>")[0]);
        answer.setIsCorrect(s.contains("mtq_hint_text"));
        if(!answer.isCorrect())
            answer.setHint((s.split("mtq_hint_text")[1]).split("</div>")[0]);

        results.push_back(answer);

        qDebug() << answer.text() <<"\n"<<answer.isCorrect()<<"\n"<<answer.hint()<<"\n";

    }
    return results;
}

QString ETextWork::getExplanation(const QString &input)
{
    QString key = "'mtq_explanation-text'>";
    QString result = (input.split(key)[1]).split("</div>")[0];
    return result.trimmed();
}
