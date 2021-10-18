import random

arr1 = []
arr2 = []
arr3 = []

for i in range(100000):
  arr1.append(random.randint(0, 999999))
  arr2.append(random.randint(0, 999999))
  arr3.append(random.randint(0, 999999))

arr1.sort()
arr2.sort()
arr3.sort()

file = open('V1', 'w')
file2 = open('V2', 'w')
file3 = open('V3', 'w')

for i in range(100000):
  file.write(f'{str(arr1[i])}\n')
  file2.write(f'{str(arr2[i])}\n')
  file3.write(f'{str(arr3[i])}\n')

file.close()
file2.close()
file3.close()