#!/usr/bin/env bash

set -e

make
exec ./bin/my_shell
