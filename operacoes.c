//
// Created by André Nunes on 30/10/2023.
//

#include "operacoes.h"
#include <stdio.h>

void escreverCaesNoFicheiro(CAO lista_cao[], int num_cao) {
    FILE *ficheiro;
    ficheiro = fopen(FICHEIRO_CAES_TXT, "w");
    if (ficheiro != NULL) {
        fprintf(ficheiro, "%d\n", num_cao);
        for (int i = 0; i < num_cao; ++i) {
            fprintf(ficheiro, "%d;%d;%s;%d;%d;%d;%s;%s;%s;%s;%s;%s;%d;%d;\n", lista_cao[i].id, lista_cao[i].tipopeso,
                    lista_cao[i].nome, lista_cao[i].peso, lista_cao[i].anos, lista_cao[i].meses, lista_cao[i].genero,
                    lista_cao[i].pelagem, lista_cao[i].cor, lista_cao[i].data_nascimento,
                    lista_cao[i].cidade_nascimento, lista_cao[i].raca, lista_cao[i].id_pai, lista_cao[i].id_mae);
        }
        printf("\n\tFicheiro de caes escrito com sucesso.\n");
        fclose(ficheiro);
    } else {
        printf("Erro ao abrir ficheiro %s\n", FICHEIRO_CAES_TXT);
    }
}

void lerCaesDoFicheiro(CAO lista_cao[], int *num_cao) {
    FILE *ficheiro;
    ficheiro = fopen(FICHEIRO_CAES_TXT, "r");
    int erro = 0;
    if (ficheiro != NULL) {
        int size = 0;
        fscanf(ficheiro, "%d\n", &size);
        (*num_cao) = size;
        for (int i = 0; i < *num_cao; ++i) {
            CAO cao = {};
            fscanf(ficheiro, "%d;%d;%[^;];%d;%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%d;%d;\n", &cao.id,
                   &cao.tipopeso, cao.nome, &cao.peso, &cao.anos, &cao.meses, cao.genero, cao.pelagem, cao.cor,
                   cao.data_nascimento, cao.cidade_nascimento, cao.raca, &cao.id_pai, &cao.id_mae);
            if (encontrarCaoPorID(lista_cao, *num_cao, cao.id).id == 0) {
                lista_cao[i] = cao;
            } else {
                erro++;
                printf("id: %d", cao.id);
                printCao(cao);
            }
        }
        printf("\n\tCaes lidos com sucesso: %d\n", (*num_cao - erro));
        printf("\n\tCaes lidos com erro(id do cao ja existe na base de dados): %d\n", erro);
        fclose(ficheiro);
    } else {
        printf("Erro ao abrir ficheiro %s\n", FICHEIRO_CAES_TXT);
    }
}

void escreverEventosNoFicheiro(EVENTO lista_evento[], int num_evento) {
    FILE *ficheiro;
    ficheiro = fopen(FICHEIRO_EVENTOS_TXT, "w");
    if (ficheiro != NULL) {
        fprintf(ficheiro, "%d\n", num_evento);
        for (int i = 0; i < num_evento; ++i) {
            fprintf(ficheiro, "%d;%s;%s;%s;%s;%d;\n", lista_evento[i].id,
                    lista_evento[i].acidente, lista_evento[i].doencas, lista_evento[i].mudanca_morada,
                    lista_evento[i].mudanca_dono, lista_evento[i].id_cao);
        }
        printf("\n\tFicheiro de eventos escrito com sucesso.\n");
        fclose(ficheiro);
    } else {
        printf("Erro ao abrir ficheiro %s\n", FICHEIRO_EVENTOS_TXT);
    }

}

void lerEventosDoFicheiro(EVENTO lista_evento[], int *num_evento) {
    FILE *ficheiro;
    ficheiro = fopen(FICHEIRO_EVENTOS_TXT, "r");
    int erro = 0;
    if (ficheiro != NULL) {
        int size = 0;
        fscanf(ficheiro, "%d\n", &size);
        (*num_evento) = size;
        for (int i = 0; i < *num_evento; ++i) {
            EVENTO evento = {};
            fscanf(ficheiro, "%d;%[^;];%[^;];%[^;];%[^;];%d;\n", &evento.id, evento.acidente,
                   evento.doencas, evento.mudanca_morada, evento.mudanca_dono, &evento.id_cao);
            if (encontrarEventoPorID(lista_evento, *num_evento, evento.id).id == 0) {
                lista_evento[i] = evento;
            } else {
                erro++;
            }
        }
        printf("\n\tEventos lidos com sucesso: %d\n", (*num_evento - erro));
        printf("\n\tEventos lidos com erro(id do cao ja existe na base de dados): %d\n", erro);
        fclose(ficheiro);
    } else {
        printf("Erro ao abrir ficheiro %s\n", FICHEIRO_EVENTOS_TXT);
    }

}
