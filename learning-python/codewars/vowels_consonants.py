import string


def get_count(words=None):
    if type(words) is str:
        vowels = "aAeEuUiIoO"
        vowels_count = 0
        consonants_count = 0

        for c in words:
            if c in vowels:
                vowels_count += 1
            else:
                if c in string.letters:
                    consonants_count += 1

        return {'vowels': vowels_count,
                'consonants': consonants_count}
    else:
        return {'vowels': 0,
                'consonants': 0}

print get_count("HEre Is sOme text")
