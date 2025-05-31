#include <stdio.h>

int main () {

    //declaracao das variaveis
    char estado1, estado2, codigo1 [3], codigo2 [3], nomeDaCidade1 [50], nomeDaCidade2 [50];
    int pontosTuristicos1, pontosTuristicos2, compararPopulacoes, compararPontosTuristicos, compararArea, compararPib, compararDensidadePopulacional, compararPibPerCapita, compararSuperPoder, atributoEscolhido1, atributoEscolhido2;
    float areaEmKm1, areaEmKm2, pib1, pib2, densidadePopulacional1, densidadePopulacional2, pibPerCapita1, pibPerCapita2, superPoder1, superPoder2, inversoDensidadePopulacional1, inversoDensidadePopulacional2, pontosCartas1 = 0, pontosCartas2 = 0;
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
    inversoDensidadePopulacional1 = 1.0f / densidadePopulacional1;
    inversoDensidadePopulacional2 = 1.0f / densidadePopulacional2;

    // inicio do jogo
    printf ("*** Bem-vindo ao jogo Super Trunfo! ***\n\n");


    // primeira escolha de atributos
    printf ("Qual o primeiro atributo você gostaria de comparar com as cartas do adversário? \n 1 - População \n 2 - Area \n 3 - PIB \n 4 - Pontos Turisticos \n 5 - Densidade Populacional \n");
    scanf ("%d", &atributoEscolhido1);

    // segunda escolha de atributos
    printf ("Qual o segundo atributo você gostaria de comparar com as cartas do adversário? (NÃO PODE SER IGUAL AO PRIMEIRO) \n 1 - População \n 2 - Area \n 3 - PIB \n 4 - Pontos Turisticos \n 5 - Densidade Populacional \n");
    scanf ("%d", &atributoEscolhido2);

    // condição para verificar se os atributos escolhidos são iguais
    if (atributoEscolhido1 == atributoEscolhido2)
    {
        printf ("Erro! Os atributos escolhidos devem ser diferentes! O programa será encerrado!\n");
        return 1; // indicando erro
    }
    

    // switch atributo 1
    switch (atributoEscolhido1) {
        case 1:
        pontosCartas1 += populacao1;
        pontosCartas2 += populacao2;
        break;
        case 2:
        pontosCartas1 += areaEmKm1;
        pontosCartas2 += areaEmKm2;
        break;
        case 3:
        pontosCartas1 += pib1;
        pontosCartas2 += pib2;
        break;
        case 4:
        pontosCartas1 += pontosTuristicos1;
        pontosCartas2 += pontosTuristicos2;
        break;
        case 5:
        pontosCartas1 += inversoDensidadePopulacional1;
        pontosCartas2 += inversoDensidadePopulacional2;
        break;
        default:
        printf ("Erro! O atributo escolhido não existe! O programa será encerrado!\n");
        return 1; 
    }

    // switch atributo 2
    switch (atributoEscolhido2) {
        case 1:
        pontosCartas1 += populacao1;
        pontosCartas2 += populacao2;
        break;
        case 2:
        pontosCartas1 += areaEmKm1;
        pontosCartas2 += areaEmKm2;
        break;
        case 3:
        pontosCartas1 += pib1;
        pontosCartas2 += pib2;
        break;
        case 4:
        pontosCartas1 += pontosTuristicos1;
        pontosCartas2 += pontosTuristicos2;
        break;
        case 5:
        pontosCartas1 += inversoDensidadePopulacional1;
        pontosCartas2 += inversoDensidadePopulacional2;
        break;
        default:
        printf ("Erro! O atributo escolhido não existe! O programa será encerrado!\n");
        return 1; 
    }

    // informar os valores
    printf ("\nSoma dos dois atributos:\n");
    printf ("Carta 1: %.2f\n", pontosCartas1);
    printf ("Carta 2: %.2f\n", pontosCartas2);

    // resultado e vencedor

    if (pontosCartas1 > pontosCartas2) {
        printf("\n*** A cidade %s VENCEU!!! ***\n", nomeDaCidade1);
    } else if (pontosCartas1 < pontosCartas2) {
        printf("\n*** A cidade %s VENCEU!!! ***\n", nomeDaCidade2);
    } else {
        printf("\n*** Ocorreu um EMPATE entre as cidades %s e %s! ***\n", nomeDaCidade1, nomeDaCidade2);
    }

    return 0;
}
