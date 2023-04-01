make


if [ "$1" = "input" ]; then
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/input.txt

elif [ "$1" = "noFirstLine" ]; then
	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./cpp09ex00 inputFiles/noFirstLine.txt

elif [ "$1" = "wrongFistLine" ]; then
	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongFistLine.txt
else
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/input.txt

	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./cpp09ex00 inputFiles/noFirstLine.txt

	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/wrongFistLine.txt
fi


# echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
# ./cpp09ex00 inputFiles/input.txt

# echo "~~~~~~~~~ testing with  ~~~~~~~~~"
# ./cpp09ex00 inputFiles/noFirstLine.txt

# echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
# ./cpp09ex00 inputFiles/wrongFistLine.txt

# echo "~~~~~~~~~ testing with noFirstLine.txt ~~~~~~~~~"
# valgrind ./cpp09ex00 inputFiles/noFirstLine.txt
