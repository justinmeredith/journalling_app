# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = journal
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
