package proCon3;

import java.util.*;
import java.io.*;

public class TeamOlympiad {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<Integer> arr1 = new ArrayList<>();
		ArrayList<Integer> arr2 = new ArrayList<>();
		ArrayList<Integer> arr3 = new ArrayList<>();
		for (int i = 1;i<n+1;i++) {
			int ele = sc.nextInt();
			switch (ele) {
				case 1: arr1.add(i);
					break;
				case 2: arr2.add(i);
					break;
				case 3: arr3.add(i);
					break;	
			}
		}
		int cnt = 0;
		String s = "";
		for (int i = 0; i<n;i++) {
			try {
				s+=arr1.get(i) + " " + arr2.get(i) + " " + arr3.get(i) + " \n";
				cnt++;
			}
			catch (IndexOutOfBoundsException e) {
				break;
			}
		}
		System.out.println(cnt);
		System.out.print(s);
	}
}
