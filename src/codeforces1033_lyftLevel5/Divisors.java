package codeforces1033_lyftLevel5;

import java.util.*;
import java.lang.*;
import java.io.*;

public class Divisors {
    static Hashtable<Long,Long> ht = new Hashtable<>();
    static int n;
    static long[][] arr;
    //returns prime factor , number factors if not prime or semiprime
    public static long[] pness(long n){
        long[] arr = new long[2];
        long sqrt = (long) Math.sqrt(n);
        if (sqrt*sqrt == n) {
            long quartroot = (long) Math.sqrt(sqrt);
            if (quartroot*quartroot == sqrt) {
                arr[1] = 4;
                arr[0] = quartroot;
                return arr;
            }
            arr[1] = 2;
            arr[0] = sqrt;
            return arr;
        }
        long cbrt = (long) Math.cbrt(n);
        if (cbrt*cbrt*cbrt == n) {
            arr[1] = 3;
            arr[0] = cbrt;
            return arr;
        }
        arr[1] = 1;
        arr[0] = n;
        return arr;
    }
    public static long gcd(long a, long b) {
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    public static void cleanseFactor(long factor){
        for (int i=0; i<n;i++){
            if (arr[i][0] == 1) continue;
            int temp = 0;
            while (true){
                if (arr[i][0]/factor*factor == arr[i][0]) {
                    temp++;
                    arr[i][0]/=factor;
                    continue;
                }
                break;
            }
            ht.put(factor, ht.get(factor)+temp);
        }
    }
    public static boolean isPrime(long num){
        if ( num > 2 && num%2 == 0 ) {
            return false;
        }
        long top = (long)Math.sqrt(num) + 1;
        for(long i = 3; i < top; i+=2){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt(); //number of terms
        arr = new long[n][2]; //array of [number, whetehr its been touched]
        for (int i=0;i<n;i++) {
            arr[i][0] = sc.nextLong();
        }

        int prod = 1;

        for (int i=0;i<n;i++){
            if (arr[i][0] == 1) continue;
            for (int j = i+1;j<n;j++){
                if (arr[j][0] ==1) continue;
                long[] pnessres = pness(gcd(arr[i][0],arr[j][0]));
                if (arr[i][1] == 0 && arr[j][1] == 0 && pnessres[1] ==1 && !isPrime(pnessres[0])){
                    prod*=9;
                    arr[i][0] = 1;
                    arr[i][1] =1;
                    arr[j][0] = 1;
                    arr[j][1] = 1;
                }
                else if (pnessres[0] != 1) {
                    ht.put(pnessres[0],0L);
                    cleanseFactor(pnessres[0]);
                    arr[i][1] = 1;
                    arr[j][1] = 1;
                }
            }
        }
        for (int i=0;i<n;i++){
            if (arr[i][1] != 1 && pness(arr[i][0])[1] == 1) prod*=4;
            else if (arr[i][0] != 1) prod*=pness(arr[i][0])[1]+1;
            prod%=998244353;
        }
        for (Enumeration<Long> e = ht.elements(); e.hasMoreElements();) {
            prod *= e.nextElement() + 1;
            prod%=998244353;
        }
        System.out.println(prod);

    }
}
