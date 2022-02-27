/*************************************************************************
	> File Name: oj_590.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Mon 21 Feb 2022 11:51:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int num[1005][1005], utd[1005][1005], dtu[1005][1005], ans[1005][1005], n, m, fin[1005][3];
// num 原数组  utd从上往下求 dtu从下向上求 ans路径 fin最后的结果数组

int main(){

    scanf("%d%d", &n, &m);
    int i, j;
    // 输入
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            scanf("%d", &num[i][j]);
        }
    }

    printf("for 1\n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= i; j++){
            utd[i][j] = max(utd[i - 1][j -1], utd[i -1][j]) + num[i][j];
        }
    }
    
    printf("for 2\n");
    for(i = n; i > 0; i--){
        for(j = 1; j <= m; j++){
            dtu[i][j] = max(dtu[i + 1][j], dtu[i + 1][j + 1]) + num[i][j];
        }
    }
    
    printf("for 3\n");
    for(i = 1; i <= n; i++){
        int m1 = 0, m2 = 0, ind = 0;
        for(j = 1; j <= i; j++){
            ans[i][j] = utd[i][j] + dtu[i][j] - num[i][j];
            printf("debug1\n");
            if(i < 2) continue;
            printf("debug2\n");
            if(ans[i][j] > m1){
                m2 = m1;
                m1 = ans[i][j];
                ind = j;
            }else if(ans[i][j] > m2){
                m2 = ans[i][j];
            }

        }
        if(i < 1)continue;
        fin[i][0] = ind; //下标
        fin[i][1] = m1; //最大
        fin[i][2] = m2; //次大
    }

    printf("for 4\n");
    for(i = 0; i < m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(x == 1 && y == 1){
            printf("-1\n");
        }else if(fin[x][0] == y){
            printf("%d\n", fin[x][2]);
        }else{
            printf("%d\n", fin[x][1]);
        }

    }

    return 0;
    /**
     *暂未结束
     */




}
