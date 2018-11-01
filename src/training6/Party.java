package training6;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Party {
    static Queue<Integer> queue = new LinkedList();

    static int maxdepth = 0;
    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    static int[] currdepth;
    static boolean[] touch;

    static void bfs(int node){
        if (touch[node]) return;
        touch[node] = true;
        if (tree.get(node).size() == 0) maxdepth = Math.max(maxdepth, currdepth[node]);
        else for (int i : tree.get(node)){
            if (!touch[i]){
                currdepth[i]=currdepth[node] + 1;
                queue.add(i);
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        currdepth = new int[n+1];
        touch = new boolean[n+1];
        for (int i=0;i<=n;i++){
            tree.add(new ArrayList<>());
        }
        ArrayList<Integer> roots = new ArrayList<>();
        for (int i=1;i<=n;i++){
            int a = sc.nextInt();
            if (a==-1) {
                roots.add(i);
                currdepth[i] = 1;
            }
            else tree.get(a).add(i);
        }
        for (int i: roots){
            bfs(i);
            while (queue.size()!= 0){
                bfs(queue.poll());
            }
        }
        System.out.println(maxdepth);
    }
}
