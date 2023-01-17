import java.io.*;
import java.util.*;
public class Main {
	
	static long muiltyply(long x) {
		return x * 2;
	}
	
	static long rightOne(long x) {
		return x * 10 + 1;
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine() + " ");
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		boolean isCheck = false;
		boolean visited[] = new boolean[B + 1];
		Queue<long[]> queue = new LinkedList<>();
		queue.add(new long[] {A,0});
		while(!queue.isEmpty()) {
			long n[] = queue.poll();
			if(n[0] == B) {
				System.out.print(n[1] + 1);
				isCheck = true;
				break;
			}
			if(muiltyply(n[0]) <=B && !visited[(int) muiltyply(n[0])]) {
				visited[(int) muiltyply(n[0])] = true;
				queue.add(new long[] {muiltyply(n[0]), n[1] + 1});
			}
			if(rightOne(n[0]) <= B && !visited[(int) rightOne(n[0])]) {
				visited[(int) rightOne(n[0])] = true;
				queue.add(new long[] {rightOne(n[0]), n[1] + 1});
			}
		}
		if(!isCheck) System.out.print(-1);
	}
}	