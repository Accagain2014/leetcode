// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * 
 * 做法：
 *      先插进去，然后在排序
 *
 * 时间复杂度：
 *      O(nlgn)
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:

    bool static cmp(struct Interval a, struct Interval b)
    {
        if(a.start != b.start)
            return a.start < b.start;
        return a.end < b.end;
    }

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), Solution::cmp);
//        for(int i=0; i<intervals.size(); i++)
//            printf("%d %d\n", intervals[i].start, intervals[i].end);

        vector<Interval> ans;
        if(intervals.size() == 0)
            return ans;

        Interval now = intervals[0];
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i].start > now.end)
            {
                ans.push_back(now);
                now = intervals[i];
            }
            else if(intervals[i].end >= now.end)
            {
                now.end = intervals[i].end;

            }
        }
        ans.push_back(now);
        for(int i=0; i<ans.size(); i++)
            printf("%d %d\n", ans[i].start, ans[i].end);
        return ans;
    }
};

int main() {
    Solution *test = new Solution();
    int data[] = {};
    vector<int> x(data, data + sizeof(data) / sizeof(data[0]));

    vector<Interval> myv;
    myv.push_back(Interval(1, 3));
    //myv.push_back(Interval(1, 2));
    myv.push_back(Interval(6, 9));
    //myv.push_back(Interval(8, 10));
    //myv.push_back(Interval(15, 18));

    test->insert(myv, Interval(2, 5));

    return 0;
}

//
// Created by cms on 17/3/28.
//


