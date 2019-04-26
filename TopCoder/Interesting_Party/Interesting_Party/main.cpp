//
//  main.cpp
//  Interesting_Party
//
//  Created by 이운형 on 26/04/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class InterestingParty {
public:
    int bestInvitation(vector<string> first, vector<string> second) {
        map<string, int> solution;
        
        for (int i = 0; i < first.size(); i++) {
            solution[first[i]] ++;
            solution[second[i]] ++;
        }
        
        int ans = 0;
        for (map<string,int>::iterator i = solution.begin(); i != solution.end(); i++) {
            ans = max(ans, i->second);
        }
        
        return ans;
    }
};

/* Example
int main() {
    
    vector<string> first = {"fishing", "gardening", "swiming", "fishing"};
    vector<string> second = {"huntinh", "fishing", "fishing", "biting"};
    
    InterestingParty i = InterestingParty();
    cout << i.bestInvitation(first, second)<<'\n';
    
    return 0;
}
 */
