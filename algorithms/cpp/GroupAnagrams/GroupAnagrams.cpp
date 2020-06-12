//
// Created by 王盟 on 2020/6/12.
//
//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Output:
//[
//["ate","eat","tea"],
//["nat","tan"],
//["bat"]
//]
//Note:
//
//All inputs will be in lowercase.
//The order of your output does not matter.
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> dict;
    for (auto &str : strs)
    {
        string key = str;
        sort(key.begin(), key.end());
        dict[key].push_back(move(str));
    }

    vector<vector<string>> res;
    for (auto i = dict.begin(); i != dict.end(); i ++ )
    {
        res.push_back(move(i -> second));
    }

    return res;
}

void printString(vector<vector<string> > &matrix)
{
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        printf("}\n");
    }
//    cout << endl;
}

int main(){
    vector<string> str = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(str);
    printString(ans);
    return 0;
}