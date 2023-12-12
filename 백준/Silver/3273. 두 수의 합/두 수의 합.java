import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
		public static void main(String[] args) throws NumberFormatException, IOException{
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(br.readLine());
			int numbers[] = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine()+ " ");
			for(int i =0; i<n; i++) {
				numbers[i] = Integer.parseInt(st.nextToken());
			}
			int x = Integer.parseInt(br.readLine());
			int start = 0;
			int end = n-1;
			int count = 0;
			Arrays.sort(numbers);
			while(end>start) {
				if(numbers[start] + numbers[end] == x) {
					count++;
					start++;
					end--;
				}
				else if(numbers[start] + numbers[end] > x) {
					end--;
				}
				else start++;
			}
			System.out.print(count);
	}	
}