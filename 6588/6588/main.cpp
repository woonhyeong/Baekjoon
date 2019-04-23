//
//  main.cpp
//  6588
//
//  Created by 이운형 on 23/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 1000001

bool prime[MAX_SIZE];

void make_prime() {
    for (int i = 2; i*i < MAX_SIZE; i++) {
        if(!prime[i]) {
            for (int k = i*i; k < MAX_SIZE; k+=i) {
                prime[k] = true;
            }
        }
    }
    prime[2] = true;
}

void solve(int num) {
    for (int i = 3; i <= num/2; i++) {
        if (!prime[i]) {
            if (!prime[num-i]) {
                printf("%d = %d + %d\n",num,i,num-i);
                break;
            }
        }
    }
}

int main() {
    make_prime();
    
    while(true) {
        int num;
        scanf("%d",&num);
        
        if (num == 0) break;
        solve(num);
    }
}
