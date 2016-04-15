/******************************************************************************
 *  Nome: Nícolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao:  javac-algs4 BulgingSquares.java
 *  Execucao:    java-algs4 BulgingSquares
 *
 *  % javac-algs4 BulgingSquares
 *
 *  Obs.: Executei o script do Carybé, não sei se precisava incluir o algs4.jar
 *  na pasta, na dúvida incluí.
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class BulgingSquares {

    static int SIZE = 540;
    
    public static void pintarDiagonais(int posx, int posy, int elem, int tam) {
        for (int aux = elem; aux > 0; aux--) {
            StdDraw.filledSquare(posx, posy, tam);
            StdDraw.filledSquare(posx, SIZE - posy, tam);
            StdDraw.filledSquare(SIZE - posx, posy, tam);
            StdDraw.filledSquare(SIZE - posx, SIZE - posy, tam);
            StdDraw.filledSquare(posx + 2*SIZE/45, posy + 2*SIZE/45, tam);
            StdDraw.filledSquare(posx + 2*SIZE/45, SIZE - (posy + 2*SIZE/45), tam);
            StdDraw.filledSquare(SIZE - (posx + 2*SIZE/45), posy + 2*SIZE/45, tam);
            StdDraw.filledSquare(SIZE - (posx + 2*SIZE/45), SIZE - (posy + 2*SIZE/45), tam);
            posx +=  SIZE/15;
            posy += SIZE/15;
        }
    }

    public static void pintarCruz(int posx, int posy, int tam) {
        //horizontal
        StdDraw.filledSquare(posx + 2*SIZE/45, posy - SIZE/45, tam);
        StdDraw.filledSquare(SIZE - (posx + 2*SIZE/45), SIZE - (posy - SIZE/45), tam);
        StdDraw.filledSquare(SIZE - (posx + 2*SIZE/45), posy - SIZE/45, tam);
        StdDraw.filledSquare(posx + 2*SIZE/45, SIZE - (posy - SIZE/45), tam);

        //vertical
        StdDraw.filledSquare(posy - SIZE/45, posx + 2*SIZE/45, tam);
        StdDraw.filledSquare(SIZE - (posy - SIZE/45), SIZE - (posx + 2*SIZE/45), tam);
        StdDraw.filledSquare(SIZE - (posy - SIZE/45), posx + 2*SIZE/45, tam);
        StdDraw.filledSquare(posy - SIZE/45, SIZE - (posx + 2*SIZE/45), tam);
    }

    public static void main(String[] args) {
    	int l = 15;
        int tam = SIZE/90 - 1;
    	boolean color = false;
    	StdDraw.setXscale (0, SIZE);
        StdDraw.setYscale (0, SIZE);

        //desenhando xadrez principal
        for (int i = 1; i <= l; i++) {
        	for (int j = 1; j <= l; j++) {
        		color = !color;
        		if (color)
					StdDraw.setPenColor(StdDraw.BLACK);
        		else
        			StdDraw.setPenColor(StdDraw.WHITE);
        		StdDraw.filledSquare(SIZE*(2*i-1)/30, SIZE*(2*j-1)/30, SIZE/30);
        		
        	}
        }
        
        //brancos com detalhes pretos
        int inix = 7*SIZE/90;
        int iniy = 49*SIZE/90;
        int elementos = 6;
        int posx, posy;
       	while (elementos > 0) {
            StdDraw.setPenColor(StdDraw.BLACK);
       		posx = inix;
       		posy = iniy;
            pintarDiagonais(posx, posy, elementos, tam);
            StdDraw.setPenColor(StdDraw.WHITE);
            pintarCruz (posx, posy, tam);
       		elementos -= 2;
       		inix += 2*SIZE/15;
       	}

       	//pretos com detalhes brancos
       	boolean flag = false;
       	inix = 1*SIZE/90;
        iniy = 49*SIZE/90;
       	elementos = 3;

       	while (elementos > 0) {
            StdDraw.setPenColor(StdDraw.WHITE);
       		posx = inix;
       		posy = iniy;
       		if (!flag) {
       			posx += 2*SIZE/15;
       			posy += 2*SIZE/15;
       			pintarDiagonais(posx, posy, elementos, tam);
       			elementos += 2;  
       			flag = !flag;
       		} else {
 				pintarDiagonais (posx, posy, elementos, tam);
                StdDraw.setPenColor(StdDraw.BLACK);
                pintarCruz (posx, posy, tam);
       			elementos -= 2;     			
       		}
            inix += 2*SIZE/15; 
       	}
        StdDraw.show();
    }
}
