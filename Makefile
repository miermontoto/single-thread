CXX = g++
CXXFLAGS = -Wall -fmessage-length=0 -fno-tree-vectorize
LIBS = -L/usr/X11R6/lib -lpthread -lm -lX11
DBGDIR = debug
RELDIR = release
OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

.PHONY: default all debug release clean

default: debug
all: debug release

debug: CXXFLAGS += -DDEBUG -g3
debug: $(DBGDIR)/
debug: $(DBGDIR)/main

release: CXXFLAGS += -O0
release: $(RELDIR)/
release: $(RELDIR)/main


$(DBGDIR)/%.o $(RELDIR)/%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(DBGDIR)/main: $(addprefix $(DBGDIR)/, $(OBJS) )
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

$(RELDIR)/main: $(addprefix $(RELDIR)/, $(OBJS) )
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

$(DBGDIR)/ $(RELDIR)/:
	mkdir -p $@

clean:
	rm -f $(DBGDIR)/*.o *~ core
	rm -f $(RELDIR)/*.o *~ core