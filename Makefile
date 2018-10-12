CXX=clang++
SHELL = sh
SRCS := $(shell find src -name '*.cpp')
LLVM_CONFIG := $(shell command -v llvm-config)
CXXFLAGS += $(shell $(LLVM_CONFIG) --cxxflags)
LIBS = $(shell $(LLVM_CONFIG) --libs)
INCLUDES = -Iinclude
MAIN = bin/pl

.PHONY: depend clean

.PHONY: all
all: pl

pl:
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(LIBS) $(INCLUDES) -o $(MAIN) $(SRCS)

clean:
	$(RM) *.o *~ $(MAIN)
	$(RM) -rf bin

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
