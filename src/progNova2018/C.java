package progNova2018;

import java.util.*;
import java.lang.*;
import java.io.*;

//incomplete
public class C {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String orig = sc.nextLine();
        int space1 = orig.indexOf(' '); //first word
        int space2 = orig.indexOf(' ', space1+1); //xor
        int space3 = orig.indexOf(' ', space2+1); //second word
        int space4 = orig.indexOf(' ', space3+1); //=

        String s1 = orig.substring(0, space1); //first num
        String s2 = orig.substring(space2+1, space3); //second num
        String s3 = orig.substring(space4+1); //third num


    }
}
