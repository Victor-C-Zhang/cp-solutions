package googleKickstart;

import java.lang.*;
import java.util.*;
import java.io.*;

public class Practice {
    public static void main(String[] args){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int ncases = sc.nextInt();
        for (int scen=1;scen<=ncases;scen++){
            int n = sc.nextInt();
            int[] prefix = new int[5007];
            for (int i = 0;i<n;i++){
                prefix[sc.nextInt()]++;
                prefix[sc.nextInt()+1]--;
            }
            for (int i=1;i<5006;i++){
                prefix[i] += prefix[i-1];
            }
            int queries = sc.nextInt();
            System.out.print("Case #" + scen + ":");
            for (int i=0;i<queries;i++){
                System.out.print(" "+prefix[sc.nextInt()]);
            }
            System.out.println();
        }
    }
}
