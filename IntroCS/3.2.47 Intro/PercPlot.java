/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 PercPlot.java
 *  Execucao: java-algs4 PercPlot N M
 *
 *  N - numero de linhas da matriz NxNxN
 *
 *  M - numero de vezes a gerar uma matriz NxNxN para estimar a probabilidade
 *  de percolacao
 *
 *  Desenha o grafico da probabilidade de percolacao baseada na observacao
 *  experimental contra a probabilidade de cada casa da matriz NxNxN estar
 *  aberta.
 *
 *  % java-algs4 PercPlot 30 10000
 *
 *  Obs.: Arquivo retirado do Sandbox disponibilizado pelo professor.
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class PercPlot {

    public static final int DEBUG = 0;

    // recursive curve plotting
    public static void curve(int N, int M, double x0, double y0, double x1, double y1) {
        double gap = .01;
        double err = .0025;
        double xm = (x0 + x1) / 2;
        double ym = (y0 + y1) / 2;
        double fxm = Estimate.eval(N, xm, M);
        if (x1 - x0 < gap || Math.abs(ym - fxm) < err) {
            StdDraw.line(x0, y0, x1, y1);
            return;
        }
        curve(N, M, x0, y0, xm, fxm);
        StdDraw.filledCircle(xm, fxm, .005);
        if (DEBUG == 1) StdDraw.textRight(xm, fxm, xm + "");
        curve(N, M, xm, fxm, x1, y1);
    }

    // test client
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int M = Integer.parseInt(args[1]);
        PercPlot.curve(N, M, 0.0, 0.0, 1.0, 1.0);
    }
}
