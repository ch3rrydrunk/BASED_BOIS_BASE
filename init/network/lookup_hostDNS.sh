#!/usr/bin/sh
# Show the IP address of the DNS responsible for given domain
nslookup $1 | awk '/Server:/ {print $2}'
