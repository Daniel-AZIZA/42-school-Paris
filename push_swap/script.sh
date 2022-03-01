#!/bin/sh

cd checke
make
make clean
mv checker ../.

cd ../push_sw
make
make clean
mv push_swap ../.
cd ..
