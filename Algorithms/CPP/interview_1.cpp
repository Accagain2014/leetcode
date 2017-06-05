// Author :  Accagain
// Date   :  17/6/5
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 题目：
 *  给定一个只包含大写字母的字符串, 定义对其旋转k操作为
1. 对字符串中所有字符增加数值k.
2. 如果改变后的字符小于'A'，则将该字符增加26，如果大于'Z"，则将该字符减少26，直到字符变为A到Z中的一个为止。
如对于字符串"AYDC"，旋转-3之后，变为"XVAZ", 旋转3后变为"DBGF"

如果对于这样的2个字符串s1和s2, 在对s1进行了某个旋转操作后，可以将其变为s2, 则认为s1和s2是旋转等价的。
如"AYDC", "XVAX"和"DBGF"都是旋转等价的。

给定一个包含n个字符串的数组，找出其中所有旋转等价的字符串子集.
例如，对于字符串数组["ABC", "BDE", "DEF", "XZB", "YAB", "GHK"],
      旋转等价的字符串子集是["ABC", "DEF"]和["BDE", "YAB"]
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

#define INF 0x3fffffff

using namespace std;

string operation(string str, int change)
{
    int SUM_ALPHA = 26;
    change = (change % SUM_ALPHA + SUM_ALPHA) % SUM_ALPHA;
    string ans = "";
    for(int i=0; i<str.size(); i++)
    {
        ans += (str[i] - 'A' + change) % SUM_ALPHA + 'A';
    }
    return ans;
}

bool judge(string str1, string str2)
{
    int SUM_ALPHA = 26;
    for(int i=0; i<SUM_ALPHA; i++)
    {
        if(operation(str1, i) == str2)
            return true;
    }
    return false;
}

vector<vector<string>> get_rotation(vector<string> save)
{
    vector<vector<string>> ans;
    int hav[save.size()];
    memset(hav, 0, sizeof(hav));

    for(int i=0; i<save.size(); i++)
    {
        if(hav[i])
            continue;
        string now = save[i];
        vector<string> tmp;
        tmp.push_back(now);
        for(int j=i+1; j<save.size(); j++)
        {
            if(judge(now, save[j]))
            {
                tmp.push_back(save[j]);
                hav[i] = 1;
                hav[j] = 1;
            }
        }
        if(tmp.size() > 1)
            ans.push_back(tmp);
    }
    return ans;

}

int main() {

    //printf("%s\n", operation("AYDC", 3).c_str());

    vector<string> test1 = {"ABC","BDE","DEF", "XZB","YAB","GHK"};
    vector<vector<string>> ans = get_rotation(test1);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            printf("%s ", ans[i][j].c_str());
        }
        printf("\n");
    }


    return 0;
}

//
// Created by cms on 17/6/5.
//

