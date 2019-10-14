//
//  main.cpp
//  7576
//
//  Created by 이운형 on 2019/10/14.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int box[1000][1000];
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
vector<pair<int,int>> alive;

struct tomato {
    int x;
    int y;
    int day;
};

void input() {
    cin >> m >> n;
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> box[i][k];
            if (box[i][k] == 1) {
                alive.push_back(make_pair(i,k));
            }
        }
    }
}

void solve() {
    if (alive.size() == m*n) {
        cout << 0 << '\n';
        return;
    } else if (alive.size() == 0) {
        cout << -1 << '\n';
        return;
    }
    
    queue<tomato> q;
    
    for (int i = 0; i < alive.size(); i++) {
        q.push({alive[i].first, alive[i].second, 0});
    }
    
    int max_day = 0;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int day = q.front().day;
        q.pop();
        
        if (max_day < day) {
            max_day = day;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (box[nx][ny] != 0) continue;
            
            box[nx][ny] = 1;
            q.push({nx,ny,day+1});
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (box[i][k] == 0) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    
    cout << max_day << '\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    input();
    solve();
    return 0;
}
