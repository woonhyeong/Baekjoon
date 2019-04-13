//
//  main.cpp
//  1938
//
//  Created by 이운형 on 13/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct tree {
    int x,y,cnt,state;
};

int map[50][50];
bool visit[50][50][2];
int htof[2][2] = {{1,1},{-1,-1}};
int ftoh[2][2] = {{-1,1},{1,-1}};
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int rotation[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int N;
queue<tree> q;

// E => 3
// TREE_STATE : 0 => -  , 1 => |
void input() {
    int t_idx = 0;
    int prev_x = 0;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int k = 0 ; k < N; k++) {
            if (line[k] == 'B') {
                if(t_idx == 1){
                    if (prev_x == i) {
                        q.push({i,k,0,0});
                        visit[i][k][0] = true;
                        t_idx++;
                    } else {
                        q.push({i,k,0,1});
                        visit[i][k][1] = true;
                        t_idx++;
                    }
                } else {
                    t_idx++;
                    prev_x = i;
                }
            } else if (line[k] == 'E') {
                map[i][k] = 3;
            } else if (line[k] == '0') {
                map[i][k] = 0;
            } else {
                map[i][k] = 1;
            }
        }
    }
}

bool victory_check(int x, int y, int state) {
    if (state == 0) {
        if (y-1 >= 0 && y+1 < N) {
            if (map[x][y-1] == 3 && map[x][y] == 3 && map[x][y+1] == 3) return true;
        }
    } else {
        if (x-1 >= 0 && x+1 < N) {
            if (map[x-1][y] == 3 && map[x][y] == 3 && map[x+1][y] == 3) return true;
        }
    }
    return false;
}

bool rck(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N) return true;
    return false;
}

bool one_contain(int x1,int y1,int x2,int y2,int x3,int y3) {
    if (!rck(x1, y1)) return false;
    if (!rck(x2, y2)) return false;
    if (!rck(x3, y3)) return false;
    if (map[x1][y1] == 1) return false;
    if (map[x2][y2] == 1) return false;
    if (map[x3][y3] == 1) return false;
    return true;
}

bool rotation_check(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x+rotation[i][0];
        int ny = y+rotation[i][1];
        if (!rck(nx,ny) || map[nx][ny] == 1) {
            return false;
        }
    }
    return true;
}

int bfs() {
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int state = q.front().state;
        q.pop();
        
        if (victory_check(x, y, state)) {
            return cnt;
        }
        // 상 하 좌 우 회전
        if (state == 0) {
            if (one_contain(x+dir[0][0],y+dir[0][1],x+dir[0][0],y-1+dir[0][1],x+dir[0][0],y+1+dir[0][1]) && !visit[x+dir[0][0]][y+dir[0][1]][state]) {
                visit[x+dir[0][0]][y+dir[0][1]][state] = true;
                q.push({x+dir[0][0],y+dir[0][1],cnt+1,state});
            }
            if (one_contain(x+dir[1][0],y+dir[1][1],x+dir[1][0],y-1+dir[1][1],x+dir[1][0],y+1+dir[1][1]) && !visit[x+dir[1][0]][y+dir[1][1]][state]) {
                visit[x+dir[1][0]][y+dir[1][1]][state] = true;
                q.push({x+dir[1][0],y+dir[1][1],cnt+1,state});
            }
            if (one_contain(x+dir[2][0],y+dir[2][1],x+dir[2][0],y-1+dir[2][1],x+dir[2][0],y+1+dir[2][1]) && !visit[x+dir[2][0]][y+dir[2][1]][state]) {
                visit[x+dir[2][0]][y+dir[2][1]][state] = true;
                q.push({x+dir[2][0],y+dir[2][1],cnt+1,state});
            }
            if (one_contain(x+dir[3][0],y+dir[3][1],x+dir[3][0],y-1+dir[3][1],x+dir[3][0],y+1+dir[3][1]) && !visit[x+dir[3][0]][y+dir[3][1]][state]) {
                visit[x+dir[3][0]][y+dir[3][1]][state] = true;
                q.push({x+dir[3][0],y+dir[3][1],cnt+1,state});
            }
            if (rotation_check(x, y) && !visit[x][y][!state]) {
                visit[x][y][!state] = true;
                q.push({x,y,cnt+1,!state});
            }
        } else if (state == 1) {
            if (one_contain(x+dir[0][0],y+dir[0][1],x-1+dir[0][0],y+dir[0][1],x+1+dir[0][0],y+dir[0][1]) && !visit[x+dir[0][0]][y+dir[0][1]][state])  {
                visit[x+dir[0][0]][y+dir[0][1]][state] = true;
                q.push({x+dir[0][0],y+dir[0][1],cnt+1,state});
            }
            if (one_contain(x+dir[1][0],y+dir[1][1],x-1+dir[1][0],y+dir[1][1],x+1+dir[1][0],y+dir[1][1]) && !visit[x+dir[1][0]][y+dir[1][1]][state]) {
                visit[x+dir[1][0]][y+dir[1][1]][state] = true;
                q.push({x+dir[1][0],y+dir[1][1],cnt+1,state});
            }
            if (one_contain(x+dir[2][0],y+dir[2][1],x-1+dir[2][0],y+dir[2][1],x+1+dir[2][0],y+dir[2][1]) && !visit[x+dir[2][0]][y+dir[2][1]][state]) {
                visit[x+dir[2][0]][y+dir[2][1]][state] = true;
                q.push({x+dir[2][0],y+dir[2][1],cnt+1,state});
            }
            if (one_contain(x+dir[3][0],y+dir[3][1],x-1+dir[3][0],y+dir[3][1],x+1+dir[3][0],y+dir[3][1]) && !visit[x+dir[3][0]][y+dir[3][1]][state]) {
                visit[x+dir[3][0]][y+dir[3][1]][state] = true;
                q.push({x+dir[3][0],y+dir[3][1],cnt+1,state});
            }
            if (rotation_check(x, y) && !visit[x][y][!state]) {
                visit[x][y][!state] = true;
                q.push({x,y,cnt+1,!state});
            }
        }
    }
    return 0;
}

int main() {
    cin >> N;
    input();
    
    cout << bfs() << endl;
}
