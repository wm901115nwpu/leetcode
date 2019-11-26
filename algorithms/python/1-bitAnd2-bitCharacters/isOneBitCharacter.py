class Solution(object):
    def isOneBitCharacter(self, bits):
        i = 0
        while i < len(bits):
            if bits[i] == 0:
                i += 1
            if i >= len(bits): return True
            if bits[i] == 1:
                i += 2
            if i >= len(bits): return False
            if i == len(bits) - 1: return True
def main():
    fun1 = Solution()
    print(fun1.isOneBitCharacter([1, 1, 1, 0]))

if __name__ == '__main__':
    main()
