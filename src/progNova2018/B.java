package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

//WA
public class B {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        int[] numopen = new int[n];
        int[] numclose = new int[n];
        for (int i = 0; i<n;i++){
            String s = sc.nextLine();
            for (int j=0;j<n;j++){
                if (s.charAt(j) == '(' ) {
                    numopen[j] ++;
                }
                else numclose[j]++;
            }

        }
        for (int i =0;i<n;i++){
            numclose[i] = n- numopen[i];
        }
        for (int i=0;i<n;i++){
            int curr = 0;
            if (numopen[0] == 0) {
                System.out.println("No");
                return;
            }
            numopen[0]--;
            curr++;
            int zero = 0;
            int j = 1;
            while (j<n-curr){
                if (curr==0) {
                    if (numopen[j]>0){
                        numopen[j]--;
                        curr++;
                        j++;
                        continue;
                    }
                    else {
                        System.out.println("No");
                        return;
                    }
                }
                if (numclose[j] !=0){
                    curr--;
                    numclose[j]--;
                    if (curr==0) zero = j+1;
                }
                else if (numopen[j] != 0) {
                    curr++;
                    numopen[j]--;
                }
                else {
                    System.out.println("No");
                    return;
                }
                j++;
            }
            while (j<n){
                if (numclose[j]>0){
                    numclose[j]--;
                    curr--;
                }
                else {
                    System.out.println("No");
                    return;
                }
                j++;
            }
            if (curr!=0) {
                System.out.println("No");
                return;
            }
        }
        System.out.println("Yes");

    }
}
