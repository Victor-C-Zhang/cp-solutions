package training5;
import java.util.*;
import java.lang.*;
import java.io.*;

//This TLEs
public class BooksQueries {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        LinkedList<Integer> deq = new LinkedList<>();
        for (int i=0; i<n;i++){
            String s = sc.next();
            if (s.equals("L")){
                deq.addFirst(sc.nextInt());
            }
            else if (s.equals("R")){
                deq.addLast(sc.nextInt());
            }
            else {
                int index = deq.indexOf(sc.nextInt());
                System.out.println(Math.min(index, deq.size()-index-1));
            }
            sc.nextLine();
        }
    }
}
