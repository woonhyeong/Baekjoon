//
//  main.cpp
//  2178
//
//  Created by 이운형 on 2019/10/10.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

int map[100][100];
bool visit[100][100];
int d[4][2] = {{1,0},{0,-1},{-1,0},{0,1}}; // 하, 좌, 상. 우
int n, m;

struct road {
    int x;
    int y;
    int val;
};

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%1d",&map[i][k]);
        }
    }
}

void bfs() {
    queue<road> q;
    q.push({0,0,1});
    visit[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int val = q.front().val;
        q.pop();
        
        if (x == n-1 && y == m-1) {
            printf("%d\n",val);
            return;
        }
        
        for (int i = 0; i<4; i++) {
            int nx = x+d[i][0];
            int ny = y+d[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            
            if (map[nx][ny] == 0 || visit[nx][ny]) continue;
            
            visit[nx][ny] = true;
            q.push({nx,ny,val+1});
        }
    }
}

int main(int argc, const char * argv[]) {
    input();
    bfs();
    
    return 0;
}
