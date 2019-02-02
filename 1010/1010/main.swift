//
//  main.swift
//  1010
//
//  Created by 이운형 on 03/02/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

let testCount = Int(readLine()!)!

for _ in 1...testCount {
    let input = readLine()!.split(separator: " ").map{Int($0)!}
    let m = input[1]
    var n = input[0]
    var standard = 0
    
    if m - n > n {
        standard = n
    } else {
        standard = m - n
        n = m - n
    }
    var n1 = 1, n2 = 1
    
    for i  in 0..<standard {
        n1 *= (m - i)
    }
    
    for i in 0..<n {
        n2 *= (n - i)
    }
    
    print(n1/n2)
}
