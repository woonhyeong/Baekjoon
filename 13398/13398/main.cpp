//
//  main.cpp
//  13398
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int left[100001];
int right[100001];
int seq[100001];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d",&seq[i]);
    }
    
    right[n] = seq[n];
    for (int li = 1, ri = n-1; li <= n; li++, ri--) {
        left[li] = max(left[li-1]+seq[li], seq[li]);
        right[ri] = max(right[ri+1]+seq[ri], seq[ri]);
    }
    
    int ans2 = INT_MIN, ans1 = INT_MIN;
    for (int i = 1; i <=n; i++) {
        ans1 = max(ans1, left[i]);
        if (i == 1 || i == n) {
            continue;
        }
        ans2 = max(ans2, left[i-1] + right[i+1]);
    }
    printf("%d\n",max(ans1,ans2));
    return 0;
}
