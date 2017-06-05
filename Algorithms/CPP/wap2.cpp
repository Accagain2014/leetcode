package com.java.test;

import java.util.Scanner;
import java.util.HashSet;

public class Main {

public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int m = in.nextInt();
        int[] data = new int[n];
        for(int i = 0;i < n;i++){
            data[i] = in.nextInt();
        }
        System.out.println(solve(n,m,data));
    }

public static String solve(int n,int m,int[] data){
        for(int i = 0;i < n;i++){
            data[i] = data[i] % m;
        }
        HashSet<Integer> numOne = new HashSet<Integer>();
        HashSet<Integer> numTwo = new HashSet<Integer>();

        int sizeOne = n/2;
        int countOne = 1<<sizeOne;
        for(int i=1; i<countOne; i++){
            int sum = 0;
            for(int j=0; j<sizeOne; j++){
                if((i&(1<<j)) > 0){
                    sum += data[j];
                    if(sum >= m){
                        sum %= m;
                    }
                }
            }
            numOne.add(sum);
        }
        int sizeTwo = n - sizeOne;
        int countTwo = 1<<sizeTwo;
        for(int i=1; i<countTwo; i++){
            int sum = 0;
            for(int j=0; j<sizeTwo; j++){
                if((i&(1<<j)) > 0){
                    sum += data[sizeOne+j];
                    if(sum >= m){
                        sum %= m;
                    }
                }
            }
            numTwo.add(sum);
        }
        if (numOne.contains(0) || numTwo.contains(0)){
            return "Yes";
        }
        for(int i : numOne){
            if(numTwo.contains(m - i)){
                return "Yes";
            }
        }

        return "No";
    }
}