package beginningTraining1;

import java.util.*;
import java.io.*;

public class Team {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        for (int i=0;i<n;i++){
            int j = sc.nextInt() + sc.nextInt() + sc.nextInt();
            if (j>1) cnt++;
        }
        System.out.println(cnt);
    }
}
