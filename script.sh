#!/bin/sh

cmpt=1
winp1=0
winp2=0
draw=0

cmp_result()
{
	if test $1 -eq $2
	then
		((draw++))
	fi
	if test $1 -gt $2
	then
		((winp1++))
	fi
	if test $1 -lt $2
	then
		((winp2++))
	fi
}

get_result()
{
	LINE=$(./bonus/map_gen > maps/rand.map | ./ex_filler/filler_vm -p1 ./jwalle.filler -p2 ./ex_filler/carli.filler -v -f maps/rand.map | grep "fin" | cut -d ' ' -f4)
	echo $LINE
	P1=$(echo $LINE | cut -d ' ' -f1)
	P2=$(echo $LINE | cut -d ' ' -f2)
	if [ -n "$LINE" ]
	then
		cmp_result $P1 $P2
	fi
}

while [ $cmpt -le 20 ]
do
	get_result
	((cmpt++))
done
printf "Player 1 win : %d\n" $winp1
printf "Player 2 win : %d\n" $winp2
printf "Draw : %d\n" $draw
exit 0
