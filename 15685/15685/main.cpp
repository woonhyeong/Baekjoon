//
//  main.cpp
//  15685
//
//  Created by 이운형 on 10/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int N;
int map[101][101];
int dir[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
vector<int> dir_stack;

int change_dir(int idx) {
    if (idx == 3) return 0;
    else return idx+1;
}

void dragon(int x, int y,int g_start, int g_end) {
    if (g_start > g_end) {
        return;
    }
    
    if (g_start == 0) {
        map[y][x] = 1;
        y += dir[dir_stack[0]][0];
        x += dir[dir_stack[0]][1];
        map[y][x] = 1;
        dragon(x, y, g_start+1, g_end);
    } else {
        int next_dir = 0;
        for (int i = (int)dir_stack.size() - 1; i >= 0 ; i--) {
            next_dir = change_dir(dir_stack[i]);
            y += dir[next_dir][0];
            x += dir[next_dir][1];
            map[y][x] = 1;
            dir_stack.push_back(next_dir);
        }
        dragon(x, y, g_start+1, g_end);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    int x,y,d,g;
    
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        dir_stack.push_back(d);
        dragon(x,y,0,g);
        dir_stack.clear();
    }
    
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int k = 0; k <= 100; k++) {
            if (map[i][k] == 1 && k+1 < 101 && i+1 < 101 && map[i][k+1] == 1 && map[i+1][k] == 1 && map[i+1][k+1] == 1) {
                ans++;
            }
        }
    }
    printf("%d\n",ans);
}
