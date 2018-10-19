#ifdef _WIN64
#define PL_WIN 1
#define LLVM_ON_WIN32 1
#elif __Linux__
#define PL_LINUX 1
#else
#define PL_UNKOWN 1
#endif

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/InitLLVM.h>

#include <string>
#include <iostream>
#include <fstream>

#include "parser.h"
#include "utils.h"

using namespace llvm;

#define DEBUG_TYPE "PL"
#ifndef DEBUG
#define DEBUG(X) LLVM_DEBUG(X)
#endif


cl::OptionCategory compiler("Compiler Options");
cl::OptionCategory debug("Debug Options");

static cl::opt<std::string>
InputFile(cl::Positional, cl::desc("<input file>"), cl::init("-"), cl::cat(compiler));

static cl::opt<std::string>
OutputFile("o", cl::desc("Output file"), cl::value_desc("filename"), cl::cat(compiler));

static cl::opt<bool>
verbose("debug", cl::desc("Be more verbose"), cl::cat(debug));

int main(int argc, char** argv) {
  InitLLVM X(argc, argv);


  StringMap<cl::Option*>& Map = cl::getRegisteredOptions();
  for(auto& entry : Map) {
    if(entry.second->Category == &cl::GeneralCategory)
      entry.second->setHiddenFlag(cl::ReallyHidden);
  }

  cl::ParseCommandLineOptions(argc, argv, "The PL Compiler");

  if(verbose) {
    DebugFlag = true;
  } else {
    DebugFlag = false;
  }

  if(InputFile == "-")
    PL::exit_on_error("No input file provided!");

  std::ifstream input(PL::make_absolute(InputFile));
  PL::Parser* parser = new PL::Parser(&input);
  parser->parse();
  delete parser;
  return EXIT_SUCCESS;
}
