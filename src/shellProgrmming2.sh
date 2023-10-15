read -p "A : " startingNum
read -p "B : " endingNum

if [ $startingNum -gt $endingNum ]; then
  echo "Starting number must be less than ending number"
else
  while [ $startingNum -le $endingNum ]; do
    echo $startingNum
    startingNum=$(($startingNum + 1))
  done
fi
