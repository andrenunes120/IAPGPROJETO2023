//
// Created by André Nunes on 30/10/2023.
//

#ifndef PROJETOIAPG202324_OPERACOES_H
#define PROJETOIAPG202324_OPERACOES_H
#include <stdio.h>
#include <string.h>
#include "dog.h"
#include "evento.h"


#define FICHEIRO_CAES_TXT "/Users/andrenunes120/Desktop/UFP/IAPGPROJETO2023/database/bd_caes.txt"
#define FICHEIRO_CAES_BINARIO "bd_caes.dat"
#define FICHEIRO_EVENTOS_TXT "/Users/andrenunes120/Desktop/UFP/IAPGPROJETO2023/database/historico_caes.txt"
#define FICHEIRO_EVENTOS_BINARIO "historico_caes.dat"


void escreverCaesNoFicheiro(CAO lista_cao[], int num_cao);

void lerCaesDoFicheiro(CAO lista_cao[], int *num_cao);

void escreverEventosNoFicheiro(EVENTO lista_evento[], int num_evento);

void lerEventosDoFicheiro(EVENTO lista_evento[], int *num_evento);

#endif //PROJETOIAPG202324_OPERACOES_H
