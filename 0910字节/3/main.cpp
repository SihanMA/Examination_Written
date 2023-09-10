#include <iostream>
#include "vector"
#include "algorithm"
using namespace std;
vector<pair<int,int>> divide(int n, int a){
    if(n < a){
        return vector<pair<int,int>>(n, make_pair(1,a));
    }
    int q = n / a;  // 商
    int r = n % a;  // 余数

    // 创建包含a个元素的vector，初始值都为q
    vector<pair<int,int>> result(a, make_pair(q,a));

    // 将余数r逐个分配到vector中的元素
    for (int i = 0; i < r; ++i) {
        result[i].first += 1;
    }
//    cout<<result.size()<<endl;
    return result;
}
int func(int n,vector<int> &a,vector<int> &b,int q,vector<int> &x){
    vector<pair<int,int>> tmp;
    for(int i = 0;i < n;++i){
        tmp.push_back(make_pair(a[i],b[i]));
    }
    for(int i = 0;i < q;++i){
        pair<int,int> select = make_pair(-1,-1);
        int index = -1;
        for(int j = 0;j < n;++j){   //找到重量等于xi,特征值最小的
            if(tmp[j].first == x[i]){
                if(select.second == -1){
                    select = tmp[j];
                    index = j;
                }
                else if(select.second > tmp[j].second){
                    select = tmp[j];
                    index = j;
                }
            }
        }
        if(select.first == -1){ //无效操作
            continue;
        }
        tmp.erase(tmp.begin() + index);
        vector<pair<int,int>> res = divide(select.first, select.second);
        tmp.insert(tmp.end(),res.begin(),res.end());

    }
    return tmp.size();
}
int main() {
//    int n = 5;
//    vector<int> a = {4,2,9,100,9};
//    vector<int> b = {2,2,3,5,2};
//    int q = 3;
//    vector<int> x = {100,100,9};
    int n = 2;
    vector<int> a = {2,1};
    vector<int> b = {3,1};
    int q = 2;
    vector<int> x = {2,1};
    cout<<func(n,a,b,q,x)<<endl;
}