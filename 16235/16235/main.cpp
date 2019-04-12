//
//  main.cpp
//  16235
//
//  Created by 이운형 on 12/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tree {
    int x, y, age;
};

int map[10][10];
int A[10][10];
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int N, M, K;
vector<tree> q;

bool cmp(const tree &A, const tree &B) {
    if (A.x == B.x && A.y == B.y) {
        return A.age < B.age;
    } else {
        if (A.x == B.x) {
            return A.y < B.y;
        } else {
            return A.x < B.x;
        }
    }
}

void winter() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] += A[i][j];
        }
    }
}

void input() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            map[i][j] = 5;
        }
    }
    for (int i = 0; i < M; i++) {
        int x,y,age;
        cin >> x >> y >> age;
        q.push_back({x-1,y-1,age});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> K;
    input();
    
    while (K--) {
        sort(q.begin(), q.end(), cmp);
        
        vector<tree> alive;
        vector<tree> dead;
        vector<tree> five;
        //봄
        for (int i = 0; i < q.size(); i++) {
            int x = q[i].x;
            int y = q[i].y;
            int age = q[i].age;
            
            if (map[x][y] < age) {
                dead.push_back({x,y,age});
            } else {
                map[x][y] -= age;
                age += 1;
                
                if (age%5 == 0) {
                    five.push_back({x,y,age});
                }
                alive.push_back({x,y,age});
                
            }
        }
        // 여름
        for (int i = 0; i < dead.size(); i++) {
            int x = dead[i].x;
            int y = dead[i].y;
            int age = dead[i].age/2;
            map[x][y] += age;
        }
        
        // 가을
        for (int i = 0; i < five.size(); i++) {
            int x = five[i].x;
            int y = five[i].y;
            
            for (int j = 0; j < 8; j++) {
                x += dir[j][0];
                y += dir[j][1];
                if (x >=0 && x < N && y >=0 && y < N) {
                    alive.push_back({x,y,1});
                }
                x -= dir[j][0];
                y -= dir[j][1];
            }
        }
        // 겨울
        winter();
        q.clear();
        for (int i = 0; i < alive.size(); i++) {
            q.push_back(alive[i]);
        }
        
        alive.clear();
        dead.clear();
        five.clear();
    }
    
    cout << q.size() << endl;
}
