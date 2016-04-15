/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 LevelTraversal.java
 *  Execucao: java-algs4 LevelTraversal < input.txt
 *
 *  Estrutura do input.txt
 *
 *  N M
 *  itens[N]
 *  raizes[M]
 *
 *  onde:
 *
 *  N - numero de elementos a serem inseridos na arvore
 *  M - numero de subarvores a serem impressas
 *  itens[N] - os inteiros a serem inseridos na arvore
 *  raizes[M] - as raizes das subarvores a serem impressas (todos os inteiros de
 *  raizes[M] estao contidos em itens[N])
 *
 *  $ more input.txt
 *
 *  9 3
 *  8 3 1 6 4 7 10 14 13
 *  8 3 13
 *
 *  $ java-algs4 LevelTraversal < input.txt
 *
 *  8 3 10 1 6 14 4 7 13 
 *  3 1 6 4 7 
 *  13 
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class LevelTraversal <Key extends Comparable<Key>>{

    /* Versao de BST que so possui chave */

    private Node raiz;

    private class Node {
        private Key chave;
        private Node esq, dir;

        public Node(Key chave) {
            this.chave = chave;
        }
    }

    public LevelTraversal() {
    }

    /* print de uma busca em largura */
    public void printLevel(Node node) {
        Queue<Node> fila = new Queue<Node>();
        fila.enqueue(node);
        while (!fila.isEmpty()) {
            Node tmp = fila.dequeue();
            if (tmp != null) {
                StdOut.print(tmp.chave + " ");
                fila.enqueue(tmp.esq);
                fila.enqueue(tmp.dir);
            }
        }
        StdOut.print("\n");
    }

    public Node busca (Node raiz, Key chave) {
        Node node;
        if (raiz == null || raiz.chave == chave) return raiz;
        if ((node = busca(raiz.esq, chave)) != null) return node;
        return busca (raiz.dir, chave);
    }

    public void put(Key chave) {
       raiz = put(raiz, chave);
    }

    private Node put(Node x, Key chave) {
        // Considera apenas a subárvore com raiz x
        // Devolve a raiz da nova subarvore
        if (x == null) return new Node(chave);
        int cmp = chave.compareTo(x.chave);
        if      (cmp < 0) x.esq = put(x.esq, chave);
        else if (cmp > 0) x.dir = put(x.dir, chave);
        return x;
    } 

    public static void main(String[] args) {
        LevelTraversal<Integer> arvore = new LevelTraversal<Integer>();
        int N = StdIn.readInt();
        int M = StdIn.readInt();
        for (int i = 0; i < N; i++) {
            int tmp = StdIn.readInt();
            arvore.put(tmp);
        }
        for (int i = 0; i < M; i++)
            arvore.printLevel(arvore.busca(arvore.raiz, StdIn.readInt()));
    }
}
