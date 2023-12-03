# Advent of Code 2023: Problem 2

colours = {
    'red': 12,
    'green': 13,
    'blue': 14,
}

result = 0

with open("test.txt") as f:
    game_number = 1

    for line in f:
        valid = True 

        for pair in line[line.find(":") + 1:].strip().replace(";",",").split(","):
            count, colour = pair.strip().split(" ")
            if int(count) > colours[colour]:
                print(f"Invalid game: {game_number}")
                valid = False
                break


        if valid: 
            result += game_number
        game_number += 1

print(result)
