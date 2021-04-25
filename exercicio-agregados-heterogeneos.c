#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[40];
    int idade;
    float altura;
} Pessoa;

void recebePessoas(int n, size_t N, Pessoa pessoas[N]) {
    for(int i = 0; i < n; i++) {
        Pessoa nova_pessoa;
        
        char novo_nome[40] = "";
        
        while(strlen(novo_nome) < 1 || strlen(novo_nome) > 39) {
            printf("\nNome da pessoa %i (ate 40 caracteres sem espacos em branco): ", (i+1));
            scanf("%s", novo_nome);
            if (strlen(novo_nome) > 39) printf("\nNome muito grande!\n");
        }
        
        strcpy(nova_pessoa.nome, novo_nome);
        
        printf("Idade da pessoa %i : ", (i+1));
        scanf("%i", &(nova_pessoa.idade));
        
        printf("Altura da pessoa %i : ", (i+1));
        scanf("%f", &(nova_pessoa.altura));
        
        strcpy(pessoas[i].nome, nova_pessoa.nome);
        pessoas[i].idade = nova_pessoa.idade;
        pessoas[i].altura = nova_pessoa.altura;
        
    }
}

Pessoa pessoa_mais_alta(size_t N, Pessoa pessoas[N]) {
    Pessoa escolhida = pessoas[0];
    for(int i = 1; i < (int)N; i++) {
        if (pessoas[i].altura > escolhida.altura) escolhida = pessoas[i];
    }
    return escolhida;
}

int main() {
    int n;
    printf("Quantas pessoas deseja gravar? : ");
    scanf("%i", &n);
    Pessoa pessoas[n];
    recebePessoas(n, (size_t)n, pessoas);
    Pessoa mais_alta = pessoa_mais_alta((size_t)n, pessoas);
    printf("\nPessoa mais alta: %s (%.2f m)", mais_alta.nome, mais_alta.altura);
}
