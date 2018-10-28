package codeforces1073;

import java.lang.*;
import java.util.*;
import java.io.*;

public class DiverseSubstring {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        for (int i=0;i<n-1;i++){
            if (s.charAt(i) != s.charAt(i+1)) {
                System.out.println("YES");
                System.out.println(Character.toString(s.charAt(i)) + s.charAt(i+1));
                return;
            }
        }
        System.out.println("NO");
    }
}
