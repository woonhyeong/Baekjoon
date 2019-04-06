//
//  main.cpp
//  2048
//
//  Created by 이운형 on 05/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

int n;
int result;
// 상 하 좌 우 0 1 2 3
void dfs(int dir, int cnt, int arr[21][21]) {
    if (cnt == 5) {
        for (int i = 0; i<n; i++) {
            for (int k = 0; k<n; k++) {
                result = max(result, arr[i][k]);
            }
        }
        return;
    }
    
    int next[21][21];
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<n; k++) {
            next[i][k] = arr[i][k];
        }
    }
    
    if (dir == 0) {
        for (int i = 0 ; i < n; i++) {
            queue<int> q;
            for (int k = 0; k < n; k++) {
                if (next[k][i]) q.push(next[k][i]);
                next[k][i] = 0;
            }
            
            int idx = 0;
            while (!q.empty()) {
                int item = q.front(); q.pop();
                
                if (next[idx][i] == 0) {
                    next[idx][i] = item;
                } else if (next[idx][i] == item) {
                    next[idx][i] *= 2;
                    idx += 1;
                } else {
                    idx += 1;
                    next[idx][i] = item;
                }
            }
        }
    } else if (dir == 1) {
        for (int i = 0 ; i < n; i++) {
            queue<int> q;
            for (int k = n-1; k >= 0; k--) {
                if (next[k][i]) q.push(next[k][i]);
                next[k][i] = 0;
            }
            
            int idx = n-1;
            while (!q.empty()) {
                int item = q.front(); q.pop();
                
                if (next[idx][i] == 0) {
                    next[idx][i] = item;
                } else if (next[idx][i] == item) {
                    next[idx][i] *= 2;
                    idx -= 1;
                } else {
                    idx -= 1;
                    next[idx][i] = item;
                }
            }
        }
    } else if (dir == 2) {
        for (int i = 0; i<n; i++) {
            queue<int> q;
            for (int k = 0; k<n; k++) {
                if(next[i][k]) q.push(next[i][k]);
                next[i][k] = 0;
            }
            
            int idx = 0;
            while (!q.empty()) {
                int item = q.front(); q.pop();
                if (next[i][idx] == 0) {
                    next[i][idx] = item;
                } else if (next[i][idx] == item) {
                    next[i][idx] *= 2;
                    idx += 1;
                } else {
                    idx += 1;
                    next[i][idx] = item;
                }
            }
        }
    } else if (dir == 3) {
        for (int i = 0; i<n; i++) {
            queue<int> q;
            for (int k = n-1; k>=0; k--) {
                if (next[i][k]) q.push(next[i][k]);
                next[i][k] = 0;
            }
            int idx = n-1;
            
            while (!q.empty()) {
                int item = q.front(); q.pop();
                if (next[i][idx] == 0) {
                    next[i][idx] = item;
                } else if(next[i][idx] == item) {
                    next[i][idx] *= 2;
                    idx-=1;
                } else {
                    idx -= 1;
                    next[i][idx] = item;
                }
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        dfs(i,cnt+1,next);
    }
}

int main() {
    scanf("%d",&n);
    int a[21][21];
    for (int i = 0; i<n; i++) {
        for (int k = 0; k<n; k++) {
            scanf("%d",&a[i][k]);
        }
    }
    
    for (int i = 0; i < 4; i++) {
        dfs(i,0,a);
    }
    printf("%d\n",result);
}
