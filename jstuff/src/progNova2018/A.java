package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

public class A {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        int n = line.indexOf(" ");
        char[] arr = new char[n];
        char[] sorted = new char[n];
        for (int i=0;i<n;i++){
            arr[i] = line.charAt(i);
            sorted[i] = line.charAt(i);

        }
        int k = Integer.parseInt(line.substring(n+1));
        Arrays.sort(sorted);
        for (int i= n-k;i<k;i++){
            if (arr[i]!=sorted[i]) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
