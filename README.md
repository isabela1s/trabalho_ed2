[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/KWzaodOp)
# Atividade Prática Sobre Tabelas Hash

## Motivação

As tabelas hash representam uma das estruturas de dados mais importantes na ciência da computação,
sendo amplamente utilizadas em sistemas que demandam eficiência na manipulação e recuperação de
informações. Sua relevância é notável em diversas áreas, como mecanismos de busca, bancos de dados e
algoritmos otimizados.

Nesta atividade, você terá a oportunidade de aprofundar seus conhecimentos sobre o funcionamento das
tabelas hash, explorando conceitos fundamentais, como funções de hash, colisões e as estratégias mais
adequadas para resolvê-las. Além disso, será possível compreender como a aplicação de princípios teóricos
pode impactar diretamente o desempenho e a escalabilidade de sistemas computacionais.
Este exercício não apenas fortalecerá sua base conceitual, mas também desenvolverá habilidades práticas
essenciais para o trabalho com estruturas de dados. É uma oportunidade para analisar, projetar e imple-
mentar soluções que refletem desafios reais enfrentados por profissionais da área.
Convidamos você a se dedicar a esta atividade com foco e rigor, para que possa extrair o máximo aprendi-
zado e consolidar seu domínio sobre este tema fundamental. Que este seja mais um passo significativo em
sua jornada de desenvolvimento acadêmico e profissional.

Vamos iniciar?

## Primeira parte

Usando o TAD fornecido como base você deverá implementar as funções básicas de uma hash e de seu
registo. O registro da hash em questão será composto de uma string, que chamaremos de de nome, uma
variável numérica que armazenará um ano e outra que armazenará a quantidade de pessoas registradas
com aquele nome. Nessa primeira parte você deverá implementar o construtor e destrutor do registro e da
hash e os métodos getters e setters do registro e da hash.
Você também deverá criar um método que imprime a tabela hash e um que, dado um número X qualquer,
sendo X ≤ tamanho da tabela, percorre toda a tabela e seleciona os X nomes com maior ocorrência, e
imprime esses nomes.

**IMPORTANTE:** sua hash deverá conter o menor número possível de posições.

## Segunda parte

Usando os métodos implementados anteriormente, você deve implementar o tratamento de colisão
conhecido como **Endereçamento Aberto** utilizando o sistema de Double Hashing. Você deverá usar o nome
lido do csv como chave, e, para tal, pode usar a seguinte operação para achar a chave:

'''
hashV alue = (hashV alue ∗ base + static_cast < unsignedlonglong > (c))% mod
'''

sendo c cada char contido na string. Use base = 31 e mod = 1e9 + 7.

## Terceira parte
   
Com o TAD Tabela Hash completo, você deverá agora implementar uma função de busca (acha
_registro e
pega_registro) que busca e devolve um registro da tabela de maneira otimizada e com o menor número
de acessos possíveis.

## Dataset
Para realizar os testes necessários, você irá usar o csv contido na mesma pasta dos arquivos de código. Um
método para ler o csv deverá ser criado.

## Perguntas teóricas

Responda as seguintes questões teóricas após fazer sua atividade prática:

### Questão 1. 
Como garantir a escolha de uma função de hash eficiente para minimizar colisões em aplicações práticas?

### Questão 2. 
Em tabelas hash com endereçamento aberto, como o problema de agrupamentos primários e secundários impacta o desempenho?

### Questão 3. 
Como o fator de carga (load factor) afeta o desempenho de uma tabela hash, e quais estratégias podem ser adotadas para mantê-lo sob controle?

## Referencias


