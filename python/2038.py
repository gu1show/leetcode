# Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/
# Runtime: 280 ms
# Memory: 17.4 MB

class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alice_score, bob_score = 0, 0
        for i in range(1, len(colors) - 1):
            if colors[i - 1] == colors[i] == colors[i + 1] == 'A': alice_score += 1
            elif colors[i - 1] == colors[i] == colors[i + 1]: bob_score += 1
        
        return alice_score > bob_score
