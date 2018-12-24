package proCon4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class KuriyamaMiraisStones {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Integer[] origarr = new Integer[n];
        long[] arr = new long[n+2];

        for (int i=0;i<n;i++){
            origarr[i] = sc.nextInt();
            arr[i+1] = arr[i] + origarr[i];
        }
        arr[n+1]=arr[n];

        Arrays.sort(origarr);
        long[] sortedarr = new long[n+2];
        for (int i=1;i<=n;i++){
            sortedarr[i]=sortedarr[i-1]+origarr[i-1];
        }
        sortedarr[n+1] = sortedarr[n];
        int m = sc.nextInt();
        for (int i=0;i<m;i++){
            int type = sc.nextInt();
            int l = sc.nextInt();
            int r = sc.nextInt();
            if (type==1) System.out.println(arr[r]-arr[l-1]);
            else if (type == 2) System.out.println(sortedarr[r] - sortedarr[l-1]);
        }

    }
}
