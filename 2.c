#include <stdio.h>

struct NoDuplo {
    struct NoDuplo *anterior;
    int dado;
    struct NoDuplo *proximo;
};

void buscarComVizinhos(struct NoDuplo *head, int cpf_alvo) {
    while (head != NULL) {
        if (head->dado == cpf_alvo) {
            int ant = head->anterior ? head->anterior->dado : 0;
            int prox = head->proximo ? head->proximo->dado : 0;
            printf("O cidadao %d esta na fila. Na frente dele esta o %d e atras dele esta o %d\n", head->dado, ant, prox);
            return;
        }
        head = head->proximo;
    }
}

int main() {
    struct NoDuplo n1, n2, n3;

    n1.dado = 111;
    n1.anterior = NULL;
    n1.proximo = &n2;

    n2.dado = 222;
    n2.anterior = &n1;
    n2.proximo = &n3;

    n3.dado = 333;
    n3.anterior = &n2;
    n3.proximo = NULL;

    buscarComVizinhos(&n1, 222);

    return 0;
}
