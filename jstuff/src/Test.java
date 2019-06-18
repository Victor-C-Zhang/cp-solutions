import java.io.File;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.*;
import java.lang.*;
public class Test {
	public static void main(String[] args) {
//        Character c1 = '*';
//        String s = "*..*.";
//        System.out.println((s.charAt(0)) == (c1));
//        int blue =50000;
//        int red = 50000;
//        int n =  100000;
//        System.out.println((long) red*blue-n+1);
//        s = "A! big bad wolf Ar a a! ";
//        String[] arr = s.split(" ");
//        String word = "A";
//        String temp = "";
//        List<String> clean = new LinkedList<String>();
//        for (int i=0;i<arr.length;i++) {
//            if (arr[i].equalsIgnoreCase(word) ||
//                    (arr[i].substring(0,arr[i].length()-1).equalsIgnoreCase(word) && ".;:!?".contains(""+ arr[i].charAt(arr[i].length()-1))))
//            {
//                if (!temp.equals("")) clean.add(temp);
//                clean.add(arr[i]);
//                temp = "";
//            }
//            else {
//                temp += arr[i];
//            }
//            if (i!=arr.length-1) temp+=" ";
//        }
//        if (s.charAt(s.length()-1)==' ') temp+=" ";
//        if (!temp.equals("")) clean.add(temp);
//        for (String a : clean) System.out.println("\"" + a + "\"");
        int levelNumber = 3, stars = 2;
        File file = new File("/home/victor/CODE/balls/optimal-mrppg/classes/artifacts/omrppg_jar/practice.txt");
        File temp = new File("/home/victor/CODE/balls/optimal-mrppg/classes/artifacts/omrppg_jar/temp.txt");
        FileWriter fw;
        Scanner sc;
        try {
            fw = new FileWriter(temp);
            sc = new Scanner(file);
            int n = sc.nextInt();
            sc.nextLine();
            fw.write(Integer.toString(n));
            fw.write(System.lineSeparator());
            int seekNum = 2 + (levelNumber-1)*4;
            for (int i=0;i<seekNum;i++) {
                fw.write(sc.nextLine());
                fw.write(System.lineSeparator());
            }
            sc.nextLine();
            fw.write('0'+stars);
            fw.write(System.lineSeparator()); //line3
            fw.write(sc.nextLine());
            fw.write(System.lineSeparator()); //line4
            if (levelNumber!=n){
                fw.write(sc.nextLine());
                fw.write(System.lineSeparator()); //line1
                fw.write('1');
                fw.write(System.lineSeparator());
                while (sc.hasNextLine()) {
                    fw.write(sc.nextLine());
                    fw.write(System.lineSeparator());
                }
            }
            fw.flush();
            fw.close();
        }
        catch (Exception e) {e.printStackTrace();}
        System.out.println(temp.renameTo(file));
	}
}
