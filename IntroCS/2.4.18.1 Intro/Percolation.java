/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 Percolation.java
 *  Execucao (test client): java-algs4 Percolation N p
 *
 *  N - numero de linhas da matriz N-N-N
 *
 *  p - probabilidade de uma casa estar aberta
 *
 *  Verifica se dada matriz NxNxN ocorre percolacao.
 *
 *  % java-algs4 Percolation 10 .5
 *
 *  Versao adaptada do arquivo Percolation.java para
 *  matrizes 3D.
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class Percolation {

    // given an N-by-N-by-N matrix of open sites, return an N-by-N-by-N matrix
    // of sites reachable from the top
    public static boolean[][][] flow(boolean[][][] open) {
        int N = open.length;
        boolean[][][] full = new boolean[N][N][N];
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                flow(open, full, 0, j, k);                
        return full;
    }

    // determine set of full sites using depth first search
    public static void flow(boolean[][][] open, boolean[][][] full, int i, int j, int k) {
        int N = open.length;

        // base cases
        if (i < 0 || i >= N) return;    // invalid row
        if (j < 0 || j >= N) return;    // invalid column
        if (k < 0 || k >= N) return;    // invalid column
        if (!open[i][j][k]) return;        // not an open site
        if (full[i][j][k]) return;         // already marked as full

        // mark i-j-k as full
        full[i][j][k] = true;

        flow(open, full, i+1, j, k);   // down
        flow(open, full, i, j+1, k);   // right
        flow(open, full, i, j-1, k);   // left
        flow(open, full, i-1, j, k);   // up
        flow(open, full, i, j, k-1);   // front
        flow(open, full, i, j, k+1);   // behind
    }


    // does the system percolate?
    public static boolean percolates(boolean[][][] open) {
        int N = open.length;
        boolean[][][] full = flow(open);
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (full[N-1][j][k]) return true;            
        return false;
    }

    // test client
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double p = Double.parseDouble(args[1]);
        //double p = Math.random();
        boolean[][][] open = BooleanMatrix3D.random(N, p);
        StdOut.printf("p = %.4f\n%b\n", p, percolates(open)); 
    }

}
