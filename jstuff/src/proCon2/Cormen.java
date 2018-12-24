package proCon2;

import java.util.*;
import java.lang.*;

public class Cormen {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //num days
		int tar = sc.nextInt(); //target num of walks
		sc.nextLine();
		int[] arr = new int[n];
		for (int i = 0; i<n;i++) {
			arr[i]=sc.nextInt();
		}
		int cnt = 0;
		for (int i=1; i<n;i++) {
			int c = tar - arr[i] - arr[i-1];
			if (c>0) {
				arr[i]+=c;
				cnt+=c;
			}
		}
		System.out.println(cnt);
		for (int i: arr) {
			System.out.print(i + " ");

		}
	}
}
