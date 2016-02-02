from collections import defaultdict


class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        counts = defaultdict(int)
        for cpd in cpdomains:
            hits, dom = cpd.split(' ')
            for d in all_domains(dom):
                counts[d] += hits


def all_domains(domain):
    domains = []
    parts = domain.split('.')

    for p in range(len(parts)):
        domains.append('.'.join(parts[-p:]))

    return domains
