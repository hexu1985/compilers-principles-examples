ANTLR4_DIR = $(HOME)/local/antlr4

CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(ANTLR4_DIR)/include/antlr4-runtime -I./gen
LDFLAGS = -Wl,-rpath,$(ANTLR4_DIR)/lib -Wl,--enable-new-dtags -L$(ANTLR4_DIR)/lib
LDLIBS = -lantlr4-runtime 

SOURCES = $(shell ls gen/*.cpp)
HEADERS = $(shell ls gen/*.h)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

PROGRAMS_SOURCES = $(shell ls *.cpp)
PROGRAMS = $(patsubst %.cpp,%,$(PROGRAMS_SOURCES))

.PHONY: all 
all: $(PROGRAMS)

$(PROGRAMS): %: %.o $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(OBJECTS) $(PROGRAMS)

