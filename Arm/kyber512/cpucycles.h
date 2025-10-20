#ifndef CPUCYCLES_H
#define CPUCYCLES_H

#include <stdint.h>

// ARM架构下获取CPU周期数的实现
static inline uint64_t cpucycles(void) {
  uint64_t result;
  
  // 使用ARM架构的PMCCNTR_EL0（性能监视器计数寄存器）
  // 需要确保EL0访问已启用（在Linux上通常默认启用）
  __asm__ volatile ("mrs %0, pmccntr_el0" : "=r"(result));
  
  return result;
}

uint64_t cpucycles_overhead(void);

#endif
