
#!/bin/bash

ls $HOME -lR > files.txt
gzip files.txt

echo "Insert USB"
