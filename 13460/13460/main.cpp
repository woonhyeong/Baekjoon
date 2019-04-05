//
//  main.cpp
//  13460
//
//  Created by 이운형 on 05/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

struct ball {
    int cnt;
    int r_x, r_y, b_x, b_y;
};

char guide[11][11];
bool check[11][11][11][11];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int bfs(ball b) {
    queue<ball> q;
    q.push(b);
    check[b.r_x][b.r_y][b.b_x][b.b_y] = true;
    int ans = -1;
    
    while (!q.empty()) {
        ball temp = q.front();
        q.pop();
        
        if (temp.cnt > 10) {
            break;
        }
        if (guide[temp.r_x][temp.r_y] == 'O') {
            ans = temp.cnt;
            break;
        }
        
        for (int i = 0; i<4; i++) {
            int rx = temp.r_x, ry = temp.r_y, bx = temp.b_x, by = temp.b_y;
            
            while (true) {
                rx += dir[i][0];
                ry += dir[i][1];
                if (guide[rx][ry] == '#') {
                    rx -= dir[i][0];
                    ry -= dir[i][1];
                    break;
                } else if(guide[rx][ry] == 'O'){
                    break;
                }
            }
            
            while (true) {
                bx += dir[i][0];
                by += dir[i][1];
                if (guide[bx][by] == '#') {
                    bx -= dir[i][0];
                    by -= dir[i][1];
                    break;
                } else if(guide[bx][by] == 'O'){
                    break;
                }
            }
            
            if (guide[bx][by] == 'O') continue;
            if (rx == bx && ry == by) {
                switch (i) {
                    case 0:
                        temp.r_x<temp.b_x ? bx++ : rx++;
                        break;
                    case 1:
                        temp.r_x<temp.b_x ? rx-- : bx--;
                        break;
                    case 2:
                        temp.r_y<temp.b_y ? by++ : ry++;
                        break;
                    case 3:
                        temp.r_y<temp.b_y ? ry-- : by--;
                        break;
                }
            }
            if (!check[rx][ry][bx][by]) {
                ball next = {temp.cnt+1,rx,ry,bx,by};
                q.push(next);
                check[rx][ry][bx][by] = true;
            }
        }
    }
    return ans;
}
    
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    
    int b_x = 0, b_y = 0;
    int r_x = 0, r_y = 0;
    
    for (int i=0; i<n; i++) {
        char str[11];
        scanf("%s",str);
        for (int k=0; k<m; k++) {
            guide[i][k] = str[k];
            if (guide[i][k] == 'B') {
                b_x = i;
                b_y = k;
            } else if (guide[i][k] == 'R') {
                r_x = i;
                r_y = k;
            }
        }
    }
    ball b = {0,r_x,r_y,b_x,b_y};
    printf("%d\n",bfs(b));
}
