package training2;

import java.util.*;

public class PerfectSquares {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());
		String[] arrn = sc.nextLine().split(" ");
		sc.close();
		int[] arr = new int[n];
		for (int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(arrn[i]);
		}
		Arrays.sort(arr);
		for (int i=n-1;i>-1;i--) {
			int key = arr[i];
			int x = 1;
			boolean found = false;
			if (key==0) continue;
			if (key<0) {
				System.out.println(key);
				break;
			}
			while (x*x<=key) {
				if (x*x==key) {
					found = true;
					break;
				}
				x++;
			}
			if (!found) {
				System.out.println(key);
				break;
			}
		}

	}

}
