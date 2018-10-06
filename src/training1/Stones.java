package training1;

import java.util.Scanner;
public class Stones {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int ans = 0;
		for (int i=5; i >=1; i--) {
			int x = a/i;
			ans +=x;
			a-=i*x;
		}
		System.out.print(ans);
		in.close();
	}
}
