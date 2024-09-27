
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
#include <llvm/Support/TargetSelect.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Value.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/Error.h>

#include "antlr4-runtime.h"
#include "SysYParserVisitor.h"


/**
 * This class provides an empty implementation of SysYParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SysYParserBaseVisitor : public SysYParserVisitor {
public:
  std::unique_ptr<llvm::LLVMContext> TheContext;
  std::unique_ptr<llvm::Module> TheModule;
  std::unique_ptr<llvm::IRBuilder<>> Builder;
  llvm::BasicBlock *Block;

  SysYParserBaseVisitor() {
    TheContext = std::make_unique<llvm::LLVMContext>();
    TheModule = std::make_unique<llvm::Module>("SysY Module", *TheContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
    Block = llvm::BasicBlock::Create(*TheContext, "entry", TheModule->getFunction("main"));
    Builder->SetInsertPoint(Block);
  }

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    llvm::Value *result = std::any_cast<llvm::Value*>(visitChildren(ctx));
    std::cout << "Generated IR: " << std::endl;
    result->print(llvm::errs()); 
    std::cout << std::endl;
    return nullptr;
  }

  virtual std::any visitDecl(SysYParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDecl(SysYParser::ConstDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBType(SysYParser::BTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstDef(SysYParser::ConstDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(SysYParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInitVal(SysYParser::InitValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(SysYParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncName(SysYParser::FuncNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncType(SysYParser::FuncTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFparams(SysYParser::FuncFparamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncFparam(SysYParser::FuncFparamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(SysYParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlockItem(SysYParser::BlockItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(SysYParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Func(SysYParser::Exp_FuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Paren(SysYParser::Exp_ParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Unary(SysYParser::Exp_UnaryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_Num(SysYParser::Exp_NumContext *ctx) override {
    llvm::Value* val = llvm::ConstantInt::get(*TheContext, llvm::APInt(32, std::stoi(ctx->getText())));
    return val;
  }

  virtual std::any visitExp_MulDivMod(SysYParser::Exp_MulDivModContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_lVal(SysYParser::Exp_lValContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExp_PlusMinus(SysYParser::Exp_PlusMinusContext *ctx) override {
    llvm::Value* L = std::any_cast<llvm::Value*> (visit(ctx->exp(0)));
    llvm::Value* R = std::any_cast<llvm::Value*> (visit(ctx->exp(1)));

    auto op = ctx->op->getText()[0];
    switch (op)
    {
    case '+':
      return Builder->CreateAdd(L, R, "addtmp");
      break;
    case '-':
      return Builder->CreateSub(L, R, "subtmp");
      break;
    default:
      break;
    }
    return visitChildren(ctx);
  }

  virtual std::any visitCond(SysYParser::CondContext *ctx) override {
    return visitChildren(ctx);
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