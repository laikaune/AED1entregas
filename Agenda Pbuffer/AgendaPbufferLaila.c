#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definições de tamanho */
#define TAM_NOME      50                          // Tamanho máximo do nome
#define TAM_EMAIL     50                          // Tamanho máximo do email
#define TAM_IDADE     sizeof(int)                 // Tamanho do campo idade
#define TAM_PTR       sizeof(void*)               // Tamanho de um ponteiro
#define TAM_NO        (TAM_NOME + TAM_EMAIL + TAM_IDADE + TAM_PTR)  // Tamanho total de cada nó
#define TEMP_AREA     100                         // Área reservada para dados temporários (ex.: entrada do menu)
#define TAM_BUFFER    1024                        // Tamanho total do buffer
 
void MostrarMenu(void *pBuffer);
void *ProximoNo(void *pBuffer);
void AdicionarPessoa(void *pBuffer);
void RemoverPessoa(void *pBuffer);
void BuscarPessoa(void *pBuffer);
void ListarTodos(void *pBuffer);
void Sair(void *pBuffer);

int main(){
    /* pBuffer é a única variável primitiva: ele armazena:
         [0, TAM_PTR)           -> ponteiro para o primeiro nó (cabeça da lista)
         [TAM_PTR, TAM_BUFFER-TEMP_AREA) -> área de nós
         [TAM_BUFFER-TEMP_AREA, TAM_BUFFER) -> área temporária (ex.: opção do menu, entradas)
    */
    void *pBuffer = malloc(TAM_BUFFER);
    if(!pBuffer){
         printf("Erro na alocação de memória!\n");
         return 1;
    }
    /* Inicializa a cabeça da lista com NULL */
    *((void **)pBuffer) = NULL;
    
    while(1){
         MostrarMenu(pBuffer);
         /* A opção lida está armazenada no início da área temporária */
         void *pOpcao = (void *)((char *)pBuffer + TAM_BUFFER - TEMP_AREA);
         switch(*((int *)pOpcao)){
             case 1: AdicionarPessoa(pBuffer); break;
             case 2: RemoverPessoa(pBuffer); break;
             case 3: BuscarPessoa(pBuffer); break;
             case 4: ListarTodos(pBuffer); break;
             case 5: 
                      Sair(pBuffer); 
                      free(pBuffer);
                      return 0;
             default: printf("Opção inválida!\n");
         }
    }
    return 0;
}

/* ================================================
   Função: MostrarMenu
   Objetivo: Exibir o menu e capturar a opção do usuário.
   a opção é armazenada na área temporária do pBuffer.
   ================================================ */
void MostrarMenu(void *pBuffer){
    char *pTemp = (char *)pBuffer + TAM_BUFFER - TEMP_AREA;
    printf("\n[Menu]");
    printf("\n1- Adicionar Pessoa");
    printf("\n2- Remover Pessoa");
    printf("\n3- Buscar Pessoa");
    printf("\n4- Listar todos");
    printf("\n5- Sair");
    printf("\nEscolha: ");
    scanf("%d", (int *)pTemp);
    getchar();
}

/* ================================================
   Função: ProximoNo
   Objetivo: Retorna o endereço onde o novo nó deve ser inserido.
   O layout do pBuffer é:
      - Offset 0: head pointer (TAM_PTR bytes)
      - Offset TAM_PTR até TAM_BUFFER - TEMP_AREA: área de nós
      - Offset TAM_BUFFER - TEMP_AREA até TAM_BUFFER: área temporária
   Se a lista estiver vazia, o novo nó será em (pBuffer+TAM_PTR).
   Caso contrário, ele é posicionado logo após o último nó.
   ================================================ */
void *ProximoNo(void *pBuffer){
    char *pBase = (char *)pBuffer;
    char *pFimUtil = pBase + TAM_BUFFER - TEMP_AREA;
    void **pHead = (void **)pBuffer;
    char *novo;
    if(*pHead == NULL){
         novo = pBase + TAM_PTR;
         if(novo + TAM_NO > pFimUtil){
              printf("Memória insuficiente!\n");
              return NULL;
         }
         return novo;
    } else {
         char *pAtual = (char *)(*pHead);
         while(1){
              /* O campo "próximo" de cada nó está armazenado em:
                   pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE */
              void **pNext = (void **)(pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE);
              if(*pNext == NULL){
                  novo = pAtual + TAM_NO;
                  if(novo + TAM_NO > pFimUtil){
                        printf("Memória insuficiente!\n");
                        return NULL;
                  }
                  return novo;
              }
              pAtual = (char *)(*pNext);
         }
    }
}

/* ================================================
   Função: AdicionarPessoa
   Objetivo: Adicionar um novo registro na lista
   ================================================ */
void AdicionarPessoa(void *pBuffer){
    void *novoNo = ProximoNo(pBuffer);
    if(novoNo == NULL)
         return;
    void **pHead = (void **)pBuffer;
    if(*pHead == NULL){
         /* Lista vazia: o novo nó se torna o primeiro */
         *pHead = novoNo;
    } else {
         /* Percorre a lista até encontrar o último nó e atualiza seu ponteiro "próximo" */
         char *pAtual = (char *)(*pHead);
         while(1){
              void **pNext = (void **)(pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE);
              if(*pNext == NULL){
                    *pNext = novoNo;
                    break;
              }
              pAtual = (char *)(*pNext);
         }
    }
    /* Define os campos do nó */
    char *pNome = (char *)novoNo;                   // Campo Nome (TAM_NOME bytes)
    char *pEmail = pNome + TAM_NOME;                  // Campo Email (TAM_EMAIL bytes)
    int  *pIdade = (int *)(pEmail + TAM_EMAIL);       // Campo Idade
    void **pProx = (void **)((char *)pIdade + TAM_IDADE); // Ponteiro "próximo"
    
    printf("Nome: ");
    fgets(pNome, TAM_NOME, stdin);
    pNome[strcspn(pNome, "\n")] = '\0';
    
    printf("Email: ");
    fgets(pEmail, TAM_EMAIL, stdin);
    pEmail[strcspn(pEmail, "\n")] = '\0';
    
    printf("Idade: ");
    scanf("%d", pIdade);
    getchar(); // Limpa o buffer
    
    *pProx = NULL;
    printf("Pessoa cadastrada!\n");
}

/* ================================================
   Função: RemoverPessoa
   Objetivo: Remover um registro da lista (buscando pelo nome).
   ================================================ */
void RemoverPessoa(void *pBuffer){
    void **pHead = (void **)pBuffer;
    if(*pHead == NULL){
         printf("Lista vazia!\n");
         return;
    }
    /* Usa a área temporária para armazenar o nome a remover */
    char *pTemp = (char *)pBuffer + TAM_BUFFER - TEMP_AREA;
    printf("Nome para remover: ");
    fgets(pTemp, TAM_NOME, stdin);
    pTemp[strcspn(pTemp, "\n")] = '\0';
    
    /* Se o nó a remover for o primeiro */
    char *pHeadNode = (char *)(*pHead);
    if(strcmp(pHeadNode, pTemp) == 0){
         void **pNext = (void **)(pHeadNode + TAM_NOME + TAM_EMAIL + TAM_IDADE);
         *pHead = *pNext;
         memset(pHeadNode, 0, TAM_NO);
         printf("Registro removido!\n");
         return;
    }
    /* Caso contrário, percorre a lista */
    char *pAnterior = (char *)(*pHead);
    while(1){
         void **pNext = (void **)(pAnterior + TAM_NOME + TAM_EMAIL + TAM_IDADE);
         if(*pNext == NULL){
              printf("Registro não encontrado!\n");
              return;
         }
         char *pAtual = (char *)(*pNext);
         if(strcmp(pAtual, pTemp) == 0){
              void **pAtualNext = (void **)(pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE);
              /* Atualiza o ponteiro "próximo" do nó anterior */
              *(void **)(pAnterior + TAM_NOME + TAM_EMAIL + TAM_IDADE) = *pAtualNext;
              memset(pAtual, 0, TAM_NO);
              printf("Registro removido!\n");
              return;
         }
         pAnterior = (char *)(*pNext);
    }
}

/* ================================================
   Função: BuscarPessoa
   Objetivo: Buscar e exibir um registro pelo nome.
   ================================================ */
void BuscarPessoa(void *pBuffer){
    void **pHead = (void **)pBuffer;
    if(*pHead == NULL){
         printf("Lista vazia!\n");
         return;
    }
    char *pTemp = (char *)pBuffer + TAM_BUFFER - TEMP_AREA;
    printf("Nome para buscar: ");
    fgets(pTemp, TAM_NOME, stdin);
    pTemp[strcspn(pTemp, "\n")] = '\0';
    
    char *pAtual = (char *)(*pHead);
    while(pAtual != NULL){
         if(strcmp(pAtual, pTemp) == 0){
              char *pEmail = pAtual + TAM_NOME;
              int *pIdade = (int *)(pEmail + TAM_EMAIL);
              printf("Nome: %s\nEmail: %s\nIdade: %d\n", pAtual, pEmail, *pIdade);
              return;
         }
         void **pNext = (void **)(pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE);
         pAtual = (char *)(*pNext);
    }
    printf("Registro não encontrado!\n");
}

/* ================================================
   Função: ListarTodos
   Objetivo: Exibir todos os registros cadastrados.
   ================================================ */
void ListarTodos(void *pBuffer){
    void **pHead = (void **)pBuffer;
    if(*pHead == NULL){
         printf("Lista vazia!\n");
         return;
    }
    char *pAtual = (char *)(*pHead);
    while(pAtual != NULL){
         char *pEmail = pAtual + TAM_NOME;
         int *pIdade = (int *)(pEmail + TAM_EMAIL);
         printf("Nome: %s\nEmail: %s\nIdade: %d\n\n", pAtual, pEmail, *pIdade);
         void **pNext = (void **)(pAtual + TAM_NOME + TAM_EMAIL + TAM_IDADE);
         pAtual = (char *)(*pNext);
    }
}

/* ================================================
   Função: Sair
   Objetivo: Encerrar o programa.
   ================================================ */
void Sair(void *pBuffer){
    printf("Encerrando programa...\n");
}
