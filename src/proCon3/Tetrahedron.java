package proCon3;

import java.util.*;
import java.io.*;

public class Tetrahedron {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] dp = new int[n+1];
		dp[1]=0;
		for (int i=2;i<n+1;i++) {
			dp[i] = (int) Math.pow(3, i-1) - dp[i-1];
		}
		System.out.println(dp[n]);
	}
}
