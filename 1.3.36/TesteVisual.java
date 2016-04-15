/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 TesteVisual.java
 *  Execucao: java-algs4 TesteVisual N T
 *
 *  N - numero de elementos por permutacao
 *  T - numero de permutacoes produzidas
 *
 *  % java-algs4 TesteVisual 6 720000
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;
import java.util.TreeMap;

public class TesteVisual{

    public static int fat(int n) {
        int fat = 1;
        for (int i = 1; i <= n; i++) {
            fat *= i;
        }
        return fat;
    }

    // test client
    public static void main(String[] args) {
        int N = Integer.parseInt(args[0]);
        int T = Integer.parseInt(args[1]);
        int max = 0;

        RandomQueue<Integer> s = new RandomQueue<Integer>();

        for (int i = 1; i <= N; i++)
            s.enqueue(i);

        TreeMap<String, Integer> perms = new TreeMap<String, Integer>();

        //construcao do dicionario de frequencias
        for (int i = 0; i < T; i++){
            String str = "";
            for (Integer num : s)
                str = str + num + " ";
            if (perms.containsKey(str))
                perms.put(str, perms.get(str) + 1);             
            else 
                perms.put(str, 1);
        }

        //construcao do histograma
        Histogram histogram = new Histogram(perms.size());
        int cont = 0;
        for (String chave : perms.keySet()) {
            int loop = perms.get(chave);
            for (int i = 0; i < loop; i++)
                histogram.addDataPoint(cont);
            cont++;
        }

        // display using standard draw
        StdDraw.setCanvasSize(500, 100);
        histogram.draw();
    }
}
