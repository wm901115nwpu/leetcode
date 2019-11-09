//
// Created by unicorn on 2019/11/9.
//
#include <iostream>
#include <vector>

using namespace std;


/*
 * 求一个数组的第k个大的数 O(N)
 *
 * 荷兰国旗问题可以实现O(N)求出数组的第k大的数(基于概率得到)
 *      类似于排序  然后找打第k个位置上的值
 *      随机的选取一个值 将大于这个数的值放右边 小于这个数的值放左边  等于这个数的值放右边
 *      如果第k大的值在等于k的范围内  可以直接得到结果
 *      如果第k大的值在左边  递归的做左边   在右边 递归的做右边
 *
 * BFPRT算法
 *      1.五个一组 O(1)
 *      2.组内排序  O(N)
 *      3.每个组中位数取出组成新的数组 O(N)
 *      4.递归调用BFPRT找到中位数 T(N/5)
 *      以上均为取划分值
 *      5.大于右边  小于左边  等于中间O(N)
 *      6.如果第k大的值在左边  递归的做左边   在右边 递归的做右边
 *
 *      中位数的个数是N/5   中位数数组的中位数假设为c
 *      至少比c的大的中位数个数N/10  至少比c大的中位数个数3N/10
 *
 *      如果k在左边  左边的最坏情况是最多有7N/10个人比中位数小T(7N/10)
 *      同理如果k在右边 右边的最坏情况是最多有7N/10个人比中位数大
 *
 *      T(N)=T(N/5)+T(7N/10)+O(N)
 *
 *      时间复杂度O(N)
 * */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

class CSolution{
public:
    int BFPRT(std::vector<int> vData,int iL,int iR){
        if(iR-iL==0)
            return vData[iR];

        std::vector<std::vector<int>> vDat;
        std::vector<int> vD;

        //五个一组分组
        for(int i=iL;i<=iR;i=i+5){
            vD.clear();
            for(int j=i;j<i+5&&j<=iR;j++){
                vD.push_back(vData[j]);
            }
            vDat.push_back(vD);
        }

        std::vector<int> vMedium;
        //组内排序提取中位数组成新数组
        for(int i=0;i<vDat.size();i++){
            std::sort(vDat[i].begin(),vDat[i].end());
            vMedium.push_back(vDat[i][vDat[i].size()/2]);
        }

        return BFPRT(vMedium,0,vMedium.size()-1);
    }

    //得到第k大的值
    int getBiggerK(std::vector<int> &vData,int iK,int iL,int iR){
        int iMedium=BFPRT(vData,iL,iR);

        //将目标与最后一个元素交换
        int iIndexTarget=getIndex(vData,iMedium);
        swap(vData,iIndexTarget,iR);

        int iLess=iL-1;
        int iMore=iR+1;
        int num=vData[iR];

        int l=iL;
        while(l<iMore){
            if(vData[l]<num){
                swap(vData,l++,++iLess);
            }
            else if(vData[l]>num){
                swap(vData,l,--iMore);
            }
            else
                l++;
        }


        int iCountLess=iLess+1-iL;//比中位数小的个数
        int iCountMore=iR-(iMore-1);//等于中位数的个数
        int iCountEqual=iMore-iLess-1;//大于中位数的个数

        if(iK<=iCountLess){
            return getBiggerK(vData,iK,iL,iL+iCountLess-1);//当第K个值在小于中位的的一边时 递归求左边
        }else if(iK>iCountLess+iCountEqual){
            return getBiggerK(vData,iK-iCountLess-iCountEqual,iL+iCountLess+iCountEqual,iR);//在右边 递归求右边
        }
        else
            return iMedium;//当等于中位数的值时返回中位数的值即可
    }

    //得到中位数所在的下标
    int getIndex(std::vector<int> &vData,int target){
        for(int i=0;i<vData.size();i++){
            if(vData[i]==target)
                return i;
        }
        return -1;
    }

    //交换数组的值
    void swap(std::vector<int> &vData,int iL,int iR){
        int tmp=vData[iL];
        vData[iL]=vData[iR];
        vData[iR]=tmp;
    }

};

int main()
{
    std::vector<int> vData={2,344,1,123,23,3,4,354,45,6,7,8,123,12,7};
    //std::vector<int> vData={2,1,3,4,6,7,7};
    CSolution cS1;
    //std::cout<<cS1.BFPRT(vData,0,vData.size()-1)<<std::endl;
    std::cout<<cS1.getBiggerK(vData,13,0,vData.size()-1)<<std::endl;

    std::sort(vData.begin(),vData.end());
    std::cout<<vData[12]<<std::endl;
    return 0;
}