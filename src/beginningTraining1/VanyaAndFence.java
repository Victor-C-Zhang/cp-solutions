package beginningTraining1;

import java.util.*;
import java.io.*;

public class VanyaAndFence {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cnt = sc.nextInt();
        int h = sc.nextInt();
        int width = 0;
        for (int i=0;i<cnt;i++){
            if (sc.nextInt()>h) width+=2;
            else width+=1;
        }
        System.out.println(width);
    }
}
