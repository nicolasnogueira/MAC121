/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 PercPlot.java
 *  Execucao: java-algs4 Distribution N M L
 *
 *  N - numero de passos dados por cada random walker
 *
 *  M - numero de random walkers simulados
 *
 *  L - tamanho do raio do quadrado a ser exibido na tela
 *
 *  Faz a simulacao de M random walkers cada um dando N passos aleatorios,
 *  .75f*n/40 com origem na coordenada (L, L). Exibe na tela um quadrado de 
 *  lado 2L onde cada quadrado de lado 1 e pintado conforme a intensidade com 
 *  a qual a coordenada (i,j) foi visitada pelos random walkers.
 *
 *  % java-algs4 Distribution 3600 100 60
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;
import java.awt.*;

public class Distribution {

    static final int SIZE = 10;

    public static Color converter(int n, int max) {
        n = (int) n*255/max;
        Color c = Color.getHSBColor(.75f*n/40, .8f, .8f);
        return c;
    }

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int M = Integer.parseInt(args[1]);
        int L = Integer.parseInt(args[2]);
        int[][] mapa = new int[2*L][2*L];
        RandomWalker[] walkers = new RandomWalker[M];
        int max = 1;

        for (int t = 0; t < M; t++) {
            walkers[t] = new RandomWalker(L, L);
            for (int cont = 0; cont < N; cont++){
                walkers[t].step();
                int xt = walkers[t].getX();
                int yt = walkers[t].getY();
                if (0 <= xt && xt < 2*L && 0 <= yt && yt < 2*L){
                    mapa[xt][yt]++;
                    if (mapa[xt][yt]>max)
                        max = mapa[xt][yt];
                }
            }
        }

        StdDraw.setXscale (0, 2*L*SIZE);
        StdDraw.setYscale (0, 2*L*SIZE);
        for (int i = 0; i < 2*L; i++) {
            for (int j = 0; j < 2*L; j++) {
                StdDraw.setPenColor(converter(mapa[i][j], max));
                StdDraw.filledSquare(i*SIZE, j*SIZE, SIZE);
            }
        }
        StdDraw.show();
    }
}
