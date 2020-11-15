awk '{for (i = 1; i <= NF; i++) {a[i,NR]=$i}} END{for (i = 1; i <= NF; i++){s=a[i,1]; for (j = 2; j <= NR; j++) {s=s " " a[i, j]} print s}}' file.txt
