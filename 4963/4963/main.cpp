//
//  main.cpp
//  4963
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visit[50][50];
int map[50][50];
int d[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int w, h;


void bfs(int i, int k) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,k));
    visit[i][k] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (visit[nx][ny] || map[nx][ny] == 0) continue;
            
            q.push(make_pair(nx,ny));
            visit[nx][ny] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    while (true) {
        cin >> w >> h;
        
        if (w == 0 && h == 0) break;
        
        memset(visit, false, sizeof(visit));
        
        for (int i = 0;  i < h; i++) {
            for (int k = 0; k < w; k++) {
                cin >> map[i][k];
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int k = 0; k < w; k++) {
                if (map[i][k] == 1 && !visit[i][k]) {
                    bfs(i, k);
                    cnt++;
                }
            }
        }
        
        cout << cnt << '\n';
    }
    return 0;
}
