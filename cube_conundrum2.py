# Advent of Code 2023: Problem 2, Part 2

colours = {
    'red': 0,
    'green': 0,
    'blue': 0,
}

result = 0

with open("test.txt") as f:
    game_number = 1

    for line in f:
        colours['red'] = 0
        colours['green'] = 0
        colours['blue'] = 0

        for pair in line[line.find(":") + 1:].strip().replace(";", ",").split(","):
            count, colour = pair.strip().split(" ")
            colours[colour] = max(colours[colour], int(count))

        print(colours)
        result += colours['red'] * colours['green'] * colours['blue']

print(result)
