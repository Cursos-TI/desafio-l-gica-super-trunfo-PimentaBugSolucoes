#include <stdio.h>
#include <string.h>

// Definição da estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} CartaSuperTrunfo;

// Função para calcular a densidade populacional e PIB per capita
void calcularDados(CartaSuperTrunfo *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaSuperTrunfo carta) {
    printf("\n-------------------\n");
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s", carta.nomeCidade);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta.pibPerCapita);
    printf("-------------------\n");
}

// Função para comparar dois atributos
void compararSimples(const char *nome, float valor1, float valor2) {
    if (valor1 > valor2)
        printf("%s: Carta 1 venceu\n", nome);
    else if (valor1 < valor2)
        printf("%s: Carta 2 venceu\n", nome);
    else
        printf("%s: Empate\n", nome);
}

// Função para comparar dois atributos ao mesmo tempo
void compararDuplo(const char *nome1, float v1a, float v1b, const char *nome2, float v2a, float v2b) {
    int pontos1 = 0, pontos2 = 0;

    pontos1 += (v1a > v2a) ? 1 : (v1a < v2a ? 0 : 0);
    pontos2 += (v2a > v1a) ? 1 : (v2a < v1a ? 0 : 0);

    pontos1 += (v1b > v2b) ? 1 : (v1b < v2b ? 0 : 0);
    pontos2 += (v2b > v1b) ? 1 : (v2b < v1b ? 0 : 0);

    printf("Comparando %s e %s: ", nome1, nome2);
    if (pontos1 > pontos2)
        printf("Carta 1 venceu\n");
    else if (pontos2 > pontos1)
        printf("Carta 2 venceu\n");
    else
        printf("Empate\n");
}

int main() {
    CartaSuperTrunfo carta1 = {'R', "R01", "Angra dos Reis\n", 207044, 819.00, 14.5, 12};
    CartaSuperTrunfo carta2 = {'S', "S01", "São Paulo\n", 12396372, 1521.11, 699.28, 120};

    calcularDados(&carta1);
    calcularDados(&carta2);

    int opcao;
    do {
        printf("\n--- Menu de Comparacão ---\n");
        printf("1. Comparar População\n");
        printf("2. Comparar Área\n");
        printf("3. Comparar PIB\n");
        printf("4. Comparar Pontos Turísticos\n");
        printf("5. Comparar Densidade Populacional\n");
        printf("6. Comparar PIB per Capita\n");
        printf("7. Comparar Dois Atributos: PIB e Pontos Turísticos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                compararSimples("População", carta1.populacao, carta2.populacao);
                break;
            case 2:
                compararSimples("\u00c1rea", carta1.area, carta2.area);
                break;
            case 3:
                compararSimples("PIB", carta1.pib, carta2.pib);
                break;
            case 4:
                compararSimples("Pontos Turísticos", carta1.pontosTuristicos, carta2.pontosTuristicos);
                break;
            case 5:
                compararSimples("Densidade Populacional", carta1.densidadePopulacional, carta2.densidadePopulacional);
                break;
            case 6:
                compararSimples("PIB per Capita", carta1.pibPerCapita, carta2.pibPerCapita);
                break;
            case 7:
                compararDuplo("PIB", carta1.pib, carta2.pib, "Pontos Turísticos", carta1.pontosTuristicos, carta2.pontosTuristicos);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}