import sys

max_days_limit = 100000
t = int(sys.stdin.readline())


def count_taller_trees(lst, threshold):
    return sum(1 for value in lst if value > threshold)


def test_target(n, heights, target):
    for k in range(n):
        if not (count_taller_trees(heights, heights[k]) == target[k]):
            return False
    return True


for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    heights = list(map(int, sys.stdin.readline().rstrip().split()))
    genetics = list(map(int, sys.stdin.readline().rstrip().split()))
    target = list(map(int, sys.stdin.readline().rstrip().split()))

    current_days = 0  # Variable to track the current number of days
    failed_counter = 0

    for i in range(max_days_limit):
        if test_target(n, heights, target):
            print(i)
            current_days = i
            break
        else:
            failed_counter += 1

        for j in range(n):
            heights[j] += genetics[j]

        if failed_counter >= 200:
            print(-1)
            break

    else:
        # If the loop completes without a break, the condition is never satisfied
        print(-1)

    # Subtract the current number of days from the max_days_limit
    max_days_limit -= current_days
