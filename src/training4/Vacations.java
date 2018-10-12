package training4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Vacations {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int vacdays = 0;
        int type = 0;
        for (int i=0; i<n;i++) {
            int j = sc.nextInt();
            if (j==0) {
                vacdays++;
                type = 0;
            }
            else if (j==3) {
                if (type == 1) type=2;
                else if (type ==2) type =1;
            }
            else {
                if (type == j) {
                    vacdays++;
                    type = 0;
                }
                else type = j;
            }
        }
        System.out.println(vacdays);
    }
}