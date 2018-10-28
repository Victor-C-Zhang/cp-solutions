package codeforces1043;

import java.util.*;
import java.lang.*;
import java.io.*;

public class C {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n+1];
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i=1;i<n+1;i++){
            arr[i] = sc.nextInt();
        }
        int a1 = arr[1];
        for (int i=2;i<n+1;i++){
            if (arr[i] == arr[i-1] + a1){
                int len = i-1;
                int cnt = 1;
                int trav = 2;
                boolean broken = false;
                for (int j=i+1;j<n+1;j++){
                    if (arr[j] == arr[trav] + cnt*arr[len]){
                        trav++;
                        if (trav==len){
                            trav = 0;
                            cnt++;
                        }
                    }
                    else {
                        broken = true;
                        break;
                    }
                }
                if (!broken) ans.add(i-1);
            }
        }
        ans.add(n);
        System.out.println(ans.size());
        for (int i: ans){
            System.out.print(i + " ");
        }
        System.out.println();
    }
}
