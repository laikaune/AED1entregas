# Laila Kauane - 23103141
Agenda com pBuffer em C

Descrição: 
Projeto de uma agenda em C onde todos os dados são armazenados em um único bloco de memória (pBuffer). O desafio foi utilizar apenas ponteiros para manipular os dados (nome, email, idade e opção do menu), sem declarar variáveis simples ou structs.

Funcionalidades
Adicionar Pessoa: Armazena nome, email e idade no pBuffer.
Remover Pessoa: Zera os dados de uma pessoa (identificada pelo nome).
Buscar Pessoa: Exibe os dados de uma pessoa cadastrada.
Listar Todos: Mostra os dados cadastrados (nesta versão, apenas um registro).
Sair: Libera o pBuffer e encerra o programa.
Organização
pBuffer: 1024 bytes alocados dinamicamente.
Dados da Pessoa:
Nome: 50 bytes
Email: 50 bytes
Idade: armazenada após nome e email
Opção do Menu: Armazenada nos últimos bytes do pBuffer.
Compilação e Execução
Para compilar o projeto, use:
gcc -o AgendaPbufferLaila AgendaPbufferLaila.c

Para executar:
/AgendaPbufferLaila

Observações
Projeto implementado seguindo o desafio de usar apenas ponteiros e um único pBuffer para gerenciar os dados.
Testado com a ferramenta de verificação de vazamento de memória Valgrind.