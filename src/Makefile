CXX=g++
RM=rm -f
CPPFLAGS=-std=c++11
LDFLAGS=
LDLIBS=

SRCS=Point.cpp Vector.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: run

run: $(OBJS)
	g++ $(LDFLAGS) -o run $(OBJS) $(LDLIBS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .depend run

include .depend

