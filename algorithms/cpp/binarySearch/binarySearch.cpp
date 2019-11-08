//
// Created by unicorn on 2019/11/9.
//
#include <iostream>
#include <vector>

using namespace std;

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r,int arr[],int NumberToFind)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] >= NumberToFind) r = mid;
        else l = mid + 1;
    }
    printf("%d",l);
    return l;
}

// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r,int arr[],int NumberToFind)
{
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if (arr[mid] <= NumberToFind) l = mid;
        else r = mid - 1;
    }
    printf("%d",l);
    return l;
}

int main(){
    int arr[5] = {0,1,3,4,5};
    bsearch_1(0,4,arr,4);
//    bsearch_2(0,4,arr,4);
    return 0;
}
