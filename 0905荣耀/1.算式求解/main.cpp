// 屏幕上会显示"1" "2" "3" "4" "5" "6" "7" "8" "9" "0" "+" "-" "="这些按钮，用户在按了若工按钮之后，如果按了"="，则会把按"="之前的字符串作为一个算式，计算结果。
// 中间结果或最后结果可以为负数。

// 输入为一个字符串，形如"23+86-6+37+24-8-13"。

// 输入字符串中保证:

// 1.不会包含除"1" "2" "3" "4" "5" "6" "7" "8" "9" "0" "+" "-" "="之外的字符

// 2.长度不为0

// 3.不以"+"或"-"开始，不以"+"或"-"结束

// 4.不会出现连续两个或两个以上"+"

// 5.不会出现连续两个或两个以上"-"

// 6."+" "-"不会相邻

// 7.操作数为范围为[0，99]

// 8.一定包含运算符 ("+"或"-")

// 输出：算式结果，一个整数。

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int func(string line){
    vector<int> tmp;
    int num = 0;
    int sign = 1;
    for(char c:line){
        if(c <= '9' && c >= '0'){
            num = num * 10 + (c - '0');
        }
        else if(c == '+' || c == '='){
            tmp.push_back(sign * num);
            num = 0;
            sign = 1;
        }
        else if(c == '-'){
            tmp.push_back(sign * num);
            num = 0;
            sign = -1;
        }
    }
    tmp.push_back(sign * num);
    for(auto it:tmp){
        cout<<it<<endl;
    }
    int res = 0;
    for(auto it:tmp){
        res += it;
    }
    return res;
}
int main(){
    cout<<func("1+2+99-10-10")<<endl;
}