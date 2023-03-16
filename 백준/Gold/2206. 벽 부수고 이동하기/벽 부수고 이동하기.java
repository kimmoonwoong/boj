import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
public class Main {	
	static int n;
	static int m;
	static int[][] map;
	static boolean[][][] visied;
	static int[] nextx = {1,-1,0,0};
	static int[] nexty = {0,0,1,-1};
	static int distance;
	static int BFS() {
		Queue<int[]> queue = new LinkedList<>();
		queue.add(new int[] {0,0,1,1});
		boolean isCheck = false;
		while(!queue.isEmpty()) {
			int[]now = queue.poll();
			int now_x = now[0];
			int now_y = now[1];
			int count = now[2];
			int onecount = now[3];
			if(now_x == n-1 && now_y == m-1) {
				distance = count;
				isCheck = true;
				break;
			}
			if(onecount == 0) {
				for(int i =0; i<4;i++) {
					int next_x = now_x + nextx[i];
					int next_y = now_y + nexty[i];
					if(next_x<0|| next_y<0 || next_x>=n|| next_y>=m) {
						continue;
					}
					if(map[next_x][next_y] == 1) continue;
					if(visied[next_x][next_y][1]) continue;
					
					queue.add(new int[] {next_x,next_y,count+1, onecount});
					visied[next_x][next_y][1] = true;
					}
			}
			else {
				for (int i = 0; i < 4; i++) {
					int next_x = now_x + nextx[i];
					int next_y = now_y + nexty[i];
					if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m) {
						continue;
					}
					if (map[next_x][next_y] == 1) {
						if(visied[next_x][next_y][1]) continue;
						queue.add(new int[] { next_x, next_y, count + 1, onecount - 1 });
						visied[next_x][next_y][1] = true;

					}
					else{
						if(visied[next_x][next_y][0]) continue;
						queue.add(new int[] { next_x, next_y, count + 1, onecount });
						visied[next_x][next_y][0] = true;
						
					}
				}
			}
		}
			if(isCheck) return 1;
			else return 0;
		}
	
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st= new StringTokenizer(br.readLine() + " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visied = new boolean[n][m][2];
		for(int i =0; i<n;i++) {
			String s = br.readLine();
			for(int j =0; j<m;j++) {
				map[i][j] = Integer.parseInt(s.substring(j,j+1));
			}
		}
		
		if(BFS() == 0) System.out.print(-1);
		else System.out.print(distance);
	}
}