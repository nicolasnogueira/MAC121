/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 DynamicWeightedQuickUnionUF.java
 *  Execucao: java-algs4 DynamicWeightedQuickUnionUF < input.txt
 *
 *  UF baseada na implementacao vista em aula com alteracao para resizing
 *
 *  % more input.txt
 *  2 10 
 *  3 5 
 *  2 8 
 *  10 5 
 *  7 4 
 *  5 1 
 *  2 10 
 *  85 1100 
 *  2541 10 
 *  1 2 
 *  10 1
 *
 *  % java-algs4 DynamicWeightedQuickUnionUF < input.txt
 *  Pares unidos na union find:
 *
 *  2 10
 *  3 5
 *  2 8
 *  10 5
 *  7 4
 *  5 1
 *  85 1100
 *  2541 10
 *
 *  Varredura no vetor com elementos utilizados em algum union:
 *
 *  1 2
 *  2 2
 *  3 2
 *  4 7
 *  5 2
 *  7 7
 *  8 2
 *  10 2
 *  85 85
 *  1100 85
 *  2541 2
 *
 *  Tamanho do vetor: 2542
 *
 ****************************************************************************/

import edu.princeton.cs.algs4.*;
public class DynamicWeightedQuickUnionUF {
    
    private int[] id;     // id[i] = parente da arvore indexada por i
    private int[] sz;    // numero de elementos da arvore indexada por i

    public DynamicWeightedQuickUnionUF() {
        id = new int[1];
        sz = new int[1];
        id[0] = 0;
        sz[0] = 1;
    }

    public int newSite() {
        int n = id.length;
        resize(n, n + 1);
        return n;
    }

    public void resize(int osize, int nsize) {
        if (nsize > osize) {
            int[] nid = new int[nsize];
            int[] nsz = new int[nsize];
            for (int i = 0; i < osize; i++) {
                nid[i] = id[i];
                nsz[i] = sz[i];
            }
            for (int i = osize; i < nsize; i++) {
                nid[i] = i;
                nsz[i] = 1;
            }
            id = nid;
            sz = nsz;
        }
    }

    public int find(int p) {
        if (p < 0 || p >= id.length) throw new IndexOutOfBoundsException();
        while (p != id[p]) {
            id[p] = id[id[p]];    // compressao de caminho
            p = id[p];
        }
        return p;
    }

    public boolean connected(int p, int q) {
        if (p < 0 || p >= id.length || q >= id.length || q < 0) return false;
        return find(p) == find(q);
    }

    public void union(int p, int q) {
        while (p >= id.length)
            newSite();
        while (q >= id.length)
            newSite();
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        if (sz[i] < sz[j]) { id[i] = j; sz[j] += sz[i]; }
        else { id[j] = i; sz[i] += sz[j]; } 
    }
    
    // test client
    public static void main(String[] args) {
        DynamicWeightedQuickUnionUF uf = new DynamicWeightedQuickUnionUF();
        StdOut.println("Pares unidos na union find:\n");
        while (!StdIn.isEmpty()) {
            int p = StdIn.readInt();
            int q = StdIn.readInt();
            if (uf.connected(p, q)) continue;
            uf.union(p, q);
            StdOut.println(p + " " + q);
        }
        StdOut.println("\nVarredura no vetor com elementos utilizados em algum union:\n");
        for (int i = 0; i < uf.id.length; i++) {
            if (uf.sz[i] != 1)
                StdOut.println(i + " " + uf.id[i]);
            else if (uf.id[i] != i)
                StdOut.println(i + " " + uf.id[i]);
        }
        StdOut.println("\nTamanho do vetor: " + uf.id.length);
    }
}
