SHELL=/bin/sh

# This file contains a set of rules used by the "make"
#   command.  This makefile $(MAKEFILE) tells "make" how the
#   executable multimin_sa_compare $(COMMAND) should be created
#   from the source files $(SRCS) via the object
#   files $(OBJS) and the header files $(HDRS); type the command:
#        "make -f make_multimin_sa_compare"
#   where make_multimin_sa_compare should be replaced by the name of
#   the makefile.
# 
# This file also tells make what to do if arguments
#   follow the "make" command.
#
# To remove the OBJS files; type the command:
#        "make -f make_multimin_sa_compare clean"
#
# To create a gzipped tar file with name $(COMMAND).tar.gz
#  containing this makefile and the SRCS files,
#  type the command:
#        "make -f make_multimin_sa_compare tarz"

## Makefile for C++ project using Boost
#
# @author Cedric "levif" Le Dillau
#
# Some notes:
# - Using ':=' instead of '=' assign the value at Makefile parsing time,
#   others are evaluated at usage time. This discards
# - Use ':set list' in Vi/Vim to show tabs (Ctrl-v-i force tab insertion)
#
# List the project' sources to compile or let the Makefile recognize
# them for you using 'wildcard' function.
#
#SOURCES = simple_ls.cpp rawr.cpp converter.cpp
#SOURCES = $(wildcard *.cpp)

# List the project' headers or let the Makefile recognize
# them for you using 'wildcard' function.
#
#HEADERS = simple_ls.h 2dquicksort.h rawr.h
#HEADERS = $(wildcard %.h)

# Construct the list of object files based on source files using
# simple extension substitution.
#OBJECTS = $(SOURCES:%.cpp=%.o)

#
# Now declare the dependencies rules and targets
#
# Starting with 'all' make it  becomes the default target when none 
# is specified on 'make' command line.
#all : $(PROGNAME)

# Declare that the final program depends on all objects and the Makfile
#$(PROGNAME) : $(OBJECTS) Makefile
#    $(CXX) -o $@ $(LDFLAGS) $(OBJECTS)

# Now the choice of using implicit rules or not (my choice)...
#
# Choice 1: use implicit rules and then we only need to add some dependencies
#           to each object.
#
## Tells make that each object file depends on all headers and this Makefile.
#$(OBJECTS) : $(HEADERS) Makefile
#
# Choice 2: don't use implicit rules and specify our will
#%.o: %.cpp $(HEADERS) Makefile
#    $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $(OUTPUT_OPTION) $<

# Simple clean-up target
# notes:
# - the '@' before 'echo' informs make to hide command invocation.
# - the '-' before 'rm' command to informs make to ignore errors.
#clean :
#    @echo "Clean."
#    -rm -f *.o $(PROGNAME) 

# List to '.PHONY' all fake targets, those that are neither files nor folders.
# "all" and "clean" are good candidates.

.PHONY: all, clean

#Source files
SRCS= \
$(wildcard *.cpp)
#Main.cpp

# Construct the list of object files based on source files using
OBJS= $(addsuffix .o, $(basename $(SRCS)))

#Header files
HDRS= \
$(wildcard %.hpp)

#Make file name
MAKEFILE= make_sort.mak
# Define the final program name
COMMAND= Main

all: $(COMMAND)
#COMPILER 
CC= g++
# CFLAGS is used for C++ compilation options.
CFLAGS= -g -O0
#WARNNING FLAG
WARNFLAGS= -Werror -Wall
#-Wshadow -fno-common
MOREFLAGS= -ansi -pedantic -Wpointer-arith -Wcast-qual -Wcast-align \
           -Wwrite-strings -fshort-enums 

# Pre-processor flags to be used for includes (-I) and defines (-D) 
CPPFLAGS := \

# LDFLAGS is used for linker (-g enables debug symbols)
LDFLAGS  := \

# PATH AND LIBRARY PATH
BOOST_LIBDIR = /home/nick/boost_1_51_0/lib/
BOOST_INCLUDEDIR = /home/nick/boost_1_51_0/include/

LIBDIR = /home/nick/CLRS/util/
INCLUDEDIR = /home/nick/CLRS/util/
# Which Boost modules to use (all)
#BOOST_MODULES = \
  date_time     \
  filesystem    \
  graph         \
  iostreams     \
  math_c99      \
  system        \
  serialization \
  regex		\


SMODULES := \
  List \

# Boost libraries' type (a suffix)
#BOOST_MODULES_TYPE := -mt

# Define library names with their type
#BOOST_MODULES_LIBS := $(addsuffix $(BOOT_MODULES_TYPE),$(BOOST_MODULES))

# Define the linker argument to use the Boost libraries.
#BOOST_LDFLAGS := $(addprefix -lboost_,$(BOOST_MODULES_LIBS))

# Define the linker argument to tuse the libraries
LIB_SMODULES := $(addprefix -l,$(SMODULES))

# Feed compiler/linker flags with Boost's
CPPFLAGS += -I$(INCLUDEDIR)
LDFLAGS += -L$(LIBDIR)

#LIBS = $(BOOST_INCLUDEDIR)

#BUILD THE FINAL PROGRAM
$(COMMAND): $(OBJS) 
#$(COMMAND): %.o 
	$(CC) -o $(COMMAND) $(LDFLAGS) $(OBJS) $(LIB_SMODULES)
	@echo "Linking complete!"
#BUILD OBJECT FILES                 
#$(OBJS): $(SRCS) $(HDRS) $(MAKEFILE)
%.o: %.cpp $(HDRS) $(MAKEFILE)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(WARNFLAGS) -c $< -o $@ 
	@echo "Compiled "$<" successfully!" 

#random_seed.o : random_seed.cpp $(MAKEFILE)
#	$(CC) $(CFLAGS) $(WARNFLAGS)  -c random_seed.cpp -o random_seed.o
 
clean:
	rm -f $(OBJS) $(COMMAND)
 
#tarz:
#	tar zcf - $(MAKEFILE) $(SRCS) $(HDRS) > $(COMMAND).tar.gz
 