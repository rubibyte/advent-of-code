"""

Part 2:

(total disk space is 70000000, total free disk space needed is 30000000)

Find the smallest directory that, if deleted, would free up enough 
space on the filesystem to run the update. What is the total size 
of that directory?

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

space_to_free = 30000000 - (70000000 - directories['/'])
dir_to_free = 0
for d in directories:
    if not dir_to_free or space_to_free <= directories[d] < directories[dir_to_free]:
        dir_to_free = d

print("What is the total size of that directory?\n\n\
Answer:", directories[dir_to_free])


