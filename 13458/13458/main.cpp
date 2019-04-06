//
//  main.cpp
//  13458
//
//  Created by 이운형 on 06/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
using namespace std;

int a[1000000];
int n,b,c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i<n; i++) cin >> a[i];
    cin >> b >> c;
    
    long long ans = n;;
    for (int i = 0; i<n; i++) {
        a[i]-=b;
        if (a[i]>0) ans = ans +a[i]/c + (a[i]%c>0?1:0);
    }
    printf("%lld\n",ans);
}
