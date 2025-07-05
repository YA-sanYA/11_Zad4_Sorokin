#ifndef PUBLICPRINTEDEDITION_H
#define PUBLICPRINTEDEDITION_H

#include "book.h"

class PublicPrintedEdition : public Book {
private:
    QString publ;
    QString p;

public:
    virtual BookData getData() const override;
    PublicPrintedEdition(QString t, QString a, QString y, QString publ, QString p);

    bool Matches(QString mt, QString ma, QString my) const override;
    bool Matches(QString mt, QString ma, QString my, QString mpubl, QString mp) const;
    bool Repl(QString new_t, QString new_a, QString new_y) override;
    bool Repl(QString new_t, QString new_a, QString new_y, QString new_publ, QString new_p);
};

#endif // PUBLICPRINTEDEDITION_H
