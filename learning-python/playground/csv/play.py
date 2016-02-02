import csv
with open('play.csv') as csvfile:
    reader = csv.DictReader(csvfile, fieldnames=None, restkey='YOLO', restval='')
    for row in reader:
        print row
