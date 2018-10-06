package proCon2;

import java.lang.*;
import java.util.*;

public class Flowers {
	static int k; //max length of whites
	static int[] dp = new int[100001];
	
	static int f(int n) {
		if (n<=0) return 0;
		if (n<k) return 1;
		if (n==k) return 2;
		if (dp[n]!=0) {
			return dp[n];
		}
		dp[n] = (f(n-1)+f(n-k))%1000000007;
		return dp[n];
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		k = sc.nextInt();
		int[] arr = new int[100001];
		for (int i=1; i<100001; i++) {
			arr[i] = (arr[i-1] + f(i))%1000000007;
		}
		for (int i = 0; i<t; i++) { //change this to only access each array member and do a_n-a_k
			int a = sc.nextInt();
			int b = sc.nextInt();
			System.out.println(((arr[b]-arr[a-1]+1000000007)%1000000007)); //this doesn't work with mods 1000000007
		}
		sc.close();
	}
}
