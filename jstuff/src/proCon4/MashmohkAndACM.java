package proCon4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class MashmohkAndACM {
    static int n,k;
    static int[][] dp; // max, length

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        dp = new int[n+1][k+1];
        for (int i=1;i<n+1;i++){
            dp[i][1] = 1;
        }

        for (int h = 1; h<n+1;h++){
            for (int i = 1;i<k;i++){
                for (int j=h;j<n+1;j+=h){
                    dp[j][i+1]+= dp[h][i];
                    dp[j][i+1]%=1000000007;
                }
            }
        }
        int cnt = 0;
        for (int i=1;i<n+1;i++){
            cnt+=dp[i][k];
            cnt%=1000000007;
        }
        System.out.println(cnt);

    }
}
