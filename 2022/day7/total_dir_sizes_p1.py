"""

Part 1:

(size includes directory and subdirectory file sizes, which is the number
before the filename)

Find all of the directories with a total size of at most 100000. 
What is the sum of the total sizes of those directories?

"""

file = open("input.txt", "r")
line = True
directories = dict()
current_path = False;
temp = 0
while line:
    line = file.readline()
    if '$ cd' in line:
        line = line.split()
        if temp and not directories[current_path]:
            directories[current_path] += temp
            temp = 0
        if not current_path:
            current_path = line[2]
        else:
            if '..' not in line:
                if current_path != '/':
                    current_path = current_path + '/' + line[2]
                else:
                    current_path = current_path + line[2]
            else:
                current_path = current_path.split('/')
                current_path.pop()
                if len(current_path) == 1:
                    current_path = '/'
                else:
                    current_path = '/'.join(current_path)
        if not directories.get(current_path):
            directories[current_path] = 0
    elif line and line.split()[0].isdigit():
        line = line.split()
        temp += int(line[0])
    elif not line and temp and not directories[current_path]:
        directories[current_path] += temp
        temp = 0

for d in directories:
    for dr in directories:
        if d in dr and d is not dr:
            directories[d] += directories[dr]

total_dir_sizes = 0
for d in directories:
    if directories[d] <= 100000:
        total_dir_sizes += directories[d]

print("What is the sum of the total sizes of those directories?\n\n\
Answer:", total_dir_sizes)


