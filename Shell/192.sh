
# Author :  Accagain
# Date   :  17/2/15
# Email  :  chenmaosen0@gmail.com

####################################################################
# 
# Write a bash script to calculate the frequency of each word in a text file words.txt.
# 
# For simplicity sake, you may assume:
# 
# words.txt contains only lowercase characters and space ' ' characters.
# 
# Each word must consist of lowercase characters only.
# 
# Words are separated by one or more whitespace characters.
# 
# For example, assume that words.txt has the following content:
# 
# the day is sunny the the
# 
# the sunny is is
# 
# Your script should output the following, sorted by descending frequency:
# 
# the 4
# 
# is 3
# 
# sunny 2
# 
# day 1
# 
# Note:
# 
# Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
# 
# 

declare -a a
declare -a b
word_exist(){
    word=$1
    i=0
    
    for var in ${a[@]};
    do
        if [ "$var" = "$word" ]
        then
            break
        fi
       # i=`expr $i + 1`
       i=$((i+1))
    done
    
    if [ $i -eq ${#a[@]} ]
    then
        return 1
    else
        return 0
    fi
}

while read line ;
do
    words=($line)
    for w in ${words[@]}
    do
        if word_exist $w
        then
            #b[$i]=`expr $b[$i] + 1`
            b[$i]=$((${b[$i]}+1))
        else
            a[$i]=$w
            b[$i]=1
        fi
    done
done < words.txt

if [ ${#a[@]} -gt 0 ]
then
    #count=`expr ${#a[@]} - 1`
    count=$((${#a[@]}-1))

    while [ $count -ge 0 ]
    do
        echo ${b[$count]} ${a[$count]}
        #count=`expr $count - 1`
        count=$((count-1))
    done | sort -n -r | awk '{print $2" "$1}'
fi