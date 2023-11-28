from itertools import permutations

def ge_per(elements):
    per_list = list(permutations(elements))
    
    for n in per_list:
        print(n)

elements = [1, 2, 3]
print("Original List:", elements)

ge_per(elements)