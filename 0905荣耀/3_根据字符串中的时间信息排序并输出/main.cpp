
//解析输入的字符串数组，提取出字符串中的时间戳信息，并且将字符串按照时间戳排序后，输出到控制台。
//第1行指定数组的size;
//
//第2行到第n行，每行为一个独立的字符串，n为size的值。
//
//每行的字符串由"-:"和字母、数字组成，时间戳在字符串中的位置不确定，时间戳格式为2019-01-01T07:30:20表示2019年1月1日，7点30分20秒。时间为24小时制。

//将输入的字符串按照时间戳进行从小到大排序后，输出。符合如下规则:
//
//如果时间戳信息相同，按照字符串长度从小到大进行排序;
//如果长度相同，则按照从首字符开始的ASCII码值比较从小到大进行排序;
//如果两个字符串完全一样，则只需要输出一个。
#include <iostream>
#include "vector"
#include "string"
#include "set"
#include "algorithm"
using namespace std;

bool checkAvailable(int YYYY,int MM,int DD,int hh,int mm,int ss){
    if(hh >= 24 || mm >= 60 || ss >= 60){
        return false;
    }
    if(MM >= 13){
        return false;
    }
    if(MM == 0 || DD == 0){
        return false;
    }
    if((MM == 1 || MM == 3 || MM == 5 || MM == 7 || MM == 8 || MM == 10 || MM == 12) && DD > 31){
        return false;
    }
    if((MM == 4 || MM == 6 || MM == 9 || MM == 11) && DD > 30){
        return false;
    }
    if((YYYY % 400 == 0 || (YYYY % 4 == 0 && YYYY % 100 != 0)) && MM == 2 && DD > 29){
        return false;
    }
    if(MM == 2 && DD > 28){
        return false;
    }
    return true;


}
pair<vector<int>,string> getTimeStamp(const string &s){
    for(int i = 0;i <= s.length() - 19;++i){
        string sub_s = s.substr(i,19);
        //检查-,T,:在不在正确位置
        if(sub_s[4] != '-' || sub_s[7] != '-'){
            continue;
        }
        if(sub_s[10] != 'T'){
            continue;
        }
        if(sub_s[13] != ':' || sub_s[16] != ':'){
            continue;
        }
        try{
            int YYYY,MM,DD,hh,mm,ss;
            sscanf(sub_s.c_str(),"%4d-%2d-%2dT%2d:%2d:%2d",&YYYY,&MM,&DD,&hh,&mm,&ss);
            if(checkAvailable(YYYY,MM,DD,hh,mm,ss)){
                return make_pair(vector<int>{YYYY,MM,DD,hh,mm,ss},s);
            }
        }
        catch (...){
            continue;
        }
    }
    return make_pair(vector<int>{},"");
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<string> input = {"my/2019-01-01T09:00:01",
                            "my/2019-01-01T09:00:01",
                            "abc/2018-12-24T08:00:00/test/you",
                            "1/2018-12-24T08:00:00/test/Test1",
                            "123/2018-12-24T08:00:09/test/me"};
    set<string> hash_set;
    vector<pair<vector<int>,string>> ans;
    for(auto s:input){
        if(hash_set.find(s) == hash_set.end()){
            hash_set.insert(s);
            ans.push_back(getTimeStamp(s));
        }
    }
    sort(ans.begin(),ans.end(),[](const auto&x,const auto&y){
        if(x.first != y.first){
            return x.first < y.first;
        }
        if(x.second.length() != y.second.length()){
            return x.second.length() < y.second.length();
        }
        return x.second < y.second;
    });

    for(auto item:ans){
        cout<<item.second<<endl;
    }
    cout<<ans.size()<<endl;
    return 0;
}