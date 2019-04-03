//
//  main.cpp
//  10819
//
//  Created by 이운형 on 03/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

int a[8];
int n;

bool next() {
    int i = n-1;
    while (i > 0 && a[i-1] >= a[i] ) i-=1;
    if (i <= 0) return false;
    
    int j = n-1;
    while (a[i-1] >= a[j]) j-=1;
    int temp = a[i-1];
    a[i-1] = a[j];
    a[j] = temp;
    
    j = n-1;
    while (i<j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i+=1;
        j-=1;
    }
    return true;
}

int main() {
    scanf("%d",&n);
    for (int i = 0; i<n; i++) scanf("%d",&a[i]);
    std::sort(a,a+n);
    int max = 0, r = 0;
    do {
        r = 0;
        for (int i = 1; i < n; i++) {
            r = r + (a[i-1]-a[i] > 0? a[i-1]-a[i]:-(a[i-1]-a[i]));
        }
        if (max < r) max = r;
    } while(next());
    printf("%d\n",max);
}
