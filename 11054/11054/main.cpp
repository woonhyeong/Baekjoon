//
//  main.cpp
//  11054
//
//  Created by 이운형 on 2019/10/17.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int asc[1001];
    int desc[1001];
    int seq[1001];
    
    int n;
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) scanf("%d",&seq[i]);
    
    for (int i = 1, di = n; i <= n; i++, di--) {
        asc[i] = 1;
        desc[di] = 1;
        for (int k = 1; k < i; k++) {
            if (seq[k] < seq[i] && asc[k]+1 > asc[i]) {
                asc[i] = asc[k] + 1;
            }
        }
        
        for (int k = n; k > di; k--) {
            if (seq[k] < seq[di] && desc[k]+1 > desc[di]) {
                desc[di] = desc[k] + 1;
            }
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (ans < asc[i] + desc[i] - 1) {
            ans = asc[i] + desc[i] - 1;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
