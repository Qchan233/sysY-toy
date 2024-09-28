
// Generated from ./SysYParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "SysYParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SysYParser.
 */
class  SysYParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SysYParser.
   */
    virtual std::any visitCompUnit(SysYParser::CompUnitContext *context) = 0;

    virtual std::any visitDecl(SysYParser::DeclContext *context) = 0;

    virtual std::any visitConstDecl(SysYParser::ConstDeclContext *context) = 0;

    virtual std::any visitBType(SysYParser::BTypeContext *context) = 0;

    virtual std::any visitConstDef(SysYParser::ConstDefContext *context) = 0;

    virtual std::any visitConstInitVal(SysYParser::ConstInitValContext *context) = 0;

    virtual std::any visitVarDecl(SysYParser::VarDeclContext *context) = 0;

    virtual std::any visitVarDef(SysYParser::VarDefContext *context) = 0;

    virtual std::any visitInitVal(SysYParser::InitValContext *context) = 0;

    virtual std::any visitFuncDef(SysYParser::FuncDefContext *context) = 0;

    virtual std::any visitFuncName(SysYParser::FuncNameContext *context) = 0;

    virtual std::any visitFuncType(SysYParser::FuncTypeContext *context) = 0;

    virtual std::any visitFuncFparams(SysYParser::FuncFparamsContext *context) = 0;

    virtual std::any visitFuncFparam(SysYParser::FuncFparamContext *context) = 0;

    virtual std::any visitBlock(SysYParser::BlockContext *context) = 0;

    virtual std::any visitBlockItem(SysYParser::BlockItemContext *context) = 0;

    virtual std::any visitStmt(SysYParser::StmtContext *context) = 0;

    virtual std::any visitExp_Func(SysYParser::Exp_FuncContext *context) = 0;

    virtual std::any visitExp_Paren(SysYParser::Exp_ParenContext *context) = 0;

    virtual std::any visitExp_Unary(SysYParser::Exp_UnaryContext *context) = 0;

    virtual std::any visitExp_Num(SysYParser::Exp_NumContext *context) = 0;

    virtual std::any visitExp_MulDivMod(SysYParser::Exp_MulDivModContext *context) = 0;

    virtual std::any visitExp_lVal(SysYParser::Exp_lValContext *context) = 0;

    virtual std::any visitExp_PlusMinus(SysYParser::Exp_PlusMinusContext *context) = 0;

    virtual std::any visitCond_Eq(SysYParser::Cond_EqContext *context) = 0;

    virtual std::any visitCond_Exp(SysYParser::Cond_ExpContext *context) = 0;

    virtual std::any visitCond_Or(SysYParser::Cond_OrContext *context) = 0;

    virtual std::any visitCond_Compare(SysYParser::Cond_CompareContext *context) = 0;

    virtual std::any visitCond_And(SysYParser::Cond_AndContext *context) = 0;

    virtual std::any visitLVal(SysYParser::LValContext *context) = 0;

    virtual std::any visitNumber(SysYParser::NumberContext *context) = 0;

    virtual std::any visitUnaryOp(SysYParser::UnaryOpContext *context) = 0;

    virtual std::any visitFuncRparams(SysYParser::FuncRparamsContext *context) = 0;

    virtual std::any visitConstExp(SysYParser::ConstExpContext *context) = 0;


};

