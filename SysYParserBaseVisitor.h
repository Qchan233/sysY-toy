
// Generated from ./SysYParser.g4 by ANTLR 4.13.0

#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include "llvm/ADT/DenseMap.h"
#include "llvm/IR/PassManager.h"
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/Error.h>

#include "antlr4-runtime.h"
#include "SysYParserVisitor.h"


/**
 * This class provides an empty implementation of SysYParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
using namespace llvm;
#define ASSERT_MSG(expr, msg)                                         \
    do {                                                              \
        if (!(expr)) {                                                \
            fprintf(stderr, "断言失败：%s\n文件：%s，行：%d\n消息：%s\n", \
                    #expr, __FILE__, __LINE__, msg);                  \
            std::abort();                                             \
        }                                                             \
    } while (0)

class  SysYParserBaseVisitor : public SysYParserVisitor {
public:
  std::unique_ptr<llvm::LLVMContext> TheContext;
  std::unique_ptr<llvm::Module> TheModule;
  std::unique_ptr<llvm::IRBuilder<>> Builder;
  llvm::BasicBlock *Block;
  llvm::Type *BasicType;
  using NameValueMap = std::map<std::string, llvm::AllocaInst *>;
  std::vector<NameValueMap> symbolStack;
  int _insideFunc = 0;
  // std::map<std::string, llvm::AllocaInst *> NamedValues;

  void setSymbol(std::string name, llvm::AllocaInst *value) {
    symbolStack[symbolStack.size() - 1][name] = value;
  }

  llvm::AllocaInst* getSymbol(std::string name) {
    // search from top to bottom
    for (int i = symbolStack.size() - 1; i >= _insideFunc; i--) {
      auto it = &symbolStack[i];
      auto symbol = it->find(name);
      if (symbol != it->end()) {
        return symbol->second;
      }
    }
    ASSERT_MSG(0, "未找到符号");
  }

  SysYParserBaseVisitor() {
    TheContext = std::make_unique<llvm::LLVMContext>();
    TheModule = std::make_unique<llvm::Module>("SysY Module", *TheContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
    llvm::FunctionType *mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(*TheContext), {}, false);
    llvm::Function *mainFunction = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", *TheModule);

    Block = llvm::BasicBlock::Create(*TheContext, "entry", mainFunction);
    Builder->SetInsertPoint(Block);

    symbolStack.push_back(NameValueMap());
  }

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    visitChildren(ctx);
    std::cout << "Generated IR: " << std::endl;
    auto mainFunction = TheModule->getFunction("main");
    mainFunction->print(llvm::errs()); 
    std::cout << std::endl;
    symbolStack.pop_back();

    return nullptr;
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    std::cout << "Not Implemented" << std::endl;
    assert(0);
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    auto basicType = ctx->getText();
    if (basicType == "int") {
      BasicType = llvm::Type::getInt32Ty(*TheContext);
    }
    else if (basicType == "void")
    {
      BasicType = llvm::Type::getVoidTy(*TheContext);
    }
    else if (basicType == "float")
    {
      BasicType = llvm::Type::getFloatTy(*TheContext);
    }
    else
    {
      assert(0);
    }
    
    return nullptr;
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    visit(ctx->bType());
    // visit(ctx->varDef(0));
    for (auto varDef : ctx->varDef())
    {
      visit(varDef);
    }

    return nullptr;
  }

  llvm::Type* computeType(std::vector<llvm::Value*> &array)
  {
    if (array.size() == 0)
    {
      return BasicType;
    }
    else
    {
      ASSERT_MSG(llvm::isa<llvm::ConstantInt>(array[0]), "数组大小应为常数");
      int size = llvm::cast<llvm::ConstantInt>(array[0])->getSExtValue();
      ASSERT_MSG(size >= 0, "数组大小不能为负数");
      std::vector baseType(array.begin() + 1, array.end());
      auto computedType = llvm::ArrayType::get(computeType(baseType), size);
      return computedType;
    }
  }
  
  virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
    std::vector<llvm::Value*> array_info = {};
    for (auto exp : ctx->constExp())
    {
      array_info.push_back(std::any_cast<llvm::Value*>(visit(exp)));
    }
    auto type = computeType(array_info);
    auto varName = ctx->IDENT()->getText();
    llvm::AllocaInst* allocaInst = Builder->CreateAlloca(type, nullptr, varName);
    setSymbol(varName, allocaInst);
    return nullptr;
  }

  virtual std::any visitInitVal(SysYParser::InitValContext *ctx) override {
    return visitChildren(ctx); 
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    auto mainBlock = Block;
    auto typeString = ctx->funcType()->getText();
    llvm::Type* returnType;
    if (typeString == "int") {
      returnType = llvm::Type::getInt32Ty(*TheContext); 
    }
    else if (typeString == "float") {
      returnType = llvm::Type::getFloatTy(*TheContext);
    }
    else if (typeString == "void") {
      returnType = llvm::Type::getVoidTy(*TheContext);
    }
    else {
      ASSERT_MSG(0, "未知的函数返回类型");
    };

    std::string funcName = ctx->funcName()->IDENT()->getText();

    symbolStack.push_back(NameValueMap());

    std::vector <llvm::Type*> argTypes;
    std::vector <std::string> argNames = {};
    if (ctx->funcFparams() == nullptr) {
      argTypes = {};
    }
    else{
      argTypes = std::any_cast<std::vector<llvm::Type*>> (visit(ctx->funcFparams()));
    }

    llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, argTypes, false);
    llvm::Function* F = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, funcName, TheModule.get());

    auto BB = llvm::BasicBlock::Create(*TheContext, "entry", F);
    Builder->SetInsertPoint(BB);

    if (ctx->funcFparams() != nullptr) {
      for (auto argName : ctx->funcFparams()->funcFparam())
      {
        argNames.push_back(argName->IDENT()->getText());
      }

      for (int i=0; i < argNames.size(); i++) {
        auto allocInst = Builder->CreateAlloca(argTypes[i], nullptr, argNames[i]);
        setSymbol(argNames[i], allocInst);
      }
    }

    _insideFunc = 1;
    if (auto RetVal = std::any_cast<llvm::Value*>(visit(ctx->block()))) {
      _insideFunc = 0;
      Builder->CreateRet(RetVal);
      F->print(llvm::errs());
      Builder->SetInsertPoint(mainBlock); 
      symbolStack.pop_back();
      return F;
    }

    return nullptr;
  }

  virtual std::any visitFuncName(SysYParser::FuncNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFparams(SysYParser::FuncFparamsContext *ctx) override {
    std::vector<llvm::Type*> argTypes = {};

    for (auto funcFparam : ctx->funcFparam())
    {
      argTypes.push_back(std::any_cast<llvm::Type*>(visit(funcFparam)));
    }
    return argTypes;
  }

  virtual std::any visitFuncFparam(SysYParser::FuncFparamContext *ctx) override {
    std::vector<llvm::Value*> arraryInfo = {};
    visit(ctx->bType());
    if (ctx->children.size() > 2)
    {
      arraryInfo.push_back(llvm::ConstantInt::get(*TheContext, llvm::APInt(32, 0)));
      for (auto exp : ctx->exp())
      {
        arraryInfo.push_back(std::any_cast<llvm::Value*>(visit(exp)));
      }
    }
    return computeType(arraryInfo);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    llvm::Value* last = nullptr;
    for (auto blockItem : ctx->blockItem())
    {
      last = std::any_cast<llvm::Value*>(visit(blockItem));
    }
    return last;
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSmtAssign(SysYParser::SmtAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtExp(SysYParser::StmtExpContext *ctx) override {
    if (ctx->exp() == nullptr)
    {
      return nullptr;
    }
    return visit(ctx->exp());
  }

  virtual std::any visitStmtBlock(SysYParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtIf(SysYParser::StmtIfContext *ctx) override {
    auto condition = std::any_cast<llvm::Value*>(visit(ctx->cond()));

    // 如果条件是整型
    if (condition->getType()->isIntegerTy()) {
        condition = Builder->CreateICmpNE(condition, llvm::ConstantInt::get(condition->getType(), 0), "nonzero");
    } 
    // 如果条件是浮点型
    else if (condition->getType()->isFloatTy() || condition->getType()->isDoubleTy()) {
        condition = Builder->CreateFCmpONE(condition, llvm::ConstantFP::get(condition->getType(), 0.0), "nonzero");
    }

    auto TheFunction = Builder->GetInsertBlock()->getParent();
    // Create blocks for the then and else cases.  Insert the 'then' block at the
    // end of the function.
    auto ThenBB = llvm::BasicBlock::Create(*TheContext, "then", TheFunction);
    auto ElseBB = llvm::BasicBlock::Create(*TheContext, "else");
    auto MergeBB = llvm::BasicBlock::Create(*TheContext, "ifcont");    

    Builder->CreateCondBr(condition, ThenBB, ElseBB);

    Builder->SetInsertPoint(ThenBB);

    llvm::Value* ThenV = std::any_cast<llvm::Value*>(visit(ctx->stmt(0)));
    if (!ThenV)
      return nullptr;

    Builder->CreateBr(MergeBB);
    ThenBB = Builder->GetInsertBlock();

    TheFunction->insert(TheFunction->end(), ElseBB);
    Builder->SetInsertPoint(ElseBB);
    auto ElseV = std::any_cast<llvm::Value*>(visit(ctx->stmt(1)));
    if (!ElseV)
      return nullptr;
    if (ThenV->getType() != ElseV->getType())
    {
      std::cout << "Then and Else should have same type" << std::endl;
      assert(0);
    }
    Builder->CreateBr(MergeBB);
    ElseBB = Builder->GetInsertBlock();

    TheFunction->insert(TheFunction->end(), MergeBB); 
    Builder->SetInsertPoint(MergeBB);
    auto PN = Builder->CreatePHI(ThenV->getType(), 2, "iftmp");

    PN->addIncoming(ThenV, ThenBB);
    PN->addIncoming(ElseV, ElseBB);
    return (llvm::Value*) (PN);
  }

  virtual std::any visitStmtWhile(SysYParser::StmtWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtBreak(SysYParser::StmtBreakContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtContinue(SysYParser::StmtContinueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmtReturn(SysYParser::StmtReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Func(SysYParser::Exp_FuncContext *ctx) override {
    auto funcName = ctx->funcName()->IDENT()->getText();
    auto F = TheModule->getFunction(funcName);
    ASSERT_MSG(F, "未找到函数");
    std::vector<llvm::Value*> ArgsV;
    if (ctx->funcRparams() != nullptr)
    {
      for (auto exp : ctx->funcRparams()->exp())
      {
        ArgsV.push_back(std::any_cast<llvm::Value*>(visit(exp)));
      }
    }
    return (llvm::Value*) Builder->CreateCall(F, ArgsV, "calltmp");
  }

  virtual std::any visitExp_Paren(SysYParser::Exp_ParenContext *ctx) override {
    return std::any_cast<llvm::Value*>(visit(ctx->exp()));
  }

  virtual std::any visitExp_Unary(SysYParser::Exp_UnaryContext *ctx) override {
    auto unaryOp = ctx->unaryOp()->getText()[0];
    auto exp = ctx->exp();
    switch (unaryOp)
    {
    case '+':
      return visit(exp);
      break;
    case '-':
      return Builder->CreateNeg(std::any_cast<llvm::Value*>(visit(exp)));
      break; 
    case '!':
      return Builder->CreateNot(std::any_cast<llvm::Value*>(visit(exp)));
      break;
    default:
      break;
    }
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Num(SysYParser::Exp_NumContext *ctx) override {
    llvm::Value* val = llvm::ConstantInt::get(*TheContext, llvm::APInt(32, std::stoi(ctx->getText())));
    return val;
  }

  virtual std::any visitExp_MulDivMod(SysYParser::Exp_MulDivModContext *ctx) override {
    llvm::Value* L = std::any_cast<llvm::Value*> (visit(ctx->exp(0)));
    llvm::Value* R = std::any_cast<llvm::Value*> (visit(ctx->exp(1)));

    auto op = ctx->op->getText()[0];
    switch (op)
    {
    case '*':
      return Builder->CreateMul(L, R, "multmp");
      break;
    case '/':
      return Builder->CreateUDiv(L, R, "divtmp");
      break;
    case '%':
      return Builder->CreateSRem(L, R, "modtmp");
      break;
    default:
      break;
    }
    return visitChildren(ctx);
  }

  virtual std::any visitExp_lVal(SysYParser::Exp_lValContext *ctx) override {
    auto varName = ctx->lVal()->IDENT()->getText();
    auto A = getSymbol(varName);
    return (llvm::Value*) Builder->CreateLoad(A->getAllocatedType(), A, varName);
  }

  virtual std::any visitExp_PlusMinus(SysYParser::Exp_PlusMinusContext *ctx) override {
    llvm::Value* L = std::any_cast<llvm::Value*> (visit(ctx->exp(0)));
    llvm::Value* R = std::any_cast<llvm::Value*> (visit(ctx->exp(1)));

    auto op = ctx->op->getText()[0];
    switch (op)
    {
    case '+':
      return Builder->CreateAdd(L, R, "addtmp");
    case '-':
      return Builder->CreateSub(L, R, "subtmp");
    default:
      break;
    }
    return visitChildren(ctx);
  }

  virtual std::any visitCond_Exp(SysYParser::Cond_ExpContext *ctx) override {
    return std::any_cast<llvm::Value*>(visit(ctx->exp()));
  }

  virtual std::any visitCond_Or(SysYParser::Cond_OrContext *ctx) override {
    auto L = std::any_cast<llvm::Value*>(visit(ctx->cond(0)));
    auto R = std::any_cast<llvm::Value*>(visit(ctx->cond(1)));

    return Builder->CreateOr(L, R, "ortmp");
  }

  virtual std::any visitCond_Compare(SysYParser::Cond_CompareContext *ctx) override {
    auto L = std::any_cast<llvm::Value*>(visit(ctx->cond(0)));
    auto R = std::any_cast<llvm::Value*>(visit(ctx->cond(1)));

    auto op = ctx->op;

    switch (op->getType())
    {
    case SysYParser::LT:
      return Builder->CreateICmpULT(L, R, "cmptmp");
      break;
    case SysYParser::GT:
      return Builder->CreateICmpUGT(L, R, "cmptmp");
      break;
    case SysYParser::LE:
      return Builder->CreateICmpULE(L, R, "cmptmp");
      break;
    case SysYParser::GE:
      return Builder->CreateICmpUGE(L, R, "cmptmp");
      break;
    default:
      std::cout << "Unkown Operator" << std::endl;
      assert(0);
      break;
    }
  }
  
  virtual std::any visitCond_And(SysYParser::Cond_AndContext *ctx) override {
    auto L = std::any_cast<llvm::Value*>(visit(ctx->cond(0)));
    auto R = std::any_cast<llvm::Value*>(visit(ctx->cond(1)));

    return Builder->CreateAnd(L, R, "andtmp");
  }

  virtual std::any visitCond_Eq(SysYParser::Cond_EqContext *ctx) override {
    auto L = std::any_cast<llvm::Value*>(visit(ctx->cond(0)));
    auto R = std::any_cast<llvm::Value*>(visit(ctx->cond(1)));

    auto op = ctx->op;

    switch (op->getType())
    {
      case SysYParser::EQ:
        return Builder->CreateICmpEQ(L, R, "cmptmp");
        break;
      case SysYParser::NEQ:
        return Builder->CreateICmpNE(L, R, "cmptmp");
        break;
      default:
        std::cout << "Unkown Operator" << std::endl;
        assert(0);
        break;
    }
  }

  virtual std::any visitLVal(SysYParser::LValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(SysYParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncRparams(SysYParser::FuncRparamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstExp(SysYParser::ConstExpContext *ctx) override {
    return visitChildren(ctx);
  }


};

