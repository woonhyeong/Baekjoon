//
//  main.swift
//  1000
//
//  Created by 이운형 on 21/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

import Foundation

if let input = readLine() {
    print(input.split(separator: " ").map{ Int($0)! }.reduce(0){$0 + $1})
}

