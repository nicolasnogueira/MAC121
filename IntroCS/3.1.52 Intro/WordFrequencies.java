/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Compilacao: javac-algs4 WordFrequencies.java
 *  Execucao: java-algs4 WordFrequencies < input.txt
 *
 *  Recebe um arquivo de texto e gera uma lista de frequencia de palavras
 *  ordenado pela frequencia de cada palavra em ordem decrescente.
 *
 *  % java-algs4 WordFrequencies < input.txt > output.txt
 *
 *  O TreeMap utilizado tem para cada entrada a chave sendo uma palavra do
 *  texto e o valor a sua frequencia.
 *
 ******************************************************************************/

import edu.princeton.cs.algs4.*;
import java.util.*;

public class WordFrequencies {

    public static void main(String[] args) {

        /*System.out.println(teste.toLowerCase());
        String[] palavras2 = teste.split("[^a-zA-Z\u00C0-\u00FF\\-]");
        for (String palavra : palavras2)
            System.out.println(palavra);*/
        TreeMap<String, Integer> dicionario = new TreeMap<String, Integer>();
        String texto = "teste-Guardachuva qtf wtf coisa alguma coisa la-la wtf wtf";
        String[] palavras = texto.split("[^a-zA-Z\u00C0-\u00FF\\-]");
        for (String palavra : palavras) {
            palavra = palavra.toLowerCase();
            System.out.println(palavra);
            if (!palavra.equals(""))
                if (dicionario.containsKey(palavra)) {
                    dicionario.put(palavra, dicionario.get(palavra) + 1);
                    System.out.println(palavra + "1");                    
                }

                else{
                    dicionario.put(palavra, 1);
                                        System.out.println(palavra + "2"); 
                }
            else
                System.out.println("-" + palavra);  
        }

        //TreeMap por padrao esta ordenado pelas chaves em ordem lexicografica

        //cmp define a regra pela qual TreeMap e ordenado

        ComparadorValores cmp = new ComparadorValores(dicionario);         
        TreeMap<String, Integer> dicionarioOrd = new TreeMap<String, Integer>(cmp);
        System.out.println("TAMANHO CMP = " + cmp.size());
        for (String chave : dicionario.keySet())
            dicionarioOrd.put(chave, dicionario.get(chave));
        System.out.println("TAMANHO 1 = " + dicionario.size() + " TAMANHO 2 = " + dicionarioOrd.size());

        //dicionarioOrd consiste no dicionario reordenado pelos valores
        //em ordem decrescente
        for (String chave : dicionario.keySet())
            System.out.println("1" + chave + " " + dicionario.get(chave));

        for (String chave : dicionarioOrd.keySet())
            System.out.println("2" + chave + " " + dicionario.get(chave));
        System.out.println(dicionario.keySet());
    }
}
