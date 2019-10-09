//
//  main.cpp
//  14500
//
//  Created by 이운형 on 06/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int figure[19][3][2] = {
    {{0,1},{0,2},{0,3}},
    {{1,0},{2,0},{3,0}},
    {{1,0},{1,1},{1,2}},
    {{0,1},{1,0},{2,0}},
    {{0,1},{0,2},{1,2}},
    {{1,0},{2,0},{2,-1}},
    {{0,1},{0,2},{-1,2}},
    {{1,0},{2,0},{2,1}},
    {{0,1},{0,2},{1,0}},
    {{0,1},{1,1},{2,1}},
    {{0,1},{1,0},{1,1}},
    {{0,1},{-1,1},{-1,2}},
    {{1,0},{1,1},{2,1}},
    {{0,1},{1,1},{1,2}},
    {{1,0},{1,-1},{2,-1}},
    {{0,1},{0,2},{-1,1}},
    {{0,1},{0,2},{1,1}},
    {{1,0},{2,0},{1,1}},
    {{1,0},{2,0},{1,-1}}
};

int map[501][501];
int n, m;

void input() {
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%d", &map[i][k]);
        }
    }
}

void solve() {
    int max_sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int j = 0; j < 19; j++) {
                bool flag = true;
                int sum = map[i][k];
                
                for (int d = 0; d < 3; d++) {
                    int y = i + figure[j][d][0];
                    int x = k + figure[j][d][1];
                    
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        flag = false;
                        break;
                    }
                    
                    sum += map[y][x];
                }
                
                if (flag && max_sum < sum) {
                    max_sum = sum;
                }
            }
        }
    }
    
    printf("%d\n", max_sum);
}

int main() {
    input();
    solve();
}
