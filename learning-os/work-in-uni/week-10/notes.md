For each user prints the number of times each proces is executed

```
ps -e -o user, pid | tail -n +2 | sort | uniq -c
```

```
ps -e -o user, pid | tail -n +2 | sort | uniq -c | while read target; do
  cout = $(echo $target (awk'{print}')
  if [$count -gt 8]; then
    echo $target
  fi
```
