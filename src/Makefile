CXX=g++
RM=rm -f

# flags for C++ compiler
CXXFLAGS=-std=c++11
LDFLAGS=
LDLIBS=
DEPFILE=.depend

SRCS=Mesh.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: run

run: $(OBJS)
	g++ $(LDFLAGS) -o run $(OBJS) $(LDLIBS)

depend: $(DEPFILE)

.depend: $(SRCS)
	rm -f ./$(DEPFILE)
	$(CXX) $(CXXFLAGS) -MM $^ > ./$(DEPFILE)

clean:
	$(RM) $(OBJS) $(DEPFILE)

dist-clean: clean
	$(RM) *~ run

sinclude $(DEPFILE)

