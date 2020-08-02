//
// Created by 王盟 on 2020/7/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

string manacherString(string str){
    string res;
    int index = 0;
    for(int i = 0; i < str.length() * 2 + 1; i++){
    	if((i & 1) == 0)
    		res.push_back('#');
    	else
    		res.push_back(str[index++]);
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
    int max_value = INT_MIN;
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
        max_value = max(max_value, pArr[i]);
    }
    return max_value - 1;
}

int main(){
    string str1 = "abc1234321ab";
   	int ans = maxLcpsLength(str1);
   	printf("%d\n", ans);
    return 0;
}
