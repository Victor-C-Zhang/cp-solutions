package codeforces517;

import java.util.*;
import java.lang.*;
import java.io.*;

public class MinimumPath {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.nextLine();
        char[][] arr = new char[n][n];
        int[][] dp = new int[n+2][n+2]; //last row/col NOT USED
        for (int i=0; i<n;i++){
            String s = sc.nextLine();
            for (int j = 0;j<n;j++){
                arr[i][j] = s.charAt(j);
            }
        }
        dp[1][1] = k;
        for (int i=2; i<=n;i++){
            if (arr[i-2][0] == 'a') dp[i][1] = dp[i-1][1];
            else dp[i][1] = dp[i-1][1]-1;
        }
        for (int i=1;i<=n;i++){
            for (int j=2;j<=n;j++){
                if (arr[i-1][j-2] == 'a') {
                    dp[i][j] = Math.max(dp[i][j-1], dp[i][j]);
                }
                else dp[i][j] = Math.max(dp[i][j-1]-1, dp[i][j]);
                if (arr[i-1][j-1] == 'a'){
                    dp[i+1][j] = dp[i][j];
                    dp[i][j+1] = dp[i][j];
                }
                else {
                    dp[i+1][j] = dp[i][j]-1;
                    dp[i][j+1] = dp[i][j]-1;
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                System.out.print(dp[i][j] + " ");
            }
            System.out.println();
        }
        //dp array works, now need to find shortest path, can be done in N^2

    }
}
