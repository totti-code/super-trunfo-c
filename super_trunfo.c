#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Lê um número decimal que pode vir com vírgula ou ponto (ex: 314,93 ou 314.93)
float lerFloatSeguro() {
    char entrada[50];
    scanf("%49s", entrada);

    // Troca ',' por '.'
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == ',') {
            entrada[i] = '.';
        }
    }

    return (float)atof(entrada);
}

int main() {

    // =========================
    // Variáveis da Carta 1
    // =========================
    char estado1;
    char codigo1[4];          // "A01" + '\0'
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1;               // em bilhões de reais (entrada)
    int pontosTuristicos1;

    // Novas propriedades (calculadas)
    float densidade1;
    float pibPerCapita1;

    // =========================
    // Variáveis da Carta 2
    // =========================
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2;               // em bilhões de reais (entrada)
    int pontosTuristicos2;

    // Novas propriedades (calculadas)
    float densidade2;
    float pibPerCapita2;

    // =========================
    // Entrada de dados - Carta 1
    // =========================
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area (em km2): ");
    area1 = lerFloatSeguro();

    printf("PIB (em bilhoes de reais): ");
    pib1 = lerFloatSeguro();

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // =========================
    // Cálculos - Carta 1
    // =========================
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;

    // =========================
    // Entrada de dados - Carta 2
    // =========================
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area (em km2): ");
    area2 = lerFloatSeguro();

    printf("PIB (em bilhoes de reais): ");
    pib2 = lerFloatSeguro();

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // =========================
    // Cálculos - Carta 2
    // =========================
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    // =========================
    // Exibição dos dados
    // =========================
    printf("\n\n===== CARTAS CADASTRADAS =====\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}