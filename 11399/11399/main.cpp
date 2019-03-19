//
//  main.cpp
//  11399
//
//  Created by 이운형 on 17/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    
    int arr[(int)1e3], n, result = 0, sum = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    
    for (int i = 0; i < n; i ++) {
        sum += arr[i];
        result += sum;
    }
    
    cout << result << endl;
    return 0;
}
