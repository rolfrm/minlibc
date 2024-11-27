#include <stdint.h>

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s) {
    int prev = *p;
    if (*p == t) {
        *p = s;
    }
    return prev; // Return the previous value.
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v) {
    int prev = *p;
    *p = v;
    return prev; // Return the previous value.
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v) {
    int prev = *p;
    *p += v;
    return prev; // Return the previous value.
}

#define a_and a_and
static inline void a_and(volatile int *p, int v) {
    *p &= v; // Perform bitwise AND.
}

#define a_or a_or
static inline void a_or(volatile int *p, int v) {
    *p |= v; // Perform bitwise OR.
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile uint64_t *p, uint64_t v) {
    *p &= v; // Perform bitwise AND on 64-bit values.
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile uint64_t *p, uint64_t v) {
    *p |= v; // Perform bitwise OR on 64-bit values.
}

#define a_inc a_inc
static inline void a_inc(volatile int *p) {
    (*p)++; // Increment the value.
}

#define a_dec a_dec
static inline void a_dec(volatile int *p) {
    (*p)--; // Decrement the value.
}

#define a_store a_store
static inline void a_store(volatile int *p, int x) {
    *p = x; // Store the value.
}

#define a_barrier a_barrier
static inline void a_barrier() {
    // In a single-threaded application, no memory barrier is required.
}

#define a_spin a_spin
static inline void a_spin() {
    // In a single-threaded application, no spin-loop logic is required.
}

#define a_crash a_crash
static inline void a_crash() {
    // Simulate a crash with an intentional illegal instruction or infinite loop.
    *((volatile int *)0) = 0; // Dereference a null pointer to crash.
}

#define a_ctz_64 a_ctz_64
static inline int a_ctz_64(uint64_t x) {
    // Count trailing zeros (single-threaded; fallback to a simple loop if not using built-ins).
    if (x == 0) return 64;
    int count = 0;
    while ((x & 1) == 0) {
        count++;
        x >>= 1;
    }
    return count;
}

#define a_ctz_32 a_ctz_32
static inline int a_ctz_32(uint32_t x) {
    // Count trailing zeros for 32-bit values.
    if (x == 0) return 32;
    int count = 0;
    while ((x & 1) == 0) {
        count++;
        x >>= 1;
    }
    return count;
}

#define a_clz_64 a_clz_64
static inline int a_clz_64(uint64_t x) {
    // Count leading zeros for 64-bit values.
    if (x == 0) return 64;
    int count = 0;
    uint64_t mask = 1ULL << 63;
    while ((x & mask) == 0) {
        count++;
        mask >>= 1;
    }
    return count;
}