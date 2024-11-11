import sys

n = int(sys.stdin.readline().rstrip().lstrip())
cows = sys.stdin.readline().rstrip().lstrip()


def min_initial_infections(n, bitstring):
    consecutive_sequences = [len(seq) for seq in bitstring.split('0') if seq != '']
    return min(consecutive_sequences) if consecutive_sequences else 0


# Easiest case
if cows == n * "1":
    print(1)
elif cows == n * "0":
    print(0)
elif (cows.find("010") != -1) or (cows[-1] == "1" and cows[-2] == '0'):
    print(len(cows.replace('0', '')))
else:
    # print(f"{(cows[-1] == "1" and cows[-2] == 0)}")
    # Normal cases
    print(min_initial_infections(n, cows))
