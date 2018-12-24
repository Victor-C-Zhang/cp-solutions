import java.lang.*;
import java.util.*;

public class DPRUCP {
}

class CountingChocolates{ //ideone.com/iHsCGa
	static int[] dp = new int[100];
	static int[] a; // user input
	int recur(int n) {
		if (n<0) return 0;
		if (n == 0 || n == 1) return a[n];
		if (dp[n]!= 0) return dp[n];
		return dp[n] = Math.max(recur(n-2), recur(n-3));
	}
}

class Triangle{ //ideone.com/ecYoGi
	static int n;
	static int[][] dp = new int[100][100];
	static int[][] a; // user input
	int fill(int r, int c) {
		if (r==n) return a[r][c];
		if (dp[r][c]!= 0) return dp[r][c];
		return dp[r][c] = Math.max(fill(r+1,c),fill(r+1,c+1));
	}
}