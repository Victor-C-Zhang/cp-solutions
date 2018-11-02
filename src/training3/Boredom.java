package training3;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Boredom {
	public static int[] arr = new int[100007];
    public static long[] dp = new long[100007];
	public static long iter(int n) {
        if (n==0) return 0;
        if (n==1) return dp[1] = arr[1];
        if (n==2) return dp[2] = 2*(long)arr[2];
        return dp[n] = n* (long) arr[n] + Math.max(dp[n-2],dp[n-3]);
	}
	
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        for (int i = 0;i<n;i++){
            int a = sc.nextInt();
            arr[a]++;
        }
        for (int i =1;i<100007;i++){
            dp[i] = -1;
        }
        for (int i = 1;i<=100000;i++){
            iter(i);
        }
        System.out.println(Math.max(dp[99999], dp[100000]));
	}

}
