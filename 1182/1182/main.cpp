//
//  main.cpp
//  1182
//
//  Created by 이운형 on 04/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int n,s;
    scanf("%d %d",&n,&s);
    
    int a[21];
    for (int i = 0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    
    int sum, result = 0;
    for (int i=1; i<(1<<n); i++) {
        sum = 0;
        for (int k = 0; k < n; k++) {
            if (i & (1<<k)) {
                sum += a[k];
            }
        }
        if (sum == s) {
            result+=1;
        }
    }
    printf("%d\n",result);
}
