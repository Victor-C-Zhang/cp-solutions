package beginningTraining1;

import java.util.*;

public class ARMLresults {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        for (int i=0;i<58;i++){
            cnt+=sc.nextInt();
        }
        System.out.println((double)cnt/58/15);
    }
}
