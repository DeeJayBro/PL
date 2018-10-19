#ifndef PL_UTILS
#define PL_UTILS

namespace llvm {
  class raw_ostream;
  class StringRef;
}

namespace PL {

llvm::raw_ostream& error(llvm::raw_ostream&);
llvm::raw_ostream& error(llvm::raw_ostream&, llvm::StringRef);

llvm::StringRef make_absolute(llvm::StringRef);

}

#endif
