#include "system.h"       // Inclui o arquivo system.h

// Implementações da classe System


const string System::bossuser = "admin";
const string System::bossPassword = "admin";
vector<Func *> System::Funcs;
Func *System::currentUser = nullptr;

void System::login()
{
    string user, password;
    cout << "Usuário: ";
    cin >> user;
    cout << "Senha: ";
    cin >> password;

    if (user == bossuser && password == bossPassword)
    {
        currentUser = nullptr; // O chefe não é considerado um funcionário regular
        bossMenu();
    }
    else
    {
        for (const auto &Func : Funcs)
        {
            if (Func->getuser() == user && Func->getPassword() == password)
            {
                currentUser = Func;
                funcMenu();
                return;
            }
        }
        cout << "Usuário ou senha inválidos." << endl;
    }
}

void System::bossMenu()
{
    while (true)
    {
        cout << "\n===== MENU DO CHEFE =====" << endl;
        cout << "1. Cadastrar funcionário" << endl;
        cout << "2. Listar funcionários cadastrados" << endl;
        cout << "3. Checar ponto" << endl;
        cout << "4. Cálculo do salário" << endl;
        cout << "5. Retornar à tela inicial" << endl;
        cout << "Escolha uma opção: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addFunc();
            break;
        case 2:
            listFuncs();
            break;
        case 3:
            verPonto();
            break;
        case 4:
            calculaSalario();
            break;
        case 5:
            return;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

void System::addFunc()
{
    string nome, funcao, user, password;
    double horaSalario;
    char FuncType;

    cout << "\n===== CADASTRO DE FUNCIONÁRIO =====" << endl;
    cout << "Nome: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Função: ";
    getline(cin, funcao);
    cout << "Salário por hora: ";
    cin >> horaSalario;
    cout << "Tipo de funcionário (V para vendedor, S para supervisor): ";
    cin >> FuncType;
    cout << "Usuário: ";
    cin >> user;
    cout << "Senha: ";
    cin >> password;

    Func *newFunc;
    if (FuncType == 'V' || FuncType == 'v')
    {
        newFunc = new VendaPessoal(nome, horaSalario, user, password);
    }
    else if (FuncType == 'S' || FuncType == 's')
    {
        newFunc = new Supervisor(nome, horaSalario, user, password);
    }
    else
    {
        cout << "Tipo de funcionário inválido." << endl;
        return;
    }

    Funcs.push_back(newFunc);
    cout << "Funcionário cadastrado com sucesso." << endl;
}

void System::listFuncs()
{
    cout << "\n===== LISTA DE FUNCIONÁRIOS =====" << endl;
    for (const auto &Func : Funcs)
    {
        Func->printDetalhes();
        cout << "-----------------------" << endl;
    }
}

void System::verPonto()
{
    // Implemente a lógica para checar o ponto dos funcionários
    cout << "\nChecar ponto." << endl;
}

void System::calculaSalario()
{
    // Implemente a lógica para calcular o salário com base nas horas trabalhadas e bonificações
    cout << "\nCálculo do salário." << endl;
}

void System::funcMenu()
{
    while (true)
    {
        cout << "\n===== MENU DO FUNCIONÁRIO =====" << endl;
        cout << "1. Cadastrar ponto" << endl;
        cout << "2. Exibir salário" << endl;
        cout << "3. Cadastrar venda" << endl;
        cout << "4. Listar vendas" << endl;
        cout << "5. Retornar à tela inicial" << endl;
        cout << "Escolha uma opção: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addAtendimento();
            break;
        case 2:
            mostrarSalario();
            break;
        case 3:
            addVenda();
            break;
        case 4:
            listVendas();
            break;
        case 5:
            return;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

void System::addAtendimento()
{
    // Implemente a lógica para cadastrar o ponto do funcionário
    cout << "\nCadastrar ponto." << endl;
}

void System::mostrarSalario()
{
    // Implemente a lógica para exibir o salário detalhado do funcionário
    cout << "\nExibir salário." << endl;
}

void System::addVenda()
{
    // Implemente a lógica para cadastrar uma venda do funcionário
    cout << "\nCadastrar venda." << endl;
}

void System::listVendas()
{
    // Implemente a lógica para listar as vendas do funcionário ou de todos os vendedores (no caso de supervisor)
    cout << "\nListar vendas." << endl;
}

void System::run()
{
    currentUser = nullptr;

    while (true)
    {
        cout << "\n===== SISTEMA DE CONTROLE DE FUNCIONÁRIOS =====" << endl;
        cout << "1. Login" << endl;
        cout << "2. Sair do sistema" << endl;
        cout << "Escolha uma opção: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            login();
            break;
        case 2:
            return;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
        }
    }
}

int main()
{
    System::run();
    return 0;
}
