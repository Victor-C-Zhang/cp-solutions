package proCon4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class KyoyaandColoredBalls {
    static int[][] pascal = new int[1001][1001];
    public static int getPascal(int n, int k){
        if (pascal[n][k] != 0) return pascal[n][k];
        if (k==0 || k==n || n==1) return pascal[n][k] = 1;
        return pascal[n][k] = (getPascal(n-1,k-1) + getPascal(n-1,k))%1000000007;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int sticks = sc.nextInt();
        long ans = 1;
        for (int i=1;i<k;i++){
            int bsticks = sc.nextInt();
            ans *= getPascal(sticks+bsticks-1,bsticks-1);
            ans %= 1000000007;
            sticks+=bsticks;
        }
        System.out.println(ans);

    }
}
