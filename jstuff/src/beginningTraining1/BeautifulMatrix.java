package beginningTraining1;

import java.util.*;
import java.io.*;
import java.lang.*;

public class BeautifulMatrix {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = 0;
        while (true){
            if (sc.nextInt()==1) break;
            n++;
        }
        int row = n/5 + 1;
        int col = n%5 + 1;
        System.out.println(Math.abs(3-row)+Math.abs(3-col));
    }
}
