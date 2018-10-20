package training5;

import java.lang.reflect.Array;
import javafx.util.*;
import java.util.*;
import java.lang.*;
import java.io.*;

public class TheFestiveEvening {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int maxguards = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        Hashtable<Character, Pair> ht = new Hashtable<>();
        int[] prefix = new int[s.length()+1];
        for (int i=0; i<n;i++){
            char c = s.charAt(i);
            if (ht.get(c) == null) {
                Pair<Integer,Integer> pair = new Pair<>(i,i);
                ht.put(c, pair);
            }
            else {
                Pair<Integer, Integer> pair = new Pair<>((int) ht.get(c).getKey(), i);
                ht.put(c, pair);
            }
        }
        for (Pair <Integer,Integer> temp : ht.values()){
            prefix[temp.getKey()] ++;
            prefix[temp.getValue()+1] --;
        }
        int guards =0;
        for (int i=0;i<prefix.length;i++){
            guards+=prefix[i];
            if (guards>maxguards) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
