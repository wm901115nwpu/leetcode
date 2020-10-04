//
// Created by 王盟 on 2020/8/8.
//
#include <iostream>
#include <vector>

using namespace std;

vector<int> partition(vector<int> &arr, int l, int r){
    int less = l - 1;
    int more = r;
    while (l < more){
        if(arr[l] < arr[r]){
            swap(arr[++less], arr[l++]);
        }
        else if(arr[l] > arr[r]){
            swap(arr[--more], arr[l]);
        }
        else{
            l++;
        }
    }
    swap(arr[more], arr[r]);
    return {less + 1, more};
}

void quickSort(vector<int> &arr, int l, int r){
    if(l < r){
        swap(arr[l + (int)(rand()%(r - l + 1))], arr[r]);
        vector<int> p = partition(arr, l, r);
        quickSort(arr, l, p[0] - 1); // < 区
        quickSort(arr, p[1] + 1, r); // > 区
    }
}

void quickSort(vector<int> &arr){
    if(arr.empty() || arr.size() < 2){
        return;
    }
    quickSort(arr, 0, arr.size() - 1);
}
int main(){
    vector<int> arr{3, 2, 1};
    quickSort(arr);
    for(auto a:arr)
        cout << a << endl;
    return 0;
}
