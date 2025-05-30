CXX = g++
CXXFLAGS = -std=c++20
TARGET = lsev
SOURCES = $(wildcard src/*.cpp)
BINDIR = /usr/bin/

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

install: $(TARGET)
	mkdir -p $(BINDIR)
	cp $(TARGET) $(BINDIR)

clean:
	rm -f $(TARGET)
