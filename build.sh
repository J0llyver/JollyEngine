#!/bin/sh

cmake -DCMAKE_BUILD_TYPE=Debug
cd src
ctags -R
