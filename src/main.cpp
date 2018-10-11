#ifdef _WIN64
#define PL_WIN 1
#define LLVM_ON_WIN32 1
#elif __Linux__
#define PL_LINUX 1
#else
#define PL_UNKOWN 1
#endif

#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Debug.h>

using namespace llvm;

#define DEBUG_TYPE "PL"
#define DEBUG(X) LLVM_DEBUG(X)

static cl::opt<std::string>
InputFile(cl::Positional, cl::desc("<input file>"), cl::init("-"));

static cl::opt<std::string>
OutputFile("o", cl::desc("Output file"), cl::value_desc("filename"));

int main(int argc, char** argv) {
  cl::ParseCommandLineOptions(argc, argv, "The PL Compiler");
  DEBUG(dbgs() << "Input file: " << InputFile << "\n");
  DEBUG(dbgs() << "Output file: " << OutputFile << "\n");
  llvm_shutdown();
  return EXIT_SUCCESS;
}
