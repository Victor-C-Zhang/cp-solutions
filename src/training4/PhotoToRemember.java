package training4;

import java.util.*;
import java.io.*;
import java.lang.*;

public class PhotoToRemember {
    //create max, and max-1: assign max to holder, assign curr_max to max
//keep counter of width, keep counter of height, if max height chosen, output max-1
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> width = new ArrayList<>();
        ArrayList<Integer> height = new ArrayList<>();
        ArrayList<Integer> sortheight = new ArrayList<>();
        int w=0,maxh,submaxh;
        for (int i=0; i<n;i++) {
            int j = sc.nextInt();
            width.add(j);
            w+=j;
            int k = sc.nextInt();
            height.add(k);
            sortheight.add(k);
/*			if (Math.max(maxh, k)!=maxh) {
				submaxh = maxh;
				maxh = k;
			}
*/		}
        Collections.sort(sortheight, Collections.reverseOrder());
        maxh = sortheight.get(0);
        submaxh = sortheight.get(1);
        for (int i=0; i<n;i++) {
            if (height.get(i)==maxh) {
                int W = w-width.get(i);
                System.out.print(W*submaxh + " ");
            }
            else {
                int W = w-width.get(i);
                System.out.print(W*maxh + " ");
            }
        }
        System.out.println();
        sc.close();
    }
}
