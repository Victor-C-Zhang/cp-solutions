package training6;

import java.util.*;
import java.lang.*;
import java.io.*;

public class MahmoudAndEhabAndTheBipartiteness {
    static Queue<Integer> queue = new LinkedList<>();

    static ArrayList<ArrayList<Integer>> tree = new ArrayList<>();
    static int red = 1;
    static int blue = 0;
    static boolean[] touch;
    static int[] color; //1=red, 2=blue
    static void bfs(int node){
        if (touch[node]) return;
        touch[node] = true;
        for (int i: tree.get(node)){
            if (!touch[i]){
                if (color[node] == 1) {
                    color[i] = 2;
                    blue++;
                    queue.add(i);
                }
                else {
                    color[i] = 1;
                    red++;
                    queue.add(i);
                }
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //num vertices
        touch = new boolean[n+1];
        color = new int[n+1];
        color[1] = 1;
        for (int i=0;i<=n;i++){
            tree.add(new ArrayList<>());
        }
        for (int i=1;i<n;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            tree.get(a).add(b);
            tree.get(b).add(a);
        }
        bfs(1);
        while (queue.size()!=0){
            bfs(queue.poll());
        }
        System.out.println((long)red*blue-n+1);
    }
}
