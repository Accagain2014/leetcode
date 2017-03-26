// Author :  Accagain
// Date   :  17/3/26
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 *  Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 * Note:
 * You can assume that you can always reach the last index.
 * 
 * 做法：
 *      动态规划
 *      dp[i]表示从第i个位置，跳到最后最少的步数
 *      不必考虑每个位置走到最后的最少步数，只考虑第一就行了
 *      
 * 时间复杂度：
 *    O(n^2) 会超时，用优先队列也不行
 *    O(n) 贪心算法
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

#define INF 0x3fffffff

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int can_farest=0, can_step=0;
        int ans = 0;
        for(int i=0; i < nums.size() - 1; i++)
        {
            can_farest = max(can_farest, nums[i]+i);
            if(i == can_step)
            {
                ans++;
                can_step = can_farest; // 走一步能到达的最远距离
            }
        }
        return ans;
    }
    /*
    struct Info
    {
        int min_step, pos;

        Info(){}
        Info(int min_step, int pos): min_step(min_step), pos(pos) {}
        bool operator < (const Info & a) const
        {
            if(a.min_step < min_step)
                return true;
            else if(a.min_step == min_step)
            {
                if(a.pos < pos)
                    return true;
                return false;
            }
            return false;
        }

    };

    int jump(vector<int>& nums) {
        int dp[nums.size()+1];
        dp[nums.size() - 1] = 0;
        priority_queue<Info> myq;
        myq.push(Info(0, nums.size()-1));
        //myq.push(Info(-1, 10));
        //printf("%d\n", myq.top().min_step);;

        for(int i=nums.size() - 2 ; i>=0; i--) {
            priority_queue<Info> now;

            if(nums[i] < 10)
            {
                dp[i] = INF;
                for(int j=i+1; (j<=i+nums[i]) && (j<=nums.size()); j++)
                    dp[i] = min(dp[j]+1, dp[i]);
                myq.push(Info(dp[i], i));
            }
            else
            {
                while(!myq.empty())
                {
                    Info tmp = myq.top();
                    if(tmp.pos <= i+nums[i])
                    {
                        dp[i] = tmp.min_step+1;
                        myq.push(Info(dp[i], i));
                        //printf("%d %d\n", i, dp[i]);
                        break;
                    }
                    myq.pop();
                    now.push(tmp);
                }
                if(!now.empty())
                {
                    //printf(":::%d\n", i);
                    while(!myq.empty())
                    {
                        now.push(myq.top());
                        myq.pop();
                    }

                    myq = now;
                }
                //myq = now;
                //printf(":::%d %d\n", i, myq.size())

                //printf("%d %d\n", i, dp[i]);
            }


        }


        return dp[0];
    }
     */
};



int main() {
    Solution *test = new Solution();
    int data[] = {2, 3, 1, 1, 4};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));
    printf("%d\n", test->jump(x));
    return 0;
}

//
// Created by cms on 17/3/26.
//

