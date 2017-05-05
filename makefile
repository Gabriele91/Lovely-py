CC            ?= g++
MKDIR_P       ?= mkdir -p
MODULE_FOLDER ?= lovely
TOP           ?= $(shell pwd)
O_DIR         ?= build
# Lovely files
LOVELY_OUTPUT  = lovely.pyd
LOVELY_INCLUDE = include/
LOVELY_SRC     = src/
LOVELY_CPP  = $(wildcard $(LOVELY_SRC)/*.cpp)
LOVELY_OBJS = $(addprefix $(O_DIR)/,$(notdir $(LOVELY_CPP:.cpp=.o)))
# FLAGS
C_FLAGS 	 = -fPIC -std=c++11 $(shell python3-config --includes)
CC_FLAGS 	 = -I$(LOVELY_INCLUDE)
LIKNER_FLAGS = 
# Others
LOVE_INCLUDE_FLAGS = -Ilove/src -Ilove/src/common -Ilove/src/modules
PYBIND11_INCLUDE_FLAGS = -Ilibraries/pybind11/include
#love
CC_FLAGS += $(LOVE_INCLUDE_FLAGS) $(PYBIND11_INCLUDE_FLAGS)
# Color Types
COLOR_BLACK = 0
COLOR_RED = 1
COLOR_GREEN = 2
COLOR_YELLOW = 3
COLOR_BLUE = 4
COLOR_MAGENTA = 5
COLOR_CYAN = 6
COLOR_WHITE = 7
##
# Support function for colored output
# Args:
#     - $(1) = Color Type
#     - $(2) = String to print
define colorecho
      @tput setaf $(1)
      @echo $(2)
      @tput sgr0
endef

# directive
all: lovely


lovely: directories $(LOVELY_OBJS)
	$(call colorecho,$(COLOR_GREEN),"[ Make $(LOVELY_OUTPUT) ]")
	$(CC) $(C_FLAGS) $(CC_FLAGS) -shared -o $(TOP)/$(MODULE_FOLDER)/$(LOVELY_OUTPUT) $(LOVELY_OBJS) $(LIKNER_FLAGS)

# Required directories
directories: $(O_DIR)

# makedir
$(O_DIR):
	$(call colorecho,$(COLOR_GREEN),"[ Create $(O_DIR) directory ]")
	@$(MKDIR_P) $(O_DIR)

# Make objects files
$(O_DIR)/%.o: $(LOVELY_SRC)%.cpp
	$(call colorecho,$(COLOR_GREEN),"[ Make object $(@) ]")
	$(CC) $(C_FLAGS) $(CC_FLAGS) $(LIKNER_FLAGS) -c $< -o $@
