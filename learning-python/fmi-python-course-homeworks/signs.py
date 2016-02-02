western_signs = [(120, 'capricorn'), (219, 'aquarius'), (320, 'pisces'),
                 (420, 'aries'), (520, 'taurus'), (620, 'gemini'),
                 (722, 'cancer'), (822, 'leo'), (922, 'virgo'),
                 (1022, 'libra'), (1121, 'scorpio'), (1221, 'sagittarius'),
                 (1231, 'capricorn')]

chinese_signs = ("rat", "ox", "tiger", "rabbit", "dragon",
                 "snake", "horse", "sheep", "monkey", "rooster", "dog", "pig")


def interpret_western_sign(day, month):
    for sign in western_signs:
        if month * 100 + day <= sign[0]:
            return sign[1]


def interpret_chinese_sign(year):
    return chinese_signs[year % 1900 % 12]


def interpret_both_signs(day, month, year):
    return interpret_western_sign(day, month), interpret_chinese_sign(year)
