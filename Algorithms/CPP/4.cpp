// Author :  Accagain
// Date   :  17/2/14
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 *
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Example 1:
 *      nums1 = [1, 3]
 *      nums2 = [2]
 *      The median is 2.0
 * Example 2:
 *      nums1 = [1, 2]
 *      nums2 = [3, 4]
 *
 * The median is (2 + 3)/2 = 2.5
 *
 *
 * 做法：
 *      在两个有序数组中，求第k大，对k二分，去掉小端的不可能的一半
 *      Olg(m+n）
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <vector>
#define  INF 0x3fffffff

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        return (findK(nums1, 0, nums2, 0, (sum+1)/2) + findK(nums1, 0, nums2, 0, (sum+2)/2))/2;
    }

    double findK(vector<int> a, int as, vector<int> b, int bs, int k)
    {
        if(as > a.size() - 1)
            return b[bs+k-1];
        if(bs > b.size() - 1)
            return a[as+k-1];

        if(k == 1)
        {
            if(!a.size())
                return b[bs];
            else if(!b.size())
                return a[as];
            return min(a[as], b[bs]);
        }


        int aMid = INF;
        int bMid = INF;

        if(as + k/2 - 1 < a.size())
            aMid = a[as+k/2-1];
        if(bs + k/2 - 1 < b.size())
            bMid = b[bs+k/2-1];

        if(aMid > bMid)
            return findK(a, as, b, bs+k/2, k-k/2);
        else
            return findK(a, as+k/2, b, bs, k-k/2);

    }
};

int main()
{
    Solution * test = new Solution();
    int data1[] = {};
    int data2[] = {1};

    vector<int> a(data1, data1+sizeof(data1)/sizeof(data1[0]));
    vector<int> b(data2, data2+sizeof(data2)/sizeof(data2[0]));

    printf("%lf\n", test->findMedianSortedArrays(a, b));
    return 0;
}