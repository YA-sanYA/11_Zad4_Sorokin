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

void Book::Replace(Book* old) {
    if (t.isEmpty()) t = old->t;
    if (a.isEmpty()) a = old->a;
    if (y.isEmpty()) y = old->y;
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

    Book* prev = nullptr;
    Book* old = first;
    for (int i = 0; i < index && old; ++i) {
        prev = old;
        old = old->next;
    }

    if (!old) return false;

    newObj->Replace(old);
    newObj->next = old->next;

    if (!prev) {
        first = newObj;
    } else {
        prev->next = newObj;
    }

    if (!newObj->next) tail = newObj;

    delete old;
    return true;
}

void Book::Clear() {
    Book* current = first;
    while (current) {
        Book* next = current->next;
        delete current;
        current = next;
    }
    first = nullptr;
    tail = nullptr;
}
