package training6;

import java.util.*;
import java.lang.*;
import java.io.*;

public class KefaAndPark {
    static int cnt=0, m;
    static int[] arr;
    static boolean[] touch;
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    static void dfs(int node){
        if (touch[node]) return;
        touch[node] = true;
        if (arr[node]>m) return;
        if (tree.get(node).size()==1 && node!=1) {
            cnt++;
            return;
        }
        for (int i :tree.get(node)){
            if (!touch[i]) {
                if (arr[i]!=0 )arr[i] += arr[node];
                dfs(i);
            }
        }

    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //num vertices
        m = sc.nextInt(); //max cats
        arr = new int[n+1];
        touch = new boolean[n+1];
        for (int i=1;i<=n;i++){
            if (sc.nextInt() == 1) arr[i] = 1;
        }
        for (int i = 0;i<=n;i++){
            tree.add(new ArrayList<Integer>());
        }
        for (int i = 0; i<n-1;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            tree.get(a).add(b);
            tree.get(b).add(a);
        }
        dfs(1);
        System.out.println(cnt);

    }
}
