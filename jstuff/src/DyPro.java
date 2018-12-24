/*Dynamic programming: math way to simplify a problem into subproblems (TAUGHT IN ALGO, 344) tues, gm, thurs, prob2
 * Conditions:
 * 		Overlapping subproblems: solving the same subproblem many times
 * 		Optimal Substructure: solving the problem by breaking it down
 * 
 * P1: given 2 sequences, find length of longest subsequence, not necessarily contiguous, in both of them
 * 		Ex: ABCDEFG
 * 			ABXDFG
 * 		ANS: "ABDFG"
 * 
 * P2: given a sequence, find the largest possible sum of a subsequence
 * 		Ex: -2,-3,4,-1,-2,1,5,-3
 * 		ANS: 4,-1,-2,1,5
 */

import java.util.*;
import java.lang.*;

public class DyPro {
	public int p1recursive(char[] X, char[] Y, int m, int n) {
		if (m==0||n==0) {
			return 0;
		}
		if (X[m-1] == Y[n-1]) {
			return 1 + p1recursive(X,Y,m-1,n-1);
		}
		else return Math.max(p1recursive(X,Y,m,n-1),p1recursive(X,Y,m-1,n));
	}
	
	public static void p1memoize(char[] X, char[] Y, int m, int n) {
		//same as recursion, but keep solved solutions in an array
		int[][] storage = new int[m][n]; //"Solve once, remember forever"
	}
	
	public void p1bottomup(char[] X, char[] Y, int m, int n) {
		int[][] L = new int[m+1][n+1]; //matrix with null, string chars on each side
		//if the characters match, add 1 to cell to the top left
		//otherwise, copy top left
	}
	
	public static void p2dp(int[] a) {
		//Kadane's method:
		//for dp[i], check if we add a[i+1] or if we discard dp[i] and start new
		int curr_max = 0;
		int max_so_far = 0;
		for (int i = 0; i<a.length; i++) {
			curr_max = Math.max(a[i],curr_max+a[i]);
			max_so_far = Math.max(max_so_far, curr_max);
		}
		System.out.println(max_so_far);
	}
	static int[] dpfib = new int[100];
	public static int fibonacci(int n) {
		if (n==0) return 0;
		if (dpfib[n] != 0) return dpfib[n];
		return dpfib[n] = fibonacci(n-1) + fibonacci(n-2);
	}
	public static void main(String[] args) {
		int[] a = {-2,-3,4,-1,-2,1,5,-3};
		p2dp(a);
	}
}
