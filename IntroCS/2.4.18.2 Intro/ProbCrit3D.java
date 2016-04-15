/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 ProbCrit3D.java
 *  Execucao: java-algs4 ProbCrit3D N M
 *
 *  N - numero de linhas da matriz NxNxN
 *
 *  M - numero de vezes a gerar uma matriz NxNxN para estimar a probabilidade
 *  de percolacao
 *
 *  De forma parecida ao PercPlot, o ProbCrit3D procura a probabilidade critica
 *  calculando valores para diferentes valores de p o menor numero de vezes 
 *  possivel.
 *
 *  % java-algs4 ProbCrit 30 10000
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class ProbCrit3D {

    // busca binaria do p que melhor se aproxima do p critico
    public static void probc(int N, int M, double x0, double x1) {
        double gap = .01;
        double err = .0025;
        double xm = (x0 + x1) / 2;
        double fxm = Estimate.eval(N, xm, M); //prob
        if (Math.abs(x1 - x0) < gap || Math.abs(.5 - fxm) < err) {
            StdOut.printf("Probabilidade critica = %.4f\n", xm);
            return;
        }
        if (fxm > .5)
            probc(N, M, x0, xm);
        else
            probc(N, M, xm, x1);
    }

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int M = Integer.parseInt(args[1]);
        probc(N, M, 0.0, 1.0);
    }
}
