#ifndef CPUCYCLES_H
#define CPUCYCLES_H

#include <stdint.h>
#include <time.h>

// ARM架构下获取时间戳的通用实现
static inline uint64_t cpucycles(void) {
  uint64_t result;

#ifdef __aarch64__
  // 尝试使用通用计时器而非性能计数器
  __asm__ volatile ("mrs %0, cntvct_el0" : "=r"(result));
#else
  // 32位ARM使用clock_gettime作为备选方案
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  result = ts.tv_sec * 1000000000ULL + ts.tv_nsec;
#endif

  return result;
}

uint64_t cpucycles_overhead(void);

#endif
