//
//  main.cpp
//  16236
//
//  Created by 이운형 on 12/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[20][20];
bool check[20][20];
int age = 2;
int eat;
int N;
int s_x, s_y;
int next_x, next_y;
int min_distance = 500;

struct info {
    int x,y,cnt;
};

int min_cnt(int a1, int a2, int a3, int a4) {
    int m1 = min(a1,a2);
    int m2 = min(a3,a4);
    return min(m1,m2);
}

void search(int ix, int iy, int cnt) {
    queue<info> q;
    q.push({ix,iy,cnt});
    check[ix][iy] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().cnt;
        q.pop();
        
        if (x == s_x && y == s_y) {
            if (min_distance > t) {
                min_distance = t;
                next_x = ix; next_y = iy;
            }
            break;
        }
        
        if (x+1 < N && !check[x+1][y] && (map[x+1][y] == 0 || map[x+1][y] == age)) {
            check[x+1][y] = true;
            q.push({x+1,y,t+1});
        }
        
        if (y+1 < N && !check[x][y+1] && (map[x][y+1] == 0 || map[x][y+1] == age)) {
            check[x][y+1] = true;
            q.push({x,y+1,t+1});
        }
        
        if (x-1 >= 0 && !check[x-1][y] && (map[x-1][y] == 0 || map[x-1][y] == age)) {
            check[x-1][y] = true;
            q.push({x-1,y,t+1});
        }
        
        if (y-1 >= 0 && !check[x][y-1] && (map[x][y-1] == 0 || map[x][y-1] == age)) {
            check[x][y-1] = true;
            q.push({x,y-1,t+1});
        }
    }
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            check[i][k] = false;
        }
    }
}

void input() {
    for (int i=0; i<N; i++) {
        for (int k=0; k<N; k++) {
            cin >> map[i][k];
            if (map[i][k] == 9) {
                map[i][k] = 0;
                s_x = i; s_y = k;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    input();
    
    int ans = 0;
    
    while (1){
        // 최소 거리 탐색
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                if (map[i][k] == 0) continue;
                if (i == s_x && k == s_y) continue;
                if (map[i][k] < age) {
                    search(i,k,0);
                    init();
                }
            }
        }
        
        // 이동 가능 거리가 있을 때
        if (min_distance != 500) {
            ans += min_distance;
            map[s_x][s_y] = 0;
            eat += 1;
            
            if (eat == age) {
                age+=1;
                eat = 0;
            }
            
            map[next_x][next_y] = 0;
            s_x = next_x;
            s_y = next_y;
            
            //초기화
            min_distance = 500;
        } else {
            break;
        }
    }
    cout << ans << endl;
}
