//
//  main.cpp
//  1201
//
//  Created by 이운형 on 20/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//
/*
 n, m, k 에 대해 최대의 경우는 n을 k개수만큼의 내림차순 수열이 m개 있는 경우이다. m*k
 최소의 경우 m의 오름차순 k의 내림차순이다. 다만, 곂치는 수 1개를 뺀다. m+k-1
 */
#include <stdio.h>

int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    
    if (m+k-1 > n || n > m*k) {
        printf("%d\n",-1);
    } else {
        int q = (n-k)/(m-1), r = (n-k)%(m-1), j = 0;
        
        if (m-1 == 0) {
            q = 1;
            r = 0;
        }
        
        for (int i = k; i < n+1; i+=q) {
            for (int u = 0; u < i-j; u++) {
                printf("%d ",i-u);
            }
            j = i;
            if (r > 0) {
                i++;
                r--;
            }
        }
    }
}

