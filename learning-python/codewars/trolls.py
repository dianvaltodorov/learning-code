# remove vowels from string
spam = "This website is for losers LOL!"
lowercase_vowels = "aoeiu"
uppercase_vowels = lowercase_vowels.upper()
all_vowels = lowercase_vowels + uppercase_vowels


def remove_vowels(x):
    res = [c for c in x if c not in all_vowels]
    return "".join(res)


print remove_vowels(spam)
