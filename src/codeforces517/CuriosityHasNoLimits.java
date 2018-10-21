package codeforces517;

import java.util.*;
import java.lang.*;
import java.io.*;

public class CuriosityHasNoLimits {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n-1];
        for (int i=0;i<n-1;i++){
            a[i] = sc.nextInt();
        }
        int[] b = new int[n-1];
        for (int i=0;i<n-1;i++){
            b[i] = sc.nextInt();
        }
        int[] ans = new int[n];
        for (int i=0;i<n-1;i++){
            if (a[i]<b[i]) {
                System.out.println("NO");
                return;
            }
        }
        int[][] tri = new int[4][n];
        tri[0][0] = 0;
        tri[1][0] = 1;
        tri[2][0] = 2;
        tri[3][0] = 3;
        for (int i=0;i<n-1;i++){
            if (a[i] == 3 && b[i]==0){
                for (int[] j: tri){
                    if (j!= null) j[i+1] = 3-j[i];
                }
            }
            else for (int j =0;j<4;j++){
                if (tri[j]!=null) {
                    if (tri[j][i] != a[i] && tri[j][i]!=b[i]) tri[j]= null;
                    else {
                        if (tri[j][i] == a[i]) tri[j][i+1] = b[i];
                        else tri[j][i+1] = a[i];
                    }
                }
            }
        }
        for (int[] j : tri){
            if (j!=null){
                System.out.println("YES");
                for (int i=0;i<n;i++){
                    System.out.print(j[i] + " ");
                }
                System.out.println();
                return;
            }
        }
        System.out.println("NO");

    }
}
