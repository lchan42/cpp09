
if [ "$1" = "1" ]; then
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/input.txt

elif [ "$1" = "2" ]; then
	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./cpp09ex00 inputFiles/noFirstLine.txt

elif [ "$1" = "3" ]; then
	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongFistLine.txt
elif [ "$1" = "4" ]; then
	echo "~~~~~~~~~ testing with wrongSeparator.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongSeparator.txt

elif [ "$1" = "5" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNotNumber.txt

elif [ "$1" = "6" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNotNumber.txt

elif [ "$1" = "7" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNotNumber.txt

elif [ "$1" = "8" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNotNumber.txt

else
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/input.txt

	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./cpp09ex00 inputFiles/noFirstLine.txt

	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongFistLine.txt

	echo "~~~~~~~~~ testing with wrongInvalidNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongInvalidNumber.txt

	echo "~~~~~~~~~ testing with wrongSeparator.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongSeparator.txt

	echo "~~~~~~~~~ testing wrongNegVal.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNegVal.txt

	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongNotNumber.txt
fi


# echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
# ./cpp09ex00 inputFiles/input.txt

# echo "~~~~~~~~~ testing with  ~~~~~~~~~"
# ./cpp09ex00 inputFiles/noFirstLine.txt

# echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
# ./cpp09ex00 inputFiles/wrongFistLine.txt

# echo "~~~~~~~~~ testing with noFirstLine.txt ~~~~~~~~~"
# valgrind ./cpp09ex00 inputFiles/noFirstLine.txt
