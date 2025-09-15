#include <iostream>
#include <cstring>

class Conta {

    char cliente[100];
    int numero;
    float saldo;

    public:

    Conta(const char* nome, int num, float sal) {

        strncpy(cliente, nome, 99);
        cliente[99] = '\0';
        numero = num;
        saldo = sal;
    }


    void mostrarConta(Conta c) {
        printf("-----------------\n"
                     "Cliente: %s\n"
                     "Conta: %d\n"
                     "Saldo: R$ %.2f\n"
                     "-----------------\n",c.cliente, c.numero, c.saldo);
    };

    void creditar(Conta *c, float valor) {
        c->saldo += valor;
        printf("Creditado R$ %.2f, novo saldo: %.2f\n",valor, c->saldo);
    };

    void debitar(Conta *c, float valor) {
        if (valor <= c->saldo) {
            c->saldo -= valor;
            printf("Saldo debitado R$ %.2f, novo saldo: R$ %.2f\n", valor, c->saldo);
        } else {
            printf("Saldo insuficiente, seu saldo é R$ %.2f\n", c->saldo);
        }
    };

};

int main() {

    Conta cliente1("falono",1001,1480);

    cliente1.creditar(&cliente1,1500);



}