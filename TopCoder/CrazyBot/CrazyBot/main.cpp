//
//  main.cpp
//  CrazyBot
//
//  Created by 이운형 on 19/05/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

bool rmap[30][30] = {false};
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
double prob[4];
double ans = 0;

class CrazyBot {
public:
    void dfs(int x, int y, int n, double p) {
        if(n == 0) {
            ans += p;
            return;
        }
        
        if (p == 0) return;
        
        for (int i = 0; i < 4 ; i++) {
            int nx = x + dir[i][1];
            int ny = y + dir[i][0];
            if (!rmap[nx][ny]) {
                rmap[nx][ny] = true;
                dfs(nx, ny, n-1, p*prob[i]);
                rmap[nx][ny] = false;
            }
        }
    }
    
    double getProbability(int n, int east, int west, int south, int north) {
        prob[0] = east/100.0;
        prob[1] = west/100.0;
        prob[2] = south/100.0;
        prob[3] = north/100.0;
        
        rmap[14][14] = true;
        dfs(14, 14, n, 1.0);
        return ans;
    }
};

int main() {
    CrazyBot c = CrazyBot();
    // 0.75
    printf("%lf\n",c.getProbability(2, 25, 25, 25, 25));
}
