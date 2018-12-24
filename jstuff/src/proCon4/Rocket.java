package proCon4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Rocket {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int right = sc.nextInt();
        int left = 1;
        int n = sc.nextInt();
        boolean[] truth = new boolean[n];
        for (int i=0;i<n;i++){
            System.out.println(1);
            System.out.flush();
            int test = sc.nextInt();
            if (test == 0 || test == -2) return;
            if (test == 1) truth[i] = true;
        }
        int cnt = 0;
        while (left<=right) {
            int mid = (left + right) / 2;
            System.out.println(mid);
            System.out.flush();
            int res = sc.nextInt();
            if (res == 0) return;
            if (res == -2) return;
            if (truth[cnt % n]) {
                if (res == 1) left = mid + 1;
                else right = mid;
            } else {
                if (res == -1) left = mid + 1;
                else right = mid;
            }
            cnt++;
        }
    }
}
