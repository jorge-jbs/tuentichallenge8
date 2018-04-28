#!/bin/bash
exec 3<>/dev/tcp/52.49.91.111/3241
echo "TEST" >&3
while read msg <&3
do
    echo -e "[SERVER] $msg"
    response=$(echo "$msg" | ./5)
    echo "[CLIENT] $response"
    if [ -n "$response" ]; then
        echo "$response" >&3
    fi
done
