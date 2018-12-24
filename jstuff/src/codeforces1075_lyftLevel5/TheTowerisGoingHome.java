package codeforces1075_lyftLevel5;

import java.sql.SQLOutput;
import java.util.*;
import java.lang.*;
import java.io.*;

public class TheTowerisGoingHome {

    static int binsearch(Integer arr[], int size, int key){ //return # of elements <= key
        int l = 0,r = size-1, mid;
        while (l<r) {
            mid = (l+r)/2;
            if (key==arr[mid]) return mid+1;
            if (key>arr[mid]) l=mid+1;
            else r = mid;
        }
        if (key>=arr[l]) return l+1;
        return l;

    }

    public static void  main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n, m;
        n = sc.nextInt();
        m = sc.nextInt();
        Integer[] vert = new Integer[n+1];
        for (int i = 0; i<n;i++){
            int temp;
            temp = sc.nextInt();
            vert[i] = temp;
        }
        vert[n] = 1000000000;
        Arrays.sort(vert);
        int[] horiz = new int[n+2];
        for (int i=0;i<=n;i++){
            horiz[i] = 0;
        }
        for (int i = 0;i<m;i++){
            int start, end, y;
            start = sc.nextInt();
            end = sc.nextInt();
            y = sc.nextInt();
            if (start==1) {
                int len = binsearch(vert,n+1,end);
                if (len>0){
                    horiz[0]++;
                    horiz[len]--;
                }
            }
        }
        for (int i=1;i<=n;i++){
            horiz[i] = horiz[i] + horiz[i-1];
        }
        int min = 200007;
        for (int i = 0;i<=n;i++){
            if (i+horiz[i]<min){
                min = i+horiz[i];
            }
        }
        System.out.println(min);
    }


}
