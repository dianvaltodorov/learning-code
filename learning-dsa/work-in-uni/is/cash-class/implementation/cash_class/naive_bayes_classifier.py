from cached_property import cached_property


class NaiveBayesClassifier(object):

    def __init__(self, instances):
        self.instances = instances
        self.above_bucket, self.below_bucket = self.train()

    def buckets(self, attr):
        return {a: 0 for a in set([inst[attr] for inst in self.instances])}

    @cached_property
    def attributes(self):
        attributes = self.instances[0].keys()
        attributes.pop(attributes.index('income'))
        return attributes

    @cached_property
    def above_len(self):
        return len(self.above_instances)

    @cached_property
    def below_len(self):
        return len(self.below_instances)

    @cached_property
    def above_instances(self):
        return [inst for inst in self.instances if inst['income'] == '>50K']

    @cached_property
    def below_instances(self):
        return [inst for inst in self.instances if inst['income'] == '<=50K']

    def bucket_map(self):
        return {attr: self.buckets(attr) for attr in self.attributes}

    def train(self):
        above_bucket = self.bucket_map()
        below_bucket = self.bucket_map()
        for inst in self.instances:
            for attribute, value in inst.iteritems():
                if attribute == 'income':
                    continue
                if inst['income'] == '>50K':
                    above_bucket[attribute][value] += 1
                else:
                    below_bucket[attribute][value] += 1

        return above_bucket, below_bucket

    def probability_above(self, instance):
        numerator = 1
        denom = 1
        for attribute, value in instance.iteritems():
            if attribute == 'income':
                continue
            numerator = numerator * self.above_bucket[attribute][value]
        numerator = numerator * self.above_len
        denom = (self.above_len ** len(self.attributes)) * len(self.instances)
        return float(numerator) / denom

    def probabilty_below(self, instance):
        numerator = 1
        denom = 1
        for attribute, value in instance.iteritems():
            if attribute == 'income':
                continue
            numerator = numerator * self.below_bucket[attribute][value]
        numerator = numerator * self.below_len
        denom = (self.below_len ** len(self.attributes)) * len(self.instances)
        return float(numerator) / denom

    def predict(self, inst):
        if self.probability_above(inst) > self.probabilty_below(inst):
            return '>50K'
        else:
            return '<=50K'
