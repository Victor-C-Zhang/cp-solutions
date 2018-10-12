package training4;

import java.lang.*;
import java.util.*;
import java.io.*;

public class ShashlikCooking {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        //divide n by (2k+1)
        int tk1 = 2*k +1;
        if (n%tk1>k) {
            System.out.println(n/tk1 +1);
            for (int i = k+1;i<n+1;i+=tk1) {
                System.out.print(i + " ");
            }
        }
        else if (n%tk1==0) {
            System.out.println(n/tk1);
            for (int i = k+1;i<n+1;i+=tk1) {
                System.out.print(i + " ");
            }
        }
        else {
            System.out.println(n/tk1 +1);
            for (int i = n%tk1 ;i<n+1;i+=tk1) {
                System.out.print(i + " ");
            }
        }

        sc.close();
    }
}