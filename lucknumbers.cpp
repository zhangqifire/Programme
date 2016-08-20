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
int a[30];
char s[30];
char b[30], c[30], d[30];
int main()
{
    int t, i, j;
    scanf("%d", &t);
    while (t--)
    {
        memset(c, 0, sizeof(c));
        memset(b, 0, sizeof(b));
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        if (len & 1)
        {
            for (i = 1; i <= (len + 1) / 2; ++i)
                printf("4");
            for (i = 1; i <= (len + 1) / 2; ++i)
                printf("7");
            printf("\n");
        }
        else
        {
            ll sum = 0;
            strcpy(d, s);
            for (i = 1; i <= (len) / 2; ++i)
            {
                c[i] = '7';
            }
            for (i = len / 2 + 1; i <= len; ++i)
            {
                
                c[i] = '4';
            }
            if (strcmp(s + 1, c + 1) > 0)
            {
                for (i = 1; i <= (len) / 2 + 1; ++i)
                    printf("4");
                for (i = 1; i <= (len) / 2 + 1; ++i)
                    printf("7");
                printf("\n");
                
            }
            else
            {
                int ans = 0;
                int la = len / 2, lb = len / 2;
                for (i = 1; s[i]; ++i)
                {
                    if (ans == 1)
                    {
                        if (la > 0)
                        {
                            b[i] = '4';
                            la--;
                        }
                        else
                        {
                            b[i] = '7';
                            lb--;
                        }
                    }
                    else if (s[i] < '4')
                    {
                        if (la <= 0)
                        {
                            b[i] = '7';
                            lb--;
                            ans = 1;
                        }
                        else
                        {
                            b[i] = '4';
                            la--;
                            ans = 1;
                        }
                    }
                    else if (s[i] >= '5' && s[i] <= '6' )
                    {
                        if (lb <= 0)
                        {
                            j = i - 1;
                            while (1)
                            {
                                if (b[j] < '7')
                                {
                                    b[j] = '7';
                                    la++;
                                    lb--;
                                    ans = 1;
                                    break;
                                }
                                lb++;
                                j--;
                            }
                            for (int k = j + 1; k <= len; ++k)
                            {
                                if (la > 0)
                                {
                                    b[k] = '4';
                                    la--;
                                }
                                else
                                {
                                    b[k] = '7';
                                    lb--;
                                }
                            }
                            break;
                        }
                        else
                        {
                            b[i] = '7';
                            lb--;
                            ans = 1;
                        }
                    }
                    else if (s[i] == '4')
                    {
                        if (la <= 0)
                        {
                            b[i] = '7';
                            lb--;
                            ans = 1;
                        }
                        else
                        {
                            b[i] = '4';
                            la--;
                        }
                    }
                    else if (s[i] == '7')
                    {
                        if (lb <= 0)
                        {
                            j = i - 1;
                            while (1)
                            {
                                if (b[j] < '7')
                                {
                                    b[j] = '7';
                                    la++;
                                    lb--;
                                    ans = 1;
                                    break;
                                }
                                lb++;
                                j--;
                            }
                            for (int k = j + 1; k <= len; ++k)
                            {
                                if (la > 0)
                                {
                                    b[k] = '4';
                                    la--;
                                }
                                else
                                {
                                    b[k] = '7';
                                    lb--;
                                }
                            }
                            break;
                        }
                        else
                        {
                            b[i] = '7';
                            lb--;
                        }
                    }
                    else if (s[i] > '7' && !ans)
                    {
                        j = i - 1;
                        while (1)
                        {
                            if (b[j] < '7')
                            {
                                b[j] = '7';
                                la++;
                                lb--;
                                ans = 1;
                                break;
                            }
                            lb++;
                            j--;
                        }
                        for (int k = j + 1;k <= len; ++k)
                        {
                            if (la > 0)
                            {
                                b[k] = '4';
                                la--;
                            }
                            else
                            {
                                b[k] = '7';
                                lb--;
                            }
                        }
                        break;
                    }
                }
                printf("%s\n", b + 1);
            }
        }
    }
}