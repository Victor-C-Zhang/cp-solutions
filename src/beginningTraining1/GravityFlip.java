package beginningTraining1;

import java.lang.*;
import java.util.*;
import java.io.*;

public class GravityFlip {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> arr = new ArrayList<>();
        for (int i = 0; i<n;i++){
            arr.add(sc.nextInt());
        }
        Collections.sort(arr);
        for (Integer i : arr) System.out.print(i + " ");
        System.out.println();
    }
}
