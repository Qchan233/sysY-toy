
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
  llvm::Type *BasicType;
  std::map<std::string, llvm::AllocaInst *> NamedValues;

  SysYParserBaseVisitor() {
    TheContext = std::make_unique<llvm::LLVMContext>();
    TheModule = std::make_unique<llvm::Module>("SysY Module", *TheContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
    llvm::FunctionType *mainType = llvm::FunctionType::get(llvm::Type::getInt32Ty(*TheContext), {}, false);
    llvm::Function *mainFunction = llvm::Function::Create(mainType, llvm::Function::ExternalLinkage, "main", *TheModule);

    Block = llvm::BasicBlock::Create(*TheContext, "entry", mainFunction);
    Builder->SetInsertPoint(Block);

    NamedValues.clear();
  }

  virtual std::any visitCompUnit(SysYParser::CompUnitContext *ctx) override {
    visitChildren(ctx);
    std::cout << "Generated IR: " << std::endl;
    auto mainFunction = TheModule->getFunction("main");
    mainFunction->print(llvm::errs()); 
    std::cout << std::endl;
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

  virtual std::any visitVarDef(SysYParser::VarDefContext *ctx) override {
    std::string varName = ctx->IDENT()->getText();
    llvm::GlobalVariable *var = TheModule->getGlobalVariable(varName);
    if (var != nullptr)
    {
      std::cout << varName << "Variable already defined" << std::endl;
      assert(0);
    }

    llvm::AllocaInst* allocaInst = Builder->CreateAlloca(BasicType, nullptr, varName);
    NamedValues[varName] = allocaInst;
    return nullptr;
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
    return visit(ctx->exp());
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
    auto A = NamedValues[varName];
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
      break;
    case '-':
      return Builder->CreateSub(L, R, "subtmp");
      break;
    default:
      break;
    }
    return visitChildren(ctx);
  }

  virtual std::any visitCond_Exp(SysYParser::Cond_ExpContext *ctx) override {
    return visit(ctx->exp());
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

