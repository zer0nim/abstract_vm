#ifndef INSTRUCTIONS_HPP
# define INSTRUCTIONS_HPP

# include "IOperand.hpp"
# include "Value.hpp"
# include "Factory.hpp"
# include <vector>

typedef void (*InstrFunc)(Factory &factory, std::vector<IOperand const *> &stack, Value *param);

void	instrAdd(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrAssert(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrDiv(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrDump(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrMod(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrMul(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrPop(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrPrint(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrPush(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrSub(Factory &factory, std::vector<IOperand const *> &stack, Value *param);

// v__Bonus_________________________

void	instrAbs(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrMin(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrMax(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrPow(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrNot(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrAnd(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrOr(Factory &factory, std::vector<IOperand const *> &stack, Value *param);
void	instrXor(Factory &factory, std::vector<IOperand const *> &stack, Value *param);

#endif
