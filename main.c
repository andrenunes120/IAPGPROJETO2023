#include <stdio.h>
#include "evento.h"
#include "dog.h"
#include "operacoes.h"

#define MAX_CAO 100
#define MAX_EVENTOS 100


void menu();


int main() {
    menu();

    return 0;
}

void menu() {

    int opcao, id_cao;
    int num_cao = 0; // numero total de caes
    CAO lista_cao[MAX_CAO]; //lista de caes
    int num_eventos = 0; // numero total de eventos
    EVENTO lista_evento[MAX_EVENTOS]; // lista de eventos

    lerCaesDoFicheiro(lista_cao,&num_cao);
    lerEventosDoFicheiro(lista_evento,&num_eventos);
    do {
        printf("\nMenu:\n");
        printf("1. Inserir novo cão\n");
        printf("2. Listagem dos Caes\n");
        printf("3. Adicionar um evento\n");
        printf("4. Criar cao mock\n");
        printf("5. Criar lista caes mock\n");
        printf("6. Pesquisar Cao\n");
        printf("7. Extrair extatisticas\n");
        printf("8. Arvore Genealogica Ascendente\n");
        printf("9. Arvore Genealogica Descendente\n");
        printf("10. Ler informação de ficheiro txt sobre caes e eventos\n");
        printf("11. Escrever informação em ficheiro txt sobre caes e eventos\n");
        printf("12. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserircao(lista_cao, &num_cao);
                break;
            case 2:
                listarcao(lista_cao, num_cao, lista_evento, num_eventos);
                break;
            case 3:
                printf("Digite o id do cao:");
                scanf("%d", &id_cao);
                if (encontrarCaoPorID(lista_cao, num_cao, id_cao).id != 0) {
                    inserirEventoCao(lista_evento, &num_eventos, id_cao);
                } else {
                    printf("\n\tId de cao invalido.\n");
                }
                break;
            case 4:
                criarCaoMock(lista_cao, &num_cao);
                break;
            case 5:
                criarListaCaoMock(lista_cao, &num_cao);
                break;
            case 6:
                pesquisarCao(lista_cao, num_cao);
                break;
            case 7:
                estatisticasCao(num_cao, lista_cao);
                break;
            case 8:
                arvoreGenealogicaAscendente(lista_cao, num_cao);
                break;
            case 9:
                arvoreGenealogicaDescendente(lista_cao, num_cao);
                break;
            case 10:
                lerCaesDoFicheiro(lista_cao,&num_cao);
                lerEventosDoFicheiro(lista_evento,&num_eventos);
                break;
            case 11:
                escreverCaesNoFicheiro(lista_cao,num_cao);
                escreverEventosNoFicheiro(lista_evento,num_eventos);
                break;
            case 12:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 12);
}








