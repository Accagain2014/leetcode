
# Author :  Accagain
# Date   :  17/2/15
# Email  :  chenmaosen0@gmail.com

####################################################################
# 
# Given a text file file.txt, transpose its content.
# 
# You may assume that each row has the same number of columns and each field 
# 
# is separated by the ' ' character.
# 
# For example, if file.txt has the following content:
# 
# name age
# alice 21
# ryan 30
# 
# Output the following:
# name alice ryan
# age 21 30
# 

declare -A matrix

row=1
col=1
file=file.txt

while read line; do
	col=1
	for word in $line; do
		matrix[$row,$col]=$word
		#echo $row, $col
		#echo -n ' '${matrix[$row,$col]}
		((col++))
	done
	((row++))
done < $file

for ((i=1;i<col;i++)) do
	#echo $i
	
	echo -n ${matrix[1,$i]}
	for ((j=2;j<row;j++)) do
		echo -n ' '${matrix[$j,$i]}
	done
	echo 
done