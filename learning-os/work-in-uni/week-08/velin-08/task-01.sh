#!/bin/bash

for i in $@;do
    filename="${i%.*}"
    echo $filename.odt
done
