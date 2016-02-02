def is_palindrome(candidate):
    return candidate == candidate[::-1]

def position_for_removeal(word):
    low = 0
    high = len(word) - 1
    while word[low] == word[high]:
        low += 1
        high -= 1

    if is_palindrome(word[low: high]):
        return high
    if is_palindrome(word[low + 1: high + 1]):
        return low
    
    return -1

if __name__ == "__main__":
    print is_palindrome('asdf')
    print is_palindrome('aba')
    word = 'abbcaZacxbba'
    idx = position_for_removeal(word)
    print idx, word[idx] 