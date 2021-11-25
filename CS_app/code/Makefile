#########################################
# Directory where to put the object files
OBJDIR = .

#########################################
# Directory where to locate source files
SRCDIR = .

#########################################
# Compiler
CC=g++

######################
# All the object files      
OBJFILES = $(OBJDIR)/catane_main.o $(OBJDIR)/catane_code_source.o

###############
# All the flagss
DEBUGFLAGS = -std=c++11 `pkg-config gtkmm-3.0 --cflags`	
STFLAGS    = `pkg-config gtkmm-3.0 --libs`



abdel: $(OBJFILES)
	$(CC) $^ $(STFLAGS) -o $(OBJDIR)/$@

# How to make the object files:
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(DEBUGFLAGS) -c $? -o $@

# Cleaning target (only works with fileutils):
clean:
	/bin/rm -f $(OBJFILES) abdel
