package proCon4;

import java.util.*;
import java.lang.*;
import java.io.*;

public class StudentsInRailwayCarriage {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int len = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        sc.nextLine();
        String s = sc.nextLine();
        sc.close();

        boolean cont = false;
        int whichnext=-1; //0 = a, 1 = b
        int ans = 0;
        for (int i = 0; i<len; i++){
            if (a==0 && b==0) break;
            if ('*' == s.charAt(i)) {
                cont = false;
                continue;
            }
            if (cont == false){
                cont= true;
                if (b>a) {
                    b--;
                    ans++;
                    whichnext = 0;
                }
                else {
                    a--;
                    ans++;
                    whichnext = 1;
                }
            }
            else if (whichnext == 0 && a>0){
                a--;
                ans++;
                whichnext = 1;
            }
            else if (whichnext == 0 && a==0) {
                whichnext = 1;
            }
            else if (b>0){
                b--;
                ans++;
                whichnext = 0;
            }
            else {
                whichnext = 0;
            }
        }
        System.out.println(ans);
    }
}
