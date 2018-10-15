package codeforces1033_lyftLevel5;

import java.util.*;
import java.lang.*;

public class PermutationGame {
    static int[] dp;
    static int[] a;
    static int f(int n){
        //dp state: if anybody starts at that position they will win (1) or lose (2)
        //want to find recur f(n) s.t. if there is a dp == 2, return 1, else return 2
        if (dp[n]!=0) return dp[n];
        if (a[n]==dp.length){
            return 2;
        }
        int m = a[n]; //the mod by which we must go up or down; WE ARE GETTING STACKOVERFLOW
        int k = 2;

        for (int i=n-m; i>=0;i-=m){
            if (f(i) == 2) {
                k=1;
                break;
            }
        }
        if (k==1) return dp[n] = 1;
        for (int i = n+m; i<dp.length;i+=m){
            if (f(i) == 2) {
                k=1;
                break;
            }
        }
        return dp[n] = k;

    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int maxn = sc.nextInt();
        dp = new int[maxn];
        a = new int[maxn];
        for (int i = 0; i<maxn;i++){
            a[i] = sc.nextInt();
        }
        for(int i = 0; i<maxn;i++){
            if (f(i)%2 ==0) System.out.print("B");
            else System.out.print("A");
        }

    }
}
