import sys

n, m = list(map(int, sys.stdin.readline().rstrip().lstrip().split()))
cows = list(map(int, sys.stdin.readline().rstrip().lstrip().split()))
candies = list(map(int, sys.stdin.readline().rstrip().lstrip().split()))

for k in candies:
    # print(f"\nCows {cows}")
    candy = [0, k]
    for i, cow in enumerate(cows):
        # print(f"Candy is at {candy}")
        # End loop
        if candy[0] == candy[1]:
            break

        # Check if height is enough
        if cow >= candy[0]:
            if cow >= candy[1]:
                grew = candy[1] - candy[0]
            else:
                grew = (cow - candy[0])

            candy[0] += grew
            cows[i] += grew

            # print(f"Cow grew by {grew}, it is now {cows[i]}\n")

for cow in cows:
    print(cow)
