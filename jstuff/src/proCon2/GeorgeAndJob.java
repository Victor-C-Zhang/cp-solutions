package proCon2; //rewrite bottom up

import java.util.*;
import java.lang.*;
import java.io.*;

public class GeorgeAndJob {
	static int m;
	static long[][] dp;
	static long[] arr;
	public static long f(int n, int k) {
		if (n<=0 || k==0) return 0;
		if (n==1 && k==1) return arr[1];
		if (dp[n][k]!=0) return dp[n][k];
		dp[n][k] = Math.max(f(n-1,k), f(n-m,k-1)+arr[n]);
		return dp[n][k];
	}
	
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		int actn = fr.nextInt(); 
		m = fr.nextInt();  //number of things per block
		int k = fr.nextInt(); //choose k pairs
		int n = actn-m+1;
		int[] initarr = new int[actn];
		for (int i = 0; i<actn;i++) {
			initarr[i] = fr.nextInt();
		}
		arr = new long[n+1];
		for (int i=1;i<n+1;i++) {
			for (int j=0;j<m;j++) {
				arr[i]+=initarr[i+j-1];
			}
		}
		dp = new long[n+1][k+1];
		System.out.println(f(n,k));
	}
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
}
