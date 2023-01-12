import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static class XY{
        int x;
        int y;
        int p;

        public XY(int x, int y, int p){
            this.x = x;
            this.y = y;
            this.p = p;
        }
    }
    static int next_x[] = {1,-1,0,0};
    static int next_y[] = {0,0,1,-1};
    static int n;
    static int m;
    static int map[][];
    static Queue<XY> queue[];
    static int index = 3000;
    static int cnt = 0;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        map = new int[n][m];
        queue = new LinkedList[3001];
        for(int i = 0;i<3001;i++){
            queue[i] = new LinkedList<>();
        }
        List<XY> list[] = new ArrayList[3001];
        for(int i = 0;i<3001;i++){
            list[i] = new ArrayList<>();
        }
        for(int i = 0;i<k;i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());

            list[p].add(new XY(x - 1,y - 1,p));
        }
        for(int i = 3000;i>=0;i--){
            for(XY now: list[i]){
                if(map[now.x][now.y] == 0){
                    queue[i].add(now);
                    map[now.x][now.y] = -1;
                }
            }

            while (!queue[i].isEmpty()){
                XY now = queue[i].poll();

                if(now.p == 0) continue;

                for(int j = 0;j<4;j++){
                    int nextx = now.x + next_x[j];
                    int nexty = now.y + next_y[j];

                    if(nextx <0 || nexty<0 || nextx>=n|| nexty>=m) continue;
                    if(map[nextx][nexty] != 0) continue;

                    queue[now.p-1].add(new XY(nextx,nexty,now.p - 1));
                    map[nextx][nexty] = now.p;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(map[i][j] != 0) cnt++;
            }
        }
        System.out.println(cnt);
    }
}