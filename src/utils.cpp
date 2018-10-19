#include "utils.h"

#include <llvm/Support/raw_ostream.h>
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Path.h"


namespace PL {

llvm::raw_ostream& error(llvm::raw_ostream& os) {
    os.changeColor(llvm::raw_ostream::RED, true);
    os << "(error) ";
    os.changeColor(llvm::raw_ostream::WHITE, true);
    return os;
}

llvm::raw_ostream& error(llvm::raw_ostream& os, llvm::StringRef msg) {
    error(os) << msg << "\n";
    os.resetColor();
    return os;
}

void exit_on_error(llvm::raw_ostream& os, llvm::StringRef msg) {
  error(os, msg);
  exit(-1);
}

void exit_on_error(llvm::StringRef msg) {
  exit_on_error(llvm::errs(), msg);
}

llvm::StringRef make_absolute(llvm::StringRef path) {
  llvm::SmallString<256> abs_path(path);
  if(auto err = llvm::sys::fs::make_absolute(llvm::Twine("."), abs_path))
    exit_on_error(llvm::errs(), err.message());

  llvm::SmallString<256> real_path(abs_path);
  if(auto err = llvm::sys::fs::real_path(llvm::Twine(abs_path), real_path))
    exit_on_error(llvm::errs(), "Could not find " + path.str());
  return real_path;
}

}
