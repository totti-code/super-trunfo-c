#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Lê um número decimal que pode vir com vírgula ou ponto (ex: 314,93 ou 314.93)
float lerFloatSeguro() {
    char entrada[50];
    scanf("%49s", entrada);

    // Troca ',' por '.'
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] == ',') entrada[i] = '.';
    }

    return (float)atof(entrada);
}

int main() {
    // =========================
    // CARTA 1
    // =========================
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1; // em bilhões de reais (entrada)
    int pontosTuristicos1;

    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // =========================
    // CARTA 2
    // =========================
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2; // em bilhões de reais (entrada)
    int pontosTuristicos2;

    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // =========================
    // ENTRADA - CARTA 1
    // =========================
    printf("=== Cadastro da Carta 1 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (em km2): ");
    area1 = lerFloatSeguro();

    printf("PIB (em bilhoes de reais): ");
    pib1 = lerFloatSeguro();

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos1);

    // =========================
    // ENTRADA - CARTA 2
    // =========================
    printf("\n=== Cadastro da Carta 2 ===\n");

    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (em km2): ");
    area2 = lerFloatSeguro();

    printf("PIB (em bilhoes de reais): ");
    pib2 = lerFloatSeguro();

    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // =========================
    // CALCULOS
    // =========================
    // densidade = população / área
    densidade1 = (float)populacao1 / area1;
    densidade2 = (float)populacao2 / area2;

    // PIB per capita = (PIB em reais) / população
    // PIB foi digitado em bilhões, então convertemos: bilhoes * 1.000.000.000
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;

    // Super Poder:
    // soma(população, área, PIB, pontos turísticos, PIB per capita, inverso da densidade)
    // inverso densidade = 1 / densidade (menor densidade => maior parcela)
    superPoder1 =
        (float)populacao1 +
        area1 +
        pib1 +
        (float)pontosTuristicos1 +
        pibPerCapita1 +
        (1.0f / densidade1);

    superPoder2 =
        (float)populacao2 +
        area2 +
        pib2 +
        (float)pontosTuristicos2 +
        pibPerCapita2 +
        (1.0f / densidade2);

    // =========================
    // EXIBIÇÃO DAS CARTAS (mantém níveis anteriores)
    // =========================
    printf("\n\n===== CARTAS CADASTRADAS =====\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km2\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km2\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // =========================
    // COMPARAÇÃO (1 = Carta 1 vence, 0 = Carta 2 vence)
    // Regras:
    // - Densidade: menor vence
    // - Demais: maior vence
    // =========================
    int vPop = (populacao1 > populacao2);
    int vArea = (area1 > area2);
    int vPIB = (pib1 > pib2);
    int vPontos = (pontosTuristicos1 > pontosTuristicos2);
    int vDens = (densidade1 < densidade2); // menor vence
    int vPibPC = (pibPerCapita1 > pibPerCapita2);
    int vSuper = (superPoder1 > superPoder2);

    printf("\n\n===== Comparacao de Cartas =====\n");
    printf("Populacao: Carta 1 venceu (%d)\n", vPop);
    printf("Area: Carta 1 venceu (%d)\n", vArea);
    printf("PIB: Carta 1 venceu (%d)\n", vPIB);
    printf("Pontos Turisticos: Carta 1 venceu (%d)\n", vPontos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", vDens);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", vPibPC);
    printf("Super Poder: Carta 1 venceu (%d)\n", vSuper);

    return 0;
}