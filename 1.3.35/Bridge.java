/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 Bridge.java
 *  Execucao: java-algs4 Bridge
 *
 *  % java-algs4 Bridge
 *
 *  9S
 *  5H
 *  5C
 *  6C
 *  5D
 *  AD
 *  7H
 *  6D
 *  3D
 *  QH
 *  8H
 *  9D
 *  4S
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class Bridge{

    // test client
    public static void main(String[] args) {
    	RandomQueue<Card> rq = new RandomQueue<Card>();
    	for (int i = 0; i < 52; i++)
    		rq.enqueue(new Card(i));
    	for (int j = 0; j < 13; j++) {
    		Card c = rq.dequeue();
    		System.out.println(c.toString());
    	}
    }
}
