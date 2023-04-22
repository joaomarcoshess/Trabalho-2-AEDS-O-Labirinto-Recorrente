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

<p> Para vencer o Labirinto Recorrente, é necessário percorrer todas as posições dos labirintos que não sejam as de perigo e as paredes, podendo ser quaisquer uma das 8 posições ao redor do garoto, a partir de um sorteio realizado pelo sistema para determinar qual posição será utilizada pelo mesmo. Além disso, quando ele chegar no labirinto final, ele será retornado para o labirinto inicial. Sua única forma de ganhar o jogo será chegar no labirinto final sem estar com nenhum item na sua sacola. O programa fará uma leitura do arquivo input.data, onde estão armazenadas as matrizes, e o usuário poderá determinar um ponto inicial, que não seja uma parede, para iniciar o programa.</p>

<p> O sistema é formado por casas que possuem número de itens gerados aleatoriamente, que aumentam a vida do garoto, paredes que bloqueiam o caminho do menino , perigos, que diminui a vida do garoto e portais, que teleportam o menino para o labirinto inicial. Estes são representados por número, pelo símbolo #, pelo símbolo * e pela letra X, respectivamente.</p>

<h2>Regras e Movimentação </h2>

``` Regras: ```

 - O garoto inicia o jogo com 10 vidas, não podendo aumentar caso encontre itens;
 - O garoto só ganhará mais vidas se estiver com 4 itens na sacola, a não ser que ele já esteja com 10 vidas;
 - A única forma de pegar itens é ir à uma posição que contenha uma quantidade de itens diferente de 0, não podendo pegar mais do que 1 item;
 - O garoto sempre se movimentará de forma aleatória;
 - Se a posição não tiver um item, nada irá acontecer;
 - Os labirintos estão cercados de portais em volta deles mesmo, então caso o garoto ultrapasse os limites das matrizes, o mesmo será levado para o próximo labirinto, a não ser que aquele seja o último labirinto;
 - Caso o labirinto em que o garoto se situa seja o último, o garoto irá voltar para o labirinto inicial;
 - O garoto só vence o jogo se chegar do primeiro labirinto ao último labirinto sem pegar um item;
 - O garoto só perde o jogo se perder todas as suas vidas;
 - Se o usuário inserir uma posição que esteja cercado de paredes ou se o usuário passar o portal e cair na mesma situação, o sistema retornará que foi impossível de passar pelo labirinto.

``` Movimentação: ```

 - Se o garoto andar em uma casa com número, ele receberá um item na sacola, com o máximo de 4 itens;
 - Se o garoto andar em uma casa com (#), ele será bloqueado de passar e o sistema sorteará outro caminho;
 - Se o garoto andar em uma casa com (*), ele perderá uma vida;
 - Se o garoto andar pra fora do labirinto, ele será teleportado para o próximo labirinto, a não ser que ele esteja no último, no qual ele irá retornar para o labirinto inicial.

<h2>Funções </h2>

* ``` void Welcome(); ```: Exibe a mensagem de entrada do programa; 
* ``` void CriandoLab(); ```: Cria tanto o labirinto quanto o arquivo que irá mostrar o caminho feito pelo garoto;
* ``` void DeletandoLab(); ```: Deleta tanto o labirinto quanto o arquivo que mostra o caminho feito pelo garoto;
* ``` void ObterPosInicial(); ```: Obtém a posição inicial inserida pelo usuário;
* ``` void ObterPosAleatoria(); ```: Sorteia uma posição aleatória quando o garoto passar por um portal;
* ``` void VerificarParede(int linha, int coluna); ```: Verifica se o garoto não está cercado por 8 paredes ao seu redor;
* ``` void CarminharNoLab();```: Sorteia o caminho no qual o garoto irá percorrer;
* ``` void VerificarSacola(); ```: Verifica quantos itens na sacola o garoto possui;
* ``` void CriarArqAux(); ```: Cria dois arquivos que auxiliam o programa, um para salvar os labirintos e o outro para salvar os labirintos com o caminho feito pelo garoto;
* ``` void ApagarArq(); ```: Apaga todos os arquivos auxiliadores usados durante o programa;
* ``` void AtualizarArqAux(); ```: Atualiza o primeiro arquivo auxiliar, no momento em que o garoto caminhar por todos os labirintos, no qual será limpado e atualizado toda vez que isso acontecer;
* ``` void AtualizarSegundoArqAux(); ```: Atualiza o segundo arquivo auxiliar, no momento em que o garoto completar um labirinto, atualizando o determinado labirinto neste arquivo;
* ``` void CriarArqVerificador(); ```:  


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
