# speedrun-011

[![Build Status](https://travis-ci.com/o-o-overflow/dc2019q-speedrun-011.svg?token=6XM5nywRvLrMFwxAsXj3&branch=master)](https://travis-ci.com/o-o-overflow/dc2019q-speedrun-011)

Blind shellcoding (shellcode where the flag is in memory but there is no output, all fds are closed and seccomp is in place).

#Compiling service 

Service compilation now requires -lseccomp, use the following. 

`gcc service/src/speedrun-011.c -lseccomp -o service/speedrun-011`


