package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Modulo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        boolean[] mods = new boolean[42];
        for (int i=0;i<10;i++){
            mods[sc.nextInt() % 42] = true;
        }
        int cnt = 0;
        for (int i=0;i<42;i++){
            if (mods[i]) cnt++;
        }
        System.out.println(cnt);
    }
}
