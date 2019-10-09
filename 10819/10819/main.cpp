//
//  main.cpp
//  10819
//
//  Created by 이운형 on 03/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[8];
int n;

void input() {
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
}

void solve() {
    int max_sum = 0;
    
    sort(a,a+n);
    
    do {
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += (a[i] - a[i+1]>0 ? a[i]-a[i+1] : a[i+1]-a[i]);
        }
        
        if (max_sum < sum) {
            max_sum = sum;
        }
    } while (next_permutation(a,a+n));
    
    printf("%d\n",max_sum);
}

int main() {
    input();
    solve();
}
