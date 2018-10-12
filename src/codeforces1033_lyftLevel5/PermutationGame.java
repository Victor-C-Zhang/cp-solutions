package codeforces1033_lyftLevel5;

import java.util.*;
import java.lang.*;

public class PermutationGame {
    static int[] dp;
    static int[] a;
    static int f(int n){
        if (dp[n]!=0) return dp[n];
        boolean sent = false;
        int m = 1;
        int max = 0;
        while (true){
            try{
                if (a[n-m*a[n]]>a[n]){
                    max = Math.max(max, dp[n-m*a[n]]);
                    sent = true;
                }
                m++;
            }
            catch (IndexOutOfBoundsException e){
                m = 0;
                break;
            }

        }
        while (true){
            try{
                if (a[n+m*a[n]]>a[n]){
                    max = Math.max(max, dp[n+m*a[n]]);
                    sent = true;
                }
                m++;
            }
            catch (IndexOutOfBoundsException e){
                m = 0;
                break;
            }

        }
        if (sent){
            return dp[n] = max+1;
        }
        return 0;

    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int maxn = sc.nextInt();
        dp = new int[maxn];
        a = new int[maxn];
        for (int i = 0; i<maxn;i++){
            a[i] = sc.nextInt();
        }
        for(int i :dp){
            if (i%2 ==0) System.out.print("B");
            else System.out.print("A");
        }

    }
}
