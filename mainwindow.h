#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddButton_clicked();

    void on_DeleteButton_clicked();

    void on_ReplaceButton_clicked();

    void on_FindButton_clicked();

    void on_ShowButton_clicked();

    void on_LoadButton_clicked();

    void on_ClearButton_clicked();

    void on_InfoButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
    void Update_Table(const QVector<Book::BookData>&);
};
#endif // MAINWINDOW_H
