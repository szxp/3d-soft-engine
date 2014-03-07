
CXX=g++
RM=rm -f
CXXFLAGS=-std=c++11 `pkg-config gtkmm-3.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs`

DEPFILE=.depend
DEPFILE_TEST=.depend-test

SRCS=Vec.cpp Mat.cpp Screen.cpp main.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

SRCS_TEST=test.cpp
OBJS_TEST=$(subst .cpp,.o,$(SRCS_TEST))

all: run

run: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

test: Vec.o Mat.o $(OBJS_TEST)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

.depend: $(SRCS)
	$(RM) ./$(DEPFILE)
	$(CXX) $(CXXFLAGS) -MM $^ > ./$(DEPFILE)

.depend-test: $(SRCS_TEST)
	$(RM) ./$(DEPFILE_TEST)
	$(CXX) $(CXXFLAGS) -MM $^ > ./$(DEPFILE_TEST)

clean:
	$(RM) $(OBJS) $(DEPFILE) $(OBJS_TEST) $(DEPFILE_TEST) run test


sinclude $(DEPFILE)
sinclude $(DEPFILE_TEST)

