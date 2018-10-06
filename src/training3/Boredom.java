package training3;

import java.util.*;
import java.lang.*;

public class Boredom {
	public static int[] a; //array of input vals
	public static int[] dp; //dp array, sum if we pick a[n]
	public static int recur(int n) {
		if (n==0) return a[n];
		if (n == 1) return Math.max(a[n], a[n-1]);
		if (dp[n]!=0) return dp[n];
		return 0; //placeholder
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
