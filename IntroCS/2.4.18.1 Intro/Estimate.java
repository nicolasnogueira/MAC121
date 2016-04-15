/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 Estimate.java
 *  Execucao (test client): java-algs4 Estimate N p M
 *
 *  N - numero de linhas da matriz NxNxN
 *
 *  p - probabilidade de uma casa estar aberta
 *
 *  M - numero de vezes a gerar uma matriz NxNxN para estimar a probabilidade
 *  de percolacao
*
 *  Gera M matrizes NxNxN, onde cada casa esta aberta com probabilidade p, e
 *  para cada matriz gerada verifica percolacao, estimando a probabilidade com
 *  que o sistema percola.
 *
 *  % java-algs4 Estimate 30 .5 10000
 *
 *  Obs.: Arquivo retirado do Sandbox disponibilizado pelo professor.
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class Estimate {

    // do M trials and return fraction that percolate
    public static double eval(int N, double p, int M) {
        int count = 0;
        for (int k = 0; k < M; k++) {
            boolean[][][] open = BooleanMatrix3D.random(N, p);
            if (Percolation.percolates(open))
                count++;
        }
        return (double) count / M;
    }

    //test client
    public static void main(String[] args) {
        int    N = Integer.parseInt(args[0]);
        double p = Double.parseDouble(args[1]);
        int    M = Integer.parseInt(args[2]);
        double q = eval(N, p, M);
        StdOut.println(q);
    }
}
