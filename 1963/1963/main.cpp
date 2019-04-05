//
//  main.cpp
//  1963
//
//  Created by 이운형 on 04/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <queue>
#include <string>
#include <string.h>
using namespace std;

bool prime[10050];
bool check[10050];
int dist[10050];

void makePrime() {
    for (int i = 2; i < 10001; i++) {
        if (!prime[i]) {
            for (int j = i*i; j < 10001; j+=i) {
                prime[j] = true;
            }
        }
    }
    for (int i = 0; i < 10001; i++) {
        prime[i] = !prime[i];
    }
}

void bfs() {
    int n, k;
    scanf("%d %d",&n,&k);
    memset(dist, 0, sizeof(dist));
    memset(check, false, sizeof(check));
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    check[n] = true;
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        
        for (int i = 0 ; i<4; i++) {
            for (int k = 0; k<=9; k++) {
                if (i == 0 && k == 0) {
                    continue;
                }
                string s = to_string(temp);
                s[i] = '0'+k;
                int next = stoi(s);
                if (prime[next] && !check[next]) {
                    q.push(next);
                    dist[next] = dist[temp] + 1;
                    check[next] = true;
                }
            }
        }
    }
    printf("%d\n",dist[k]);
}

int main() {
    makePrime();
    
    int t;
    scanf("%d",&t);
    while (t--) {
        bfs();
    }
}

