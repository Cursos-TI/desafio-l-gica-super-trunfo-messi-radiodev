#include <stdio.h>

int main () {
    
    //declaracao das variaveis
    char estado1, estado2, codigo1 [3], codigo2 [3], nomeDaCidade1 [50], nomeDaCidade2 [50];
    int pontosTuristicos1, pontosTuristicos2, compararPopulacoes, compararPontosTuristicos, compararArea, compararPib, compararDensidadePopulacional, compararPibPerCapita, compararSuperPoder, pontosCartas1 = 0, pontosCartas2 = 0, atributoEscolhido;
    float areaEmKm1, areaEmKm2, pib1, pib2, densidadePopulacional1, densidadePopulacional2, pibPerCapita1, pibPerCapita2, superPoder1, superPoder2, inversoDensidadePopulacional1, inversoDensidadePopulacional2;
    unsigned long int populacao1, populacao2;
    
    //dados de entrada, usuario atribui valor as variaveis
    printf ("Digite uma letra de A a H para representar o estado da carta 1: \n");
    scanf (" %c", &estado1);
    printf ("Digite uma letra de A a H para representar o estado da carta 2: \n");
    scanf (" %c", &estado2);
    printf ("Digite um código de 01 a 04 para representar o codigo da carta 1: \n");
    scanf ("%2s", &codigo1); // inserido o 2 para limitar a quantidade de caracteres
    printf ("Digite um código de 01 a 04 para representar o codigo da carta 2: \n");
    scanf ("%2s", &codigo2); // inserido o 2 para limitar a quantidade de caracteres
    printf ("Digite o primeiro nome da cidade da carta 1: \n");
    scanf ("%s", &nomeDaCidade1);
    printf ("Digite o primeiro nome da cidade da carta 2: \n");
    scanf ("%s", &nomeDaCidade2);
    printf ("Digite a população da cidade da carta 1: \n");
    scanf ("%lu", &populacao1);
    printf ("Digite a população da cidade da carta 2: \n");
    scanf ("%lu", &populacao2);
    printf ("Digite a quantidade de pontos turisticos da cidade da carta 1: \n");
    scanf ("%d", &pontosTuristicos1);
    printf ("Digite a quantidade de pontos turisticos da cidade da carta 2: \n");
    scanf ("%d", &pontosTuristicos2);
    printf ("Digite a area em Km da cidade da carta 1: \n");
    scanf ("%f", &areaEmKm1);
    printf ("Digite a area em Km da cidade da carta 2: \n");
    scanf ("%f", &areaEmKm2);
    printf ("Digite o PIB da cidade da carta 1: \n");
    scanf ("%f", &pib1);
    printf ("Digite o PIB da cidade da carta 2: \n");
    scanf ("%f", &pib2);

    //calculo sendo realizado após a leitura dos dados inseridos pelo usuario
    densidadePopulacional1 = (float) populacao1 / areaEmKm1;
    densidadePopulacional2 = (float) populacao2 / areaEmKm2;
    inversoDensidadePopulacional1 = (float) 1.0f / densidadePopulacional1;
    inversoDensidadePopulacional2 = (float) 1.0f / densidadePopulacional2;
    pibPerCapita1 = (float) pib1 / populacao1;
    pibPerCapita2 = (float) pib2 / populacao2;
    superPoder1 = (float) (populacao1 + pontosTuristicos1 + areaEmKm1 + pib1 + inversoDensidadePopulacional1 + pibPerCapita1);
    superPoder2 = (float) (populacao2 + pontosTuristicos2 + areaEmKm2 + pib2 + inversoDensidadePopulacional2 + pibPerCapita2);

    //formulas de comparação
    compararPopulacoes = populacao1 > populacao2;
    compararArea = areaEmKm1 > areaEmKm2;
    compararPib = pib1 > pib2;
    compararPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    compararDensidadePopulacional = densidadePopulacional1 < densidadePopulacional2; // menor valor vence
    compararPibPerCapita = pibPerCapita1 > pibPerCapita2;
    compararSuperPoder = superPoder1 > superPoder2;

   // tela de interação com o usuario
    printf ("*** Bem-vindo ao jogo Super Trunfo! ***\n\n");
    printf ("Qual atributo você gostaria de comparar com as cartas do adversário? \n 1 - População \n 2 - Area \n 3 - PIB \n 4 - Pontos Turisticos \n 5 - Densidade Populacional \n");
    scanf ("%d", &atributoEscolhido);

    // resultado da interação do usuario
    switch (atributoEscolhido) {
        case 1:
            if (populacao1 == populacao2) {
                printf ("Empate entre as cidades! População da carta 1: %lu e da carta 2: %lu\n", populacao1, populacao2);
            } else if (compararPopulacoes) {
                printf ("A Cidade %s vence! População da carta 1: %lu e da carta 2: %lu\n", nomeDaCidade1, populacao1, populacao2);
            } else {
                printf ("A Cidade %s vence! População da carta 1: %lu e da carta 2: %lu\n", nomeDaCidade2, populacao1, populacao2);
            }
            break;
        case 2:
            if (areaEmKm1 == areaEmKm2) {
                printf ("Empate entre as cidades! Área em Km da carta 1: %.2f e da carta 2: %.2f\n", areaEmKm1, areaEmKm2);
            } else if (compararArea) {
                printf ("A Cidade %s vence! Área em Km da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade1, areaEmKm1, areaEmKm2);
            } else {
                printf ("A Cidade %s vence! Área em Km da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade2, areaEmKm1, areaEmKm2);
            }
            break;
        case 3:
            if (pib1 == pib2) {
                printf ("Empate entre as cidades! PIB da carta 1: %.2f e da carta 2: %.2f\n", pib1, pib2);
            } else if (compararPib) {
                printf ("A Cidade %s vence! PIB da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade1, pib1, pib2);
            } else {
                printf ("A Cidade %s vence! PIB da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade2, pib1, pib2);
            }
            break;
        case 4:
            if (pontosTuristicos1 == pontosTuristicos2) {
                printf ("Empate entre as cidades! Nº de Pontos Turísticos da carta 1: %d e da carta 2: %d\n", pontosTuristicos1, pontosTuristicos2);
            } else if (compararPontosTuristicos) {
                printf ("A Cidade %s vence! Nº de Pontos Turísticos da carta 1: %d e da carta 2: %d\n", nomeDaCidade1, pontosTuristicos1, pontosTuristicos2);
            } else {
                printf ("A Cidade %s vence! Nº de Pontos Turísticos da carta 1: %d e da carta 2: %d\n", nomeDaCidade2, pontosTuristicos1, pontosTuristicos2);
            }
            break;
        case 5:
            if (densidadePopulacional1 == densidadePopulacional2) {
                printf ("Empate entres as cidades! Densidade Demográfica da carta 1: %.2f e da carta 2: %.2f\n", densidadePopulacional1, densidadePopulacional2);
            } else if (compararDensidadePopulacional) {
                printf ("A Cidade %s vence! Densidade Demográfica da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade1, densidadePopulacional1, densidadePopulacional2);
            } else {
                printf ("A Cidade %s vence! Densidade Demográfica da carta 1: %.2f e da carta 2: %.2f\n", nomeDaCidade2, densidadePopulacional1, densidadePopulacional2);
            }
            break;
        default:
            printf ("Opção inválida!\n");
            break;
    }

    return 0;

}
