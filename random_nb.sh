#!/bin/bash

echo "******100 numbers sort******"
ARG=""; for i in {1..100}; do
  while :; do
    num=$((RANDOM % 10000 - 500))
    if [[ ! $ARG =~ $num ]]; then
      [ -n "$ARG" ] && ARG="$ARG "
      ARG="$ARG$num"
      break
    fi
  done
done
echo $ARG


# 运行 push_swap 和 checker_OS
echo "checker_linux:"
./push_swap $ARG | ./checker_linux $ARG
echo "checker bonus:" 
./push_swap $ARG | ./checker $ARG

echo "moves:" 
./push_swap $ARG | wc -l

#使用 for i in {1..10}; do ... done 循环来生成 10 个数字。您可以根据需要更改 {1..10} 来生成更多或更少的数字。
#在循环内部，num=$((RANDOM % 100 - 50)) 生成一个 -50 到 49 之间的随机数字。这是因为 RANDOM % 100 生成 0 到 99 的数字，然后减去 50 将范围变成 -50 到 49。您可以调整这些数值来改变范围。
#将生成的数字添加到 ARG 字符串中，如果 ARG 不为空，则在添加新数字之前先加上一个空格。
#这个脚本会重复生成数字，直到找到一个不在 ARG 中的数字。请注意，这种方法在数字数量接近其范围的上限时效率较低，因为找到一个唯一的数字可能需要多次尝试。
#如果您需要生成大量不重复的随机数字，考虑使用更适合处理这类问题的编程语言，如 Python，然后通过脚本调用该程序来生成数字。在 Python 中，您可以轻松地使用集合和随机数库来生成不重复的随机数字序列。

