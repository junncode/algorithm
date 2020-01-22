package com.example01;
import java.util.Scanner;

public class B2577 {
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
    	
        int ans = A * B * C;
        int[] cnt = new int[10];
    	
        String s = Integer.valueOf(ans).toString();
    	
        for(int i = 0; i < s.length(); i++) {
            int num = s.charAt(i) - '0';
            cnt[num] += 1;
        }
    	
        for(int i = 0; i < 10; i++) 
            System.out.println(cnt[i]);
    }
}
