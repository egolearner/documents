sed -n '10p' file.txt

awk  'NR==10{print}' file.txt


#  XXX
# shell不记得如何设置IFS了
# file="file.txt"
# 
# IFS=$'\n'
# i=0
# res=""
# 
# for line in $( cat $file ); do 
#   (( i=i+1 ))
#   if [[ i -eq 10 ]]; then 
#     res=$line
#     break
#   fi
# done
# echo $res
