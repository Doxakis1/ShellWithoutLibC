#ifndef DOX_SHELL
#define DOX_SHELL
#define NULL (void *)0
#define true 1
#define false 0

#define HEAP_SIZE 0x42694269
extern int errnum;
#define O_RDONLY    00    /* Open for reading only */
#define O_WRONLY    01    /* Open for writing only */
#define O_RDWR      02    /* Open for reading and writing */
#define O_CREAT     0100    /* Create file if it does not exist */
#define O_EXCL      0200    /* Exclusive use flag */
#define O_TRUNC     01000    /* Truncate flag */
#define O_APPEND    02000    /* Set file offset to end prior to each write */
#define O_NONBLOCK  04000    /* Non-blocking mode */
#define O_SYNC      010000    /* Synchronous write option */
#define S_IRUSR  0400  /* Read permission, owner */
#define S_IWUSR  0200  /* Write permission, owner */
#define S_IXUSR  0100  /* Execute permission, owner */
#define S_IRGRP  0040  /* Read permission, group */
#define S_IWGRP  0020  /* Write permission, group */
#define S_IXGRP  0010  /* Execute permission, group */
#define S_IROTH  0004  /* Read permission, others */
#define S_IWOTH  0002  /* Write permission, others */
#define S_IXOTH  0001  /* Execute permission, others */
#define SIGINT 2
#define SIGQUIT 3

#define REGISTER(type, name, reg, value) register type name asm(reg) = value ; 
#define SYS_CALL  asm("syscall");

typedef unsigned int size_t;

typedef struct s_mchunk
{
	size_t size;
	_Bool isUsed;
	struct s_mchunk *next;
} mchunk;

typedef struct s_sigaction
{
	void  (*handler)(int);
	void  *ptr;
    int   sa_mask;
    int   sa_flags;
    void  (*restorer)(void);
} s_sigaction;


size_t d_write(int , const char *, size_t );
size_t d_read(int , char *, size_t );
size_t d_close(int);
int d_open(const char *, int, int);
void d_exit(int);
void *d_brk(unsigned long);
void *d_malloc(size_t);
void d_free(void *ptr);
void d_execve(const char *, const char **, const char **);
int d_fork(void);
int d_wait(int, int *, int);
int d_pipe(int *);
void d_sigaction(int, s_sigaction *, s_sigaction *);
void d_signal(int, void*);


//d_helpers.c
size_t d_strlen(const char *);
void d_bzero(void *, size_t);

#endif
