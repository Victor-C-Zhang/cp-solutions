package training2;

import java.util.*;
public class WalkingBetweenHouses {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(); //num houses
		int k = sc.nextInt(); //num steps
		long s = sc.nextLong(); //num distance
		sc.close();
		
		long div = s/k;
		long rem = s%k;
		
		if ((div+1>=n || div == 0) && rem != 0) System.out.println("NO");
		else if (div>=n && rem == 0) System.out.println("NO");
		else {
			System.out.println("YES");
			String ans = "";
			boolean flip = true;
			if (rem == 0) {
				long div1 = div + 1;
				for (int i=0; i<k; i++) {
					if (flip) ans = ans.concat(String.valueOf(div1));
					else ans = ans.concat(" 1 ");
					flip = !flip;
				}
				System.out.println(ans.trim());
			}
			else {
				long div2 = div + 2;
				for (int i=0; i<rem; i++) {
					if (flip) ans = ans.concat(String.valueOf(div2));
					else ans = ans.concat(" 1 ");
					flip = !flip;
				}
				for (long i=rem; i<k; i++) {
					if (flip) ans = ans.concat(String.valueOf(div2));
					else ans = ans.concat(" 2 ");
					flip = !flip;
				}
				System.out.println(ans.trim());
			}
		}
	}

}
