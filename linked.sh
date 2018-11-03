#!/bin/bash

export GTEST_DIR=~/googletest/googletest
cd ~/linked_list
g++ -isystem ${GTEST_DIR}/include -pthread linked_list_testcase.c linked_list.c Gtest_main.c libgtest.a -o linked_list
./linked_list
