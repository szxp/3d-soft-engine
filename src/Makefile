CXX=g++
RM=rm -f

# flags for C++ compiler
CXXFLAGS=-std=c++11 `pkg-config gtkmm-3.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs`
DEPFILE=.depend

SRCS=Mat4.cpp Screen.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: run

run: $(OBJS)
	g++ $(CXXFLAGS) -o run $(OBJS) $(LDFLAGS)

depend: $(DEPFILE)

.depend: $(SRCS)
	rm -f ./$(DEPFILE)
	$(CXX) $(CXXFLAGS) -MM $^ > ./$(DEPFILE)

clean:
	$(RM) $(OBJS) $(DEPFILE)

dist-clean: clean
	$(RM) *~ run

sinclude $(DEPFILE)

