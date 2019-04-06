//
//  main.cpp
//  3190
//
//  Created by 이운형 on 06/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int t[100];
char next_dir[100];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,k;

// 우하좌상 0123
int change_dir(int d, char c) {
    if (c == 'D') {
        return d+1>3? 0 : d+1;
    } else {
        return d-1<0? 3 : d-1;
    }
}

int snake() {
    queue<int> head;
    queue<pair<int, int>> tail;
    
    int ld;
    // 방향 변환 입력
    cin >> ld;
    for (int i = 0; i < ld; i++) {
        int x; char y;
        cin >> x >> y;
        t[i] = x; next_dir[i] = y;
        head.push(i);
    }
    
    int sec = 0;
    int hx = 0, hy = 0;
    int curr_dir = 0;
    
    tail.push(make_pair(0, 0));
    while (!head.empty()) {
        int idx = head.front(); head.pop();
        int time = t[idx]-sec;
        
        while (time--) {
            sec ++;
            hx += dir[curr_dir][0];
            hy += dir[curr_dir][1];
            
            if ( hx<0 || hx>=n || hy<0 || hy>=n || map[hx][hy] == 1) {
                return sec;
            }
            // 사과 일때
            if (map[hx][hy] == 2) {
                map[hx][hy] = 1;
                tail.push(make_pair(hx, hy));
            }
            // 빈 곳
            else if (map[hx][hy] == 0) {
                map[hx][hy] = 1;
                map[tail.front().first][tail.front().second] = 0;
                tail.pop();
                tail.push(make_pair(hx, hy));
            }
        }
        curr_dir = change_dir(curr_dir, next_dir[idx]);
    }
    
    while (1) {
        sec ++;
        hx += dir[curr_dir][0];
        hy += dir[curr_dir][1];
        
        if ( hx<0 || hx>=n || hy<0 || hy >=n || map[hx][hy] == 1) {
            break;
        }
        // 사과 일때
        if (map[hx][hy] == 2) {
            map[hx][hy] = 1;
            tail.push(make_pair(hx, hy));
        }
        // 빈 곳
        else if (map[hx][hy] == 0) {
            map[hx][hy] = 1;
            map[tail.front().first][tail.front().second] = 0;
            tail.pop();
            tail.push(make_pair(hx,hy));
            
        }
    }
    return sec;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 사과 입력
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x,y;
        cin >> x >> y;
        map[x-1][y-1] = 2;
    }
    map[0][0] = 1;
    printf("%d\n",snake());
}
