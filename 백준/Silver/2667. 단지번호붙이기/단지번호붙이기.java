import java.io.*;
import java.util.*;

public class Main {
    static class XY{
        int x;
        int y;

        public XY(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static int map[][];
    static boolean visited[][];
    static int n;

    static int BFS(XY start){
        Queue<XY> queue = new LinkedList<>();
        queue.add(start);
        int count = 1;
        visited[start.x][start.y] = true;
        while (!queue.isEmpty()){
            XY now = queue.poll();
            for(int i = 0;i<4;i++){
                int nextx = now.x + next_x[i];
                int nexty = now.y + next_y[i];

                if(nextx <0 || nexty<0 || nextx>=n|| nexty>=n) continue;
                if(visited[nextx][nexty]) continue;
                if(map[nextx][nexty] == 0) continue;
                visited[nextx][nexty] = true;
                count++;
                queue.add(new XY(nextx, nexty));
            }
        }
        return count;
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0;i<n;i++){
            String s = br.readLine();
            for(int j =0;j<n;j++){
                map[i][j] = Integer.parseInt(s.substring(j,j+1));
            }
        }
        int resultcount = 0;
        ArrayList<Integer> list=  new ArrayList<>();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j]) continue;
                if(map[i][j] == 0) continue;

                list.add(BFS(new XY(i,j)));
                resultcount++;
            }
        }
        System.out.println(resultcount);
        Collections.sort(list);
        for (int i = 0;i<list.size();i++){
            System.out.println(list.get(i));
        }


    }
}