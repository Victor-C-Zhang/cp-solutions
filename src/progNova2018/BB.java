package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

//WA again

public class BB {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        sc.nextLine();
        for (int i =0;i<n;i++){
            String line = sc.nextLine();
            for (int j = 0;j<n;j++){
                if (line.charAt(j) == '(') arr[j]++;
                else arr[j]--;
            }
        }
        for (int i=1;i<n;i++){
            arr[i] += arr[i-1];
        }

        if (arr[0]!=n) {
            System.out.println("No");
            return;
        }
        if (arr[n-1]!= 0) {
            System.out.println("No");
            return;
        }
        for (int i=1;i<n-1;i++){
            if (arr[i]<0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");
    }
}
