class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        position = [0, 0]
        for i in moves:
            if i == 'L':
                position[0] -= 1
            if i == 'R':
                position[0] += 1
            if i == 'U':
                position[1] += 1
            if i == 'D':
                position[1] -= 1
        if position == [0, 0]:
            return True
        else :
            return False
