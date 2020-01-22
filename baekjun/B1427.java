package com.example01;

import java.util.*;

public class B1427 {
	public static void main(String[] args) {
        
    	ArrayList<Integer> list = new ArrayList<Integer>();
    	Scanner sc = new Scanner(System.in);
        
        String a = sc.next();
        for(int i=0; i<a.length(); i++) {
        	list.add(a.charAt(i)-48);
        	
        }
        Collections.sort(list);
        for(int i=a.length()-1; i>-1; --i) {
        	System.out.print(list.get(i));
        }
    }  
}
