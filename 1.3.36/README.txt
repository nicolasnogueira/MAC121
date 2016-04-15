README

Fiz uma versão alternativa do TesteVisual.java que realiza o teste de aderência 
Qui-quadrado com nível de significância = 0.01.

Para fazer o teste do Qui-quadrado eu utilizei uma biblioteca da apache.org. O 
jar está incĺuído na pasta.

Eu não conheço muito sobre as configurações do java, a única forma que eu 
encontrei para compilar e executar o programa com os dois jars (o que eu utilizei
para o qui-quadrado e o algs4) foi utilizando o seguinte comando:

javac -cp commons-math3-3.0.jar:algs4.jar RandomQueue.java TesteVisualQQ.java Histogram.java

E para executar (exemplo):

java -cp commons-math3-3.0.jar:algs4.jar:. TesteVisualQQ 6 7200

Nota: A biblioteca exige para o teste de qui-quadrado que T >= N!.

Obs.: Caso não dê para rodar com o jar a versão base o TesteVisual funciona 
normalmente.

