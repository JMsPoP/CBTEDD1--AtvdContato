#include <iostream>
#include <string>
#include <locale.h>
using namespace std;

// classe Data
class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    // construtor
    Data(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), ano(a) {}

    int getDia() const { return dia; }
    void setDia(int d) { dia = d; }

    int getMes() const { return mes; }
    void setMes(int m) { mes = m; }

    int getAno() const { return ano; }
    void setAno(int a) { ano = a; }
};

// classe Contato
class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    // construtor
    Contato(const string& e = "", const string& n = "", const string& tel = "", const Data& data = Data()) : email(e), nome(n), telefone(tel), dtnasc(data) {}

    string getEmail() const { return email; }
    void setEmail(const string& e) { email = e; }

    string getNome() const { return nome; }
    void setNome(const string& n) { nome = n; }

    string getTelefone() const { return telefone; }
    void setTelefone(const string& tel) { telefone = tel; }

    Data getDataNascimento() const { return dtnasc; }
    void setDataNascimento(const Data& data) { dtnasc = data; }

    // calcular a idade
    int idade() const {
        setlocale(LC_ALL, "pt_BR.utf8");
        int anoAtual = 2024;

        return anoAtual - dtnasc.getAno();
    }

    // exibir os dados do contato
    void exibirContato() const {
        cout << "| Nome: " << nome << endl;
        cout << "| E-mail: " << email << endl;
        cout << "| Telefone: " << telefone << endl;
        cout << "| Idade: " << idade() << endl;
        cout << "---------------------" << endl;
    }

    // método para inserir os dados do contato
    void inserirContato() {
        cout << "Digite o nome: ";
        getline(cin, nome);

        cout << "Digite o e-mail: ";
        getline(cin, email);

        cout << "Digite o telefone: ";
        getline(cin, telefone);

        int dia, mes, ano;
        cout << "Digite a data de nascimento (DD MM AAAA): ";
        cin >> dia >> mes >> ano;
        cin.ignore();
        Data dataNascimento(dia, mes, ano);
        setDataNascimento(dataNascimento);
    }
};

int main() {
    Contato contatos[5];


    for (int i = 0; i < 5; i++) {
        cout << "Digite os dados do contato " << i + 1 << ":" << endl;
        contatos[i].inserirContato();
        cout << endl;
    }


    for (int i = 0; i < 5; i++) {
        cout << "---------------------" << endl;
        cout << "| Contato " << i + 1 << endl;
        cout << "---------------------" << endl;
        contatos[i].exibirContato();
    }

    return 0;
}
