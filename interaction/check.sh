#!/bin/sh -e

RESULT=$(echo "adam" | nc -q 1 "$1" "$2")
echo "$RESULT" | grep "Can you drive with a blindfold?"
echo "$RESULT" | grep "Send me your vehicle"

RESULT=$(python -c "print('adam\x00')" | nc -q 1 "$1" "$2")
echo "$RESULT" | grep "Failed smog inspection."
