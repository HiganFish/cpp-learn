#!/bin/bash

while true; do
    read line
    echo $line >> /dev/tty
    echo $line

done
