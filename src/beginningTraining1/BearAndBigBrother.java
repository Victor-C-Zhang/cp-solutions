package beginningTraining1;

import java.util.*;
import java.io.*;

public class BearAndBigBrother {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int cnt = 0;
        while (a<=b){
            a*=3;
            b*=2;
            cnt++;
        }
        System.out.println(cnt);
    }
}
