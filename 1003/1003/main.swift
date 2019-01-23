//
//  main.swift
//  1003
//
//  Created by 이운형 on 23/01/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

func fibonacci(_ n:Int) -> (Int, Int) {
    if n == 0 {
        return (1,0)
    } else if n == 1 {
        return (0,1)
    } else if n == 2{
        return (1,1)
    } else {
        var n1 = 1, n2 = 1, n3 = 2
        for _ in 3...n {
            n3 = n1 + n2
            n1 = n2
            n2 = n3
        }
        return (n1, n2)
    }
}

let count = Int(readLine()!)!
for _ in 1...count {
    let n = Int(readLine()!)!
    let result = fibonacci(n)
    print("\(result.0) \(result.1)")
}

/*
// 처음에 성공했던 코드
extension Collection{
    subscript(optional i: Int) -> Bool {
        return self.count > i
    }
}
var array = [1,1]

func fibonacci(_ n:Int) -> Int {
    if array[optional: n]{
        return array[n]
    } else {
        array.append(fibonacci(n-1) + fibonacci(n-2))
        return array[n]
    }
}

let count = Int(readLine()!)!
for _ in 1...count {
    let n = Int(readLine()!)!
    fibonacci(n)
    if n == 0 {
        print("1 0")
    } else if n == 1 {
        print("0 1")
    } else {
        print("\(array[n-2]) \(array[n-1])")
    }
}
*/
