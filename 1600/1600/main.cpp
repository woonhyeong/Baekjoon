//
//  main.cpp
//  1600
//
//  Created by 이운형 on 13/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct info {
    int x, y, m, cnt;
};

int K, H, W;
int map[200][200];
bool visit[200][200][32];
int horse[8][2] = {{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2}};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void input() {
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int k = 0; k < W; k++) {
            cin >> map[i][k];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> K;
    input();
    
    queue<info> q;
    q.push({0,0,K,0});
    visit[0][0][K] = true;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int m = q.front().m;
        int cnt = q.front().cnt;
        q.pop();
        
        if (x == H-1 && y == W-1) {
            cout << cnt << endl;
            return 0;
        }
        
        if (m > 0) {
            for (int i = 0; i < 8; i++) {
                int nx = x+horse[i][0];
                int ny = y+horse[i][1];
                if (nx >= 0 && nx < H && ny >=0 && ny < W) {
                    if(map[nx][ny] == 0 && !visit[nx][ny][m-1]){
                        q.push({nx,ny,m-1,cnt+1});
                        visit[nx][ny][m-1] = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x+dir[i][0];
            int ny = y+dir[i][1];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (map[nx][ny] == 0 && !visit[nx][ny][m]) {
                    q.push({nx,ny,m,cnt+1});
                    visit[nx][ny][m] = true;
                }
            }
        }
        
    }
    
    cout << "-1" << endl;
}
