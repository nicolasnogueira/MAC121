/******************************************************************************
 *  Compilation:  javac Generator.java
 *  Execution:    java Generator
 *  Dependencies: StdDraw.java
 *
 *
 *  % java Generator N M H A
 *  N - numero de vertices gerados pelo Random web (1.6.14)
 *  M - numero de arestas geradas pelo Random web (1.6.14)
 *  H - numero de hubs
 *  A - numero de authorities
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class HubsAndAuthorities { 

    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int M = Integer.parseInt(args[1]);
        int H = Integer.parseInt(args[2]);
        int A = Integer.parseInt(args[3]);
        int x, y, sum;
        int links[][] = new int[N + H + A][N + H + A];
        for (int i = 0; i < M; i++) {
            x = (int) Math.floor(Math.random() * N);
            y = (int) Math.floor(Math.random() * N);
            links[x][y]++;
        }

        //Hubs sao vertices de N até N+H-1
        for (int i = 0; i < H; i++) {
            int base = (int) Math.ceil(.1*N);
            while (base != 0) {
                int r = (int) Math.floor(Math.random() * N);
                if (links[r][N + i] == 0) {
                    links[r][N + i]++;
                    base--;
                }
            }
        }

        //Authorities sao vertices de N+H até N+H+A-1
        for (int i = 0; i < A; i++) {
            int base = (int) Math.ceil(.1*N);
            while (base != 0) {
                int r = (int) Math.floor(Math.random() * N);
                if (links[N + H + i][r] == 0) {
                    links[N + H + i][r]++;
                    base--;
                }
            }
        }

        System.out.print((N+H+A) + "\n");
        for (int i = 0; i < (N + H + A); i++) {
            sum = 0;
            for (int j = 0; j < (N + H + A); j++)
                while (links[i][j] > 0) {
                    System.out.print(i + " " + j + "  ");
                    links[i][j]--;
                    sum++;
                }
            if (sum > 0) System.out.print("\n");
        }
    }
}
