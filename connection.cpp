#include "connection.h"


connection::Connection(){

}

bool connection::createconnect(){
    bool test=false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_CPP");
    db.setUserName("yassine");
    db.setPassword("esprit18");

    if (db.open())
        test=true;

    return test;

}

void connection::closeconnection(){db.close();}
