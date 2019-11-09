//
// Created by unicorn on 2019/11/9.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNextArray(const string& ms){
    vector<int> next;
    if(ms.size() == 1){
        next.push_back(-1);
        return next;
    }
    next.push_back(-1);
    next.push_back(0);
    int pos = 2;
    int cn = 0;
    while (pos < next.size()){
        if(ms[pos - 1] == ms[cn]){
            next[pos++] = ++cn;
        }
        else if(cn > 0){
            cn = next[cn];
        }
        else{
            next[pos++] = 0;
        }
    }
    return next;
}

int getIndexOf(const string& ss, const string& ms){
    if(ss.empty() || ms.empty() || ms.size() < 1 || ss.size() < ms.size() )
        return -1;
    int si = 0;
    int mi = 0;
    vector<int> next = getNextArray(ms);
    while(si < ss.size() && mi < ms.size()){
        if(ss[si] == ms[mi]){
            si++;
            mi++;
        }
        else if(next[mi] == -1){
            si++;
        }
        else {
            mi = next[mi];
        }
    }
    return mi == ms.size() ? si - mi : -1;
}

int main(){
    string ss("acbc");
    string ms("bc");
    cout << ss << endl;
    cout << ms << endl;
    int res = getIndexOf(ss, ms);
    printf("%d\n", res);
    return 0;
}