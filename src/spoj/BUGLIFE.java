package spoj;

import java.util.*;
import java.lang.*;
import java.io.*;

public class BUGLIFE {
    static LinkedList<Integer> queue = new LinkedList<>();
    static int[] gender;
    static ArrayList<Integer>[] arr;
    static void bfs(int node){ //1 male, 2 female // node = current node, male = gender of current
        for (int i: arr[node]){
            if (gender[node] == gender[i]) {
                System.out.println(); //print statement, then break
            }
            else if (gender[node] == 1){
                gender[i] = 2;
            }
            else if (gender[node] == 2){
                gender[i] = 1;
            }
            queue.addFirst(i);
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int ncases = sc.nextInt();
        for (int i=0; i<ncases;i++){
            int nbugs = sc.nextInt();
            int interactions = sc.nextInt();
            gender = new int[nbugs+1];
            arr = new ArrayList[nbugs+1];
            for (int j=0;j<interactions;j++){
                int a = sc.nextInt();
                int b = sc.nextInt();
                arr[a].add(b);
                arr[b].add(a);
            }
            bfs(1);
            while(queue.size()!=0){
                bfs(queue.pollFirst());
            }
        }
    }
}
