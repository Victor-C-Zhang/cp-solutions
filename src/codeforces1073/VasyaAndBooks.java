package codeforces1073;

import java.util.*;
import java.lang.*;
import java.io.*;

public class VasyaAndBooks {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[] ht = new boolean[200007];
        int[] arr = new int[n];
        for (int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int cnt = -1;
        for (int i=0;i<n;i++){
            int book = sc.nextInt();
            if (!ht[book]){
                int curr = cnt+1;
                while (arr[curr] != book) {
                    ht[arr[curr]] = true;
                    curr++;
                }
                ht[arr[curr]] = true;
                System.out.print(curr - cnt + " ");
                cnt = curr;
            }
            else System.out.print("0 ");
        }
        sc.close();
    }
}
