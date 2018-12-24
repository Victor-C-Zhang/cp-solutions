package training6;

import java.util.*;
import java.lang.*;
import java.io.*;

public class RoadConstruction {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean[] hub = new boolean[n+1]; //if true, then i CANNOT be the hub!! <DONT FORGET>
        hub[0] = true;
        int m = sc.nextInt();
        for (int i=0;i<m;i++){
            hub[sc.nextInt()] = true;
            hub[sc.nextInt()] = true;
        }
        for (int i=0;i<=n;i++){
            if (!hub[i]){
                System.out.println(n-1);
                for (int j=1; j<=n;j++){
                    if (j!=i){
                        System.out.println(i + " " + j);
                    }
                }
                break;
            }
        }
    }
}
