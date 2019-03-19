//
//  main.cpp
//  1931
//
//  Created by 이운형 on 17/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define Con pair<int, int>
Con arr[(int)1e5];

int main() {
    int n, mid = 0, result = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr+n);
    
    for (int i = 0; i < n; i++) {
        if (arr[i].second < mid) {
            continue;
        } else {
            mid = arr[i].first;
            result ++;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
