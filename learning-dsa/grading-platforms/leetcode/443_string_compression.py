class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        i = 0
        n = len(chars)
        res = []
        j = 0
        while i < n:

            current_c = chars[i]
            chars[j] = current_c
            current_count = 0
    
            while i < n and current_c == chars[i]:
                i += 1
                current_count += 1

            if current_count == 1:
                continue

            st = []
            while current_count:
                st.append(current_count % 10)
                current_count = current_count // 10

            while st:
                chars[j] = st.pop()
                j += 1

        print(chars)
        return len(chars)


s = Solution()
print(s.compress(["a", "a", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "b", "c", "c", "c"]))
print(s.compress(["a"]))
print(s.compress(["a", "b", "c"]))
