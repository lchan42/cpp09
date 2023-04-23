
if [ "$1" = "1" ]; then
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./btc inputFiles/input.txt

elif [ "$1" = "2" ]; then
	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./btc inputFiles/noFirstLine.txt

elif [ "$1" = "3" ]; then
	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./btc inputFiles/wrongFistLine.txt
elif [ "$1" = "4" ]; then
	echo "~~~~~~~~~ testing with wrongSeparator.txt ~~~~~~~~~"
	./btc inputFiles/wrongSeparator.txt

elif [ "$1" = "5" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongNotNumber.txt

elif [ "$1" = "6" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongNotNumber.txt

elif [ "$1" = "7" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongNotNumber.txt

elif [ "$1" = "8" ]; then
	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongNotNumber.txt

else
	echo "~~~~~~~~~ testing with input.txt ~~~~~~~~~"
	./btc inputFiles/input.txt

	echo "~~~~~~~~~ testing with  ~~~~~~~~~"
	./btc inputFiles/noFirstLine.txt

	echo "~~~~~~~~~ testing with wrongFistLine.txt ~~~~~~~~~"
	./btc inputFiles/wrongFistLine.txt

	echo "~~~~~~~~~ testing with wrongInvalidNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongInvalidNumber.txt

	echo "~~~~~~~~~ testing with wrongSeparator.txt ~~~~~~~~~"
	./btc inputFiles/wrongSeparator.txt

	echo "~~~~~~~~~ testing wrongNegVal.txt ~~~~~~~~~"
	./btc inputFiles/wrongNegVal.txt

	echo "~~~~~~~~~ testing with wrongNotNumber.txt ~~~~~~~~~"
	./btc inputFiles/wrongNotNumber.txt
fi
