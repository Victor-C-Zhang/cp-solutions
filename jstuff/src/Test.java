import java.math.BigInteger;
import java.util.*;
import java.lang.*;
public class Test {
	public static void main(String[] args) {
        Character c1 = '*';
        String s = "*..*.";
        System.out.println((s.charAt(0)) == (c1));
        int blue =50000;
        int red = 50000;
        int n =  100000;
        System.out.println((long) red*blue-n+1);
        s = "A! big bad wolf Ar a a! ";
        String[] arr = s.split(" ");
        String word = "A";
        String temp = "";
        List<String> clean = new LinkedList<String>();
        for (int i=0;i<arr.length;i++) {
            if (arr[i].equalsIgnoreCase(word) ||
                    (arr[i].substring(0,arr[i].length()-1).equalsIgnoreCase(word) && ".;:!?".contains(""+ arr[i].charAt(arr[i].length()-1))))
            {
                if (!temp.equals("")) clean.add(temp);
                clean.add(arr[i]);
                temp = "";
            }
            else {
                temp += arr[i];
            }
            if (i!=arr.length-1) temp+=" ";
        }
        if (s.charAt(s.length()-1)==' ') temp+=" ";
        if (!temp.equals("")) clean.add(temp);
        for (String a : clean) System.out.println("\"" + a + "\"");
	}
}
