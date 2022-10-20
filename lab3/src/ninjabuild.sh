#!/bin/sh

sudo apt install ninja-build

mkdir ninjabuild
cd ninjabuild

cmake -GNinja ..
ninja

echo ""
echo "Ninja build completed successfuly"
echo ""
