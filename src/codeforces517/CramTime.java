package codeforces517;

import java.util.*;
import java.lang.*;
import java.io.*;

//wrong answer
public class CramTime {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int maxa = 0;
        int add = 1;
        while (maxa<=a+b){
            maxa+=add;
            add++;
        }
        int max = add-2;
        if (max*(max-1)/2 > (a+b)) max--;
        boolean[] touched = new boolean[max+1];
        touched[0] = true;
        int i=1;
        int atouched = 0;
        while(a>0){
            a-= i;
            atouched++;
            if (a>=0) touched[i] = true;
            else {
                touched[i-1] = false;
                try{
                    touched[a+i+i-1] = true;
                }
                catch (ArrayIndexOutOfBoundsException e){
                    touched[max] = true;
                }
                atouched--;
            }
            i++;
        }
        System.out.println(atouched);
        for (int j=1;j<max+1;j++){
            if (touched[j]) System.out.print(j + " ");
        }
        System.out.println();
        System.out.println(max-atouched);
        for (int j=1;j<max+1;j++){
            if (!touched[j]) System.out.print(j+ " ");
        }
        System.out.println();

    }
}
