//
//  main.cpp
//  2468
//
//  Created by 이운형 on 13/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
int map[100][100];
bool visit[100][100];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int MAX_HEIGHT, MAX_SAFE_ZONE;

void input() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            cin >> map[i][k];
            if (map[i][k] > MAX_HEIGHT) {
                MAX_HEIGHT = map[i][k];
            }
        }
    }
}

void init_visit() {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            visit[i][k] = false;
        }
    }
}

void draw_visit(int h, vector<pair<int,int>> &u) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (map[i][k] <= h) {
                visit[i][k] = true;
            } else {
                u.push_back(make_pair(i, k));
            }
        }
    }
}

bool check_visit(int num) {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (map[i][k] == num) {
                return true;
            }
        }
    }
    return false;
}

void solve(int h) {
    vector<pair<int,int>> u;
    draw_visit(h,u);
    
    int sum = 0;
    for (int i = 0 ; i < u.size(); i++) {
        int x = u[i].first;
        int y = u[i].second;
        
        if(!visit[x][y]) {
            queue<pair<int,int>> q;
            q.push(make_pair(x,y));
            visit[x][y] = true;
            while (!q.empty()) {
                int next_x = q.front().first;
                int next_y = q.front().second;
                q.pop();
                
                if (next_x+1 < N && !visit[next_x+1][next_y]) {
                    visit[next_x+1][next_y] = true;
                    q.push(make_pair(next_x+1,next_y));
                }
                if (next_x-1 >= 0 && !visit[next_x-1][next_y]) {
                    visit[next_x-1][next_y] = true;
                    q.push(make_pair(next_x-1,next_y));
                }
                if (next_y+1 < N && !visit[next_x][next_y+1]) {
                    visit[next_x][next_y+1] = true;
                    q.push(make_pair(next_x,next_y+1));
                }
                if (next_y-1 >= 0 && !visit[next_x][next_y-1]) {
                    visit[next_x][next_y-1] = true;
                    q.push(make_pair(next_x, next_y-1));
                }
            }
            sum ++;
        } else {
            continue;
        }
    }
    if (MAX_SAFE_ZONE < sum) {
        MAX_SAFE_ZONE = sum;
    }
    init_visit();
}

int main() {
    cin >> N;
    input();
    
    for (int i = MAX_HEIGHT; i>0; i--) {
        if (check_visit(i)) {
            solve(i);
        }
    }
    
    if (MAX_SAFE_ZONE < 1 ) {
        MAX_SAFE_ZONE = 1;
    }
    
    cout << MAX_SAFE_ZONE << endl;
}
