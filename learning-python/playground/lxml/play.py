from lxml import etree


path = 'fprs.xml'
tree = etree.parse(path)

root = tree.getroot()

print(root)
print(root.tag)
# print(etree.tostring(root))
print(root.find('{http://www.iata.org/IATA/EDIST}ShoppingResponseID'))


curl -H "Content-Type: application/json" --data @bradning.json http://fab-branding-api.slingshot.eu-west-1.prod.aws.skyscanner.local/config/[partner_id] 
curl -H "Content-Type: application/json" -X PUT --data @example.json https://httpbin.org/put