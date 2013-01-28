.PHONY: all, clean

SRC = $(wildcard *.h)

tTarget= $(addsuffix .so, $(basename $(SRC)))
Target = $(addprefix lib, $(tTarget))
#Target = libList.so 
	
OBJ = $(addsuffix .o, $(basename $(SRC)))
all: $(Target) 
%.o: %.cpp %.h
	g++ -fpic -c  $<
	@echo $<" successfully compled"

$(Target): $(OBJ)
	g++ -shared -o $@ $<    

clean:
	rm -f $(OBJ) $(Target)
