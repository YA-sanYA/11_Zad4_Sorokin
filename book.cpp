#include "book.h"
#include "publicprintededition.h"

Book::Book(QString new_t, QString new_a, QString new_y)
    : t(new_t), a(new_a), y(new_y), next(nullptr) {}

Book::~Book() {}

Book::BookData Book::getData() const {
    return BookData{t, a, y, "", 0, "Book"};
}

bool Book::Matches(QString mt, QString ma, QString my) const {
    return (mt.isEmpty() || t == mt) &&
           (ma.isEmpty() || a == ma) &&
           (my.isEmpty() || y == my);
}

bool Book::Repl(QString new_t, QString new_a, QString new_y) {
    t = new_t;
    a = new_a;
    y = new_y;
    return true;
}

void Book::Add(Book* obj) {
    if (first)
        tail->next = obj;
    else
        first = obj;
    tail = obj;
    obj->next = nullptr;
}

bool Book::Del(int ind) {
    Book* obj = first;
    Book* prev = nullptr;
    int i = 0;

    while (obj && i < ind) {
        prev = obj;
        obj = obj->next;
        ++i;
    }

    if (!obj) return false;

    if (obj == first) {
        first = obj->next;
        if (obj == tail)
            tail = nullptr;
    } else if (obj == tail) {
        tail = prev;
        if (prev)
            prev->next = nullptr;
    } else {
        if (prev)
            prev->next = obj->next;
    }

    delete obj;
    return true;
}

QVector<Book::BookData> Book::FindDataExtended(QString mt, QString ma, QString my, QString mpubl, QString mp) {
    QVector<BookData> result;
    Book* obj = first;
    while (obj) {
        bool match = false;
        if (auto* printed = dynamic_cast<PublicPrintedEdition*>(obj))
            match = printed->Matches(mt, ma, my, mpubl, mp);
        else
            match = (mpubl.isEmpty() && mp.isEmpty()) ? obj->Matches(mt, ma, my) : false;

        if (match)
            result.append(obj->getData());

        obj = obj->next;
    }
    return result;
}

QVector<Book::BookData> Book::AllData() {
    QVector<BookData> result;
    Book* obj = first;
    while (obj) {
        result.append(obj->getData());
        obj = obj->next;
    }
    return result;
}

Book* Book::getByIndex(int ind) {
    Book* obj = first;
    int i = 0;
    while (obj && i < ind) {
        obj = obj->next;
        ++i;
    }
    return obj;
}

bool Book::ReplaceAt(int index, Book* newObj) {
    if (!first) return false;

    if (index == 0) {
        newObj->next = first->next;
        delete first;
        first = newObj;
        if (!newObj->next) tail = newObj;
        return true;
    }

    Book* prev = first;
    for (int i = 0; i < index - 1 && prev; ++i)
        prev = prev->next;

    if (!prev || !prev->next) return false;

    Book* old = prev->next;
    newObj->next = old->next;
    prev->next = newObj;

    if (!newObj->next) tail = newObj;

    delete old;
    return true;
}


