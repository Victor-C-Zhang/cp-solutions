package training4;

import java.util.*;
import java.io.*;
import java.lang.*;

public class NikitaAndString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		ArrayList<Integer> arr = new ArrayList<>();
		//converts string to list
		//ex: abba => 1,2,1 ; bab => 0,1,1,1,0
		char temp = 'a';
		int numtemp = 0;
		for (int i=0;i<s.length();i++) {
			if (s.charAt(i) == temp) numtemp++;
			else {
				arr.add(numtemp);
				numtemp = 1;
				temp = s.charAt(i);
			}
		}
		arr.add(numtemp);
		if (temp == 'b') arr.add(0);
		
		int minsofar = 6000;
		for (int bstart = 1; bstart<arr.size()-1;bstart+=2) {
			for (int astart = bstart+1; astart<arr.size(); astart +=2){
				int currmin = 0;
				for (int i = bstart+1; i<astart; i+=2) {
					currmin +=arr.get(i);
				}
				for (int i = bstart-2; i>-1;i-=2) {
					currmin+=arr.get(i);
				}
				for (int i = astart+1; i<arr.size();i+=2) {
					currmin +=arr.get(i);
				}
				if (currmin<minsofar) minsofar = currmin;

			}
		}
		System.out.println(s.length()-minsofar);
	}
}


