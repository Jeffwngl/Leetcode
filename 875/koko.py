def minEatingSpeed(self, piles: List[int], h: int) -> int:
    l = 1
    r = max(piles)
    k = 0

    while l <= r:
        mid = (l + r) // 2
        totalTime = 0
        for i in range(len(piles)):
            if piles[i] > 0 and mid > 0:
                totalTime += -(piles[i] // -mid)

        if totalTime <= h: # if koko can finish within h, we can make our eating
            r = mid - 1 # speed slower by searching the left side
            k = mid
        elif totalTime > h: # if koko cant finish, we need to increase eating
            l = mid + 1 # speed
    return k
