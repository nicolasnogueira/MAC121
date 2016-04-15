/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac -cp commons-math3-3.0.jar:algs4.jar TesteVisualQQ.java
 *  Execucao: java -cp commons-math3-3.0.jar:algs4.jar TesteVisualQQ N T
 *
 *  N - numero de elementos por permutacao
 *  T - numero de permutacoes produzidas
 *
 *  % java-algs4 TesteVisualQQ 6 720000
 *
 *  Hipótese nula não rejeitada. Valor para qui-quadrado calculado: 6.4799999999999995
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;
import java.util.TreeMap;
import org.apache.commons.math3.stat.inference.ChiSquareTest;

public class TesteVisualQQ{

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
        
        //Variaveis do Teste Qui-quadrado
        double qq = 0;
        double vesp = T / fat(N);
        double[] espec = new double[fat(N)];
        long[] observed = new long[fat(N)];

        for (int i = 0; i < fat(N); i++)
            espec[i] = vesp;

        //construcao do histograma
        Histogram histogram = new Histogram(perms.size());
        int cont = 0;
        for (String chave : perms.keySet()) {
            int loop = perms.get(chave);
            for (int i = 0; i < loop; i++)
                histogram.addDataPoint(cont);
            observed[cont] = loop;
            cont++;
            qq += (loop - vesp) * (loop - vesp) / vesp;
        }

        //teste qui-quadrado com alfa = 0.01
        ChiSquareTest chiSquareTest = new ChiSquareTest();
        if (chiSquareTest.chiSquareTest(espec, observed, .01)){
            StdOut.printf("Hipótese nula rejeitada. Valor para qui-quadrado calculado: %.4f\n", qq);
        } else {
            StdOut.printf("Hipótese nula não rejeitada. Valor para qui-quadrado calculado: %.4f\n", qq);
        }           

        // display using standard draw
        StdDraw.setCanvasSize(500, 100);
        histogram.draw();
    }
}
