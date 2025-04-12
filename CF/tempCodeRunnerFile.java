import java.io.*;
import java.util.Scanner;

public class Solution {
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String [] words = s.split(" ");

        int n = words.length;

        for(int i = n-1; i >= 0; i--){
            System.out.print(words[i] + " ");
        }

        
    }
}