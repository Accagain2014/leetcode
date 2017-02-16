
// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 *
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 *
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 *
 * O(nlog(n))
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct Info
    {
        int height, pos;
        //Info(int x, int y): height(x), pos(y) {}
    };

    static bool cmp(Info a, Info b)
    {
        if(a.height != b.height)
            return a.height > b.height;
        return a.pos < b.pos;
    }

    int maxArea(vector<int>& height) {
        Info save[height.size()];
        for(int i=0; i<height.size(); i++)
        {
            save[i].height = height[i];
            save[i].pos = i;
        }

        sort(save, save+height.size(), cmp);
        //printf("%d\n", save[0].height);

        int ans = 0;
        int Min = save[0].pos;
        int Max = save[0].pos;

        for(int i=1; i<height.size(); i++)
        {
            int temp = max(abs(save[i].pos - Min), abs(save[i].pos - Max)) * save[i].height;

            ans = max(ans, temp);

            Min = min(Min, save[i].pos);
            Max = max(Max, save[i].pos);
        }

        /*
         * O(n^2) TLE
        int ans = 0;
        for(int i=0; i<height.size(); i++)
        {
            int left = height[i];
            for(int j=i+1; j<height.size(); j++)
            {
                int right = height[j];
                ans = max(ans, (j - i) * min(left, right));
            }
        }
         */
        return ans;
    }
};

int main() {
    Solution * test = new Solution();
    vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(1);

    printf("%d\n", test->maxArea(data));
    return 0;
}

//
// Created by cms on 17/2/14.
//

