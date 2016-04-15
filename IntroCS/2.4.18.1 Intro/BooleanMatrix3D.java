/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 BooleanMatriz3D.java
 *  Execucao (test client): java-algs4 BooleanMatrix3D N p
 *
 *  N - numero de linhas da matriz NxNxN
 *
 *  p - probabilidade de uma casa estar aberta
*
 *  Gera uma matriz NxNxN booleana onde cada casa tem probabilidade p de estar
 *  aberta (valer 1).
 *
 *  Test client: imprime a matriz NxNxN criada decompondo em N matrizes NxN.
 *
 *  % java-algs4 BooleanMatrix3D 10 .5
 *
 ******************************************************************************/
import edu.princeton.cs.algs4.*;

public class BooleanMatrix3D {

    // return a random N-by-N-by-N boolean matrix, where each entry is
    // true with probability p
    public static boolean[][][] random(int N, double p) {
        boolean[][][] a = new boolean[N][N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    a[i][j][k] = StdRandom.bernoulli(p);
        return a;
    }

    //test client
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        double p = Double.parseDouble(args[1]);
        boolean[][][] a = random(N, p);
        System.out.println(N + " " + N + " " + N + "\n");
        int k = 0;
        for (boolean[][] bid : a){
            System.out.println("K = " + k + "\n");
            for (boolean[] uni : bid){
                for (boolean u : uni){
                    System.out.print(u ? 1 + " " : 0 + " ");
                }
                System.out.print("\n");
            }
            k++;
            System.out.print("\n");
        }
    }
}
