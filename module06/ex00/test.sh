#!/bin/bash

if [[ ! -x ./convert ]]; then
  echo "エラー: ./convert が見つかりません。先にビルドしてください。" >&2
  exit 1
fi

cases=(
  "0"
  "nan"                 # double special
  "42.0f"               # float special
  "abc"                 # invalid
  "42abc"               # invalid
  "1.2.3"               # invalid
  ""                    # invalid (empty string)
  " "                   # space
  "127"                 # int, char nondisplayable
  "-2147483648"         # int min
  "999999999999"        # int overflow but < double/float max
  "-4.2f"               # float
  "nanf"                # float special
  "+inff"               # float special
  "-inff"               # float special
  "-4.2"                # double
  "nan"                 # double special (再掲)
  "+inf"                # double special
  "-inf"                # double special
  "3.4e+38f"            # float max 付近
  "3.4e+40f"            # float overflow but < double max
  "1e400"               # double overflow
  "-0.0"                # negative zero
)

for lit in "${cases[@]}"; do
  printf '==== Test: "%s" ====\n' "$lit"
  ./convert "$lit"
  echo
done
