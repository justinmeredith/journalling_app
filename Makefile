# Makefile

CXX = g++
CXXFLAGS = -std=c++17 -Wall -lsqlite3
TARGET = journal
SRC = main.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
