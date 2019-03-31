//
//  main.cpp
//  1939
//
//  Created by 이운형 on 28/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector< pair<int, int> > map[10001];
bool isVisit[10001];
int st, dst;

bool travel(int cost) {
    queue<int> q;
    q.push(st);
    isVisit[st] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        if (curr == dst) return true;
        
        for (int i = 0; i < map[curr].size(); i++) {
            int next = map[curr][i].first;
            int nextCost = map[curr][i].second;
            
            if (!isVisit[next] && cost<=nextCost) {
                isVisit[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    
    int min = 1, max = 0;
    for (int i = 0; i<m; i++) {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        map[x].push_back(make_pair(y, z));
        map[y].push_back(make_pair(x, z));
        if (z > max) max = z;
    }
    scanf("%d %d",&st,&dst);
    
    int mid = 0;
    while (min <= max) {
        mid = (min + max)/2;
        memset(isVisit, false, sizeof(isVisit));
        if (travel(mid)) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    
    printf("%d\n", max);
}
