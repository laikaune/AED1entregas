# LAILA KAUANE CARVALHO DA SILVA
# Maximum Average Pass Ratio

Este programa resolve um problema de maximizar a média da taxa de aprovação em turmas, distribuindo alunos extras de forma estratégica.

## 📌 Descrição

Dado um conjunto de turmas onde cada uma tem um número de alunos aprovados e um número total de alunos, além de um número extra de alunos garantidos que sempre passarão, o objetivo é distribuir esses alunos extras para maximizar a média final da taxa de aprovação.

Para isso, o programa utiliza uma **heap máxima** para priorizar a turma onde adicionar um aluno extra traria o maior benefício.

## 🛠️ Como Compilar e Executar

### **1. Compilar**
No terminal, execute o seguinte comando para compilar o programa:

```sh
gcc MaximumAverageLaila.c -o MaximumAverageLaila -lm

## **2. Executar**

Após a compilação, rode o programa com:
./MaximumAverageLaila

📥 Entrada e 📤 Saída
Exemplo de Entrada
O código usa uma matriz com as turmas no formato [aprovados, total] e um número de alunos extras. 
Exemplo:
int dados[][2] = {{1,2}, {3,5}, {2,2}};
int tamanho = 3;
int alunosExtras = 2;
Exemplo de Saída
Média final: 0.78333

Isso significa que, distribuindo os alunos extras da melhor maneira, a média final da taxa de aprovação será aproximadamente 78,33%.

🏗️ Estrutura do Código

struct Turma: Guarda os dados de cada turma.
calcularGanho(): Calcula o quanto a taxa de aprovação de uma turma melhora ao adicionar um aluno extra.
ajustarHeap() e construirHeap(): Mantêm a heap máxima organizada.
maximoMediaAprovacao(): Principal função que distribui os alunos extras da melhor maneira.
main(): Testa o programa com um conjunto de dados e imprime o resultado.

⚡ Conclusão

Este programa usa heap máxima para distribuir os alunos de forma eficiente, garantindo que a média final seja a mais alta possível. Ele funciona para qualquer número de turmas e alunos extras, mantendo um bom desempenho.
