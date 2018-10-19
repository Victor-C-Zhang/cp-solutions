package proCon4;

import java.math.BigInteger;
import java.util.*;
import java.lang.*;
import java.io.*;

public class KyoyaandColoredBalls {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        BigInteger[] dp = new BigInteger[1001];
        dp[0] = BigInteger.ONE;
        dp[1] = BigInteger.ONE;
        for (int i=2;i<1001;i++){
            dp[i] = BigInteger.ZERO;
        }
        BigInteger a = new BigInteger(Integer.toString(sc.nextInt()));
        for (int i=1;i<k;i++){
            int b = sc.nextInt()-1;
            if (!(dp[b].equals(BigInteger.ZERO))){
                for (int j=1;j<=b;j++){
                    a=a.multiply(a.subtract(new BigInteger(Integer.toString(i))));
                }
                a=a.divide(dp[b]);

            }
            else {
                dp[b] = dp[b-1].multiply(new BigInteger(Integer.toString(b)));
                for (int j=1;j<=b;j++){
                    a=a.multiply(a.subtract(new BigInteger(Integer.toString(i))));
                }
                a=a.divide(dp[b]);
            }
            a=a.add(BigInteger.ONE);

        }
        System.out.println(a.mod(new BigInteger("1000000007")));
    }
}
