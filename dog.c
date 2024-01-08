//
// Created by André Nunes on 13/10/2023.
//

#include "dog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dog.h"

void inserircao(CAO cao[], int *num_cao) {
    CAO novo_cao;
    novo_cao.id = *num_cao + 1;
    printf("Digite o nome do cao:");
    scanf("%s", novo_cao.nome);
    printf("Digite a raca do cao:");
    scanf("%s", novo_cao.raca);
    printf("Digite o peso do cao:");
    scanf("%d", &novo_cao.peso);
    if (novo_cao.peso < 10) {
        novo_cao.tipopeso = 0;
    } else if (novo_cao.peso <= 25) {
        novo_cao.tipopeso = 1;
    } else if (novo_cao.peso > 25) {
        novo_cao.tipopeso = 2;
    }
    printf("Digite quantos anos o cao tem:");
    scanf("%d", &novo_cao.anos);
    printf("Digite quantos meses o cao tem:");
    scanf("%d", &novo_cao.meses);
    printf("Digite o genero do cao:");
    scanf("%s", novo_cao.genero);
    printf("Digite a pelagem do cao:");
    scanf("%s", novo_cao.pelagem);
    printf("Digite a cor do cao:");
    scanf("%s", novo_cao.cor);
    printf("Digite a data de nascimento do cao:");
    scanf("%s", novo_cao.data_nascimento);
    printf("Digite a cidade que o cao nasceu:");
    scanf("%s", novo_cao.cidade_nascimento);
    printf("Digite o id do pai, caso nao conheça use 0:");
    scanf("%d", &novo_cao.id_pai);
    printf("Digite o id da mae,caso nao conheça use 0:");
    scanf("%d", &novo_cao.id_mae);
    cao[*num_cao] = novo_cao;
    (*num_cao)++;
    printf("Cao adicionado com sucesso.\n");
}

CAO inserirCao(CAO listaCao[], int *num_cao, char nome[], int peso, int anos, int meses, char genero[],
               char pelagem[], char cor[], char data_nascimento[], char cidade_nascimento[], char raca[], int id_pai,
               int id_mae) {
    CAO cao = {};
    cao.id = *num_cao + 1;
    strcpy(cao.nome, nome);
    cao.peso = peso;
    if (cao.peso < 10) {
        cao.tipopeso = 0;
    } else if (cao.peso <= 25) {
        cao.tipopeso = 1;
    } else if (cao.peso > 25) {
        cao.tipopeso = 2;
    }
    cao.anos = anos;
    cao.meses = meses;
    strcpy(cao.genero, genero);
    strcpy(cao.pelagem, pelagem);
    strcpy(cao.cor, cor);
    strcpy(cao.data_nascimento, data_nascimento);
    strcpy(cao.cidade_nascimento, cidade_nascimento);
    strcpy(cao.raca, raca);
    cao.id_pai = id_pai;
    cao.id_mae = id_mae;

    listaCao[*num_cao] = cao;
    (*num_cao)++;
    return cao;
}

CAO encontrarCaoPorID(CAO listaCao[], int num_cao, int id) {
    CAO caoNaoEncontrado = {};
    for (int i = 0; i < num_cao; i++) {
        if (listaCao[i].id == id) {
            return listaCao[i];
        }
    }
    return caoNaoEncontrado; // Retorna cão vazio se não for encontrado
}

void listarcao(CAO cao[], int num_cao, EVENTO evento[], int num_evento) {
    printf("\nNumero total de caes: %d\n", num_cao);
    for (int i = 0; i < num_cao; ++i) {
        printf("\tID: %d\n", cao[i].id);
        printCao(cao[i]);
        listarEventosDeUmCao(evento, num_evento, cao[i].id);
        if (i != num_cao - 1) {
            printf("\t___________________________\n");
        }
    }
}

void listarTiosCao(CAO listaCao[], int num_cao, int id) {
    CAO cao = encontrarCaoPorID(listaCao, num_cao, id);
    if (cao.id == 0) {
        printf("\n\tId de cao invalido.\n");

    }
    CAO caoPai = encontrarCaoPorID(listaCao, num_cao, cao.id_pai);
    CAO caoMae = encontrarCaoPorID(listaCao, num_cao, cao.id_mae);
    if (caoPai.id == 0 && caoMae.id == 0) {
        printf("\n\tNao existem dados sobre a familia deste cao.\n");
    } else {
        int prints = 0;
        for (int i = 0; i < num_cao; ++i) {
            //se pai existir && se cao atual nao for o pai &&
            // && (se pai do cao atual for o avo do cao || se mae do cao atual for o avo do cao)
            //tios lado do pai
            if (caoPai.id != 0 && listaCao[i].id != caoPai.id &&
                ((caoPai.id_pai != 0 && listaCao[i].id_pai == caoPai.id_pai) ||
                 (caoPai.id_mae != 0 && listaCao[i].id_mae == caoPai.id_mae))) {
                prints++;
                printCao(listaCao[i]);
                printf("\t___________________________\n");
                //tios lado da mae
            } else if (caoMae.id != 0 && listaCao[i].id != caoMae.id &&
                       ((caoMae.id_pai != 0 && listaCao[i].id_pai == caoMae.id_pai) ||
                        (caoMae.id_pai != 0 && listaCao[i].id_mae == caoMae.id_mae))) {
                prints++;
                printCao(listaCao[i]);
                printf("\t___________________________\n");
            }
        }
        if (prints == 0) {
            printf("\n\tTios nao encontrados\n");
        }
    }

}

void pesquisarCao(CAO listaCao[], int num_cao) {
    int opcao;
    int id, resultado = 0;
    char cor[CHAR_MAX_LENGTH], raca[CHAR_MAX_LENGTH];
    char faixaetaria[CHAR_MAX_LENGTH];
    char porte[CHAR_MAX_LENGTH];
    do {
        printf("\nMenu:\n");
        printf("1. Pesquisar Cao pelo ID\n");
        printf("2. Pesquisar Cao pelo Porte\n");
        printf("3. Pesquisar Cao pela faixa etaria\n");
        printf("4. Pesquisar Tios de um cao pelo ID\n");
        printf("5. Pesquisar por cor\n");
        printf("6. Pesquisar por raca\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o ID:");
                scanf("%d", &id);
                CAO cao = encontrarCaoPorID(listaCao, num_cao, id);
                if (cao.id != 0) {
                    printf("\nCao encontrado:\n");
                    printCao(cao);
                } else {
                    printf("\n\tNao existe nenhum cao esse ID.\n");
                }
                break;
            case 2:
                printf("Pequeno: 0-10kg\n");
                printf("Medio: 10-25kg\n");
                printf("Grande: >25kg\n");
                printf("Indique o porte do cao:");
                scanf("%s", porte);
                if (!(strcasecmp(porte, "pequeno") == 0 || strcasecmp(porte, "medio") == 0 ||
                      strcasecmp(porte, "grande") == 0)) {
                    printf("\n\tNao existe essa opção de  porte.\n");
                    break;
                }

                for (int i = 0; i < num_cao; i++) {
                    if (strcasecmp(porte, "pequeno") == 0 && listaCao[i].peso <= 10) {
                        printCao(listaCao[i]);
                        resultado = 1;
                        printf("\t___________________________\n");
                    } else if (strcasecmp(porte, "medio") == 0 && listaCao[i].peso > 10 && listaCao[i].peso <= 25) {
                        printCao(listaCao[i]);
                        resultado = 1;
                        printf("\t___________________________\n");
                    } else if (strcasecmp(porte, "grande") == 0 && listaCao[i].peso > 25) {
                        printCao(listaCao[i]);
                        resultado = 1;
                        printf("\t___________________________\n");
                    }
                }
                if (!resultado)
                    printf("\n\tNao existem caes no porte %s.\n", porte);

                resultado = 0;
                break;
            case 3:
                printf("Filhote\n");
                printf("Adulto\n");
                printf("Velho\n");
                printf("Indique a faixa etaria do cao:");
                scanf("%s", faixaetaria);
                if (!(strcasecmp(faixaetaria, "filhote") == 0 || strcasecmp(faixaetaria, "adulto") == 0 ||
                      strcasecmp(faixaetaria, "velho") == 0)) {
                    printf("\n\tNao existe essa opção de faixa etaria.\n");
                    break;
                }
                for (int i = 0; i < num_cao; i++) {
                    //Porte pequeno, filhote
                    if ((strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 0 && listaCao[i].anos == 1)
                        ||
                        (strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 0 &&
                         listaCao[i].meses < 12 &&
                         listaCao[i].anos == 0)) {
                        printCao(listaCao[i]);
                        printf("porte pequeno, filhote\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        // porte medio, filhote
                    } else if (
                            (strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 1 &&
                             listaCao[i].anos == 1 && listaCao[i].meses <= 2
                            ) || (strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 1 &&
                                  listaCao[i].anos == 0 &&
                                  listaCao[i].meses < 12)) {
                        printCao(listaCao[i]);
                        printf("porte medio, filhote\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte grande, filhote
                    } else if (
                            (strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 2 &&
                             listaCao[i].anos == 1 && listaCao[i].meses <= 6
                            ) || (strcasecmp(faixaetaria, "filhote") == 0 && listaCao[i].tipopeso == 2 &&
                                  listaCao[i].anos == 0 &&
                                  listaCao[i].meses < 12)) {
                        printCao(listaCao[i]);
                        printf("porte grande, filhote\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte pequeno, adulto
                    } else if (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 0 &&
                               listaCao[i].anos > 1 &&
                               listaCao[i].anos <= 8) {
                        printCao(listaCao[i]);
                        printf("porte pequeno, adulto\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte medio, adulto
                    } else if (
                            (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 1 &&
                             listaCao[i].anos == 1 &&
                             listaCao[i].meses >= 2 && listaCao[i].meses < 12) ||
                            (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 1 &&
                             listaCao[i].anos < 8 &&
                             listaCao[i].anos > 1 && listaCao[i].meses < 12)
                            || (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 1 &&
                                listaCao[i].anos == 8)) {
                        printCao(listaCao[i]);
                        printf("porte medio, adulto\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte grande, adulto
                    } else if (
                            (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 2 &&
                             listaCao[i].anos == 1 &&
                             listaCao[i].meses >= 6 && listaCao[i].meses < 12)
                            ||
                            (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 2 &&
                             listaCao[i].anos < 6 &&
                             listaCao[i].anos > 1 && listaCao[i].meses < 12)
                            || (strcasecmp(faixaetaria, "adulto") == 0 && listaCao[i].tipopeso == 2 &&
                                listaCao[i].anos == 6)) {
                        printCao(listaCao[i]);
                        printf("porte grande, adulto\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte pequeno, velho
                    } else if (
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 0 &&
                             listaCao[i].anos == 8 &&
                             listaCao[i].meses < 12 && listaCao[i].meses > 0)
                            ||
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 0 &&
                             listaCao[i].anos > 8 &&
                             listaCao[i].meses < 12)) {
                        printCao(listaCao[i]);
                        printf("porte pequeno, velho\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte medio, velho
                    } else if (
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 1 &&
                             listaCao[i].anos == 8 &&
                             listaCao[i].meses < 12 && listaCao[i].meses > 0)
                            ||
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 1 &&
                             listaCao[i].anos > 8 &&
                             listaCao[i].meses < 12)) {
                        printCao(listaCao[i]);
                        printf("porte medio, velho\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                        //porte grande, velho
                    } else if (
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 2 &&
                             listaCao[i].anos == 6 &&
                             listaCao[i].meses < 12 && listaCao[i].meses > 0)
                            ||
                            (strcasecmp(faixaetaria, "velho") == 0 && listaCao[i].tipopeso == 2 &&
                             listaCao[i].anos > 6 &&
                             listaCao[i].meses < 12)) {
                        printCao(listaCao[i]);
                        printf("porte grande, velho\n");
                        printf("\t___________________________\n");
                        resultado = 1;
                    }
                }
                if (!resultado)
                    printf("Cao nao encontrado.\n");
                resultado = 0;
                break;
            case 4:
                printf("Digite o ID:");
                scanf("%d", &id);
                listarTiosCao(listaCao, num_cao, id);
                break;
            case 5:
                printf("Digite a cor do cao:");
                scanf("%s", cor);
                listarCaoPorCor(listaCao, num_cao, cor);
                break;
            case 6:
                printf("Digite a raca do cao:");
                scanf("%s", raca);
                listarCaoPorRaca(listaCao, num_cao, raca);
                break;
            case 7:
                break;
        }
    } while (opcao != 7);


}

void listarCaoPorCor(CAO listaCao[], int num_cao, char cor[]) {
    int size = 0;
    for (int i = 0; i < num_cao; ++i) {
        if (strcasecmp(cor, listaCao[i].cor) == 0) {
            printCao(listaCao[i]);
            printf("\t___________________________\n");
            size++;
        }
    }
    if (size == 0) {
        printf("\n\tNao existem caes na base de dados com a cor %s\n", cor);
    }
}

void listarCaoPorRaca(CAO listaCao[], int num_cao, char raca[]) {
    int size = 0;
    for (int i = 0; i < num_cao; ++i) {
        if (strcasecmp(raca, listaCao[i].raca) == 0) {
            printCao(listaCao[i]);
            printf("\t___________________________\n");
        }
    }
    if (size == 0) {
        printf("\n\tNao existem caes na base de dados com a raca %s\n", raca);
    }
}


void printCao(CAO cao) {
    printf("\tNome: %s\n", cao.nome);
    printf("\tRaca: %s\n", cao.raca);
    printf("\tPeso: %d\n", cao.peso);
    printf("\tAnos: %d\n", cao.anos);
    printf("\tMeses: %d\n", cao.meses);
    printf("\tGenero: %s\n", cao.genero);
    printf("\tPelagem: %s\n", cao.pelagem);
    printf("\tCor: %s\n", cao.cor);
    printf("\tData de nascimento: %s\n", cao.data_nascimento);
    printf("\tCidade de nascimento: %s\n", cao.cidade_nascimento);
    printf("\tID do pai: %d\n", cao.id_pai);
    printf("\tID da mae: %d\n", cao.id_mae);

}

void criarCaoMock(CAO listaCao[], int *num_cao) {
    CAO cao;
    strcpy(cao.nome, "Andre");
    cao.id = *num_cao + 1;
    cao.peso = 9;
    cao.anos = 3;
    cao.meses = 11;
    cao.tipopeso = 0;
    strcpy(cao.genero, "Masc");
    strcpy(cao.pelagem, "Liso");
    strcpy(cao.cor, "Preto");
    strcpy(cao.data_nascimento, "27-12-99");
    strcpy(cao.cidade_nascimento, "Porto");
    strcpy(cao.raca, "ChowCHow");
    cao.id_pai = 0;
    cao.id_mae = 0;
    listaCao[*num_cao] = cao;
    (*num_cao)++;
}

void criarListaCaoMock(CAO listaCao[], int *num_cao) {

    //------------- avos
    CAO andre = inserirCao(listaCao, num_cao, "Andre", 22, 20, 6, "Masculino", "Liso", "Preto", "27-12-2020", "Porto",
                           "Beagle", 0, 0);
    CAO viviana = inserirCao(listaCao, num_cao, "Viviana", 15, 20, 6, "Feminino", "Liso", "Castanho", "27-12-2020", "Braga",
                             "Rottweiler", 0, 0);
    // ------------
    CAO nani = inserirCao(listaCao, num_cao, "Nani", 21, 24, 4, "Masculino", "Liso", "Preto", "27-12-2020", "Porto",
                          "ChowChow", 0, 0);
    CAO margarida = inserirCao(listaCao, num_cao, "Margarida", 18, 22, 0, "Feminino", "Liso", "Branco", "27-12-2020",
                               "Porto",
                               "ChowChow", 0, 0);

    //------------ familia 1
    //tio de bolas
    CAO joaquimPai = inserirCao(listaCao, num_cao, "Joaquim", 10, 20, 3, "Masculino", "Liso", "Preto", "27-12-2003",
                                "Porto", "Rottweiler", andre.id, viviana.id);
    CAO nikitaMae = inserirCao(listaCao, num_cao, "Nikita", 13, 19, 9, "Feminino", "Liso", "Preto", "27-12-2004", "Braga",
                               "ChowChow", 0, 0);
    CAO jonasFilho = inserirCao(listaCao, num_cao, "Jonas", 4, 0, 6, "Masculino", "Liso", "Azul", "27-12-2020", "Felgueiras",
                                "ChowChow", joaquimPai.id, nikitaMae.id);

    //---------- familia 2
    CAO simbaPai = inserirCao(listaCao, num_cao, "Simba", 30, 20, 6, "Masculino", "Liso", "Preto", "27-12-2020", "Porto",
                              "ChowChow", nani.id, margarida.id);
    //tia de jonas
    CAO cookieMae = inserirCao(listaCao, num_cao, "Cookie", 8, 19, 9, "Feminino", "Liso", "Castanho", "27-12-2004",
                               "Porto",
                               "ChowChow", andre.id, viviana.id);
    CAO bolas = inserirCao(listaCao, num_cao, "Bolas", 5, 0, 2, "Masculino", "Liso", "Preto", "27-12-2020", "Margem Sul",
                           "ChowChow", simbaPai.id, cookieMae.id);
    // -------------------
    // solteiro filho de andre e viviana, tio de bolas
    CAO antonio = inserirCao(listaCao, num_cao, "Antonio", 12, 14, 6, "Masculino", "Liso", "Preto", "27-12-2020", "Matosinhos",
                             "ChowChow", nani.id, margarida.id);

    //solteiro filho de andre e viviana, tio de jonasFilho e bolas
    CAO francisco = inserirCao(listaCao, num_cao, "Francisco", 19, 12, 6, "Masculino", "Liso", "Preto", "27-12-2020",
                               "Porto","ChowChow", andre.id, viviana.id);

    /*
    //Pai
    CAO caoPai;
    strcpy(caoPai.nome, "Joaquim");
    caoPai.id = *num_cao + 1;
    caoPai.peso = 10;
    caoPai.anos = 20;
    caoPai.meses = 3;
    caoPai.tipopeso = 1;
    strcpy(caoPai.genero, "Masculino");
    strcpy(caoPai.pelagem, "Liso");
    strcpy(caoPai.cor, "Preto");
    strcpy(caoPai.data_nascimento, "27-12-2003");
    strcpy(caoPai.cidade_nascimento, "Porto");
    strcpy(caoPai.raca, "ChowChow");
    caoPai.id_pai = 0;
    caoPai.id_mae = 0;
    listaCao[*num_cao] = caoPai;
    (*num_cao)++;
*/
    /*
    //Mae
    CAO caoMae;
    strcpy(caoMae.nome, "Nikita");
    caoMae.id = *num_cao + 1;
    caoMae.peso = 13;
    caoMae.anos = 19;
    caoMae.meses = 9;
    caoMae.tipopeso = 1;
    strcpy(caoMae.genero, "Feminino");
    strcpy(caoMae.pelagem, "Liso");
    strcpy(caoMae.cor, "Preto");
    strcpy(caoMae.data_nascimento, "27-12-2004");
    strcpy(caoMae.cidade_nascimento, "Porto");
    strcpy(caoMae.raca, "ChowCHow");
    caoMae.id_pai = 0;
    caoMae.id_mae = 0;
    listaCao[*num_cao] = caoMae;
    (*num_cao)++;
*/
    /*
    //Filho
    CAO caoFilho;
    strcpy(caoFilho.nome, "Jonas");
    caoFilho.id = *num_cao + 1;
    caoFilho.peso = 4;
    caoFilho.anos = 0;
    caoFilho.meses = 6;
    caoFilho.tipopeso = 1;
    strcpy(caoFilho.genero, "Masculino");
    strcpy(caoFilho.pelagem, "Liso");
    strcpy(caoFilho.cor, "Preto");
    strcpy(caoFilho.data_nascimento, "27-12-2020");
    strcpy(caoFilho.cidade_nascimento, "Porto");
    strcpy(caoFilho.raca, "ChowCHow");
    caoFilho.id_pai = caoPai.id;
    caoFilho.id_mae = caoMae.id;
    listaCao[*num_cao] = caoFilho;
    (*num_cao)++;
     */
}

void estatisticasCao(int num_cao, CAO listaCao[]) {
    int quantidadeP = 0, quantidadeM = 0, quantidadeG = 0;
    float proporcaoP = 0, proporcaoM = 0, proporcaoG = 0;
    int quantidadeidade1 = 0, quantidadeidade2 = 0, quantidadeidade3 = 0, quantidadeidade4 = 0, quantidadeidade5 = 0, quantidadeidade6 = 0;
    float proporcaoidade1 = 0, proporcaoidade2 = 0, proporcaoidade3 = 0, proporcaoidade4 = 0, proporcaoidade5 = 0, proporcaoidade6 = 0;
    if (num_cao > 0) {
        for (int i = 0; i < num_cao; i++) {
            if (listaCao[i].peso < 10) {
                quantidadeP++;
            } else if (listaCao[i].peso < 25) {
                quantidadeM++;
            } else if (listaCao[i].peso >= 25) {
                quantidadeG++;
            }
        }
        //CALCULO DA PROPORCAO DO NUMERO DE ANIMAIS em %
        proporcaoP = ((float) quantidadeP / (float) num_cao) * 100;
        proporcaoM = ((float) quantidadeM / (float) num_cao) * 100;
        proporcaoG = ((float) quantidadeG / (float) num_cao) * 100;

        printf("Existem %d caes pequenos, %d caes medios, %d caes grandes\n", quantidadeP, quantidadeM, quantidadeG);
        printf("%.2f%% sao caes pequenos, %.2f%% sao caes medios e %.2f%% sao caes grandes\n", proporcaoP, proporcaoM,
               proporcaoG);

        for (int i = 0; i < num_cao; i++) {
            if (listaCao[i].anos == 0 && listaCao[i].meses < 3) {
                quantidadeidade1++;
            } else if (listaCao[i].anos == 0 && listaCao[i].meses >= 3 && listaCao[i].meses <= 6) {
                quantidadeidade2++;
            } else if (listaCao[i].anos == 0 && listaCao[i].meses > 6 && listaCao[i].meses <= 9) {
                quantidadeidade3++;
            } else if (listaCao[i].anos == 0 && listaCao[i].meses > 9 && listaCao[i].meses <= 11 ||
                       listaCao[i].anos == 1 && listaCao[i].meses == 0) {
                quantidadeidade4++;
            } else if (listaCao[i].anos > 1 && listaCao[i].anos <= 3) {
                quantidadeidade5++;
            } else if (listaCao[i].anos > 3) {
                quantidadeidade6++;
            }
        }
        proporcaoidade1 = ((float) quantidadeidade1 / (float) num_cao) * 100;
        proporcaoidade2 = ((float) quantidadeidade2 / (float) num_cao) * 100;
        proporcaoidade3 = ((float) quantidadeidade3 / (float) num_cao) * 100;
        proporcaoidade4 = ((float) quantidadeidade4 / (float) num_cao) * 100;
        proporcaoidade5 = ((float) quantidadeidade5 / (float) num_cao) * 100;
        proporcaoidade6 = ((float) quantidadeidade6 / (float) num_cao) * 100;

        printf("<3 meses= %d \n"
               "3 a 6 meses= %d \n"
               "6 a 9 meses= %d \n"
               "9 a 12 meses= %d \n"
               "1 a 3 anos= %d \n"
               "mais de 3 anos= %d \n", quantidadeidade1, quantidadeidade2, quantidadeidade3, quantidadeidade4,
               quantidadeidade5, quantidadeidade6);
        printf("<3 meses= %.2f%% \n"
               "3 a 6 meses= %.2f%% \n"
               "6 a 9 meses= %.2f%% \n"
               "9 a 12 meses= %.2f%% \n"
               "1 a 3 anos= %.2f%% \n"
               "mais de 3 anos= %.2f%% \n", proporcaoidade1, proporcaoidade2, proporcaoidade3, proporcaoidade4,
               proporcaoidade5, proporcaoidade6);


        // imprimir numero de racas
        int numeroRacas[num_cao];
        char racasUnicas[num_cao][CHAR_MAX_LENGTH];
        int racasDiferentes = 0;
        for (int i = 0; i < num_cao; ++i) {
            int racaUnica = 0;
            for (int j = 0; j < racasDiferentes; j++) {
                if (strcmp(listaCao[i].raca, racasUnicas[j]) == 0) {
                    numeroRacas[j]++;
                    racaUnica = 1;
                    break;
                }
            }
            if (!racaUnica) {
                strcpy(racasUnicas[racasDiferentes], listaCao[i].raca);
                numeroRacas[racasDiferentes++] = 1;
            }
        }
        for (int i = 0; i < racasDiferentes; ++i) {
            printf("\tNumero de caes com a raca %s: %d\n", racasUnicas[i], numeroRacas[i]);
        }
        printf("\n");

        //imprimir numero de cores
        int numeroCores[num_cao];
        char coresUnicas[num_cao][CHAR_MAX_LENGTH];
        int coresDiferentes = 0;
        for (int i = 0; i < num_cao; ++i) {
            int corUnica = 0;
            for (int j = 0; j < coresDiferentes; j++) {
                if (strcmp(listaCao[i].cor, coresUnicas[j]) == 0) {
                    numeroCores[j]++;
                    corUnica = 1;
                    break;
                }
            }
            if (!corUnica) {
                //copia a string de .cor
                strcpy(coresUnicas[coresDiferentes], listaCao[i].cor);
                numeroCores[coresDiferentes++] = 1;
            }
        }
        for (int i = 0; i < coresDiferentes; ++i) {
            printf("\tNumero de caes com a cor %s: %d\n", coresUnicas[i], numeroCores[i]);
            printf("\t__\n");

        }


    } else {
        printf("A lista de caes esta vazia\n");
    }
}


void arvoreGenealogicaAscendente(CAO listaCao[], int num_cao) {
    int id = 0;
    printf("Digite o ID:");
    scanf("%d", &id);
    CAO cao = encontrarCaoPorID(listaCao, num_cao, id);
    if (cao.id == 0) {
        printf("\n\t Cao nao encontrado\n");
    }
    //pais
    CAO caoPai = encontrarCaoPorID(listaCao, num_cao, cao.id_pai);
    CAO caoMae = encontrarCaoPorID(listaCao, num_cao, cao.id_mae);
    if (caoPai.id != 0 || caoMae.id != 0) {
        printf("Pais:\n");
        if (caoPai.id != 0) {
            printf("\t---Pai---\n");
            printCao(caoPai);
        }
        if (caoMae.id != 0) {
            printf("\t---Mae---\n");
            printCao(caoMae);
        }
        printf("Tios:\n");
        listarTiosCao(listaCao, num_cao, id);

        CAO caoAvoPaiM = encontrarCaoPorID(listaCao, num_cao, caoPai.id_pai);
        CAO caoAvoPaiF = encontrarCaoPorID(listaCao, num_cao, caoPai.id_mae);
        CAO caoAvoMaeM = encontrarCaoPorID(listaCao, num_cao, caoMae.id_pai);
        CAO caoAvoMaeF = encontrarCaoPorID(listaCao, num_cao, caoMae.id_mae);
        if (caoAvoPaiM.id != 0 || caoAvoPaiF.id != 0 || caoAvoMaeM.id != 0 || caoAvoMaeF.id != 0) {
            printf("Avos:\n");
            if (caoAvoPaiM.id != 0) {
                printf("\t---Avô lado Pai---\n");
                printCao(caoAvoPaiM);
            }
            if (caoAvoPaiF.id != 0) {
                printf("\t---Avó lado Pai---\n");
                printCao(caoAvoPaiF);
            }
            if (caoAvoMaeM.id != 0) {
                printf("\t---Avô lado Mae---\n");
                printCao(caoAvoMaeM);
            }
            if (caoAvoMaeF.id != 0) {
                printf("\t---Avó lado Mae---\n");
                printCao(caoAvoMaeF);
            }
        } else {
            printf("\n\tEste cao nao tem avos.\n");
        }
    } else {
        printf("\n\tNao existem dados sobre a familia desta cao.\n");
    }
}

void arvoreGenealogicaDescendente(CAO listaCao[], int num_cao) {
    int id = 0;
    printf("Digite o ID:");
    scanf("%d", &id);
    CAO cao = encontrarCaoPorID(listaCao, num_cao, id);
    if (cao.id == 0) {
        printf("\n\t Cao nao encontrado\n");
    }
    printf("Filhos:\n");
    for (int i = 0; i < num_cao; ++i) {
        int count = 0;
        if (listaCao[i].id_pai == cao.id || listaCao[i].id_mae == cao.id) {
            printf("\nFilho do %s:\n", cao.nome);
            printCao(listaCao[i]);
            printf("\t___________________________\n");
            for (int j = 0; j < num_cao; ++j) {
                if (listaCao[j].id_pai == listaCao[i].id || listaCao[j].id_mae == listaCao[i].id) {
                    if (count == 0) {
                        printf("Filhos do cao %s e  netos do cao %s:\n", listaCao[i].nome, cao.nome);
                        count = 1;
                    }
                    printCao(listaCao[j]);
                    printf("\t___________________________\n");
                }
            }
        }
    }
}

