from bisect import bisect_right

def climbingLeaderboard(ranked, player):
    # Write your code here
    s = set(ranked)
    ranked = [e for e in s]
    ranked.sort()
    out = []
    for score in player:
        out.append(len(ranked) - bisect_right(ranked, score) + 1)

    return out

print(climbingLeaderboard([100,100,50,40,40,20,10],[5,25,50,120]))