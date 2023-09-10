//输入一个已经按升序排序过的数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数字。
//
//如果有多对数字的和等于输入的数字，输出找到的第一对即可。
// 也可以使用左右指针，边向中间移动边判断指针对应值的和是否等于target
#include <iostream>
#include<vector>

using namespace std;

int findIndex(vector<int>&nums,int target){
    int i = 0,j = nums.size() - 1;
    while(i <= j){
        int m = i + (j - i) / 2;
        if(nums[m] == target){
            return m;
        }
        else if(nums[m] < target){
            i = m + 1;
        }
        else{
            j = m - 1;
        }
    }
    return -1;
}
pair<int,int> func(vector<int> &nums,int target){
    if(target < nums[0]){
        return make_pair(0,0);
    }
    for(int i = 0;i < nums.size();++i){
        if(target < nums[i]){
            return make_pair(0,0);
        }
        int tmp = target - nums[i];
        int index = findIndex(nums,tmp);
        if(index != i && nums[index] == tmp){
            int first = nums[min(index,i)];
            int second = nums[max(index,i)];
            return make_pair(first,second);
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    vector<int> nums = {1,2,4,7,11,15};
    pair<int,int> res = func(nums,6);
    cout<<res.first<<" "<<res.second<<endl;
//    cout<<findIndex(nums,2)<<endl;
    return 0;
}