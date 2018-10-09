package training4;

import java.lang.*;
import java.util.*;
import java.io.*;

public class Joysticks {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int cnt = 0;
		while (a>=1 && b>=1) {
			if (a>=b) {
				b++;
				a-=2;
				if (a<0) break;
				cnt ++;
			}
			else {
				a++;
				b-=2;
				if (b<0) break;
				cnt++;
			}
		}
		System.out.println(cnt);
		sc.close();
	}
}