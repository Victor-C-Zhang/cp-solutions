package codeforces1033_lyftLevel5;

import java.util.*;
import java.lang.*;

public class KingEscape {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        sc.nextInt();
        int a1 = sc.nextInt();
        int a2 = sc.nextInt();
        int b1 = sc.nextInt();
        int b2 = sc.nextInt();
        int c1 = sc.nextInt();
        int c2 = sc.nextInt();
        int quadk; //quadrant of king
        int quadc; //quad of c
        if (a1-b1<0){
            if (a2-b2<0) quadk = 1;
            else quadk = 4;
        }
        else {
            if (a2-b2<0) quadk = 2;
            else quadk = 3;
        }

        if (a1-c1<0){
            if (a2-c2<0) quadc = 1;
            else quadc = 4;
        }
        else {
            if (a2-c2<0) quadc = 2;
            else quadc = 3;
        }
        if (quadk == quadc) System.out.println("YES");
        else System.out.println("NO");
    }
}
