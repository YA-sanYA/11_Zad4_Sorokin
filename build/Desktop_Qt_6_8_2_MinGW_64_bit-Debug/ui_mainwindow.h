/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *IndexlineEdit;
    QLabel *label_2;
    QLineEdit *NamelineEdit;
    QLabel *label_3;
    QLineEdit *AuthorlineEdit;
    QLabel *label_4;
    QLineEdit *YearlineEdit;
    QLabel *label_5;
    QLineEdit *PagelineEdit;
    QLabel *label_6;
    QLineEdit *PublisherlineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *ShowButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ReplaceButton;
    QPushButton *FindButton;
    QPushButton *LoadButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *InfoButton;
    QPushButton *ExitButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout_4->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label);

        IndexlineEdit = new QLineEdit(centralwidget);
        IndexlineEdit->setObjectName("IndexlineEdit");
        IndexlineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(IndexlineEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label_2);

        NamelineEdit = new QLineEdit(centralwidget);
        NamelineEdit->setObjectName("NamelineEdit");
        NamelineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(NamelineEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label_3);

        AuthorlineEdit = new QLineEdit(centralwidget);
        AuthorlineEdit->setObjectName("AuthorlineEdit");
        AuthorlineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(AuthorlineEdit);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label_4);

        YearlineEdit = new QLineEdit(centralwidget);
        YearlineEdit->setObjectName("YearlineEdit");
        YearlineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(YearlineEdit);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label_5);

        PagelineEdit = new QLineEdit(centralwidget);
        PagelineEdit->setObjectName("PagelineEdit");
        PagelineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(PagelineEdit);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setMaximumSize(QSize(239, 20));

        verticalLayout->addWidget(label_6);

        PublisherlineEdit = new QLineEdit(centralwidget);
        PublisherlineEdit->setObjectName("PublisherlineEdit");
        PublisherlineEdit->setMaximumSize(QSize(239, 28));

        verticalLayout->addWidget(PublisherlineEdit);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(centralwidget);
        DeleteButton->setObjectName("DeleteButton");

        horizontalLayout->addWidget(DeleteButton);

        ShowButton = new QPushButton(centralwidget);
        ShowButton->setObjectName("ShowButton");

        horizontalLayout->addWidget(ShowButton);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        ReplaceButton = new QPushButton(centralwidget);
        ReplaceButton->setObjectName("ReplaceButton");

        horizontalLayout_2->addWidget(ReplaceButton);

        FindButton = new QPushButton(centralwidget);
        FindButton->setObjectName("FindButton");

        horizontalLayout_2->addWidget(FindButton);

        LoadButton = new QPushButton(centralwidget);
        LoadButton->setObjectName("LoadButton");

        horizontalLayout_2->addWidget(LoadButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        InfoButton = new QPushButton(centralwidget);
        InfoButton->setObjectName("InfoButton");

        horizontalLayout_3->addWidget(InfoButton);

        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName("ExitButton");

        horizontalLayout_3->addWidget(ExitButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\264\320\265\320\272\321\201", nullptr));
        IndexlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \321\202\320\276\320\273\321\214\320\272\320\276 \320\264\320\273\321\217 \321\203\320\264\320\260\320\273\320\265\320\275\320\270\321\217 \320\270 \320\267\320\260\320\274\320\265\320\275\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\270", nullptr));
        NamelineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\264\320\273\321\217 \320\272\320\275\320\270\320\263 \320\270 \320\277\320\265\321\207\320\260\321\202\320\275\321\213\321\205 \320\270\320\267\320\264\320\260\320\275\320\270\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200 \320\272\320\275\320\270\320\263\320\270", nullptr));
        AuthorlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\264\320\273\321\217 \320\272\320\275\320\270\320\263 \320\270 \320\277\320\265\321\207\320\260\321\202\320\275\321\213\321\205 \320\270\320\267\320\264\320\260\320\275\320\270\320\271", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        YearlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\264\320\273\321\217 \320\272\320\275\320\270\320\263 \320\270 \320\277\320\265\321\207\320\260\321\202\320\275\321\213\321\205 \320\270\320\267\320\264\320\260\320\275\320\270\320\271", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        PagelineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\264\320\273\321\217 \320\277\320\265\321\207\320\260\321\202\320\275\321\213\321\205 \320\270\320\267\320\264\320\260\320\275\320\270\320\271", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\264\320\260\321\202\320\265\320\273\321\214\321\201\321\202\320\262\320\276", nullptr));
        PublisherlineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\264\320\273\321\217 \320\277\320\265\321\207\320\260\321\202\320\275\321\213\321\205 \320\270\320\267\320\264\320\260\320\275\320\270\320\271", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        ShowButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\262\321\201\321\221", nullptr));
        ReplaceButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        FindButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        LoadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        InfoButton->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
