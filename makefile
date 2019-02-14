# Makefile for tictactoe terminal game
EXECUTABLES = tictactoe

# set flags for all warnings (Wall) and add debugging infomation (-g)
CXX = g++
CXX_FLAGS = -Wall -g -std=c++11

SRC_DIR	= ./src
BIN_DIR	= ./bin
OBJ_DIR = $(BIN_DIR)/obj

# Tells the compiler where to look for header files
INCLUDES 	= -I$(SRC_DIR)

# Create list of all cpp src files without path
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)/*.cpp))
#SRC_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) 

# Use substitution to create a mirror lis of object files 
# prefixed with path to object dir
OBJ_FILES = $(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: clean print build all

build: scaffold $(BIN_DIR)/$(EXECUTABLES)

scaffold: 
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)

clean: 
	rm -rf $(BIN_DIR)

print:
	echo $(OBJ_FILES)


# $@ is target name, $^ is prerequisite list
$(BIN_DIR)/$(EXECUTABLES): $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -o $@ $^

# Here we are using the static pattern rule to specify multiple targets.
# $< is first prerequisite
$(OBJ_FILES): $(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@echo Compiling $<
	$(CXX) $(CXX_FLAGS) $(INCLUDES) -c $< -o $@

# Creating tests we would need all the source to be compiled and then need to compile the tests
#test: $(OBJ_FILES) $(TEST_OBJS)

#$TEST_OBJS = $
# compile the tests
#$(TEST_OBJS): 

