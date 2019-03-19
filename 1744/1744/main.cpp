//
//  main.cpp
//  1744
//
//  Created by 이운형 on 19/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[10002];
int main() {
    int n, result=0;
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
    }
    
    sort(arr+1, arr+n+1);
    arr[0] = -10001;
    arr[n+1] = 10001;
    
    for(int i = 1; i <= n; i+=2) {
        if(arr[i]>=0) break;
        
        if (arr[i+1] <= 0) {
            result += arr[i]*arr[i+1];
        } else result += arr[i];
    }
    
    for(int i = n; i>0; i-=2) {
        if (arr[i] <=0) break;
        
        if (arr[i-1] >= 1) {
            result += arr[i]*arr[i-1];
            if (arr[i-1] == 1) result++;
        } else result += arr[i];
    }
    
    printf("%d\n", result);
    return 0;
}
