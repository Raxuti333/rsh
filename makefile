CC=gcc
CFLAG=-O2 -march=native -I. -Wno-unused-result
CSRC=source/*
EXE=rsh


build:
	@${CC} ${CFLAG} -o ${EXE} ${CSRC}
