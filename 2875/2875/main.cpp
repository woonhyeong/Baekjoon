//
//  main.cpp
//  2875
//
//  Created by 이운형 on 19/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>

int main() {
    int n, m ,k, r = 0;
    scanf("%d %d %d",&n,&m,&k);
    
    r = (n/2 - m)==0 ? m : (n/2-m>0?m:n/2);
    n -= r*2;
    m -= r;
    k -= n+m;
    if(k>0) r -= k/3 + (k%3==0?0:1);
    
    printf("%d\n",r);
    return 0;
}
