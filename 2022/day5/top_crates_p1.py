"""
Part 1:

(the crane can move only one crate at a time)

After the rearrangement procedure completes, what crate 
ends up on top of each stack?

"""

file = open("input.txt", "r")
line = True;
crate_stacks = list([] for i in range(9))
while line:
    line = file.readline()
    if ']' in line:
        for i in range(len(line)):
            if line[i].isalpha():
                crate_stacks[int(i / 4)].append(line[i])
    if 'move' in line:
        line = line.split()
        for i in range(int(line[1])):
            crate_stacks[int(line[5]) - 1].insert(0, crate_stacks[int(line[3]) - 1].pop(0))

print("After the rearrangement procedure \
completes, what crate ends up on top of each stack?\n\nAnswer:", end="")
for i in range(len(crate_stacks)):
    print(crate_stacks[i][0], end="")
print("")
