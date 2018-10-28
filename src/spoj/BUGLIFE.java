package spoj;

import java.util.*;
import java.lang.*;
import java.io.*;

public class BUGLIFE {
    static Queue<Integer> queue = new LinkedList<>();
    static int[] gender;
    static boolean[] visited;
    static int scen;
    static boolean sus;
    static ArrayList<Integer>[] arr;
    static void bfs(int node){ //1 male, 2 female // node = current node, male = gender of current
        for (int i: arr[node]){
            if(visited[i] == true) {
                if (gender[node] == gender[i]) {
                    System.out.println("Scenario #" + scen + ":");
                    System.out.println("Suspicious bugs found!");
                    sus = true;
                    break; //print statement, then break
                }
                continue;
            }
            visited[i] = true;

            if (gender[node] == 1){
                gender[i] = 2;
            }
            else if (gender[node] == 2){
                gender[i] = 1;
            }
            queue.add(i);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ncases = sc.nextInt();
        for (scen=1; scen<=ncases;scen++){
            sus = false;
            int nbugs = sc.nextInt();
            int interactions = sc.nextInt();
            gender = new int[nbugs+1];
            visited = new boolean[nbugs+1];
            arr = new ArrayList[nbugs+1];
            for (int i=1;i<=nbugs;i++){
                arr[i] = new ArrayList<Integer>();
            }
            for (int j=0;j<interactions;j++){
                int a = sc.nextInt();
                int b = sc.nextInt();
                arr[a].add(b);
                arr[b].add(a);
            }
            for (int i=1; i<=nbugs;i++){
                if (!sus && gender[i] == 0){
                    gender[i] = 1;
                    bfs(i);
                    while(queue.size()!=0){
                        bfs(queue.remove());
                        if (sus) break;
                    }
                }
            }
            if (!sus) {
                System.out.println("Scenario #" + scen + ":");
                System.out.println("No suspicious bugs found!");
            }

        }
    }
}
