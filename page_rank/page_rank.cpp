//
// Created by 陈浩 on 2023/5/13.
//
#include<bits/stdc++.h>

int main()
{
    //模拟4个网页，即4图里的4个节点
    int pages = 4;
    //阻尼系数，表示有一部分点击概率来自于新开窗口而，一部分来自于跳转
    double d = 0.85;
    //网页被点击的初始状态
    double w0[]={0.25,0.25,0.25,0.25};
    //图中各节点出发的边的数目(0表示没有连接，1表示有一条边)
    double edges[4][4] = {{0,0,0,0},
                          {1,0,1,0},
                          {1,0,0,0},
                          {1,1,1,0}};
    //图中各节点出发的边的总数
    double outlines[] = {0,2,1,3};

    //计算转移概率矩阵
    printf("状态转移矩阵：\n");
    double p[4][4];
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            p[i][j] = (edges[i][j] == 0 ? 0 : edges[i][j]/outlines[i]);
            printf("%.3f ",p[i][j]);
        }
        printf("\n");

    }
    printf("\n");

    double wn[4];
    int times=0;

    //根据转移概率计算平稳分布
    while(1)
    {
        for(int i=0;i<4;i++)
        {
            double x=0;
            for(int j=0;j<4;j++)
            {
                //1、向量与矩阵的乘法
                x+=w0[j]*p[j][i];
            }
            //计算加上阻尼以后的概率
            wn[i] =(1-d)/pages + d*x;
        }
        //每一步都判断是否到达平稳状态
        int tag = 0;
        //2、对初始状态进行更新，以作为下一次转移的初始值
        for(int i=0;i<4;i++)
        {
            if(w0[i]!=wn[i])
            {
                tag=1;
                //只要不相等，就继续算下去
                w0[i]=wn[i];
            }
        }
        printf("转移步数%d:\n",++times);

        //打印出当前状态结果
        for(int i=0;i<4;i++)
        {
            printf("%.3f ",w0[i]);
        }
        printf("\n");
        printf("\n");
        if(tag==0)
            break;

    }
    return 0;
}