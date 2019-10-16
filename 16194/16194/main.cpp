//
//  main.cpp
//  16194
//
//  Created by 이운형 on 2019/10/16.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int card[1001];
int p[10001];

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        card[i] = p[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (int k = 1; k < i; k++) {
            card[i] = min(card[i-k] + p[k], card[i]);
        }
    }
    
    printf("%d\n",card[n]);
    
    return 0;
}
