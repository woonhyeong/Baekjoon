//
//  main.cpp
//  2667
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int map[25][25];
bool visit[25][25];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<int> result;
int n;

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            scanf("%1d", &map[i][k]);
        }
    }
}

void bfs(int i, int k) {
    queue<pair<int,int>> q;
    q.push(make_pair(i,k));
    visit[i][k] = true;
    
    int cnt = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (visit[nx][ny] || map[nx][ny] == 0) continue;
            
            q.push(make_pair(nx, ny));
            visit[nx][ny] = true;
            cnt++;
        }
    }
    
    result.push_back(cnt);
}

int main(int argc, const char * argv[]) {
    
    input();
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (map[i][k] == 1 && !visit[i][k]) {
                bfs(i,k);
            }
        }
    }
    
    printf("%lu\n", result.size());
    sort(result.begin(), result.end());
    
    for (int i = 0; i < result.size(); i++) {
        printf("%d\n",result[i]);
    }
    
    return 0;
}
