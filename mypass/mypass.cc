
#include <llvm/Pass.h>

#include <llvm/IR/InstIterator.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/InstrTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/Intrinsics.h>
#include <llvm/IR/GlobalVariable.h>
#include <llvm/IR/DebugLoc.h>
#include <llvm/IR/DebugInfo.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/DataLayout.h>

#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/SmallPtrSet.h>
#include <llvm/ADT/StringSet.h>

#include <llvm/Transforms/Utils/ModuleUtils.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>

#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/Casting.h>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
using namespace llvm;
using namespace std;

namespace {
  void perI(Instruction &I) {
    BitCastInst* BCI = dyn_cast<BitCastInst>(&I);
    if (!BCI) {
      return;
    }
    // get dest ty
    std::string type_str;
    llvm::raw_string_ostream type_rso(type_str);
    BCI->getDestTy()->print(type_rso);
    outs() << type_rso.str() << "\n";
    outs() << BCI->getOperand(0) << "\n";;

    // if (type_rso.str().find("l2cap_chan")) {
    //   var_tracking[BCI] = std::make_pair(State::chan, std::vector<int>());
    //   var_tracking[BCI->getOperand(0)] = std::make_pair(State::chan, std::vector<int>());
    // }
    // if (type_rso.str().find("l2cap_conn")) {
    //   var_tracking[BCI] = std::make_pair(State::conn, std::vector<int>());
    //   var_tracking[BCI->getOperand(0)] = std::make_pair(State::conn, std::vector<int>());
    // }
    
  }


  struct SkeletonPass : public FunctionPass {
    static char ID;
    SkeletonPass() : FunctionPass(ID) {}

    virtual bool runOnFunction(Function &F) {
      // errs() << "I saw a function called " << F.getName() << "!\n";
      outs() << "I saw a function called " << F.getName() << "!\n";

      // per basic block
      for (auto& BB: F) {
        // per instruction
        for (auto& I: BB) {
          perI(I);
        }
      }
      return false;
    }
  };
}

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                         legacy::PassManagerBase &PM) {
  PM.add(new SkeletonPass());
}
static RegisterStandardPasses
  RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                 registerSkeletonPass);