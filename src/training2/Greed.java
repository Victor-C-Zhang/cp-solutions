package training2;

import java.util.*;
public class Greed {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = Integer.parseInt(sc.nextLine());
		Integer[] vol = new Integer[n];
		Integer[] max = new Integer[n];
		String[] svol = sc.nextLine().split(" ");
		String[] smax = sc.nextLine().split(" ");
		for (int i = 0; i<n; i++) {
			vol[i] = Integer.parseInt(svol[i]);
		}
		for (int i = 0; i<n; i++) {
			max[i] = Integer.parseInt(smax[i]);
		}
		sc.close();
		Arrays.sort(max, Collections.reverseOrder());
		int sum = max[0]+max[1];
		boolean sent = true;
		for (Integer i:vol) {
			sum-=i;
			if (sum<0) {
				sent = false;
				break;
			}
		}
		if (sent) {
			System.out.println("YES");
		}
		else System.out.println("NO");
	}
}
