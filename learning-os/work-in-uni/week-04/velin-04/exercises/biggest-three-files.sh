#!/bin/bash
find /usr/bin -type f -exec du -h "{}" \;  | sort -n -r | head -n 3
