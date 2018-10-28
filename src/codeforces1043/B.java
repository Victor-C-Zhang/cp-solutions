package codeforces1043;

import java.util.*;
import java.lang.*;
import java.io.*;

public class B {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean flipped = false;
        String s = sc.nextLine();
        int n = s.length();
        for (int i=0;i<n-1;i++) {
            if (s.charAt(i+1) == 'a'){
                if (flipped) System.out.print("0 ");
                else {
                    flipped = true;
                    System.out.print("1 ");
                }
            }
            else {
                if (!flipped) System.out.print("0 ");
                else {
                    flipped = false;
                    System.out.print("1 ");
                }
            }
        }
        if (flipped) System.out.println("1");
        else System.out.println("0");
    }
}
