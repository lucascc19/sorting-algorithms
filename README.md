# sorting-algorithms
💻 Trabalho de Estrutura de Dados Avançadas
Foi implemetado dois algortimos de ordenação usando a linguagem C, que são:
1. Heap-sort
2. Insertion-sort
## Heap-sort
O Heap Sort é uma técnica de ordenação baseada em comparação com base na Binary Heap. Esta técnica é semelhante ao Select Sort, onde primeiro encontramos o elemento mínimo e colocamos o elemento mínimo no início. Repita o mesmo processo para os demais elementos.
A diferença dele para o Insertion Sort é que o tempo necessário para realizar a ordenaçãoaumenta logaritmicamente, enquanto o Insertion cresce exponencialmente mais lento. Além disso o uso de memória é mínimo, visto que, além do necessário para manter a lista inicial de itens a serem classificados, não precisa de espaço de memória adicional para funcionar. <br>
**Complexidade de tempo:** O(N log N)
## Insertion-sort
O Insertion Sort se trata de um algoritmo de ordenação simples que funciona de maneira semelhante à maneira como você classifica as cartas de baralho em suas mãos. A matriz é virtualmente dividida em um parte classificada e uma parte não classificada. Os valores da peça não classificada são selecionados e colocados na posição correta na peça classificada. Vale ressaltar que a ordenação por inserção é eficiente para pequenos valores de dados, visto que quando se trata de valores maiores ou quando são classificados em ordem inversa, o algoritmo leva mais tempo para classificá-los.
**Complexidade de tempo:** O(N²)
---
Após a implementação, foi realizado um teste com vetores de 1.000, 10.000, 100.000 e 1.000.000. Eis o resultado:
Tamanho do vetor   | Heap-sort | Insertion-sort
------------------ | --------- | --------------
1.000              | 2 ms      | 5 ms
10.000             | 10 ms     | 79 ms
100.000            | 44 ms     | 5668 ms
1.000.000          | 537 ms    | 597813 ms
