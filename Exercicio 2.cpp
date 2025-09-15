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

    
    const char* getCliente() {
        return cliente;
    }

    int getNumero() {
        return numero;
    }

    float getSaldo() {
        return saldo;
    }

    void creditar(float valor) {
        saldo += valor;
        printf("Creditado R$ %.2f, novo saldo: R$ %.2f\n", valor, saldo);
    }

    void debitar(float valor) {
        if (valor <= saldo) {
            saldo -= valor;
            printf("Debitado R$ %.2f, novo saldo: R$ %.2f\n", valor, saldo);
        } else {
            printf("Saldo insuficiente, seu saldo é R$ %.2f\n", saldo);
        }
    }

};

void mostrarConta(Conta& c) {
    printf("-----------------\n"
           "Cliente: %s\n"
           "Conta: %d\n"
           "Saldo: R$ %.2f\n"
           "-----------------\n", c.getCliente(), c.getNumero(), c.getSaldo());
}

int main() {

    Conta cliente1("falono", 1001, 1480);
    mostrarConta(cliente1);

    cliente1.creditar(1500);

    mostrarConta(cliente1);
}
