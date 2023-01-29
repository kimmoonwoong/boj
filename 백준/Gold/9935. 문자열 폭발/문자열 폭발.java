import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String boom = br.readLine();

        Stack<String> stack = new Stack<>();
        String result = "";
        for(int i = 0;i<s.length();i++){
                stack.add(s.substring(i,i+1));
                if(stack.size() >= boom.length()){
                    boolean isCheck = false;
                    for(int j = 0;j<boom.length();j++){
                        if(!stack.get(stack.size() - boom.length() + j).equals(boom.substring(j,j+1))){
                            isCheck = true;
                            break;
                        }
                    }
                    if(!isCheck){
                        for(int j = 0;j<boom.length();j++){
                            stack.pop();
                        }
                    }
                }
        }
        StringBuilder sb = new StringBuilder();
        for(String k:stack){
            sb.append(k);
        }
        if(sb.length() == 0){
            System.out.println("FRULA");
        }
        else{
            System.out.println(sb);
        }
    }

}