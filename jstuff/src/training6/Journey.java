package training6;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Journey {
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    static boolean[] touch;
    static double[][] length;
    static ArrayList<Integer> leaves = new ArrayList<>();
    static void dfs(int node){
        if (touch[node]) return;
        touch[node] = true;
        int numnodes = 0;
        for (int i: tree.get(node)){
            if (!touch[i]){
                numnodes++;
            }
        }
        for (int i: tree.get(node)){
            if (!touch[i]){
                length[i][0] = length[node][0] + 1;
                length[i][1] = length[node][1] /(double) numnodes;
                dfs(i);
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        touch = new boolean[n+1];
        length = new double[n+1][2];
        length[1][1] = 1;
        for (int i = 0;i<=n;i++){
            tree.add(new ArrayList<>());
        }
        for (int i=1;i<n;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            tree.get(a).add(b);
            tree.get(b).add(a);
        }
        for (int i = 2; i<=n;i++){
            if (tree.get(i).size()==1) leaves.add(i);
        }
        dfs(1);
        double ans = 0;
        for (int i : leaves){
            ans+=length[i][0]*length[i][1];
        }
        System.out.println(ans);

    }
}
