/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 RandomWalker.java
 *  Execucao: java-algs4 RandomWalker N
 *
 *  N - numero de passos do random walker
 *
 *  Simula um random walker que da N passos em direcoes aleatorios, ao final
 *  retorna a distancia do random walker da origem do sistema.
 *
 *  % java-algs4 RandomWalker 10000
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;

public class RandomWalker {

    // x0 e y0 representam a origem do sistema

    private int x, y, x0, y0;

    public RandomWalker (int x0, int y0) {
        this.x = x0;
        this.y = y0;
        this.x0 = x0;
        this.y0 = y0;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void step() {
        int n = (int) Math.floor(Math.random() * 4);
        switch (n) {
            case 0:
                x++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y++;
                break;
            case 3:
                y--;
                break;
            default:
        }
    }

    public double distance() {
        return (double) Math.sqrt((x-x0)*(x-x0) + (y-y0)*(y-y0));
    }

    // test client
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int passosRest = N;
        RandomWalker walker = new RandomWalker(0, 0);
        while (passosRest > 0) {
            walker.step();
            passosRest--;
        }
        StdOut.printf("Distancia = %.4f\n", walker.distance());
    }
}
