#!/bin/sh

cmpt=1
winp1=0
winp2=0
draw=0


test_all()
{
	LINES=$(make test | grep "fin" | cut -d ' ' -f4)
}


while [ $cmpt -le 5 ]
do
	test_all
	((cmpt++))
done
exit 0
