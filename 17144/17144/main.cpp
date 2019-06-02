//
//  main.cpp
//  17144
//
//  Created by 이운형 on 02/06/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct pot {
    int x, y, v;
};

int R, C, T;
int room[50][50];
int clean[2][2];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

bool range(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || room[x][y] == -1) {
        return false;
    }
    return true;
}

void spread() {
    queue<pot> q;
    
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < C; k++) {
            if (room[i][k] > 0) {
                q.push({i,k,room[i][k]});
            }
        }
    }
    
    while (!q.empty()) {
        int x = q.front().x, y = q.front().y, v = q.front().v;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (range(nx, ny)) {
                room[nx][ny] += v/5;
                room[x][y] -= v/5;
            }
        }
    }
}

void wind() {
    int ucx = clean[0][0];
    int dcx = clean[1][0];
    
    for (int i = ucx-1; i > 0; i--) {
        room[i][0] = room[i-1][0];
    }
    for (int i = 0; i < C-1; i++) {
        room[0][i] = room[0][i+1];
    }
    for (int i = 0; i < ucx; i++) {
        room[i][C-1] = room[i+1][C-1];
    }
    for (int i = C-1; i >= 2; i--) {
        room[ucx][i] = room[ucx][i-1];
    }
    room[ucx][1] = 0;
    
    for (int i = dcx+1; i < R-1; i++) {
        room[i][0] = room[i+1][0];
    }
    for (int i = 0; i < C-1; i++) {
        room[R-1][i] = room[R-1][i+1];
    }
    for (int i = R-1; i > dcx; i--) {
        room[i][C-1] = room[i-1][C-1];
    }
    for (int i = C-1; i >= 2; i--) {
        room[dcx][i] = room[dcx][i-1];
    }
    room[dcx][1] = 0;
}

void input() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < C; k++) {
            cin >> room[i][k];
            if (room[i][k] == -1) {
                clean[0][0] = i-1;
                clean[0][1] = k;
                clean[1][0] = i;
                clean[1][1] = k;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    
    for (int i = 0; i < T; i++) {
        spread();
        wind();
    }
    
    int ans = 0;
    
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < C; k++) {
            ans += room[i][k];
        }
    }
    cout << ans+2 << '\n';
}
