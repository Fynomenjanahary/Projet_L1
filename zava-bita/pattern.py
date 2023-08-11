import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
text = input()

for i in range(len(text)-n+1):
    print(text[i:i+n])
