import java.io.*;
import java.util.*;

public class Main {
    static class Study implements Comparable<Study>{
        int score;
        int plusscore;

        public Study(int score, int plusscore){
            this.score = score;
            this.plusscore = plusscore;
        }

        @Override
        public int compareTo(Study o){
            return Math.min(100 - o.score , o.plusscore) - Math.min(100 - this.score , this.plusscore);
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        PriorityQueue<Study> queue1 = new PriorityQueue<>();

        st = new StringTokenizer(br.readLine());
        int result = 0;
        int score[] = new int[m];
        for(int i = 0;i<m;i++){
            score[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());

        for(int i = 0;i<m;i++){
            int k = Integer.parseInt(st.nextToken());
            queue1.add(new Study(score[i], k));
        }

        int time = 24 * n;
        for(int i = 0;i<time;i++){
            if(queue1.isEmpty()) break;

            Study now = queue1.poll();
            now.score = Math.min(now.score+now.plusscore, 100);

            if(now.score == 100){
                result += 100;
                continue;
            }

            queue1.add(now);

        }
        while (!queue1.isEmpty()){
            result+= queue1.poll().score;
        }
        System.out.println(result);

    }
}