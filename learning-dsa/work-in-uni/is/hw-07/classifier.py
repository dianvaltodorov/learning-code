from cached_property import cached_property


class BayesClassifier(object):

    def __init__(self, politician_votes):
        self.politician_votes = politician_votes

    @cached_property
    def republican_votes(self):
        republican_votes = [
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
        ]
        for p in self.politician_votes:
            if p[16] == 'republican':
                for idx, vote in enumerate(p[:-1]):
                    republican_votes[idx][vote] += 1
        return republican_votes

    @cached_property
    def democrat_votes(self):
        democrat_votes = [
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
            {'y': 0, 'n': 0, '?': 0},
        ]
        for p in self.politician_votes:
            if p[16] == 'democrat':
                for idx, vote in enumerate(p[:-1]):
                    democrat_votes[idx][vote] += 1
        return democrat_votes

    @cached_property
    def republican_count(self):
        count = 0
        for p in self.politician_votes:
            if p[16] == 'republican':
                count += 1
        return count

    @cached_property
    def democrat_count(self):
        count = 0
        for p in self.politician_votes:
            if p[16] == 'democrat':
                count += 1
        return count

    @cached_property
    def politician_count(self):
        return len(self.politician_votes)

    def republican_probability(self, vs):
        numerator = 1
        denominator = 1
        for idx, vote in enumerate(vs[:-1]):
            numerator = numerator * self.republican_votes[idx][vote]
        numerator = numerator * self.republican_count
        denominator = (self.republican_count ** len(vs[:-1])) * len(self.politician_votes)
        return float(numerator) / denominator

    def democrat_probability(self, vs):
        numerator = 1
        denominator = 1
        for idx, vote in enumerate(vs[:-1]):
            numerator = numerator * self.democrat_votes[idx][vote]
        numerator = numerator * self.democrat_count
        denominator = (self.republican_count ** len(vs[:-1])) * len(self.politician_votes)
        return float(numerator) / denominator

    def classify(self, vs):
        if self.republican_probability(vs) > self.democrat_probability(vs):
            return 'republican'
        else:
            return 'democrat'