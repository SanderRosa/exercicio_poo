#include <stdio.h>

typedef struct {
    char cliente[50];
    int numero;
    float saldo;
}Conta;

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

int main() {
    Conta c1 = {"Fulano", 1001, 1480.54};
    Conta c2 = {"Ciclano", 1002, 1460.54};
    mostrarConta(c1);
    mostrarConta(c2);
    debitar(&c2, 5000);
    creditar(&c1, 400);
    mostrarConta(c1);


}