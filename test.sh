
if [ "$1" = "1" ]; then
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./cpp09ex00 inputFiles/input.txt

elif [ "$1" = "2" ]; then
	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./cpp09ex00 inputFiles/noFirstLine.txt

elif [ "$1" = "3" ]; then
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
