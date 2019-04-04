//
//  main.cpp
//  1697
//
//  Created by 이운형 on 04/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
using namespace std;

const int MAX = 250000;
bool check[250001];
int dist[250001];
int n,k;

void bfs(int v) {
    check[v] = true;
    dist[v] = 0;
    queue<int> q;
    q.push(v);
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        
        if (temp == k) {
            return;
        }
        
        if (temp-1 >= 0 && !check[temp-1]) {
            q.push(temp-1);
            check[temp-1] = true;
            dist[temp-1] = dist[temp] + 1;
        }
        
        if (temp+1 <= MAX && !check[temp+1]) {
            q.push(temp+1);
            check[temp+1] = true;
            dist[temp+1] = dist[temp] + 1;
        }
        
        if (temp*2 <= MAX && !check[temp*2]) {
            q.push(temp*2);
            check[temp*2] = true;
            dist[temp*2] = dist[temp] + 1;
        }
    }
}

int main() {
    scanf("%d %d",&n,&k);
    bfs(n);
    printf("%d\n",dist[k]);
    return 0;
}
