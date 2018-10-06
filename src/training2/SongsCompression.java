package training2;

import java.util.*;

public class SongsCompression {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String[] emp = sc.nextLine().split(" ");
		int n = Integer.parseInt(emp[0]);
		int max = Integer.parseInt(emp[1]);
		Integer[] a = new Integer[n];
		Integer[] diff = new Integer[n];
		for (int i = 0; i<n; i++) {
			String[] temp = sc.nextLine().split(" ");
			a[i] = Integer.parseInt(temp[0]);
			diff[i] = a[i] - Integer.parseInt(temp[1]); //save the difference between a_i, b_i
		}
		sc.close();
		Arrays.sort(diff, Collections.reverseOrder()); //largest differences first
		int curr_sum = 0;
		for (int i : a) { //find current sum of a_i
			curr_sum+=i;
		}
		boolean senti = true;
		/* for (int i=0; i<n; i++) { // problem: code does not check if last iteration solves the problem
			if (curr_sum>max) { //use a while loop instead with try/catch index out of bounds
				curr_sum-=diff[i];
			}
			else {
				System.out.println(i);
				senti = false;
				break;
			}
		}
		if (curr_sum>max) {
			System.out.println("-1");
		}
		else if (curr_sum<=max && senti == true) {
			System.out.println(n);
		}
		else if (senti==true) System.out.println("-1");
		*/
		int tally = 0;
		for (int i=0; curr_sum>max; i++) { //compress songs incrementally while storage is overfull
			try {
				curr_sum -= diff[i]; //represents 1 song being compressed
				tally++;
			}
			catch (IndexOutOfBoundsException e){ //if curr_sum is still greater than max after all diff[i] are exhausted
				System.out.println("-1");
				senti = false;
				break;
			}
		}
		if (senti) System.out.println(tally);
	}

}
