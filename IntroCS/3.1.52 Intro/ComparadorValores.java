/******************************************************************************
 *  Nome: Nicolas Nogueira Lopes da Silva
 *  Nº USP: 9277541
 *
 *  Comparador que define uma regra de ordenacao do Map base, levando em
 *  consideracao a ordem decrescente dos valores do Map.
 *
 ******************************************************************************/

import java.util.Comparator;
import java.util.Map;
 
public class ComparadorValores implements Comparator<String> {
     
    Map<String, Integer> base;
     
    public ComparadorValores(Map<String, Integer> base) {
        this.base = base;
    }
     
    @Override
    public int compare(String o1, String o2) {
    	System.out.println(o1 + " comparando " + o2 + " = " + base.get(o2).compareTo(base.get(o1)));
        return base.get(o2).compareTo(base.get(o1));
    }
}