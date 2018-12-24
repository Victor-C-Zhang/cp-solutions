package training5;

import java.util.*;
import java.io.*;
import java.lang.*;

public class AandBandCompilationErrors {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[n-1];
        int[] arr3 = new int[n-2];
        for (int i=0;i<n;i++) arr1[i] = sc.nextInt();
        for (int i=0;i<n-1;i++) arr2[i] = sc.nextInt();
        for (int i=0;i<n-2;i++) arr3[i] = sc.nextInt();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        Arrays.sort(arr3);
        for (int i=0; i<n; i++) {
            try{
                if (arr1[i] != arr2[i]) {
                    System.out.println(arr1[i]);
                    break;
                }
            }
            catch (IndexOutOfBoundsException e) {
                System.out.println(arr1[i]);
            }
        }
        for (int i=0; i<n-1; i++) {
            try{
                if (arr2[i] != arr3[i]) {
                    System.out.println(arr2[i]);
                    break;
                }
            }
            catch (IndexOutOfBoundsException e) {
                System.out.println(arr2[i]);
            }
        }


    }
}
