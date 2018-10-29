package codeforces1043;

import java.util.*;
import java.lang.*;
import java.io.*;

public class D {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); //number sus
        int m = sc.nextInt(); //number cases
        if (m==1) {
            System.out.println(n*(n+1)/2);
            return;
        }
        int[][] master = new int[21][n+1]; //1-10 actual list, 11-20 pointers
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                int a = sc.nextInt();
                master[i][j] = a;
                master[i+10][a] = j;
            }
        }
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        for (int i=1;i<n+1;){
            ArrayList<Integer> curr = new ArrayList<>();
            curr.add(master[1][i]);
            int ind = master[12][i];
            i++;
            ind++;
            try{
                while (master[2][ind]==master[1][i]){
                    curr.add(master[2][ind]);
                    i++;
                    ind++;
                }
            }
            catch (ArrayIndexOutOfBoundsException e){}
            if (curr.size()!=1) arr.add(curr);

        }
        for (int i=3;i<=m;i++){
            for (int j = 0; j<arr.size();j++){ //each list
                boolean changed = false;
                for (int k = 0; k<arr.get(j).size();k++){ //iterate through one list
                    ArrayList<Integer> curr = new ArrayList<>();
                    curr.add(master[i][arr.get(j).get(k)]);
                    int ind = master[i+11][arr.get(j).get(k)];
                    k++;
                    ind++;
                    try{
                        while (master[i+11][ind]==master[i][arr.get(j).get(k)]){
                            curr.add(master[i+11][ind]);
                            k++;
                            ind++;
                        }
                    }
                    catch (ArrayIndexOutOfBoundsException e){}
                    if (curr.size()!=1) {
                        arr.set(j, curr);
                        changed = true;
                    }
                }
                if (!changed) {
                    arr.remove(j);
                    j--;
                }
            }
        }
        int ans = n;
        for (int i = 0; i<arr.size(); i++){
            int a = arr.get(i).size();
            ans+=(a-1)*a/2;
        }
        System.out.println(ans);
        sc.close();
    }
}
