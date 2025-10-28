#ifndef CPUCYCLES_H
#define CPUCYCLES_H

#include <stdint.h>
#include <time.h>  // 用于clock_gettime


// 仅支持x86架构（x86_64和i386）
#if defined(__x86_64__) || defined(__i386__)

static inline uint64_t cpucycles(void) {
  struct timespec ts;
  // 使用单调时钟（不受系统时间调整影响，适合计时）
  clock_gettime(CLOCK_MONOTONIC, &ts);
  // 转换为纳秒级64位时间戳（秒数*1e9 + 纳秒数）
  return (uint64_t)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

#else
// 非x86架构编译时报错
#error "cpucycles.h only supports x86 architectures (x86_64/i386)"
#endif


// 声明开销计算函数（需在其他源文件中实现）
uint64_t cpucycles_overhead(void);

#endif  // CPUCYCLES_H