#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include "funcionario.h"  // Inclui o arquivo funcionario.h

using namespace std;

class System
{
    private:
    static const string bossuser;
    static const string bossPassword;
    static vector<Func *> Funcs;
    static Func *currentUser;

    static void login();
    static void bossMenu();
    static void addFunc();
    static void listFuncs();
    static void verPonto();
    static void calculaSalario();
    static void funcMenu();
    static void addAtendimento();
    static void mostrarSalario();
    static void addVenda();
    static void listVendas();

public:
    static void run();
};

#endif  // SYSTEM_H
