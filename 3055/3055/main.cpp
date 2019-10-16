//
//  main.cpp
//  3055
//
//  Created by 이운형 on 2019/10/15.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int R, C;
int map[50][50]; // '.' = 0, 'S' = 1, 'D' = 2, '*' = 3, 'X'= 4, visit = 5
int sx, sy; // start
int dx, dy; // end
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
queue<pair<int,int>> water;

void input() {
    cin >> R >> C;
    
    string str;
    for (int i = 0; i < R; i++) {
        cin >> str;
        for (int k = 0; k < str.size(); k++) {
            char temp = str[k];
            
            if (temp == '.') map[i][k] = 0;
            if (temp == 'S') {
                map[i][k] = 1;
                sx = i; sy = k;
            }
            if (temp == 'D') {
                map[i][k] = 2;
                dx = i; dy = k;
            }
            if (temp == '*') {
                map[i][k] = 3;
                water.push(make_pair(i,k));
            }
            if (temp == 'X') {
                map[i][k] = 4;
            }
        }
    }
}

void water_flood() {
    int size = (int)water.size();
    for (int i = 0; i < size; i++) {
        int x = water.front().first;
        int y = water.front().second;
        water.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = x + d[k][0];
            int ny = y + d[k][1];
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            
            if (map[nx][ny] == 0 || map[nx][ny] == 5) {
                map[nx][ny] = 3;
                water.push(make_pair(nx,ny));
            }
        }
    }
}

void solve() {
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    map[sx][sy] = 4;
    
    int cnt = 0;
    while (!q.empty()) {
        water_flood();
        
        int size = (int)q.size();
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
                        
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                
                if (map[nx][ny] == 0) {
                    q.push({nx,ny});
                    map[nx][ny] = 5;
                }
                if (map[nx][ny] == 2) {
                    cout << cnt+1 << '\n';
                    return;
                }
            }
        }
        cnt++;
    }
    cout << "KAKTUS\n";
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    return 0;
}
