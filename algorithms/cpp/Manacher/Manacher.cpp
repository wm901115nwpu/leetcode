//
// Created by 王盟 on 2020/7/19.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string manacherString(string str){
    char[] charArr = str.data();
    char[] res = new char[str.length() * 2 + 1];
    int index = 0;
    for(int i = 0; i != res.length(); i++){
        res[i] = (i & 1) == 0 ? '#' : charArr[index++];
    }
    return res;
}

int maxLcpsLength(string s){
    if(s.empty() || s.length() == 0){
        return 0;
    }
    string str = manacherString(s);
    vector<int> pArr(str.length());
    int C = -1;
    int R = -1;
    int max = INT_MIN;
    for(int i = 0; i != str.length(); i++){
        pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
        while (i + pArr[i] < str.length() && i - pArr[i] > -1){
            if (str[i + pArr[i]] == str[i - pArr[i]])
                pArr[i]++;
            else {
                break;
        }
    }
        if (i + pArr[i] > R) {
            R = i + pArr[i];
            C = i;
        }
        max = max(max, pArr[i]);
    }
    return max - 1;
}

int main(){
    string str1 = "abc1234321ab";
    cout << maxLcpsLength(str1) << endl;
    return 0;
}
