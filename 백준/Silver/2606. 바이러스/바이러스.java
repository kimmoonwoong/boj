import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	
	static int BFS(ArrayList<ArrayList<Integer>> list, int start, ArrayList<String> visited) {
		Queue<Integer> queue= new LinkedList<>();
		queue.add(start);
		visited.set(start, "YES");
		int count = 0;
		while(!queue.isEmpty()) {
			int u = queue.poll();
			for(int i = 0; i<list.get(u).size(); i++) {
				if(visited.get(list.get(u).get(i)).equals("NO")) {
					visited.set(list.get(u).get(i), "YES");
					queue.add(list.get(u).get(i));
					count++;
				}
			}
		}
		return count;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int m = Integer.parseInt(br.readLine());
		ArrayList<ArrayList<Integer>> list = new ArrayList<>();
		ArrayList<String> visited = new ArrayList<>();
		list.add(new<Integer> ArrayList());
		for(int i = 0; i<n; i++) {
			list.add(new <Integer> ArrayList());
		}
		for(int i = 0; i<list.size(); i++) {
			visited.add("NO");
		}
		for(int i =0; i<m; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine() + " ");
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			list.get(v1).add(v2);
			list.get(v2).add(v1);
		}
		System.out.print(BFS(list, 1, visited));
	}
}