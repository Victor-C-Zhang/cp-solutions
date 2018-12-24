package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

public class CanonicalCoinSystems {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        for (int i=n-2;i>-1;i--){
            if (arr[i]>arr[i+1]/2) {
                System.out.println("non-canonical");
                return;
            }
        }
        System.out.println("canonical");
    }
}
