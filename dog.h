//
// Created by André Nunes on 13/10/2023.
//

#ifndef PROJETOIAPG202324_DOG_H
#define PROJETOIAPG202324_DOG_H
#define CHAR_MAX_LENGTH 100

#include "evento.h"

//estrutura do cao
typedef struct Cao {
    int id;
    int tipopeso;
    char nome[CHAR_MAX_LENGTH];
    int peso;
    int anos;
    int meses;
    char genero[CHAR_MAX_LENGTH];
    char pelagem[CHAR_MAX_LENGTH];
    char cor[CHAR_MAX_LENGTH];
    char data_nascimento[CHAR_MAX_LENGTH];
    char cidade_nascimento[CHAR_MAX_LENGTH];
    char raca[CHAR_MAX_LENGTH];
    int id_pai;
    int id_mae;
} CAO;


void inserircao(CAO cao[], int *num_cao);

CAO inserirCao(CAO listaCao[], int *num_cao, char nome[], int peso, int anos, int meses, char genero[],
               char pelagem[], char cor[], char data_nascimento[], char cidade_nascimento[], char raca[], int id_pai,
               int id_mae);

CAO encontrarCaoPorID(CAO listaCao[], int num_cao, int id);

void listarcao(CAO cao[], int num_cao, EVENTO evento[], int num_evento);

void listarTiosCao(CAO listaCao[], int num_cao, int id);

void listarCaoPorCor(CAO listaCao[], int num_cao, char cor[]);

void listarCaoPorRaca(CAO listaCao[], int num_cao, char raca[]);

void criarCaoMock(CAO listaCao[], int *num_cao);

void criarListaCaoMock(CAO listaCao[], int *num_cao);

void pesquisarCao(CAO listaCao[], int num_cao);

void printCao(CAO cao);

void estatisticasCao(int num_cao, CAO listaCao[]);

void arvoreGenealogicaAscendente(CAO listaCao[], int num_cao);

void arvoreGenealogicaDescendente(CAO listaCao[], int num_cao);


#endif //PROJETOIAPG202324_DOG_H
