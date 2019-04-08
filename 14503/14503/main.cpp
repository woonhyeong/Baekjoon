//
//  main.cpp
//  14503
//
//  Created by 이운형 on 08/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

// 0 1 2 3 북 동 남 서
int change_dir(int d) {
    return d > 0? d-1 : 3;
}

int back_dir(int d) {
    if (d == 0) return 2;
    else if (d == 1) return 3;
    else if (d == 2) return 0;
    else return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int x,y,see;
    cin >> x >> y >> see;
    
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cin >> map[i][k];
        }
    }
    
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    
    int ans = 0;
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second; q.pop();
        
        if (map[x][y] == 0) {
            map[x][y] = 2;
            ans ++;
        }
        
        see = change_dir(see);
        x += dir[see][0]; y += dir[see][1];
        
        if (x>=0 && x<n && y>=0 && y<m && map[x][y] == 0) {
            q.push(make_pair(x,y));
            continue;
        } else {
            x -= dir[see][0]; y -= dir[see][1];
        }
        
        see = change_dir(see);
        x += dir[see][0]; y += dir[see][1];
        
        if (x>=0 && x<n && y>=0 && y<m && map[x][y] == 0) {
            q.push(make_pair(x,y));
            continue;
        } else {
            x -= dir[see][0]; y -= dir[see][1];
        }
        
        see = change_dir(see);
        x += dir[see][0]; y += dir[see][1];
        
        if (x>=0 && x<n && y>=0 && y<m && map[x][y] == 0) {
            q.push(make_pair(x,y));
            continue;
        } else {
            x -= dir[see][0]; y -= dir[see][1];
        }
        
        see = change_dir(see);
        x += dir[see][0]; y += dir[see][1];
        
        if (x>=0 && x<n && y>=0 && y<m && map[x][y] == 0) {
            q.push(make_pair(x,y));
            continue;
        } else {
            x -= dir[see][0]; y -= dir[see][1];
        }
        
        int back = back_dir(see);
        x += dir[back][0]; y+= dir[back][1];
        
        if (x<0 || x>=n || y<0 || y>=m || map[x][y] == 1) {
            printf("%d\n",ans);
            return 0;
        } else {
            q.push(make_pair(x, y));
        }
    }
}
