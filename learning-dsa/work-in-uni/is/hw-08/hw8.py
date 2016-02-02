import csv
import math
from collections import defaultdict

OUTCOME = 'play'
with open('example.csv') as csvfile:
    reader = csv.DictReader(csvfile, delimiter=',')
    rows = [row for row in reader]


class Node(object):

    def __init__(self, label=None):
        self.label = label
        self.children = []


def skeleton():
    table = {}
    for r in rows:
        for a, v in r.iteritems():
            if a not in table:
                table[a] = {}
            table[a][v] = 0
    return table


def attributes():
    attrs = {}
    for r in rows:
        for attribute, value in r.iteritems():
            if attribute not in attrs:
                attrs[attribute] = set()
            attrs[attribute].add(value)
    return attrs


def frequency_table(rows):
    table = skeleton()
    for r in rows:
        for a, v in r.iteritems():
            table[a][v] += 1
    return table


def enthropy(attribute_table):
    enth = 0.0
    elements_count = sum([v for v in attribute_table.values()])
    for x, count in attribute_table.iteritems():
        if count != 0:
            enth = enth - count / \
                float(elements_count) * \
                math.log(count / float(elements_count), 2)
    return enth


def best_attribute(docs, unused_attrs):
    table = frequency_table(docs)
    enth = enthropy(table[OUTCOME])
    gains = []
    for attr in unused_attrs:
        stats = table[attr]
        gain = enth
        for s in stats:
            filtered_rows = [r for r in rows if r[attr] == s]
            freq_table = frequency_table(filtered_rows)
            s_enth = enthropy(freq_table['play'])
            gain = gain - len(filtered_rows) / float(len(rows)) * s_enth

        gains.append((gain, attr))
    return max(gains)[1]


def id3(docs, target_attribute, unused_attributes):
    table = frequency_table(docs)

    for val, count in table[OUTCOME].iteritems():
        if count == len(docs):
            return Node(label=val)

    if not unused_attributes:
        return Node(label=max(table[OUTCOME], key=table[OUTCOME].get))

    best = best_attribute(docs, unused_attributes)
    node = Node(label=best)

    for value in attributes()[best]:
        node.children.append(Node(label=value))
        count = table[best].get(value, 0)
        if count == 0:
            child =  Node(label=max(table[OUTCOME], key=table[OUTCOME].get))
        else:
            subset_docs = [d for d in docs if d[best] == value]
            ua = list(unused_attributes)
            ua.remove(best)
            # node.children.append(id3(subset_docs, OUTCOME, ua))
    unused_attributes.remove(best)
    return node


attrs =  rows[0].keys()
attrs.remove(OUTCOME)
node =  id3(rows, OUTCOME, attrs)
import ipdb; ipdb.set_trace()