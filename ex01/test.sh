export subject1="8 9 * 9 - 9 - 9 - 4 - 1 +"
export subject2="7 7 * 7 -"
export subject3="1 2 * 2 / 2 * 2 4 - +"
export subject4="(1 + 1)"
export test1="1 2 3 4 qqwe + + + +"
export test2="1 a 3 4 + + +"
export test3="1 2 3 4 + + + +"
export test4="1 +2 3 4 + + +"
export test5="1 -2 3 4 + + +"
export test6="1 2 3 4 + + ++"
export test7="1 2 3 4 + + + +"
export test8="1 2 3 4 + + + + + "
export test9="1 2 3 4 + "
export test10="1 2 3 4 + + + "
export test11="1 2 3 11 + + + "
export test12="5 2 + 3 *"
export test13="8 4 / 2 -"
export test14="3 7 * 4 2 / -"
export test15="9 2 ^ 1 + 5 *"
export test16="6 2 * 3 / 4 +"
export test17="1 2 3 0 + + / "
export test18="1 2 0 3 / / + "
make re

echo "$> ./RPN " "$subject1"
 ./RPN "$subject1"
 #echo $'\n'
echo "$> ./RPN " "$subject2"
 ./RPN "$subject2"
 #echo $'\n'
echo "$> ./RPN " "$subject3"
 ./RPN "$subject3"
 #echo $'\n'
echo "$> ./RPN " "$subject4"
 ./RPN "$subject4"
 #echo $'\n'
echo "$> ./RPN " "$test1"
 ./RPN "$test1"
 #echo $'\n'
echo "$> ./RPN " "$test2"
 ./RPN "$test2"
 #echo $'\n'
echo "$> ./RPN " "$test3"
 ./RPN "$test3"
 #echo $'\n'
echo "$> ./RPN " "$test4"
 ./RPN "$test4"
 #echo $'\n'
echo "$> ./RPN " "$test5"
 ./RPN "$test5"
 #echo $'\n'
echo "$> ./RPN " "$test6"
 ./RPN "$test6"
 #echo $'\n'
echo "$> ./RPN " "$test7"
 ./RPN "$test7"
 #echo $'\n'
echo "$> ./RPN " "$test8"
 ./RPN "$test8"
 #echo $'\n'
echo "$> ./RPN " "$test9"
 ./RPN "$test9"
 #echo $'\n'
echo "$> ./RPN " "$test10"
 ./RPN "$test10"
 #echo $'\n'
echo "$> ./RPN " "$test11"
 ./RPN "$test11"
 #echo $'\n'
 echo "$> ./RPN " "$test12"
 ./RPN "$test12"
 #echo $'\n'
 echo "$> ./RPN " "$test13"
 ./RPN "$test13"
 #echo $'\n'
 echo "$> ./RPN " "$test14"
 ./RPN "$test14"
 #echo $'\n'
 echo "$> ./RPN " "$test15"
 ./RPN "$test15"
 #echo $'\n'
 echo "$> ./RPN " "$test16"
 ./RPN "$test16"
 #echo $'\n'
 echo "$> ./RPN " "$test17"
 ./RPN "$test17"
 #echo $'\n'
 echo "$> ./RPN " "$test18"
 ./RPN "$test18"
 #echo $'\n'
