
# Author :  Accagain
# Date   :  17/2/15
# Email  :  chenmaosen0@gmail.com

####################################################################
# 
# How would you print just the 10th line of a file?
# 
# For example, assume that file.txt has the following content:
# 
# Line 1
# Line 2
# Line 3
# Line 4
# Line 5
# Line 6
# Line 7
# Line 8
# Line 9
# Line 10
# 
# Your script should output the tenth line, which is:
# Line 10
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