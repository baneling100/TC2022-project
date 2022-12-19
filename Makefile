CXX=g++
CXXFLAGS=-std=gnu++17 -O2
LDFLAGS=
TARGET=lcp
OBJECTS=main.o height.o suffix.o traversal.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean

run: $(TARGET)
	./lcp

clean:
	rm $(TARGET) $(OBJECTS)
