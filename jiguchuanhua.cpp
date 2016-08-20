//
//  test.cpp
//  Programme
//
//  Created by 张琪 on 16/8/14.
//  Copyright © 2016年 张琪. All rights reserved.
//

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>
#include<string>
#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

void fre()
//输出重定向
{
    freopen("/Users/zhangqi/Documents/Programme/Programme/input.txt", "r", stdin);
    freopen("/Users/zhangqi/Documents/Programme/Programme/output.txt", "w", stdout);
}


int n, m;
int num[40][40];
int dfs(int from, int step) {
    if (step == 0){
        if (from == 0) return 1;
        else return 0;
    }
    if (num[from][step] != -1)
        return num[from][step];
    num[from][step] = dfs((from + 1) % n, step - 1) + dfs((from + n - 1) % n, step - 1);
    return num[from][step];
}
int main() {
    //fre();
    while (scanf("%d%d", &n, &m) != EOF){
        memset(num, -1, sizeof(num));
        printf("%d\n", dfs(0, m));
    }
    return 0;
}