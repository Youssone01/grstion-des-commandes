/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *centralwidget_2;
    QPushButton *Ajouter;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *le_2;
    QLabel *label;
    QPushButton *chercher;
    QLabel *PREN;
    QPushButton *trierbutton;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_paiement;
    QLineEdit *lineEdit_statut;
    QLineEdit *lineEdit_date;
    QPushButton *supprimerbutton;
    QLineEdit *lineEdit_rechercher_id;
    QPushButton *modifierbutton;
    QTableView *tableView;
    QLineEdit *supp;
    QLabel *le_3;
    QPushButton *Afficher;
    QRadioButton *radioButtonASC;
    QRadioButton *radioButtonDESC;
    QPushButton *pdfButton;
    QPushButton *afficherStatistiques;
    QCheckBox *checkboxListe;
    QPushButton *Quitter;
    QLabel *label_stat;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1022, 721);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget_2 = new QWidget(centralwidget);
        centralwidget_2->setObjectName("centralwidget_2");
        centralwidget_2->setGeometry(QRect(0, 0, 1031, 701));
        centralwidget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(162, 109, 159);"));
        Ajouter = new QPushButton(centralwidget_2);
        Ajouter->setObjectName("Ajouter");
        Ajouter->setGeometry(QRect(480, 290, 93, 29));
        Ajouter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        label_4 = new QLabel(centralwidget_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 270, 111, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI Black")});
        font.setPointSize(14);
        font.setBold(true);
        label_4->setFont(font);
        label_6 = new QLabel(centralwidget_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 310, 241, 31));
        label_6->setFont(font);
        label_5 = new QLabel(centralwidget_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 220, 221, 31));
        label_5->setFont(font);
        le_2 = new QLabel(centralwidget_2);
        le_2->setObjectName("le_2");
        le_2->setGeometry(QRect(40, 160, 171, 31));
        le_2->setFont(font);
        label = new QLabel(centralwidget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 30, 371, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Display")});
        font1.setPointSize(36);
        font1.setBold(true);
        label->setFont(font1);
        chercher = new QPushButton(centralwidget_2);
        chercher->setObjectName("chercher");
        chercher->setGeometry(QRect(830, 50, 93, 29));
        chercher->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        PREN = new QLabel(centralwidget_2);
        PREN->setObjectName("PREN");
        PREN->setGeometry(QRect(590, 50, 51, 31));
        PREN->setFont(font);
        trierbutton = new QPushButton(centralwidget_2);
        trierbutton->setObjectName("trierbutton");
        trierbutton->setGeometry(QRect(610, 110, 93, 29));
        trierbutton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        lineEdit_id = new QLineEdit(centralwidget_2);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(290, 160, 141, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setItalic(false);
        lineEdit_id->setFont(font2);
        lineEdit_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        lineEdit_paiement = new QLineEdit(centralwidget_2);
        lineEdit_paiement->setObjectName("lineEdit_paiement");
        lineEdit_paiement->setGeometry(QRect(290, 310, 141, 31));
        lineEdit_paiement->setFont(font2);
        lineEdit_paiement->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        lineEdit_statut = new QLineEdit(centralwidget_2);
        lineEdit_statut->setObjectName("lineEdit_statut");
        lineEdit_statut->setGeometry(QRect(290, 270, 141, 31));
        lineEdit_statut->setFont(font2);
        lineEdit_statut->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        lineEdit_date = new QLineEdit(centralwidget_2);
        lineEdit_date->setObjectName("lineEdit_date");
        lineEdit_date->setGeometry(QRect(290, 220, 141, 31));
        lineEdit_date->setFont(font2);
        lineEdit_date->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        supprimerbutton = new QPushButton(centralwidget_2);
        supprimerbutton->setObjectName("supprimerbutton");
        supprimerbutton->setGeometry(QRect(870, 400, 93, 29));
        supprimerbutton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        lineEdit_rechercher_id = new QLineEdit(centralwidget_2);
        lineEdit_rechercher_id->setObjectName("lineEdit_rechercher_id");
        lineEdit_rechercher_id->setGeometry(QRect(660, 50, 141, 31));
        lineEdit_rechercher_id->setFont(font2);
        lineEdit_rechercher_id->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        modifierbutton = new QPushButton(centralwidget_2);
        modifierbutton->setObjectName("modifierbutton");
        modifierbutton->setGeometry(QRect(480, 250, 93, 29));
        modifierbutton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        tableView = new QTableView(centralwidget_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(630, 190, 331, 192));
        tableView->setStyleSheet(QString::fromUtf8("background-color: rgb(200, 115, 163);"));
        supp = new QLineEdit(centralwidget_2);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(700, 400, 141, 31));
        supp->setFont(font2);
        supp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 11pt \"Segoe UI\";"));
        le_3 = new QLabel(centralwidget_2);
        le_3->setObjectName("le_3");
        le_3->setGeometry(QRect(610, 400, 61, 31));
        le_3->setFont(font);
        Afficher = new QPushButton(centralwidget_2);
        Afficher->setObjectName("Afficher");
        Afficher->setGeometry(QRect(480, 210, 93, 29));
        Afficher->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        radioButtonASC = new QRadioButton(centralwidget_2);
        radioButtonASC->setObjectName("radioButtonASC");
        radioButtonASC->setGeometry(QRect(730, 110, 110, 24));
        radioButtonDESC = new QRadioButton(centralwidget_2);
        radioButtonDESC->setObjectName("radioButtonDESC");
        radioButtonDESC->setGeometry(QRect(850, 110, 110, 24));
        pdfButton = new QPushButton(centralwidget_2);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(30, 380, 249, 29));
        pdfButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        afficherStatistiques = new QPushButton(centralwidget_2);
        afficherStatistiques->setObjectName("afficherStatistiques");
        afficherStatistiques->setGeometry(QRect(30, 420, 249, 29));
        afficherStatistiques->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);"));
        checkboxListe = new QCheckBox(centralwidget_2);
        checkboxListe->setObjectName("checkboxListe");
        checkboxListe->setGeometry(QRect(310, 380, 231, 24));
        Quitter = new QPushButton(centralwidget_2);
        Quitter->setObjectName("Quitter");
        Quitter->setGeometry(QRect(940, 10, 71, 29));
        Quitter->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 119, 178);\n"
""));
        label_stat = new QLabel(centralwidget_2);
        label_stat->setObjectName("label_stat");
        label_stat->setGeometry(QRect(170, 470, 671, 181));
        label_2 = new QLabel(centralwidget_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 30, 81, 51));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/Screenshots/fash.png")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1022, 26));
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
        Ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "mode de paiement :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Date_Commande :", nullptr));
        le_2->setText(QCoreApplication::translate("MainWindow", "Id_commande :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "COMMANDES", nullptr));
        chercher->setText(QCoreApplication::translate("MainWindow", "Chercher", nullptr));
        PREN->setText(QCoreApplication::translate("MainWindow", " ID :", nullptr));
        trierbutton->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        lineEdit_id->setText(QString());
        lineEdit_paiement->setText(QString());
        lineEdit_statut->setText(QString());
        lineEdit_date->setText(QString());
        supprimerbutton->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        lineEdit_rechercher_id->setText(QString());
        modifierbutton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        supp->setText(QString());
        le_3->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        Afficher->setText(QCoreApplication::translate("MainWindow", "Afficher ", nullptr));
        radioButtonASC->setText(QCoreApplication::translate("MainWindow", "Ascendant", nullptr));
        radioButtonDESC->setText(QCoreApplication::translate("MainWindow", "Descendant", nullptr));
        pdfButton->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        afficherStatistiques->setText(QCoreApplication::translate("MainWindow", "Stats", nullptr));
        checkboxListe->setText(QCoreApplication::translate("MainWindow", "Exporter liste des commandes", nullptr));
        Quitter->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        label_stat->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
