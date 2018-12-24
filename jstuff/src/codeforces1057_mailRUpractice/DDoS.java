package codeforces1057_mailRUpractice;

import java.util.*;
import java.lang.*;
import java.io.*;

public class DDoS {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n+1];
        int maxsoFar = 0;
        int currmax = 0;
        double sum = 0;
        boolean ddos = false;
        for (int i=1;i<=n;i++) {
            int val = sc.nextInt();
            arr[i] = val;
            if (val>100 && !ddos) {
                currmax = 1;
                sum = val;
                ddos = true;
                for (int j = i-1;j>0;j--){
                    if ((sum+arr[j])/(i-j+1)>100){
                        currmax++;
                        sum+=arr[j];
                        continue;
                    }
                    maxsoFar = Math.max(currmax,maxsoFar);
                    break;
                }
                maxsoFar = Math.max(currmax,maxsoFar);
            }
            else if (ddos) {
                sum+=val;
                if (sum/(currmax+1)>100){
                    currmax++;
                }
                else {
                    ddos = false;
                    maxsoFar = Math.max(maxsoFar,currmax);
                }
            }
        }
        maxsoFar = Math.max(maxsoFar,currmax);
        System.out.println(maxsoFar);
    }
}
