def min_days_to_satisfy_request(N, heights, growth_rates, request):
    days = 0
    satisfied = [0] * N

    while True:
        for i in range(N):
            heights[i] += growth_rates[i]

        for i in range(N):
            taller_count = sum(heights[j] > heights[i] for j in range(N) if j != i)
            if taller_count != request[i]:
                break
        else:
            return days

        days += 1

        if days > 1000:  # Set a limit to avoid infinite loop
            return -1


# Read input
T = int(input())

for _ in range(T):
    N = int(input())
    heights = list(map(int, input().split()))
    growth_rates = list(map(int, input().split()))
    request = list(map(int, input().split()))

    result = min_days_to_satisfy_request(N, heights, growth_rates, request)
    print(result)
