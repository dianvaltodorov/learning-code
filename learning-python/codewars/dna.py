def complement(s):
    if s == 'T':
        return 'A'
    elif s == 'A':
        return 'T'
    elif s == 'C':
        return 'G'
    else:
        return 'C'


def DNA_strand(dna):
    return "".join([complement(x) for x in dna])

print DNA_strand("ATTACG")


def DNA_strand1(dna):
    reference = {"A": "T",
                 "T": "A",
                 "C": "G",
                 "G": "C"}
    return "".join([reference[x] for x in dna])


def DNA_strand(dna):
    return "".join([{'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}[l] for l in dna])
