
public class Test {
	public static void main(String[] args) {
		System.out.println("".concat(String.valueOf(253532523)));
		long cnt = 0;
		for (int j = 1; j<41; j++) {
			cnt +=Math.pow(2, j);
			cnt = cnt % 1000000007;
		}
		System.out.println(cnt);
	}
}
