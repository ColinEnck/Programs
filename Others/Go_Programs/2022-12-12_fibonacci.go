package main

import "fmt"

func main() {
	var num float64 = 0
	var next float64 = 1
	fibonacci(num, next)
}

func fibonacci(num float64, next float64) {
	fmt.Println(num)
	var temp = num
	num = next
	next += temp
	fibonacci(num, next)
}
