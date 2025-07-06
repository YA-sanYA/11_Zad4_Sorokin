#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "publicprintededition.h"
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression rx("\\d*");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->IndexlineEdit->setValidator(validator);
    ui->YearlineEdit->setValidator(validator);
    ui->PagelineEdit->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Update_Table(const QVector<Book::BookData>& data)
{
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(data.size());

    QStringList head = {"Название", "Автор", "Год издания", "Количество страниц", "Издательство"};
    ui->tableWidget->setHorizontalHeaderLabels(head);

    for(int i = 0; i < data.size(); i++)
    {
        const Book::BookData& obj = data[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(obj.title));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(obj.author));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(obj.year));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(!obj.pages.isEmpty() ? obj.pages : "-"));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(!obj.publisher.isEmpty() ? obj.publisher : "-"));
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
    QString pages = ui->PagelineEdit->text().trimmed();

    if(title.isEmpty() || author.isEmpty() || year.isEmpty() || (publisher.isEmpty() ^ (pages.isEmpty())))
    {
        QMessageBox::warning(this, "Ошибка ввода", "Пожалуйста, заполните все обязательные поля.\n"
                                                   "Для книги: название, автор, год издания.\n"
                                                   "Для издания: также издательство и количество страниц.");
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
        QMessageBox::warning(this, "Удаление", "Объект с указанным номером не найден.");
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
    QString pages = ui->PagelineEdit->text().trimmed();

    Book* old = Book::getByIndex(ind - 1);
    if (!old) {
        QMessageBox::warning(this, "Замена", "Объект с указанным номером не найден.");
        ui->IndexlineEdit->clear();
        return;
    }

    if (Book::getByIndex(ind - 1)->getData().type == "Book" && (publisher.isEmpty() || pages.isEmpty())) {
        if(publisher.isEmpty() ^ pages.isEmpty())
        {
            QMessageBox::warning(this, "Замена", "Нельзя заменить книгу на издание без всех полей.");
            return;
        }
        Book* obj = new Book(title, author, year);
        if(!Book::ReplaceAt(ind - 1, obj))
        {
            QMessageBox::information(this, "Замена", "Неудалось заменить книгу");
        }
    } else {
        PublicPrintedEdition* obj = new PublicPrintedEdition(title, author, year, publisher, pages);
        if(!Book::ReplaceAt(ind - 1, obj))
        {
            QMessageBox::information(this, "Замена", "Неудалось заменить книгу");
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
    QString pages = ui->PagelineEdit->text().trimmed();

    QVector<Book::BookData> data = Book::FindDataExtended(title, author, year, publisher, pages);

    if(data.size() != 0)
    {
        Update_Table(data);
    }
    else
    {
        QMessageBox::information(this, "Результат поиска", "Ни одного объекта не найдено по заданным критериям.");
    }

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
    Book::Clear();
    QFile input("input.txt");
    if(input.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&input);
        QString line = in.readLine().trimmed();
        int count = line.toInt();
        while(count--)
        {
            line = in.readLine().trimmed();
            QStringList parts = line.split(';');

            QString title = parts[1];
            QString author = parts[2];
            QString year = parts[3];
            QString publisher;
            QString pages;

            if(parts[0] == "PublicPrintedEdition")
            {
                publisher = parts[4];
                pages = parts[5];
            }

            if(title.isEmpty() || author.isEmpty() || year.isEmpty() || (publisher.isEmpty() ^ (pages.isEmpty())))
            {
                QMessageBox::warning(this, "Ошибка загрузки", "Некорректные данные в файле. Проверьте формат.");
                return;
            }

            if (publisher.isEmpty() || pages.isEmpty()) {
                Book* obj = new Book(title, author, year);
                Book::Add(obj);
            } else {
                PublicPrintedEdition* obj = new PublicPrintedEdition(title, author, year, publisher, pages);
                Book::Add(obj);
            }
        }
    }
    else
    {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл input.txt для чтения.");
        return;
    }
    Update_Table(Book::AllData());
}


void MainWindow::on_ClearButton_clicked()
{
    Book::Clear();
    ui->IndexlineEdit->clear();
    ui->NamelineEdit->clear();
    ui->AuthorlineEdit->clear();
    ui->YearlineEdit->clear();
    ui->PagelineEdit->clear();
    ui->PublisherlineEdit->clear();
    Update_Table(Book::AllData());
}


void MainWindow::on_InfoButton_clicked()
{
    QString info =
        "Программа управления списком книг и печатных изданий\n\n"
        "Функции:\n"
        "   Добавление объекта:\n"
        "  • Укажите название, автора и год издания.\n"
        "  • Для издания дополнительно введите издательство и количество страниц.\n"
        "  • Если заполнены только частично — появится предупреждение.\n\n"

        "   Удаление:\n"
        "  • Введите номер объекта (с 1) и нажмите \"Удалить\".\n"
        "  • При ошибке появится предупреждение.\n\n"

        "   Замена:\n"
        "  • Введите номер заменяемого объекта.\n"
        "  • Укажите любые новые данные. Пустые поля сохранят старые значения.\n"
        "  • Можно заменить книгу на издание и наоборот.\n\n"

        "   Поиск:\n"
        "  • Укажите любое сочетание полей.\n"
        "  • Если не найдено — будет сообщение.\n\n"

        "   Показать все:\n"
        "  • Показывает весь текущий список объектов.\n\n"

        "   Загрузка из файла:\n"
        "  • Файл \"input.txt\" должен содержать количество объектов и список:\n"
        "    Book;Название;Автор;Год\n"
        "    PublicPrintedEdition;Название;Автор;Год;Издательство;Страницы\n"
        "  • Загруженные данные заменяют текущие.\n\n"

        "   Очистка:\n"
        "  • Полностью очищает список объектов.\n\n"

        "   Выход:\n"
        "  • Завершает работу программы.\n\n"
        "   Все действия автоматически обновляют таблицу.";

    QMessageBox::information(this, "Справка", info);
}

void MainWindow::on_ExitButton_clicked()
{
    QApplication::quit();
}
