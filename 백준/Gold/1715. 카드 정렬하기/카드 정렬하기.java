import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for(int i = 0;i<n;i++){
            queue.add(Integer.parseInt(br.readLine()));
        }
        int result = 0;
        while (!queue.isEmpty()){
            if(queue.size() == 1){
                break;
            }
            int fir = queue.poll();
            int sec = queue.poll();
            queue.add(fir + sec);
            result += (fir + sec);
        }
        System.out.println(result);
    }
}