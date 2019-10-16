//
//  main.cpp
//  2206
//
//  Created by 이운형 on 2019/10/15.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <tuple>
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
bool visit[1001][1001][2];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void input() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            scanf("%1d", &map[i][k]);
        }
    }
}

void solve() {
    queue<tuple<int,int,bool>> q;
    q.push({0,0,false});
    visit[0][0][0] = true;
    
    int cnt = 1;
    while (!q.empty()) {
        
        int size = (int)q.size();
        
        while(size--) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front())? 1:0;
            q.pop();
            
            
            if (x == n-1 && y == m-1) {
                printf("%d\n", cnt);
                return;
            }
            
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if (map[nx][ny] == 0 && !visit[nx][ny][z]) {
                    visit[nx][ny][z] = true;
                    q.push({nx,ny,z});
                }
                
                if (z == 0 && map[nx][ny] == 1 && !visit[nx][ny][z+1]) {
                    visit[nx][ny][z+1] = true;
                    q.push({nx,ny,z+1});
                }
            }
        }
        
        cnt++;
    }
    
    printf("%d\n",-1);
}

int main(int argc, const char * argv[]) {
    input();
    solve();
    
    return 0;
}
