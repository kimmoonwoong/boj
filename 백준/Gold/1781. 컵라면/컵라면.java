import java.io.*;
import java.util.*;

public class Main {
    static class Node implements Comparable<Node>{
        int deadline;
        int cnt;

        public Node(int deadline, int cnt){
            this.deadline = deadline;
            this.cnt = cnt;
        }

        @Override
        public int compareTo(Node o){
            if (this.deadline == o.deadline){
                return o.cnt - this.cnt;
            }
            else{
                return this.deadline - o.deadline;
            }
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        List<Node> list = new ArrayList<>();
        for (int i = 0;i<n;i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int deadline = Integer.parseInt(st.nextToken());
            int cnt = Integer.parseInt(st.nextToken());
            list.add(new Node(deadline, cnt));

        }
        Collections.sort(list);
        for (int i = 0;i<n;i++){
            Node now = list.get(i);

            if (queue.isEmpty() || queue.size() < now.deadline) queue.add(now.cnt);
            else if (queue.size() == now.deadline){
                if (queue.peek() < now.cnt){
                    queue.poll();
                    queue.add(now.cnt);
                }
            }
        }
        int ans = 0;
        while (!queue.isEmpty()){
            ans += queue.poll();
        }
        System.out.println(ans);
    }
}