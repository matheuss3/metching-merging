file = open('V1', 'w')
file2 = open('V2', 'w')

for i in (range(1000000)):
  file.write(f'{str(i)}\n')
  
  if (i % 2 == 0):
    file2.write(f'{str(i)}\n')

file.close()
file2.close()