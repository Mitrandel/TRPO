EXECS = matches
TEMPDIR = $(shell pwd)/tmp
C_FLAGS = -c
CC = g++ -o2
LD_FLAGS = -Wl,-rpath

SRCS = $(wildcard *.cpp)
SRCS_CC = $(wildcard *.cc)

OBJECTS = $(patsubst %.cpp,$(TEMPDIR)/%.o, $(notdir $(SRCS)))
OBJECTS += $(patsubst %.cc,$(TEMPDIR)/%.o, $(notdir $(SRCS_CC)))

$(EXECS): clean $(OBJECTS)
	@echo linking
	$(CC) $(OBJECTS) -o $@ $(LD_FLAGS) $(LIBS)
	
$(TEMPDIR)/%.o: $(SRC_APP_DIR)/%.cc
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@
	
$(TEMPDIR)/%.o: %.cc
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@
	
$(TEMPDIR)/%.o: %.cpp
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@

clean:
	@echo cleaning
	rm -f $(TEMPDIR)/*.*
