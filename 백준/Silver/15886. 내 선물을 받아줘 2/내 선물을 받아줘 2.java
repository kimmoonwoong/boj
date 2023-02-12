import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Character array[] = new Character[n];
        String s = br.readLine();
        for(int i = 0;i<n;i++){
            array[i] = s.charAt(i);
        }
        int count = 0;

        for(int i = 0;i<n;i++){
            if(array[i].equals('E')){
               if(array[i + 1].equals('W')) count++;
            }
        }
        System.out.println(count);

    }
}