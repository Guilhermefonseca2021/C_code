#include <stdio.h>
#include <string.h>

#define TAMANHO_ACERVO 20   // Define o tamanho máximo do acervo de livros.

/*
    ---------------------------------------------------------
    STRUCT: Representa um livro dentro do acervo.
    Cada campo modela uma informação essencial do catálogo.
    ---------------------------------------------------------
*/
struct Livro {
    int codigo;
    char titulo[50];
    char autor[30];
    char area[30];
    int ano;
    char editora[30];
};

/*  ---------------------------------------------------------
    Protótipos das funções
    Mantém a organização do código ao permitir que as funções
    sejam definidas após a função main.
    --------------------------------------------------------- */
void cadastrarLivros(struct Livro acervo[], int tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca);
void ordenarLivros(struct Livro acervo[], int tamanho);

/*
    =========================================================
    FUNÇÃO PRINCIPAL
    Controla o fluxo do sistema: exibe menu, recebe comandos
    do usuário e delega para as funções apropriadas.
    =========================================================
*/
int main() {
    struct Livro acervo[TAMANHO_ACERVO];   // Vetor de structs representando o acervo.
    int opcao;
    int codigoBusca;

    do {
        // Menu principal
        printf("\n================ Sistema de Biblioteca ================\n");
        printf("1 - Cadastrar livros\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Pesquisar livro por codigo\n");
        printf("4 - Ordenar livros por ano de publicacao\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                // Cadastro completo de todos os livros
                cadastrarLivros(acervo, TAMANHO_ACERVO);
                break;

            case 2:
                // Exibe o conteúdo total do acervo
                imprimirLivros(acervo, TAMANHO_ACERVO);
                break;

            case 3:
                // Pesquisa por código — identificador único
                printf("Digite o codigo do livro para pesquisa: ");
                scanf("%d", &codigoBusca);
                pesquisarLivro(acervo, TAMANHO_ACERVO, codigoBusca);
                break;

            case 4:
                // Ordenação crescente por ano usando BubbleSort
                ordenarLivros(acervo, TAMANHO_ACERVO);
                printf("Livros ordenados com sucesso!\n");
                break;

            case 5:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}

/*
    -------------------------------------------------------------
    FUNÇÃO: cadastrarLivros
    Lê do teclado os dados de cada livro e popula o vetor acervo.

    Observação:
    Uso proposital de scanf() simples para manter a implementação
    em nível introdutório, conforme práticas das disciplinas iniciais.
    -------------------------------------------------------------
*/
void cadastrarLivros(struct Livro acervo[], int tamanho) {
    printf("\n--- Cadastro de Livros ---\n");

    for (int i = 0; i < tamanho; i++) {
        printf("\nLivro %d:\n", i + 1);

        printf("Codigo: ");
        scanf("%d", &acervo[i].codigo);

        printf("Titulo (sem espaços, use _): ");
        scanf("%s", acervo[i].titulo);

        printf("Autor (sem espaços, use _): ");
        scanf("%s", acervo[i].autor);

        printf("Area (sem espaços, use _): ");
        scanf("%s", acervo[i].area);

        printf("Ano: ");
        scanf("%d", &acervo[i].ano);

        printf("Editora (sem espaços, use _): ");
        scanf("%s", acervo[i].editora);
    }
}

/*
    -------------------------------------------------------------
    FUNÇÃO: imprimirLivros
    Percorre o vetor e exibe todas as informações cadastradas.
    Útil para testes visuais e validação do acervo.
    -------------------------------------------------------------
*/
void imprimirLivros(struct Livro acervo[], int tamanho) {
    printf("\n--- Lista de Livros Cadastrados ---\n");

    for (int i = 0; i < tamanho; i++) {
        printf("\nLivro %d:\n", i + 1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
    }
}

/*
    -------------------------------------------------------------
    FUNÇÃO: pesquisarLivro
    Busca linear pelo código informado. Decisão lógica adequada
    para vetores pequenos (20 posições). Simples, eficiente e clara.
    -------------------------------------------------------------
*/
void pesquisarLivro(struct Livro acervo[], int tamanho, int codigoBusca) {
    int encontrado = 0;

    for (int i = 0; i < tamanho; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\n--- Livro Encontrado ---\n");
            printf("Codigo: %d\n", acervo[i].codigo);
            printf("Titulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Area: %s\n", acervo[i].area);
            printf("Ano: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nLivro nao encontrado!\n");
    }
}

/*
    -------------------------------------------------------------
    FUNÇÃO: ordenarLivros
    Implementação clássica do algoritmo Bubble Sort.

    Justificativa da escolha:
    - O acervo é pequeno (20 posições).
    - Algoritmo simples, didático e adequado para disciplinas iniciais.
    - Fácil de explicar no vídeo do MAPA.
    -------------------------------------------------------------
*/
void ordenarLivros(struct Livro acervo[], int tamanho) {
    struct Livro temp;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {

            // Troca se o ano atual for maior que o próximo
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j];
                acervo[j] = acervo[j + 1];
                acervo[j + 1] = temp;
            }
        }
    }
}
