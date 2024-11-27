#ifndef ALLTYPES
#define ALLTYPES

typedef long long int64_t;
typedef int int32_t;
typedef short int16_t;
typedef signed char int8_t;
typedef unsigned long long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef int wchar_t;
typedef int wint_t;
typedef int wctype_t;

typedef float float_t;
typedef double double_t;

typedef long clock_t;
typedef unsigned long size_t;
typedef long ssize_t;
typedef ssize_t intptr_t;


typedef long long  time_t;

typedef struct __locale_struct * locale_t;
typedef int clockid_t;
typedef int pid_t;
typedef int64_t suseconds_t;
typedef unsigned id_t;
typedef unsigned uid_t;
typedef unsigned gid_t;

typedef int ino_t;
typedef int nlink_t;
typedef int blksize_t;
typedef int blkcnt_t;

struct timespec {
	long tv_sec;
	long tv_nsec;
};

struct timeval { time_t tv_sec; suseconds_t tv_usec; };

typedef void * timer_t;

typedef unsigned long long off_t;

typedef __builtin_va_list __isoc_va_list;
typedef __builtin_va_list va_list;

typedef unsigned mode_t;
typedef unsigned dev_t;

typedef struct __sigset_t { unsigned long __bits[128/sizeof(long)]; } sigset_t;
typedef unsigned socklen_t;
typedef unsigned short sa_family_t;

struct iovec { void *iov_base; size_t iov_len; };

typedef unsigned pthread_t ;
typedef unsigned pthread_cond_t ;
typedef unsigned pthread_rwlock_t ;
typedef unsigned pthread_rwlockattr_t ;
typedef unsigned pthread_spinlock_t ;
typedef unsigned pthread_barrier_t ;
typedef unsigned pthread_barrierattr_t ;
typedef unsigned pthread_key_t;
typedef unsigned pthread_attr_t;
typedef unsigned pthread_condattr_t;
typedef unsigned pthread_mutexattr_t;
typedef unsigned pthread_mutex_t;
typedef unsigned pthread_once_t;

typedef struct _IO_FILE FILE;

typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;
#define __LONG_MAX 0x7fffffffL
#endif