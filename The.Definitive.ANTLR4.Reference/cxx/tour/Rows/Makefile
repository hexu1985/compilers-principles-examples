ANTLR4_DIR = $(HOME)/local/antlr4

CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(ANTLR4_DIR)/include/antlr4-runtime -I./gen
LDFLAGS = -Wl,-rpath,$(ANTLR4_DIR)/lib -Wl,--enable-new-dtags -L$(ANTLR4_DIR)/lib
LDLIBS = -lantlr4-runtime 
PROGRAM = Col

SOURCES = $(shell ls */*.cpp)
HEADERS = $(shell ls */*.h)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

PROGRAM_SOURCES = $(shell ls *.cpp)
PROGRAM_OBJECTS = $(patsubst %.cpp,%.o,$(PROGRAM_SOURCES))

.PHONY: all 
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS) $(PROGRAM_OBJECTS)
	$(CXX) $(LDFLAGS) -o $(PROGRAM) $(OBJECTS) $(PROGRAM_OBJECTS) $(LDLIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(PROGRAM_OBJECTS) $(PROGRAM)

