CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic -O2
LIBS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TARGET := build/notmele
SOURCES := \
	src/main.cpp \
	src/game/Game.cpp \
	src/player/Player.cpp

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ $(LIBS)

clean:
	rm -f $(TARGET)
