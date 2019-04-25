//
//  main.cpp
//  14803
//
//  Created by 이운형 on 25/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <algorithm>
#define P pair<int,int>
using namespace std;

bool cmp(const P &A, const P &B) {
    if (A.first == B.first) {
        return A.second < B.second;
    }
    return A.first < B.first;
}

void solve(vector<P> horse, int D, int N) {
    double hours = (D-horse[0].first)/(double)horse[0].second;
    
    for (int i = 1; i < horse.size(); i++) {
        hours = max(hours, (D-horse[i].first)/(double)horse[i].second);
    }
    
    printf("Case #1: %.6lf\n", D/hours);
}

int main() {
    int T;
    scanf("%d",&T);
    
    while (T--) {
        int D, N;
        scanf("%d %d", &D, &N);
        
        vector<P> horse;
        for (int i = 0; i < N; i++) {
            int dist, speed;
            scanf("%d %d", &dist, &speed);
            horse.push_back({dist,speed});
        }
        
        if (horse.size() > 1) sort(horse.begin(), horse.end(), cmp);
        solve(horse, D, N);
    }
}
