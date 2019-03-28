//
//  main.cpp
//  2805
//
//  Created by 이운형 on 28/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    scanf("%d %d", &n, &m);
    
    vector<long long> tree(n);
    long long min = 0;
    long long max = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%lld", &tree[i]);
        if (tree[i] > max) max = tree[i];
    }
    
    long long r = 0;
    long long mid;
    while (min <= max) {
        mid = (min+max)/2;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) r += (tree[i] - mid);
        }
        
        if (r >= m) {
            min = mid+1;
        } else {
            max = mid-1;
        }
        r = 0;
    }
    printf("%lld\n", max);
}
