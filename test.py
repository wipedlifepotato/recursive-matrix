#!/bin/env python3
max_depth=900
counter=0
def fun(m):
    global counter
    counter=counter+1
    if counter == max_depth: return m
    return (m),fun(m)

M=()
M=( fun(M) )
print("your(0) M:")
print( M )
