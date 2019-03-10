//
//  main.swift
//  2448
//
//  Created by 이운형 on 09/03/2019.
//  Copyright © 2019 201302458. All rights reserved.
//

let testCount = Int(readLine()!)!
var result:[String] = Array(repeating: "", count: testCount)


func triangle(_ s:Int, _ e: Int) {
    var k = 0
    for i in s..<e {
        result[i] += result[k]
        k += 1
    }
    
    unTriangle(s,e)
    
    k = 0
    for j in s..<e {
        result[j] += result[k]
        k += 1
    }
    
    if e == testCount {
        return
    }
    
    triangle(e,e*2)
}

func unTriangle(_ s: Int, _ e: Int) {
    var i = e-s
    var k = 0
    
    while i > 0 {
        result[s+k] += whiteSpace(i*2 - 1)
        i -= 1
        k += 1
    }
}

func whiteSpace(_ n : Int) -> String {
    var r: String = ""
    
    for _ in 0..<n {
        r += " "
    }
    
    return r
}

result[0] = "*"
result[1] = "* *"
result[2] = "*****"

if testCount > 3 {
    triangle(3,6)
}

var resultPrint:String = ""

for i in 0..<testCount {
    resultPrint += (whiteSpace(testCount - i - 1) + result[i] + whiteSpace(testCount - i - 1))
    if i != testCount-1 {
        resultPrint += "\n"
    }
}

print(resultPrint)
