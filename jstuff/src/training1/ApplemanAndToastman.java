package training1;

import java.util.Scanner;
import java.util.Arrays;

public class ApplemanAndToastman {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i=0;i<n;i++) {
			arr[i] = Integer.parseInt(sc.nextLine().split(" ")[i]);
		}
		Arrays.sort(arr);
		int sum = 0;
		for (int i=0;i<n;i++) {
			sum+=(arr[i]*(i+1));
		}
		System.out.println(sum);
		sc.close();
	}
}
