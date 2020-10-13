#!/bin/bash

port=$1

# '$2 ~ /[0-9]/' 
# 对第二列 使用正则表达式[0-9]匹配  ~表示使用正则匹配
# // 之间包裹正则表达式

pid=`lsof -i tcp:$port | awk '$2 ~ /[0-9]/{print $2}' | uniq`

echo "kill port: $port pid: $pid"

kill -9 $pid
