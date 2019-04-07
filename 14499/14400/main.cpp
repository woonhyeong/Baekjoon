//
//  main.cpp
//  14400
//
//  Created by 이운형 on 06/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int map[20][20];
int dir[5][2] = {{0,0},{0,1},{0,-1},{-1,0},{1,0}};
int ins[1000];
int dice[6];
int dice_idx[6] = {0,1,2,3,4,5};

void change_dice(int d){
    int d0=dice_idx[0], d1=dice_idx[1], d2=dice_idx[2], d3=dice_idx[3],d4=dice_idx[4],d5=dice_idx[5];
    if (d==1) {
        dice_idx[0] = d1;
        dice_idx[1] = d5;
        dice_idx[5] = d2;
        dice_idx[2] = d0;
    } else if (d==2) {
        dice_idx[0] = d2;
        dice_idx[1] = d0;
        dice_idx[5] = d1;
        dice_idx[2] = d5;
    } else if (d==3) {
        dice_idx[0] = d4;
        dice_idx[3] = d0;
        dice_idx[5] = d3;
        dice_idx[4] = d5;
    } else if (d==4) {
        dice_idx[0] = d3;
        dice_idx[3] = d5;
        dice_idx[5] = d4;
        dice_idx[4] = d0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,x,y,k;
    cin >> n >> m >> x >> y >> k;
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i<k; i++) {
        int next;
        cin >> next;
        x += dir[next][0];
        y += dir[next][1];
        if (x>=n || x<0 || y>=m || y<0) {
            x -= dir[next][0];
            y -= dir[next][1];
            continue;
        } else {
            change_dice(next);
            
            if(map[x][y] == 0) {
                map[x][y] = dice[dice_idx[0]];
            } else {
                dice[dice_idx[0]] = map[x][y];
                map[x][y] = 0;
            }
            printf("%d\n",dice[dice_idx[5]]);
        }
    }
}
