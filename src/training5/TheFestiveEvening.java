package training5;

import java.lang.reflect.Array;
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
        Hashtable<Character, Integer> ht = new Hashtable<>();
        int[] prefix = new int[s.length()+1];
        for (int i=0; i<n;i++){
            char c = s.charAt(i);
            if (ht.get(c) == null) {
                int[] pair = {i,i};
                ht.put(c, 2);
            }
        }
    }
}
