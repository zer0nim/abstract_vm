#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

# include "IOperand.hpp"
# include "Value.hpp"
# include <vector>

typedef void (*InstrFunc)(std::vector<IOperand *> &stack, Value *param);

void	instrAdd(std::vector<IOperand *> &stack);
void	instrAssert(std::vector<IOperand *> &stack, Value *param);
void	instrDiv(std::vector<IOperand *> &stack, Value *param);
void	instrDump(std::vector<IOperand *> &stack, Value *param);
void	instrExit(std::vector<IOperand *> &stack, Value *param);
void	instrMod(std::vector<IOperand *> &stack, Value *param);
void	instrMul(std::vector<IOperand *> &stack, Value *param);
void	instrPop(std::vector<IOperand *> &stack, Value *param);
void	instrPrint(std::vector<IOperand *> &stack, Value *param);
void	instrPush(std::vector<IOperand *> &stack, Value *param);
void	instrSub(std::vector<IOperand *> &stack, Value *param);

#endif
