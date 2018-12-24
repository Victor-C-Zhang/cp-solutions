package codeforces517;

import java.util.*;
import java.lang.*;
import java.io.*;

public class GoldenPlate {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        int k = sc.nextInt();
        int edge = 0;
        while (k>0){
            edge+=w*h;
            if (w>1&&h>1) edge-=(w-2)*(h-2);
            w-=4;
            h-=4;
            k--;
        }
        System.out.println(edge);
    }
}
