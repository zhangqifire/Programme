//
//  test.cpp
//  Programme
//
//  Created by 张琪 on 16/8/14.
//  Copyright © 2016年 张琪. All rights reserved.
//



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
#define esp  1e-8
const double PI = acos(-1.0);
const int inf = 1000000005;
typedef long long ll;
const long long mod = 1000000007;
//freopen("in.txt","r",stdin); //输入重定向,输入数据将从in.txt文件中读取
//freopen("out.txt","w",stdout); //输出重定向,输出数据将保存在out.txt文件中
void fre()
//输出重定向
{
    freopen("/Users/zhangqi/Documents/Programme/Programme/input.txt", "r", stdin);
    freopen("/Users/zhangqi/Documents/Programme/Programme/output.txt", "w", stdout);
}
/**
 线性时间复杂度求数组中第K大数
 ** author :liuzhiwei
 ** data   :2011-08-07
 **/


//基于快速排序思想，求数组a中第k大的数，low和high分别为数组的起始和结束位置
//时间复杂度为o(n)，n为数组的长度
//1<=k<=n
//如果存在，返回第k大数的下标，否则返回-1

int selectk(int a[], int low, int high, int k)
{
    if(k <= 0)
        return -1;
    if(k > high - low + 1)
        return -1;
    int pivot = low + rand()%(high - low + 1);    //随即选择一个支点
    swap(a[low], a[pivot]);
    int m = low;
    int count = 1;
    
    //一趟遍历，把较大的数放到数组的左边
    
    for(int i = low + 1; i <= high; ++i)
    {
        if(a[i] > a[low])
        {
            swap(a[++m], a[i]);
            count++;              //比支点大的数的个数为count-1
        }
    }
    swap(a[m], a[low]);           //将支点放在左、右两部分的分界处
    if(count > k)
    {
        return selectk(a, low, m - 1, k);
    }
    else if( count < k)
    {
        return selectk(a, m + 1, high, k - count);
    }
    else
    {
        return m;
    }
}
int main(void)
{
    int a[] = {5, 15, 5, 7, 9, 17,100, 3, 12, 10, 19, 18, 16, 10, 1000,1,1,1,1,1,1,1,1};
    int r = selectk(a, 0, sizeof(a) /sizeof(int) - 1, 1);
    cout<<(r == -1 ? r : a[r])<<endl;
    int pause;
    cin>>pause;
    return 0;
}