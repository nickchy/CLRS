.PHONY: all, clean

CC = g++
CFLAG = -g -O0
WARNFLAG = -Werror -Wall
SRC = $(wildcard *.h)

tTarget= $(addsuffix .so, $(basename $(SRC)))
Target = $(addprefix lib, $(tTarget))
#Target = libList.so 
	
OBJ = $(addsuffix .o, $(basename $(SRC)))
all: $(Target) 

%.o: %.cpp %.h
	$(CC) -fpic $(CFLAG) $(WARNFLAG) -c  $<
	@echo $<" successfully completed"

$(Target): $(OBJ)
	g++ -shared -o $@ $<    

clean:
	rm -f $(OBJ) $(Target)
