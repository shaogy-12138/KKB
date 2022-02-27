/*************************************************************************
	> File Name: eul-011.cpp
	> Author: Jason.shao
	> Mail: 
	> Created Time: Tue 22 Feb 2022 06:00:35 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


int num[30][30], ans;
int dirx[4] = {-1, 0, 1, 1};
int diry[4] = { 1, 1, 1, 0};
// (-1, 1) left-down
// ( 0, 1) down
// ( 1, 1) right-down
// ( 1, 0) right

int main(){

    int i, j, k, s;
    for(i = 5; i < 25; i++){
        for(j = 5; j < 25; j++){
            cin>>num[i][j];
        }
    }
    
    for(i = 5; i < 25; i++){
        for(j = 5; j < 25; j++){
            for(k = 0; k < 4; k++){
                int temp = num[i][j];
                for(s = 1; s < 4; s++){
                    int x = i + dirx[k] * s;
                    int y = j + diry[k] * s;
                    temp *= num[x][y];
                }

                ans = max(ans, temp);
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
