//
// Created by André Nunes on 13/10/2023.
//

#ifndef PROJETOIAPG202324_EVENTO_H
#define PROJETOIAPG202324_EVENTO_H
#define CHAR_MAX_LENGTH 100

typedef struct Evento {
    int id;
    int id_cao;
    char acidente[CHAR_MAX_LENGTH];
    char doencas[CHAR_MAX_LENGTH];
    char mudanca_morada[CHAR_MAX_LENGTH];
    char mudanca_dono[CHAR_MAX_LENGTH];
} EVENTO;

void inserirEventoCao(EVENTO arrayEvento[], int *numEventos,int id_cao);

void listarEventosDeUmCao(EVENTO evento[], int num_evento, int id_cao);

void printEvento(EVENTO evento);

EVENTO encontrarEventoPorID(EVENTO lista_evento[], int num_evento, int id);

#endif //PROJETOIAPG202324_EVENTO_H
