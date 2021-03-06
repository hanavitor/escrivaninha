#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct endereco{
    char rua[100];
    char num[50];
}tEndereco;

typedef struct pessoa{
    char nome[100];
    char telefone[50];
    tEndereco endereco;
}tPessoa;

int main (){
    
    tPessoa lista[MAX];
    FILE *fp;
    fp = fopen("dadoslegivel.txt", "w");

    if(fp<0){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    for(int i = 0; i<MAX; i++){
        printf("Digite o nome: ");
        fgets(lista[i].nome, 100, stdin);
        lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
        printf("Digite o telefone: ");
        fgets(lista[i].telefone, 50, stdin);
        lista[i].telefone[strcspn(lista[i].telefone, "\n")] = 0;
        printf("Digite a rua: ");
        fgets(lista[i].endereco.rua, 100, stdin);
        lista[i].endereco.rua[strcspn(lista[i].endereco.rua, "\n")] = 0;
        printf("Digite o numero: ");
        fgets(lista[i].endereco.num, 50, stdin);
        lista[i].endereco.num[strcspn(lista[i].endereco.num, "\n")] = 0;
    }

    printf("Lista das pessoas:\n");
    for(int i = 0; i<MAX;i++){
        printf("Nome: %s\n", lista[i].nome);
        printf("Telefone: %s\n", lista[i].telefone);
        printf("Rua: %s\n", lista[i].endereco.rua);
        printf("Numuro: %s\n", lista[i].endereco.num);
        fprintf(fp, "%s\n", lista[i].nome);
        fprintf(fp, "%s\n", lista[i].telefone);
        fprintf(fp, "%s\n", lista[i].endereco.rua);
        fprintf(fp, "%s\n", lista[i].endereco.num);
    }
        

    return 0;
}
