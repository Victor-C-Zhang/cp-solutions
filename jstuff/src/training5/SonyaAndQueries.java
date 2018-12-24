package training5;

import java.util.*;
import java.lang.*;
import java.io.*;
//this TLEs

public class SonyaAndQueries {
    public static String trimZeros(String s){
        for (int i=0;i<s.length();i++){
            if (s.charAt(i) =='1') return s.substring(i);
        }
        return "0";
    }
    public static String convertZeros(String s){
        String k = "";
        for (int i=0;i<s.length();i++){
            if (((int) s.charAt(i))%2 ==1) k+="1";
            else k+="0";
        }
        return trimZeros(k);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Hashtable<String, Integer> ht = new Hashtable<>();
        int n = sc.nextInt();
        sc.nextLine();
        for (int i=0;i<n;i++){
            String s = sc.nextLine();
            switch (s.charAt(0)){
                case '+':
                    String add = convertZeros(s.substring(2));
                    try{
                        ht.put(add, ht.get(add) + 1);

                    }
                    catch(NullPointerException e){
                        ht.put(add,1);
                    }
                    break;

                case '-':
                    String del = convertZeros(s.substring(2));
                    ht.put(del, ht.get(del) - 1);
                    break;
                case '?':
                    String key = trimZeros(s.substring(2));
                    if (ht.get(key) != null) {
                        System.out.println(ht.get(key));
                    }
                    else System.out.println(0);
                    break;
            }
        }
    }
}
