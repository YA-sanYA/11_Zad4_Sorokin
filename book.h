#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <QVector>

class Book {
protected:
    QString t, a, y;

private:
    static inline Book* first = nullptr;
    static inline Book* tail = nullptr;
    Book* next = nullptr;

public:
    struct BookData {
        QString title;
        QString author;
        QString year;
        QString publisher;
        QString pages;
        QString type;
    };
    Book(QString new_t, QString new_a, QString new_y);
    virtual ~Book();

    virtual bool Matches(QString mt, QString ma, QString my) const;
    virtual bool Repl(QString new_t, QString new_a, QString new_y);
    virtual void Replace(Book* old);

    static void Add(Book* obj);
    static bool Del(int ind);
    static QVector<BookData> FindDataExtended(QString mt = "", QString ma = "", QString my = "", QString mpubl = "", QString mp = "");
    static QVector<BookData> AllData();
    static Book* getByIndex(int ind);
    virtual BookData getData() const;
    static bool ReplaceAt(int index, Book* newObj);
    static void Clear();
};

#endif // BOOK_H
