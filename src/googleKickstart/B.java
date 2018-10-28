package googleKickstart;

import java.io.*;
import java.lang.*;
import java.util.*;

public class B {
    public static void main(String[] args){
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int ncases = sc.nextInt();
        for (int scen = 1;scen<=ncases;scen++){
            int n = sc.nextInt();
            int q = sc.nextInt();
            long x1 = sc.nextLong();
            long x2 = sc.nextLong();
            long a1 = sc.nextLong();
            long b1 = sc.nextLong();
            long c1 = sc.nextLong();
            long m1 = sc.nextLong();
            int[] X = new int[n];
            X[0] = (int) x1;
            try{ X[1] = (int) x2;}
            catch (IndexOutOfBoundsException e){}
            for (int i=2;i<n;i++){
                X[i] =(int) ((a1*(long)X[i-1] + b1*(long)X[i-2] + c1) % m1);
            }
            long y1 = sc.nextLong();
            long y2 = sc.nextLong();
            long a2 = sc.nextLong();
            long b2 = sc.nextLong();
            long c2 = sc.nextLong();
            long m2 = sc.nextLong();
            int[] Y = new int[n];
            Y[0] =(int) y1;
            try {Y[1] =(int) y2;}
            catch (IndexOutOfBoundsException e){}
            for (int i=2;i<n;i++){
                Y[i] =(int) ((a2*(long)Y[i-1] + b2*(long)Y[i-2] + c2) % m2);
            }
            long z1 = sc.nextLong();
            long z2 = sc.nextLong();
            long a3 = sc.nextLong();
            long b3 = sc.nextLong();
            long c3 = sc.nextLong();
            long m3 = sc.nextLong();
            int[] Z = new int[q];
            Z[0] = (int) z1;
            try{ Z[1] = (int)z2;}
            catch (IndexOutOfBoundsException e){}
            for (int i=2;i<q;i++){
                Z[i] = (int)((a3*(long)Z[i-1] + b3*(long)Z[i-2] + c3) % m3);
            }
            //int[] X = new int[n]; //mins
            //int[] Y = new int[n]; //maxes
            //int[] Z = new int[q]; //queries
            int maxr = 0;
            for (int i=0;i<n;i++){
                int x = Math.min(X[i],Y[i]) + 1;
                int y = Math.max(X[i],Y[i]) + 1;
                X[i] = x; Y[i] = y;
                if (Y[i]>maxr) maxr = Y[i];
            }
            for (int i=0;i<q;i++){
                Z[i] = Z[i] + 1;
            }
            int[] prefix = new int[maxr+1];
            for (int i=0;i<n;i++){
                prefix[Y[i]]++;
                prefix[X[i]-1]--;
            }
            for (int i=maxr-1;i>-1;i--){
                prefix[i] = prefix[i+1] + prefix[i];
            }
            long sum = 0;
            for (int i=1;i<=q;i++){
                long cnt = 0;
                for (int j=maxr;j>=0;j--){
                    Z[i-1]-=prefix[j];
                    cnt = j;
                    if (Z[i-1]<=0) break;
                }
                sum+=cnt*i;
            }
            System.out.println("Case #" + scen + ": "+ sum);

        }
        sc.close();
    }
}
