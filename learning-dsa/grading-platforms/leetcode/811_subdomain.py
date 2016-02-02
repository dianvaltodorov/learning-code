class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        hits = {}
        for cpd in cpdomains:
            count, d = cpd.split(" ")

            splits = d.split('.')
            subdomains = ['.'.join(splits[-i:]) for i in range(1, len(splits) + 1)]

            for sd in subdomains:
                if sd in hits:
                    hits[sd] = hits[sd] + int(count)
                else:
                    hits[sd] = int(count)

        return [' '.join([str(v), k]) for k, v in hits.items()]





s = Solution()
print(s.subdomainVisits(["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]))