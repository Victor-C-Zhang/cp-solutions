package googleKickstart;

import java.util.*;
import java.lang.*;
import java.io.*;

public class A {

    public static void main(String[] args){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int ncases = sc.nextInt();
        for (int scen = 1;scen<=ncases; scen++){
            int n = sc.nextInt();
            long[] arr = new long[n];
            long[][] dp = new long[n][n];
            for (int i=0;i<n;i++){
                arr[i] = sc.nextInt();
            }
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    dp[i][j] = arr[i]*arr[j];
                }
            }
            int cnt = 0;
            for (int a = 0; a<n-2;a++){
                for (int b = a+1;b<n-1;b++){
                    for (int c = b+1;c<n;c++){
                        if (arr[a] == dp[b][c] || arr[b] == dp[a][c] || arr[c] == dp[a][b]) cnt++;
                    }
                }
            }
            System.out.println("Case #" + scen + ": " + cnt);
        }
    }
}
