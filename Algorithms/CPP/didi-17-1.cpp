// Author :  Accagain
// Date   :  17/5/7
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      
 * 时间复杂度：
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

#define INF 0x3fffffff

using namespace std;

string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> save;
vector<string> all_str;

void dfs(int now, string nums, string hav)
{
    if(now == nums.size())
    {
        all_str.push_back(hav);
        return ;
    }
    for(int i=0; i<dict[nums[now]-'0'].size(); i++)
    {
        dfs(now+1, nums, hav+dict[nums[now]-'0'][i]);
    }
}

int getLongCommon(string a, string b)
{
    int a_len = a.size();
    int b_len = b.size();

    int dp[a_len+10][b_len+10];
    memset(dp, 0, sizeof(dp));
    int ans = 0;


    for(int i=1; i<=a_len; i++)
    {
        for(int j=1; j<=b_len; j++)
        {
            if(a[i-1] == b[j-1])
            {
                //printf("%c %c %d %d\n", a[i-1], b[j-1], i, j);

                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        }
    }
    //printf("::%d\n", dp[a_len][b_len]);
    return dp[a_len][b_len];;


}

int main() {

    int cnt = 0, pos = 0;
    char s[1000];
    gets(s);
    //printf("%s\n", s);

    stringstream ss;
    ss.clear();
    ss << s;
    while (!ss.eof())
    {
        string now;
        ss >> now;
        save.push_back(now);
        cnt++;
    }
//    for(int i=0; i<cnt; i++)
//        printf("%s\n", save[i].c_str());
    string now;
    cin >> now;
    string last = "";

    all_str.clear();
    dfs(0, now, "");

    int ans = -1;
    int max = -1;

    for(int i=0; i<cnt; i++) {


        //printf("%s %s\n", save[i], last.c_str());
        //printf("%d\n", ans);
        int tmp_max = -1;
        for(int j=0; j<all_str.size(); j++) {
            int now_len = getLongCommon(all_str[j], save[i]);
            if (now_len > tmp_max)
            {
                tmp_max = now_len;
            }
        }
        if(tmp_max > max)
        {
            max = tmp_max;
            ans = i;
        }
    }
    printf("%s\n", save[ans].c_str());


    return 0;
}

//
// Created by cms on 17/5/7.
//

/*
 * Produces a printable string representation of a dictionary
 * 784
 */