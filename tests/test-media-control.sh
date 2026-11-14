#!/bin/sh
set -eu
R=$(cd "$(dirname "$0")/.." && pwd)
T=$(mktemp -d)
trap 'rm -rf "$T"' EXIT
cc -std=c99 -O2 -Wall -Wextra -Werror -I"$R/app" -o "$T/op_media_control_test" \
    "$R/tests/op_media_control_test.c" "$R/app/op_media_control.c"
"$T/op_media_control_test"
