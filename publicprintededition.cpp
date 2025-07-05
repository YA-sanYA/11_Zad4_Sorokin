#include "publicprintededition.h"

PublicPrintedEdition::PublicPrintedEdition(QString t, QString a, QString y, QString publ_, QString p_)
    : Book(t, a, y), publ(publ_), p(p_) {}

Book::BookData PublicPrintedEdition::getData() const {
    return BookData{t, a, y, publ, p, "PublicPrintedEdition"};
}

bool PublicPrintedEdition::Matches(QString mt, QString ma, QString my) const {
    return Book::Matches(mt, ma, my);
}

bool PublicPrintedEdition::Matches(QString mt, QString ma, QString my, QString mpubl, QString mp) const {
    return Matches(mt, ma, my) &&
           (mpubl.isEmpty() || publ == mpubl) &&
           (mp.isEmpty() || p == mp);
}

bool PublicPrintedEdition::Repl(QString new_t, QString new_a, QString new_y) {
    return Book::Repl(new_t, new_a, new_y);
}

bool PublicPrintedEdition::Repl(QString new_t, QString new_a, QString new_y, QString new_publ, QString new_p) {
    Book::Repl(new_t, new_a, new_y);
    publ = new_publ;
    p = new_p;
    return true;
}
