//
// Created by André Nunes on 13/10/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "evento.h"

void inserirEventoCao(EVENTO arrayEvento[], int *numEventos,int id_cao) {
    EVENTO novo_evento = {};
    novo_evento.id = *numEventos + 1;
    novo_evento.id_cao=id_cao;
    strcpy(novo_evento.acidente," ");
    strcpy(novo_evento.doencas," ");
    strcpy(novo_evento.mudanca_morada," ");
    strcpy(novo_evento.mudanca_dono," ");
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Descrever acidente\n");
        printf("2. Digitar doencas do cao\n");
        printf("3. Digitar nova morada\n");
        printf("4. Digitar novo dono\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Descreva o acidente: ");
                scanf(" %[^\n]", novo_evento.acidente);
                break;
            case 2:
                printf("Digite as doencas do cao: ");
                scanf(" %[^\n]", novo_evento.doencas);
                break;
            case 3:
                printf("Digite a nova morada: ");
                scanf(" %[^\n]", novo_evento.mudanca_morada);
                break;
            case 4:
                printf("Digite o novo dono: ");
                scanf(" %[^\n]", novo_evento.mudanca_dono);
                break;
            case 5:
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    arrayEvento[*numEventos] = novo_evento;
    (*numEventos)++;
    printf("Evento adicionado com sucesso.\n");
}

void listarEventosDeUmCao(EVENTO evento[], int num_evento, int id_cao) {
    for (int i = 0; i < num_evento; i++) {
        if (evento[i].id_cao == id_cao) {
            printf("\t\t___________________________\n");
            printEvento(evento[i]);
        }
    }
}

void printEvento(EVENTO evento) {
    printf("\t\tID do evento: %d\n", evento.id);
    if (strcmp(evento.acidente," ")!=0) {
        printf("\t\tAcidente do cao: %s\n", evento.acidente);
    }
    if (strcmp(evento.doencas," ") != 0) {
        printf("\t\tDoencas do cao: %s\n", evento.doencas);
    }
    if (strcmp(evento.mudanca_morada," ") != 0) {
        printf("\t\tNova morada: %s\n", evento.mudanca_morada);
    }
    if (strcmp(evento.mudanca_dono," ") != 0) {
        printf("\t\tNovo dono: %s\n", evento.mudanca_dono);
    }
}

EVENTO encontrarEventoPorID(EVENTO lista_evento[], int num_evento, int id) {
    EVENTO eventoNaoEncontrado = {};
    for (int i = 0; i < num_evento; i++) {
        if (lista_evento[i].id == id) {
            return lista_evento[i];
        }
    }
    return eventoNaoEncontrado; // Retorna cão vazio se não for encontrado
}
