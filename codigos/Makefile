VERSION:=beta01
ifdef USE_DEBUG
CPPFLAGS:=-Wall -Wextra -Wpointer-arith -pedantic -Wno-long-long -DVERSION=$(VERSION) -DMEMORY_USAGE
CXXFLAGS:=-fopenmp -g -ffast-math -msse2 -mfpmath=sse -mtune=native
FFLAGS:=-mcmodel=large -g -ffixed-line-length-none -cpp
else
CC=gcc
CPPFLAGS:=-Wall -Wextra -Wpointer-arith -pedantic -Wno-long-long -DVERSION=$(VERSION) -DNDEBUG -DMEMORY_USAGE
CXXFLAGS:=-fopenmp -O3 -ffast-math -msse2 -mfpmath=sse -mtune=native
FFLAGS:=-O3 -ffixed-line-length-none -cpp
endif

CXX:=g++

PARALLEL=4

all: 
	g++ -C clase_06_practica_02.cpp
