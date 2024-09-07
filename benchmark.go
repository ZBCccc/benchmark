package main

import (
	"crypto/hmac"
	"crypto/sha256"
	"fmt"
	"time"
)

const (
	KEY        = "secret_key"
	MESSAGE    = "Hello, World!"
	ITERATIONS = 1000
)

func main() {
	start := time.Now()

	for i := 0; i < ITERATIONS; i++ {
		mac := hmac.New(sha256.New, []byte(KEY))
		mac.Write([]byte(MESSAGE))
		mac.Sum(nil)
	}

	duration := time.Since(start)
	fmt.Printf("Go: HMAC operation executed %d times in %v seconds\n", ITERATIONS, duration.Seconds())
}