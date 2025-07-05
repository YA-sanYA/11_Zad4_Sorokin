#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicprintededition.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update_Table(const QVector<Book::BookData>& data)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(data.size());

    QStringList head = {"Название", "Автор", "Год издания", "Количество страниц", "Издательство", "Тип"};
    ui->tableWidget->setHorizontalHeaderLabels(head);

    for(int i = 0; i < data.size(); i++)
    {
        const Book::BookData& obj = data[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(obj.title));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(obj.author));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(obj.year));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(!obj.pages.isEmpty() ? obj.pages : "-"));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(!obj.publisher.isEmpty() ? obj.publisher : "-"));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(obj.type));
    }
    auto* header = ui->tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableWidget->resizeColumnsToContents();
    header->setStretchLastSection(true);
}


void MainWindow::on_AddButton_clicked()
{
    QString title = ui->NamelineEdit->text().trimmed();
    QString author = ui->AuthorlineEdit->text().trimmed();
    QString year = ui->YearlineEdit->text().trimmed();
    QString publisher = ui->PublisherlineEdit->text().trimmed();
    QString pages = ui->PagelineEdit->text().trimmed().trimmed();

    if(title.isEmpty() || author.isEmpty() || year.isEmpty() || (publisher.isEmpty() ^ (pages.isEmpty())))
    {
        //!
        return;
    }

    if (publisher.isEmpty() || pages.isEmpty()) {
        Book* obj = new Book(title, author, year);
        Book::Add(obj);
    } else {
        PublicPrintedEdition* obj = new PublicPrintedEdition(title, author, year, publisher, pages);
        Book::Add(obj);
    }

    Update_Table(Book::AllData());

    ui->NamelineEdit->clear();
    ui->AuthorlineEdit->clear();
    ui->YearlineEdit->clear();
    ui->PagelineEdit->clear();
    ui->PublisherlineEdit->clear();
}



void MainWindow::on_DeleteButton_clicked()
{
    int ind = ui->IndexlineEdit->text().trimmed().toInt();
    if(!Book::Del(ind - 1))
    {
        //!
    }
    Update_Table(Book::AllData());
    ui->IndexlineEdit->clear();
}


void MainWindow::on_ReplaceButton_clicked()
{
    int ind = ui->IndexlineEdit->text().trimmed().toInt();
    QString title = ui->NamelineEdit->text().trimmed();
    QString author = ui->AuthorlineEdit->text().trimmed();
    QString year = ui->YearlineEdit->text().trimmed();
    QString publisher = ui->PublisherlineEdit->text().trimmed();
    QString pages = ui->PagelineEdit->text().trimmed().trimmed();

    if (Book::getByIndex(ind - 1)->getData().type == "Book" && (publisher.isEmpty() || pages.isEmpty())) {
        Book* obj = new Book(title, author, year);
        if(Book::ReplaceAt(ind - 1, obj))
        {
            //!
        }
    } else {
        PublicPrintedEdition* obj = new PublicPrintedEdition(title, author, year, publisher, pages);
        if(Book::ReplaceAt(ind - 1, obj))
        {
            //!
        }
    }

    Update_Table(Book::AllData());

    ui->IndexlineEdit->clear();
    ui->NamelineEdit->clear();
    ui->AuthorlineEdit->clear();
    ui->YearlineEdit->clear();
    ui->PagelineEdit->clear();
    ui->PublisherlineEdit->clear();
}


void MainWindow::on_FindButton_clicked()
{
    QString title = ui->NamelineEdit->text().trimmed();
    QString author = ui->AuthorlineEdit->text().trimmed();
    QString year = ui->YearlineEdit->text().trimmed();
    QString publisher = ui->PublisherlineEdit->text().trimmed();
    QString pages = ui->PagelineEdit->text().trimmed().trimmed();

    Update_Table(Book::FindDataExtended(title, author, year, publisher, pages));

    ui->NamelineEdit->clear();
    ui->AuthorlineEdit->clear();
    ui->YearlineEdit->clear();
    ui->PagelineEdit->clear();
    ui->PublisherlineEdit->clear();
}


void MainWindow::on_ShowButton_clicked()
{
    Update_Table(Book::AllData());
}


void MainWindow::on_LoadButton_clicked()
{

}


void MainWindow::on_InfoButton_clicked()
{
    QString info =
        "Программа управления списком книг и печатных изданий\n\n"
        "Функциональность:\n"
        "1. Добавление объекта\n"
        "   • Введите название, автора, год издания.\n"
        "   • Для печатных изданий также укажите издательство и количество страниц.\n"
        "   • Нажмите \"Добавить\".\n\n"

        "2. Удаление объекта\n"
        "   • Введите номер объекта (с 1).\n"
        "   • Нажмите \"Удалить\".\n\n"

        "3. Замена объекта\n"
        "   • Введите номер объекта, который хотите заменить.\n"
        "   • Заполните поля новыми значениями.\n"
        "   • Можно заменить книгу на печатное издание и наоборот.\n"
        "   • Нажмите \"Заменить\".\n\n"

        "4. Поиск объектов\n"
        "   • Укажите любые из следующих полей: название, автор, год издания,\n"
        "     издательство, количество страниц.\n"
        "   • Оставьте неиспользуемые поля пустыми.\n"
        "   • Нажмите \"Поиск\".\n\n"

        "5. Показать все\n"
        "   • Нажмите \"Показать все\", чтобы вывести весь список книг и изданий.\n\n"

        "6. Выход\n"
        "   • Нажмите \"Выход\" для закрытия программы.\n\n"

        "Примечания:\n"
        "• Нумерация объектов начинается с 1 (как указано в поле \"Номер\").\n"
        "• После каждой операции таблица обновляется автоматически.\n";

    QMessageBox::information(this, "Справка", info);
}


void MainWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}
