#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Func
{
protected:
    string nome;
    string funcao;
    double horaSalario;
    string user;
    string password;

public:
    Func(const string &nome, const string &funcao, double horaSalario, const string &user, const string &password)
        : nome(nome), funcao(funcao), horaSalario(horaSalario), user(user), password(password) {}

    virtual ~Func() {}

    const string &getnome() const
    {
        return nome;
    }

    const string &getfuncao() const
    {
        return funcao;
    }

    double gethoraSalario() const
    {
        return horaSalario;
    }

    const string &getuser() const
    {
        return user;
    }

    const string &getPassword() const
    {
        return password;
    }

    virtual void printDetalhes() const = 0;
};

class VendaPessoal : public Func
{
private:
    double vendas;
    double bonusPorcentagem;

public:
    VendaPessoal(const string &nome, double horaSalario, const string &user, const string &password)
        : Func(nome, "Vendedor", horaSalario, user, password), vendas(0), bonusPorcentagem(0.1) {}

    double getVendas() const
    {
        return vendas;
    }

    void setvendas(double vendas)
    {
        this->vendas = vendas;
    }

    double getBonus() const
    {
        return vendas * bonusPorcentagem;
    }

    void printDetalhes() const override
    {
        cout << "Nome: " << nome << endl;
        cout << "Função: " << funcao << endl;
        cout << "Salário por hora: " << horaSalario << endl;
        cout << "Usuário: " << user << endl;
        cout << "Senha: " << password << endl;
        cout << "Vendas: " << vendas << endl;
        cout << "Bonificação: " << getBonus() << endl;
    }
};

class Supervisor : public Func
{
private:
    vector<VendaPessoal *> vendaPessoal;
    double bonusPorcentagem;

public:
    Supervisor(const string &nome, double horaSalario, const string &user, const string &password)
        : Func(nome, "Supervisor", horaSalario, user, password), bonusPorcentagem(0.01) {}

    void addVendaPessoal(VendaPessoal *VendaPessoal)
    {
        vendaPessoal.push_back(VendaPessoal);
    }

    double getTotalVendas() const
    {
        double vendasTotal = 0;
        for (const auto &VendaPessoal : vendaPessoal)
        {
            vendasTotal += VendaPessoal->getVendas();
        }
        return vendasTotal;
    }

    double getBonus() const
    {
        return getTotalVendas() * bonusPorcentagem;
    }

    void printDetalhes() const override
    {
        cout << "Nome: " << nome << endl;
        cout << "Função: " << funcao << endl;
        cout << "Salário por hora: " << horaSalario << endl;
        cout << "Usuário: " << user << endl;
        cout << "Senha: " << password << endl;
        cout << "Total de vendas: " << getTotalVendas() << endl;
        cout << "Bonificação: " << getBonus() << endl;
    }
};