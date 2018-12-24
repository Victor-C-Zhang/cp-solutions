package codeforces1057_mailRUpractice;

import java.io.*;
import java.util.*;
import java.lang.*;

public class BmailComputerNetwork {
    static int[] nodes;
    static void hop(int n){
        if (n==1) {
            System.out.print("1 ");
            return;
        }
        hop(nodes[n]);
        System.out.print(n + " ");
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        nodes = new int[n+1];
        for (int i=2;i<=n;i++){
            nodes[i] = sc.nextInt();
        }
        hop(n);
        System.out.println();
    }
}
