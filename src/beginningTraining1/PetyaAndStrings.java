package beginningTraining1;

import java.util.*;
import java.lang.*;
import java.io.*;

public class PetyaAndStrings {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().toLowerCase();
        String t = sc.nextLine().toLowerCase();
        if (s.compareTo(t)<0) System.out.println("-1");
        else if (s.compareTo(t)==0) System.out.println("0");
        else System.out.println("1");
    }
}
