# Trabalho 2 - O Labirinto Recorrente
Trabalho 2 de AEDS com implementação em C++ de "O Labirinto Recorrente".

<div style="display: inline-block;">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg"/> 
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
<a href="https://github.com/mpiress/midpy/issues">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat"/>
<img align="center" height="20px" width="80px" src="https://badgen.net/badge/license/MIT/green"/>
</a> 
</div>

<p> </p>
<p> </p>

<h2>Introdução </h2>

<p> Por muitos anos, foram criados jogos, principalmente 2d, no qual a sua movimentação se baseava em oito direções: Acima, abaixo, direita, esquerda e todas as diagonais. Atualmente, ---. Dito isso, o Labirinto Recorrente utiliza de matrizes NxN formada por variados caminhos que podem aumentar sua vida, diminuir sua vida, acrescentar sua quantidade de itens ou bloquear o seu caminho. </p>

<p> O programa consiste na utilização de K matrizes quadradas de tamanho [N/N], a fim de determinar o caminho com os maiores valores numéricos próximos de determinada posição. </p>

<h2>Objetivo </h2>

<p> Para vencer o Labirinto Recorrente, é necessário percorrer todas as posições </p>


<h2>Compilação e Execução do Programa</h2>

<p>Através do makefile, é posição utilizar comandos que realizam o processo de compilação e execução do programa. A seguir, temos alguns comandos que podem ser utilizados:</p><br>

<li><b>make</b>: Realiza a compilação do código por meio do gcc, no qual o resultado vai para a pasta build.</li><br>
<li><b>make run</b>: Executa o programa armazenado na pasta build após este ser compilado.</li><br>
<li><b>make clean</b>: Exclui a última compilação feita anteriormente na pasta build.</li><br><br>

<p>Também é possível executar o programa através do site de hospedagem de código, Replit, onde foi realizado a programação do código do "O Labirinto Recorrente": <link>https://replit.com/@Joao-MarcosMa57/Trabalho-2-AEDS</link></p>

<br>

<h2>Conclusão</h2>

<p>Não é possível calcular o custo computacional de um programa com caminhos randômicos, pois existem inúmeras possibilidades de opções para serem analisadas. No entanto, é possível pegar um caso específico, ou melhor, um caso especial para ser explorado, que é o caso do programa percorrer todas as colunas de uma determinada linha e logo em seguida passar para a próxima. Caso isso aconteça, o custo computacional será n*M. </p>


<h2>Contato</h2>

<p><i>marcosjoaohess@gmail.com</i></p>
