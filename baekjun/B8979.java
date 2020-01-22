package com.example01;
import java.util.Arrays;
import java.util.Scanner;

class Nation implements Comparable<Nation>{
    int nationNum;
    int gold;
    int silver;
    int bronze;
    int rank;

    Nation(int nationNum, int gold, int silver, int bronze) {
        this.nationNum = nationNum;
        this.gold = gold;
        this.silver = silver;
        this.bronze = bronze;
        this.rank = 1;
    }
    @Override
    public int compareTo(Nation o) {
        if(this.gold > o.gold) {
            return -1;
        } else if(this.gold == o.gold) {
            if(this.silver > o.silver) {
                return -1;
            } else if(this.silver == o.silver) {
                if(this.bronze > o.bronze) {
                    return -1;
                } else if(this.bronze == o.bronze) {
                    return 0;
                }
            }
        }
        return 1;
    }
}
public class B8979 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nNation = sc.nextInt();
        int targetNationNum = sc.nextInt();

        Nation[] nationAry = new Nation[nNation];
        for(int i = 0; i < nNation; i++) {
            int tNationNum = sc.nextInt();
            int tGold = sc.nextInt();
            int tSilver = sc.nextInt();
            int tBronze = sc.nextInt();
            nationAry[i] = new Nation(tNationNum, tGold, tSilver, tBronze);
        }

        Arrays.sort(nationAry);

        calRank(nationAry);
		
        for(int i = 0; i < nNation; i++) {
            if(nationAry[i].nationNum == targetNationNum) {
                System.out.println(nationAry[i].rank);
                break;
            }
        }
    }
    
    public static void calRank(Nation[] nationAry) {
        for(int i = 1; i < nationAry.length; i++) {
            if(nationAry[i].gold == nationAry[i-1].gold
                && nationAry[i].silver == nationAry[i-1].silver
                && nationAry[i].bronze == nationAry[i-1].bronze) {
               nationAry[i].rank = nationAry[i-1].rank;
            } else {
                nationAry[i].rank = i+1;
            }
        }
    }
}