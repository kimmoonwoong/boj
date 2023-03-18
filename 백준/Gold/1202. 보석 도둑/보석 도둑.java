import java.io.*;
import java.util.*;


public class Main {

    static class Item implements Comparable<Item>{
        int m;
        int v;

        public Item(int m, int v){
            this.m = m;
            this.v = v;
        }

        @Override
        public int compareTo(Item o){
            if(this.m == o.m) return o.v - this.v;
            else return this.m - o.m;
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        List<Item> itemList = new ArrayList<>();
        List<Integer> bagList = new ArrayList<>();

        for(int i = 0;i<n;i++){
            st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            itemList.add(new Item(m,v));
        }

        for(int i = 0;i<k;i++) bagList.add(Integer.parseInt(br.readLine()));

        Collections.sort(itemList);
        Collections.sort(bagList);
        PriorityQueue<Integer> queue = new PriorityQueue<>(Collections.reverseOrder());
        int index = 0;
        long cnt = 0;
        for(int i = 0;i<k;i++){
            while (index<n && itemList.get(index).m <= bagList.get(i)){
                queue.add(itemList.get(index).v);
                index++;
            }

            if(!queue.isEmpty()) cnt+=queue.poll();
        }
        System.out.println(cnt);
    }
}