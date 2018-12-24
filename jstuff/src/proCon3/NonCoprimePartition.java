package proCon3;
 import java.util.*;
 import java.io.*;
 
public class NonCoprimePartition {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		if (n ==1 || n==2) System.out.println("No");
		else {
			System.out.println("Yes");
			System.out.println("1 " + n);
			System.out.print(n-1 + " ");
			for (int i=1;i<n;i++) {
				System.out.print(i);
				System.out.print(" ");
			}
			System.out.println();
		}
		sc.close();
	}
}
