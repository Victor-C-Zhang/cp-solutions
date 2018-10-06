package proCon3;

import java.util.*;
import java.io.*;

public class Juicer {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //te number of oranges
		int b = sc.nextInt(); //max size
		int d = sc.nextInt(); //size of trash
		int cnt = 0;
		int trash = 0;
		for (int i = 0; i<n;i++) {
			int orange = sc.nextInt();
			if (orange>b) continue;
			else {
				trash +=orange;
				if (trash>d) {
					trash = 0;
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}
}
