EXECS = matches
C_FLAGS = -c
CC = g++ -o2
LD_FLAGS = -Wl,-rpath

SRCS = $(wildcard *.cpp)
SRCS_CC = $(wildcard *.cc)

OBJECTS = $(patsubst %.cpp,$%.o, $(notdir $(SRCS)))
OBJECTS += $(patsubst %.cc,$%.o, $(notdir $(SRCS_CC)))

$(EXECS): clean $(OBJECTS)
	@echo linking
	$(CC) $(OBJECTS) -o $@ $(LD_FLAGS) $(LIBS)
	
$%.o: $(SRC_APP_DIR)/%.cc
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@
	
$%.o: %.cc
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@
	
$%.o: %.cpp
	$(CC) $(INC_DIRS) $(C_FLAGS) $< -o $@

clean:
	@echo cleaning
	rm -f *.o
