"""

Part 1:

(the number represents the tree height)

Consider your map; how many trees are visible from outside the grid?

"""

file = open("input.txt", "r")
line = True
trees = list()
visible_trees = list()

while line:
    line = file.readline()
    if line:
        trees.append(list(int(n) for n in line if n.isdigit()))
        visible_trees.append(list(0 for n in line if n.isdigit()))

#columns from north to south
for i in range(len(trees[0])):
    biggest_tree = -1
    for j in range(len(trees)):
        if trees[j][i] > biggest_tree:
            visible_trees[j][i] = 1
            biggest_tree = trees[j][i]

#rows from west to east
for i in range(len(trees)):
    biggest_tree = -1
    for j in range(len(trees[0])):
        if trees[i][j] > biggest_tree:
            visible_trees[i][j] = 1
            biggest_tree = trees[i][j]

#rows from east to west
for i in range(len(trees)):
    biggest_tree = -1
    for j in range(len(trees[0])):
        if trees[i][len(trees[0]) - 1 - j] > biggest_tree:
            visible_trees[i][len(trees[0]) - 1 - j] = 1
            biggest_tree = trees[i][len(trees[0]) - 1 - j]

#columns from south to north
for i in range(len(trees[0])):
    biggest_tree = -1
    for j in range(len(trees)):
        if trees[len(trees) - 1 - j][i] > biggest_tree:
            visible_trees[len(trees) - 1 - j][i] = 1
            biggest_tree = trees[len(trees) - 1 - j][i]

total_visible_trees = 0
for i in range(len(visible_trees)):
    for j in range(len(visible_trees[0])):
        if visible_trees[i][j]:
            total_visible_trees += 1

print("How many trees are visible from outside the grid?\n\n\
Answer:", total_visible_trees)


