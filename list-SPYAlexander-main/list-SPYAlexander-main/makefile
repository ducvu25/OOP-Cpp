CFLAGS = -std=c++14 -Wall -g
CC = g++
SOURCEDIR = .
BUILDDIR = cmake-build-debug

EXE = list
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
#SOURCES = $(SOURCEDIR)/*.cpp
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

all: dir $(BUILDDIR)/$(EXE)

dir:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/$(EXE):	$(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS):	$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXE)

