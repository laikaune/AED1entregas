#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50     // Tamanho máximo para o campo nome
#define TAM_EMAIL 50    // Tamanho máximo para o campo email
#define TAM_BUFFER 1024 // Tamanho total do buffer de memória

// Declaração dos protótipos das funções, todas recebem o pBuffer (buffer de memória) como parâmetro
void AdicionarPessoa(void *pBuffer);
void RemoverPessoa(void *pBuffer);
void BuscarPessoa(void *pBuffer);
void ListarTodos(void *pBuffer);
void Sair(void *pBuffer);

// Função auxiliar para exibir o menu e ler a opção escolhida
// Recebe como parâmetro um ponteiro para o local onde a opção será armazenada
void MostraMenu(int *pEscolha);

int main() {
    // Aloca dinamicamente um bloco de memória de tamanho TAM_BUFFER
    // Esse bloco de memória (pBuffer) será usado para armazenar TODAS as informações do programa
    void *pBuffer = malloc(TAM_BUFFER);
    if (!pBuffer) { // Verifica se a alocação foi bem-sucedida
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Define a posição no pBuffer onde será armazenada a opção do menu
    // A opção é armazenada nos últimos bytes do pBuffer: (pBuffer + TAM_BUFFER - sizeof(int))
    int *pEscolha = (int *)(pBuffer + TAM_BUFFER - sizeof(int));

    // Loop principal do programa (menu)
    while (1) {
        // Exibe o menu e lê a opção escolhida, armazenando-a em pEscolha
        MostraMenu(pEscolha);

        // Verifica a opção escolhida e chama a função correspondente
        switch (*pEscolha) {
            case 1:
                AdicionarPessoa(pBuffer);
                break;
            case 2:
                RemoverPessoa(pBuffer);
                break;
            case 3:
                BuscarPessoa(pBuffer);
                break;
            case 4:
                ListarTodos(pBuffer);
                break;
            case 5:
                Sair(pBuffer);
                free(pBuffer); // Libera a memória alocada antes de encerrar o programa
                return 0;
            default:
                // Caso a opção não seja de 1 a 5, exibe mensagem de opção inválida
                printf("Opção inválida.\n");
                break;
        }
    }

    return 0;
}

// Função para adicionar uma pessoa ao pBuffer
// Essa função utiliza o pBuffer para armazenar os dados da pessoa: nome, email e idade
void AdicionarPessoa(void *pBuffer) {
    // Define um ponteiro para o início do buffer para armazenar o nome
    // O nome será armazenado a partir do início do pBuffer
    char *pNome = (char *)(pBuffer);

    // O email será armazenado logo após o nome, ou seja, no endereço pBuffer + TAM_NOME
    char *pEmail = (char *)(pBuffer + TAM_NOME);

    // A idade será armazenada logo após o nome e o email:
    // endereço pBuffer + TAM_NOME + TAM_EMAIL
    int *pIdade = (int *)(pBuffer + TAM_NOME + TAM_EMAIL);

    // Solicita o nome da pessoa e lê do teclado
    printf("Nome: ");
    fgets(pNome, TAM_NOME, stdin);
    // Remove o caractere de nova linha (\n) que pode ter sido lido pelo fgets
    pNome[strcspn(pNome, "\n")] = '\0';

    // Solicita o email da pessoa e lê do teclado
    printf("Email: ");
    fgets(pEmail, TAM_EMAIL, stdin);
    // Remove o \n
    pEmail[strcspn(pEmail, "\n")] = '\0';

    // Solicita a idade e lê um inteiro do teclado
    printf("Idade: ");
    scanf("%d", pIdade);
    getchar(); // Remove o '\n' que fica no buffer do teclado

    // Informa que a pessoa foi adicionada com sucesso
    printf("Pessoa adicionada!\n");
}

// Função para remover uma pessoa do pBuffer
// Essa implementação simples utiliza o campo nome para identificar a pessoa a ser removida
void RemoverPessoa(void *pBuffer) {
    // Define os ponteiros para nome, email e idade
    // Como nessa implementação não estamos usando lista encadeada,
    // presume-se que os dados de uma única pessoa estão armazenados no início do pBuffer
    char *pNome = (char *)(pBuffer);
    char *pEmail = (char *)(pBuffer + TAM_NOME);
    int *pIdade = (int *)(pBuffer + TAM_NOME + TAM_EMAIL);

    // Solicita o nome da pessoa que se deseja remover
    printf("Digite o nome da pessoa a ser removida: ");
    fgets(pNome, TAM_NOME, stdin);
    pNome[strcspn(pNome, "\n")] = '\0';

    // Se o nome tiver algum caractere (ou seja, se não estiver vazio)
    if (strlen(pNome) > 0) {
        // Limpa os dados armazenados para "remover" a pessoa
        memset(pNome, 0, TAM_NOME);   // Zera o campo nome
        memset(pEmail, 0, TAM_EMAIL);  // Zera o campo email
        *pIdade = 0;                  // Zera a idade
        printf("Pessoa removida!\n");
    } else {
        // Se o nome estiver vazio, exibe mensagem que a pessoa não foi encontrada
        printf("Pessoa não encontrada.\n");
    }
}

// Função para buscar uma pessoa pelo nome no pBuffer
// Novamente, essa implementação simples considera que há apenas uma pessoa armazenada
void BuscarPessoa(void *pBuffer) {
    // Define os ponteiros para acessar os dados (nome, email e idade)
    char *pNome = (char *)(pBuffer);
    char *pEmail = (char *)(pBuffer + TAM_NOME);
    int *pIdade = (int *)(pBuffer + TAM_NOME + TAM_EMAIL);

    // Solicita o nome da pessoa a ser buscada
    printf("Digite o nome da pessoa a ser buscada: ");
    fgets(pNome, TAM_NOME, stdin);
    pNome[strcspn(pNome, "\n")] = '\0';

    // Se o nome tiver conteúdo (não vazio), imprime os dados
    if (strlen(pNome) > 0) {
        printf("Nome: %s\n", pNome);
        printf("Email: %s\n", pEmail);
        printf("Idade: %d\n", *pIdade);
    } else {
        // Se o nome estiver vazio, informa que a pessoa não foi encontrada
        printf("Pessoa não encontrada.\n");
    }
}

// Função para listar os dados de todas as pessoas cadastradas
// Nessa implementação, há apenas uma pessoa armazenada no pBuffer
void ListarTodos(void *pBuffer) {
    // Define os ponteiros para acessar os dados da pessoa
    char *pNome = (char *)(pBuffer);
    char *pEmail = (char *)(pBuffer + TAM_NOME);
    int *pIdade = (int *)(pBuffer + TAM_NOME + TAM_EMAIL);

    // Se o campo nome não estiver vazio, assume que há uma pessoa cadastrada e exibe os dados
    if (strlen(pNome) > 0) {
        printf("Nome: %s\n", pNome);
        printf("Email: %s\n", pEmail);
        printf("Idade: %d\n", *pIdade);
    } else {
        // Caso contrário, informa que não há nenhuma pessoa cadastrada
        printf("Nenhuma pessoa cadastrada.\n");
    }
}

// Função para sair do programa
void Sair(void *pBuffer) {
    // Apenas exibe uma mensagem de saída
    // pBuffer não é utilizado nessa função, mas está presente para manter a consistência da assinatura
    printf("Saindo...\n");
}

// Função auxiliar para exibir o menu e ler a opção do usuário
// O parâmetro pEscolha aponta para o local no pBuffer onde a opção será armazenada
void MostraMenu(int *pEscolha) {
    // Há um erro de digitação na função abaixo, onde "printf" está escrito incorretamente como "printtf"
    // Corrigindo: removemos essa linha ou corrigimos para "printf("\n");"
    printf("\n");

    // Exibe as opções do menu
    printf("1- Adicionar Pessoa\n");
    printf("2- Remover Pessoa\n");
    printf("3- Buscar Pessoa\n");
    printf("4- Listar todos\n");
    printf("5- Sair\n");
    printf("Escolha uma opção: ");
    
    // Lê a opção do usuário e armazena no endereço apontado por pEscolha
    scanf("%d", pEscolha);
    getchar(); // Remove o '\n' deixado no buffer após a leitura do número
}
