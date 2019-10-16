//
//  main.cpp
//  1261
//
//  Created by 이운형 on 2019/10/15.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <deque>
using namespace std;

int n, m;
int map[100][100];
bool visit[100][100];
int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

struct admin {
    int x;
    int y;
    int num;
};

void input() {
    scanf("%d %d", &m, &n);
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%1d", &map[i][k]);
        }
    }
}

void solve() {
    deque<admin> q;
    q.push_back({0,0,0});
    visit[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int num = q.front().num;
        q.pop_front();
        
        if (x == n-1 && y == m-1) {
            printf("%d\n",num);
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visit[nx][ny]) continue;
            
            if (map[nx][ny] == 0) {
                q.push_front({nx,ny,num});
                visit[nx][ny] = true;
            } else if (map[nx][ny] == 1) {
                q.push_back({nx,ny,num+1});
                visit[nx][ny] = true;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    input();
    solve();
    
    return 0;
}
