class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<int, unordered_map<int, int>> bestSteps;
        return tryLock(0, 0, ring, key, INT_MAX, bestSteps);
    }

private:
    int countSteps(int curr, int next, int ringLength) {
        int stepsBetween = abs(curr - next);
        int stepsAround = ringLength - stepsBetween;
        return min(stepsBetween, stepsAround);
    }

    int tryLock(int ringIndex, int keyIndex, string ring, string key, int minSteps,
                unordered_map<int, unordered_map<int, int>>& bestSteps) {
        if (bestSteps[ringIndex][keyIndex]) {
            return bestSteps[ringIndex][keyIndex];
        }
        if (keyIndex == key.length()) {
            return 0;
        }
        for (int charIndex = 0; charIndex < ring.length(); charIndex++) {
            if (ring[charIndex] == key[keyIndex]) {
                int totalSteps = countSteps(ringIndex, charIndex, ring.length()) + 1
                                            + tryLock(charIndex, keyIndex + 1, ring, key, INT_MAX, bestSteps);
                minSteps = min(minSteps, totalSteps);
                bestSteps[ringIndex][keyIndex] = minSteps;
            }
        }
        return minSteps;
    }
};