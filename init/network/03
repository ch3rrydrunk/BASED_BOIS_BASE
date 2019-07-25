#!/usr/bin/sh
# Show my MAC (network/wifi card for the laptop case)
ifconfig en0 | awk '/ether/ {print $2}'
