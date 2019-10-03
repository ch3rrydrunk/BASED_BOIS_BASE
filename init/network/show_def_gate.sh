#!/usr/bin/sh
# Show default IP gateway routing table (see the full table without grep'ing 'default')
netstat -rn -f inet | grep en0 | awk '/default/ {print $2}'
