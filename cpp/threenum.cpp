#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<iterator>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()<3) return res;
        map<vector<int>, bool> temp1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            vector<int> temp;
            for (int j = i + 1; j < nums.size() - 1; j++)
            {
                int tar = -(nums[i] + nums[j]);
                bool flag = binary_search(nums.begin() + j+1, nums.end(), tar);
                if (flag)
                {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(tar);
                    sort(temp.begin(), temp.end());
                    if(temp1[temp]==true)
                    {
                        temp1.insert(pair<vector<int>,bool>(temp,true));
                    }
                    temp.clear();
                    continue;
                }
                else
                {
                    continue;
                }
            }
        }
        map<vector<int>, bool>::iterator p;
        for(p=temp1.begin();p!=temp1.end();p++)
        {
            res.push_back(p->first);
        }
        return res;
    }
};
int main()
{
    Solution a1;
    vector<int> s = { -1,0,1};
    vector<vector<int>> s1;
    s1 = a1.threeSum(s);
    for (int i = 0; i < s1.size(); i++)
    {
        printf("%d %d %d\n", s1[i][0], s1[i][1], s1[i][2]);
    }

}