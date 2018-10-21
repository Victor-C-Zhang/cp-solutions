package spoj;

import java.util.*;
import java.lang.*;

//This TLEs
public class PT07Z {
    static ArrayList<ArrayList<Integer>> arr;
    static int bestnode = 0;
    static int maxlen = 0;
    static boolean[] visited;
    public static void dfs(int node, int reps){
        visited[node] = true;

        if (arr.get(node).size() == 1) {
            if (reps>maxlen){
                maxlen = reps;
                bestnode = node;
            }
            if (maxlen != 0) return;
        }
        for (int i: arr.get(node)) {
            if (!visited[i]){
                dfs(i, reps+1);
            }
        }
        return;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        arr = new ArrayList<>();
        for (int i = 0; i<=n;i++){
            arr.add(new ArrayList<>());
        }
        visited = new boolean[n+1];
        for (int i=1;i<n;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            arr.get(a).add(b);
            arr.get(b).add(a);
        }
        dfs(1,0);
        maxlen = 0;
        visited = new boolean[n+1];
        dfs(bestnode, 0);
        System.out.println(maxlen);
    }
}
