CXX = g++
CXXFLAGS = -Wall -std=c++17 -I$(HOME)/local/antlr4/include/antlr4-runtime

LDFLAGS = -Wl,-rpath,$(HOME)/local/antlr4/lib -Wl,--enable-new-dtags -L$(HOME)/local/antlr4/lib
LDLIBS = -lantlr4-runtime #-lpthread
PROGRAM = Test

SOURCES = $(shell ls *.cpp)
HEADERS = $(shell ls *.h)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

.PHONY: all 
all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(PROGRAM) $(OBJECTS) $(LDLIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJECTS) $(PROGRAM)

