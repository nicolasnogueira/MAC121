/******************************************************************************
 *  Nome: Nícolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao:  javac-algs4 RandomQueue.java
 *  Execucao:    java-algs4 RandomQueue < input.txt
 *
 *  % java-algs4 RandomQueue < input.txt
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;
import java.util.NoSuchElementException;

public class RandomQueue<Item> {
    private Item[] a;         // array of items
    private int N;            // number of elements on stack


    public RandomQueue() {
        a = (Item[]) new Object[2];
        N = 0;
    }

    public boolean isEmpty() {
        return N == 0;
    }

    public int getSize() {
        return N;
    }

    // redimensionamento do array
    private void resize(int capacity) {
        Item[] temp = (Item[]) new Object[capacity];
        for (int i = 0; i < N; i++) {
            temp[i] = a[i];
        }
        a = temp;
    }

    public void enqueue(Item item) {
        if (N == a.length) resize(2*a.length);    // teste de redimensionamento
        a[N++] = item;
    }

    public Item dequeue() {
        if (isEmpty()) throw new NoSuchElementException("RandomQueue underflow");
        int rand = StdRandom.uniform(N);
        Item item = a[rand];
        a[rand] = a[N - 1];
        a[N - 1] = null;
        N--;
        // teste de redimensionamento
        if (N > 0 && N == a.length/4) resize(a.length/2);
        return item;
    }

    public Item sample() {
        if (isEmpty()) throw new NoSuchElementException("RandomQueue underflow"); 
        int rand = StdRandom.uniform(N);
        return a[rand];      
    }

    //test client
    public static void main(String[] args) {
        RandomQueue<String> s = new RandomQueue<String>();
        StdOut.printf("RandomQueue: ");
        while (!StdIn.isEmpty()) {
            String item = StdIn.readString();
            s.enqueue(item);
            StdOut.printf("%s ", item);
        }
        StdOut.printf("\nSamples: ");
        for (int i = 0; i < s.getSize(); i++) {
            String itemr = s.sample();
            StdOut.printf("%s ", itemr);             
        }
        StdOut.printf("\nRetiradas: ");
        while (!s.isEmpty()) {
            String itemr = s.dequeue();
            StdOut.printf("%s ", itemr);            
        }
        StdOut.println("\nRandomQueue vazia!");
    }
}