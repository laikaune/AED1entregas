# Laila Kauane - 23103141

📒 Agenda com pBuffer em C

📌 Descrição
Este projeto implementa uma agenda simples em C, onde todos os dados são armazenados em um único bloco de memória (pBuffer). O desafio foi utilizar apenas ponteiros para manipular os dados, sem declarar variáveis tradicionais ou structs.

🔧 Funcionalidades
1️⃣ Adicionar Pessoa → Armazena nome, email e idade no pBuffer.
2️⃣ Remover Pessoa → Remove uma pessoa cadastrada.
3️⃣ Buscar Pessoa → Exibe os dados de uma pessoa pelo nome.
4️⃣ Listar Todos → Mostra todas as pessoas cadastradas.
5️⃣ Sair → Libera a memória e encerra o programa.


🗂 Organização do pBuffer
O pBuffer tem um tamanho fixo de 1024 bytes, onde são armazenados:

📛 Nome → 50 bytes
📧 Email → 50 bytes
🔢 Idade → Inteiro armazenado após nome e email
📌 Opção do Menu → Armazenada nos últimos bytes

🖥 Como Compilar e Executar
Para compilar:
gcc -o AgendaPbufferLaila AgendaPbufferLaila.c
Para executar:
./AgendaPbufferLaila

✅ Casos de Teste Realizados
📝 Teste 1 – Adicionar e listar uma pessoa
Passos:

Escolher a opção 1 (Adicionar Pessoa)
Inserir:
Nome: João Silva
Email: joao@email.com
Idade: 25
Escolher a opção 4 (Listar Todos)
Resultado esperado:
Nome: João Silva  
Email: joao@email.com  
Idade: 25  
🔍 Teste 2 – Buscar uma pessoa cadastrada
Passos:

Adicionar "Maria Oliveira" com email maria@email.com e idade 30
Escolher a opção 3 (Buscar Pessoa) e digitar "Maria Oliveira"
Resultado esperado:
Nome: Maria Oliveira  
Email: maria@email.com  
Idade: 30  
🗑️ Teste 3 – Remover uma pessoa
Passos:

Adicionar "Carlos Mendes"
Escolher a opção 2 (Remover Pessoa) e digitar "Carlos Mendes"
Escolher a opção 4 (Listar Todos)
Resultado esperado:
Nenhuma pessoa cadastrada.  
📌 Observações
✔️ O código foi testado com Valgrind, sem vazamentos de memória.
✔️ Segue as regras do desafio, sem uso de variáveis declaradas ou structs.
