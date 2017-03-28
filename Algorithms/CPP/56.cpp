// Author :  Accagain
// Date   :  17/3/28
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 *
 * Given [1,3],[2,6],[8,10],[15,18],
 *
 * return [1,6],[8,10],[15,18].
 * 
 * 做法：
 *      排序，然后一个一个合并
 *
 * 时间复杂度：
 *      排序的时间复杂度，O(nlgn)
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

    vector<Interval> merge(vector<Interval>& intervals) {

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
    myv.push_back(Interval(2, 6));
    myv.push_back(Interval(8, 10));
    myv.push_back(Interval(15, 18));

    test->merge(myv);

    return 0;
}

//
// Created by cms on 17/3/28.
//

