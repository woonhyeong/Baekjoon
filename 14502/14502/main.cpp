//
//  main.cpp
//  14502
//
//  Created by 이운형 on 07/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[8][8];
int birus[10][10];
int bi;
int n,m;
int result;

void input() {
    cin >> n >> m;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            cin >> map[i][k];
            if (map[i][k] == 2) {
                birus[bi][0] = i;
                birus[bi][1] = k;
                bi++;
            }
        }
    }
}

int poison() {
    int temp[8][8];
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            temp[i][k] = map[i][k];
        }
    }
    
    queue<pair<int,int>> q;
    for (int i = 0 ; i<bi; i++) {
        q.push(make_pair(birus[i][0], birus[i][1]));
    }
    
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second; q.pop();
        
        if (x-1 >= 0 && temp[x-1][y]==0) {
            temp[x-1][y] = 2;
            q.push(make_pair(x-1, y));
        }
        
        if (x+1 < n && temp[x+1][y]==0) {
            temp[x+1][y] = 2;
            q.push(make_pair(x+1, y));
        }
        
        if (y-1 >= 0 && temp[x][y-1]==0) {
            temp[x][y-1] = 2;
            q.push(make_pair(x, y-1));
        }
        
        if (y+1 < m && temp[x][y+1]==0) {
            temp[x][y+1] = 2;
            q.push(make_pair(x, y+1));
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<m; k++) {
            if (temp[i][k] == 0) {
                ans++;
            }
        }
    }
    return ans;
}

void solve(int idx, int cnt) {
    if (cnt == 3) {
        int ans = poison();
        if (result < ans) {
            result = ans;
        }
        return;
    }
    
    for (int i = idx+1; i < n*m; i++) {
        int x = i/m, y = i%m;
        if (map[x][y] == 0) {
            map[x][y] = 1;
            solve(i,cnt+1);
            map[x][y] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i = 0; i<n*m; i++) {
        int x = i/m;
        int y = i%m;
        if (map[x][y] == 0) {
            map[x][y] = 1;
            solve(0,1);
            map[x][y] = 0;
        }
    }
    printf("%d\n",result);
}
