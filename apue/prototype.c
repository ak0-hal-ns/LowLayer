// <aio.h>

int aio_cancel(int fd, struct aioc *aiocb);

int aio_error(const struct aiocb *aiocb);

int aio_fsync(int op, struct aiocb *aiocb);

int aio_read(struct aiocb *aiocb);

ssize_t aio_return(const struct aiocb *aiocb);

int aio_suspend(const struct aiocb *const list[], int nent, const struct timespec *timeout);

int aio_write(struct aiocb *aiocb);

int lio_listio(int mode, struct aiocb *restrict const list[restrict], int nent, struct sigevent *restrict sigev);


// <arpa/inet.h>

uint32_t htonl(uint32_t hostint32);

uint16_t htons(uint16_t hostint16);

const char *inet_ntop(int domain, const void *restrict addr, char *restrict str, socklen_t size);

int inet_pton(int domain, const char *restrict str, void *restrict addr);

uint32_t ntohl(uint32_t netint32);

uint16_t ntohs(uint16_t netint16);


// <dirent.h>

int closedir(DIR *dp);

DIR *fdopendir(int fd);

DIR *opendir(const char *path);

struct dirent *readdir(DIR *dp);

void rewinddir(DIR *dp);

void seekdir(DIR *dp, long loc);

long telldir(DIR *dp);


// <fcntl.h>

int creat(const char *path, mode_t mode);

int fcntl(int fd, int cmd, ... /* int arg */);

int getopt(int argc, char *const argv[], const char *options);

int open(const char *path, int oflag, ... /* mode_t mode */);

int openat(int fd, const char *path, int oflag, ... /* mode_t mode */);

int posix_openat(int oflag);  // <stdlib.h>


// <grp.h>
void endgrent(void);

struct group *getgrent(void);

struct group *getgrgid(gid_t gid);

struct group *getgrnam(const char *name);

int initgroups(const char *username, gid_t basegid);  /* <unistd.h> Mac OS X */

void setgrent(void);

int setgroups(int ngroups, const gid_t grouplist[]);  /* <unistd.h> Mac OS X */


// <netdb.h>

void endhostent(void);

void endnetent(void);

void endprotoent(void);

void endservent(void);

void freeaddrinfo(struct addrinfo *ai);  // <sys/socket.h>

const char *gai_strerror(int error);

int getaddrinfo(const char *restrict host, const char *restrict service, const struct addrinfo *restrict hint, struct addrinfo **restrict res);  // <sys/socket.h>

struct hostent *gethostent(void);

int getnameinfo(const struct sockaddr *restrict addr, sockelen_t alen, char *restrict host, socklen_t hostlen, char *restrict service, sockelen_t servlen, unsigned int flgas);  // <sys/socket.h>

struct netent *getnetbyaddr(uint32_t net, int type);

struct netent *getnetbyname(const char *name);

struct protoent *getprotobyname(const char *name);

struct protoent *getprotobynumber(int proto);

struct protoent *getprotoent(void);

struct servent *getservbyname(const char *name, const char *proto);

struct servent *getservbyport(int port, const char *proto);

struct servent *getservent(void);

void sethostent(int stayopen);

void setnetent(int stayopen);

void setprotoent(int stayopen);

void setservent(int stayopen);


// <poll.h>

int poll(struct pollfd fdarray[], nfds_t nfds, int timeout);


// <pthread.h>

int pthread_atfork(void (*prepare)(void), void (*parent)(void), void (*child)(void));

int pthread_attr_destroy(pthread_attr_t *attr);

int pthread_attr_getdetachstate(const pthread_attr_t *attr, int *detachstate);

int pthread_attr_getguardsize(const pthread_attr_t *restrict attr, size_t *restrict guardsize);

int pthread_attr_getstack(const pthread_attr_t *restrict attr, void **restrict stackaddr, size_t *restrict stacksize);

int pthread_attr_getstacksize(const pthread_attr_t *restrict attr, size_t *restrict stacksize);

int pthread_attr_init(pthread_attr_t *attr);

int pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);

int pthread_attr_setguardsize(pthread_attr_t *attr, size_t guardsize);

int pthread_attr_setstack(const pthread_attr_t *attr, void *stackaddr, size_t *stacksize);

int pthread_barrierattr_destroy(pthread_barrierattr_t *attr);

int pthread_barrierattr_getpshared(const pthread_barrierattr_t *restrict attr, int *restrict pshared);

int pthread_barrierattr_init(pthread_barrierattr_t *attr);

int pthread_barrierattr_setpshared(pthread_barrierattr_t *attr, int pshared);

int pthread_barrier_destroy(pthread_barrier_t *barrier);

int pthread_barrier_init(pthread_barrier_t *restrict barrier, const pthread_barrierattr_t *restrict attr, unsigned int count);

int pthread_barrier_wait(pthread_barrier_t *barrier);

int pthread_cancel(pthread_t tid);

void pthread_cleanup_pop(int execute);

void pthread_cleanup_push(void (*rtn)(void *), void *arg);

int pthread_condattr_destroy(pthread_condattr_t *attr);

int pthread_condattr_getclock(const pthread_condattr_t *restrict attr, clockid_t *restrict clock_id);

int pthread_condattr_getpshared(const pthread_condattr_t *restrict attr, int *restrict pshared);

int pthread_condattr_init(pthread_condattr_t *attr);

int pthread_condattr_setclock(pthread_condattr_t *attr, clockid_t clock_id);

int pthread_condattr_setpshared(pthread_condattr_t *attr, int pshared);

int pthread_cond_broadcast(pthread_cond_t *cond);

int pthread_cond_destroy(pthread_cond_t *cond);

int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);

int pthread_cond_signal(pthread_cond_t *cond);

int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict timeout);

int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);

int pthread_create(pthread_t *restrict tidp, const pthread_attr_t *restrict attr, void * (*start_rtn)(void *), void *restrict arg);

int pthread_detach(pthread_t tid);

int pthread_equal(pthread_t tid1, pthread_t tid2);

void pthread_exit(void *rval_ptr);

void *pthread_getspecific(pthread_key_t key);

int pthread_join(pthread_t thread, void **rval_ptr);

int pthread_key_create(pthread_key_t *keyp, void (*destructor)(void *));

int pthread_key_delete(pthread_key_t key);

int pthread_kill(pthread_t thread, int signo);

int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr, int *restrict pshared);

int pthread_mutexattr_getrobust(const pthread_mutexattr_t *restrict attr, int *restrict robust);

int pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr, int *restrict type);

int pthread_mutextattr_init(pthread_mutextattr_t *attr);

int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr, int pshared);

int pthread_mutexattr_setrobust(pthread_mutexattr_t *attr, int robust);

int pthread_mutextattr_settype(pthread_mutexattr_t *attr, int type);

int pthread_mutex_consistent(pthread_mutex_t *mutex);

int pthread_mutex_destroy(pthread_mutex_t *mutex);

int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);

int pthread_mutex_lock(pthread_mutex_t *mutex);

int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex, const struct timespec *restrict tsptr);

int pthread_mutex_trylock(pthread_mutex_t *mutex);

int pthread_mutex_unlock(pthread_mutex_t *mutex);

int pthread_once(pthread_once_t *initflag, void (*initfn)(void));

int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);

int pthread_rwlockattr_getshared(const pthread_rwlockattr_t *restrict attr, int *restrict pshared);

int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);

int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr, int pshared);

int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);

int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, const pthread_rwlockattr_t *restrict attr);

int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);

int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict tsptr);

int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock, const struct timespec *restrict tsptr);

int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);

int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);

int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);

int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);

pthread_t pthread_self(void);

int pthread_setcancelstate(int state, int *oldstate);

int pthread_setcanceltype(int type, int *oldtype);

int pthread_setspecific(pthread_key_t key, const void *value);

int pthread_sigmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);

int pthread_spin_destroy(pthread_spinlock_t *lock);

int pthread_spin_init(pthread_spinlock_t *lock, int pshared);

int pthread_spin_lock(pthread_spinlock_t *lock);

int pthread_spin_trylock(pthread_spinlock_t *lock);

int pthread_spin_unlock(pthread_spinlock_t *lock);

void pthread_testcancel(void);


// <pwd.h>

void endpwent(void);

struct passwd *getpwent(void);

struct passwd *getpwuid(uid_t uid);

void setpwent(void);


// <semaphore.h>

int sem_close(sem_t *sem);

int sem_destroy(sem_t *sem);

int sem_getvalue(sem_t *restrict sem, int *restrict valp);

int sem_init(sem_t *sem, int pshared, unsigned int value);

sem_t *sem_open(const char *name, int oflag, ... /* mode_t mode, unsigned int value */);

int sem_post(sem_t *sem);

int sem_trywait(sem_t *sem);

int sem_unlink(const char *name);

int sem_wait(sem_t *sem);


// <setjmp.h>

void longjmp(jmp_buf env, int val);

int setjmp(jmp_buf env);

void siglongjmp(sigjmp_buf env, int val);

int sigsetjmp(sigjmp_buf env, int savemask);


// <shadow.h>

void endspent(void);

struct spwd *getspent(void);

struct spwd *getspnam(const char *name);

void setspent(void);


// <signal.h>

int kill(pid_t pid, int signo);

void psiginfo(const siginfo_t *info, const char *msg);

void psignal(int signo, const char *msg);

int raise(int signo);

int sig2str(int signo, char *str);

int sigaction(int signo, const struct sigaction *restrict act, struct sigaction *restrict oact);

int sigaddset(sigset_t *set, int signo);

int sigdelset(sigset_t *set, int signo);

int sigemptyset(sigset_t *set);

int sigfillset(sigset_t *set);

int sigismember(const sigset_t *set, int signo);

void (*signal(int signo, void (*func)(int)))(int);

int sigpending(sigset_t *set);

int sigprocmask(int how, const sigset_t *restrict set, sigset_t *restrict oset);

int sigqueue(pid_t pid, int signo, const union sigval value);

int sigsuspend(const sigset_t *sigmask);

int sigwait(const sigset_t *restrict set, int *restrict signop);

int str2sig(const char *str, int *signop);


// <stdarg.h>

int vdprintf(int fd, const char *restrict format, va_list arg);  // <stdio.h>

int vfprintf(FILE *restrict fp, const char *restrict format, va_list arg);  // <stdio.h>

int vfscanf(FILE *restrict fp, const char *restrict format, va_list arg);  // <stdio.h>

int vprintf(const char *restrict format, va_list arg);  // <stdio.h>

int vscanf(const char *restrict format, va_list arg);  // <stdio.h>

int vsnprintf(char *restrict buf, size_t n, const char *restrict format, va_list arg);  // <stdio.h>

int vsprintf(char *restrict buf, const char *restrict format, va_list arg);  // <stdio.h>

int vsscanf(const char *restrict buf, const char *restrict format, va_list arg);  // <stdio.h>

void vsyslog(int priority, const char *format, va_list arg);  // <syslog.h>


// <stdio.h>

void clearerr(FILE *fp);

char *ctermid(char *ptr);

int dprintf(int fd, const char *restrict format, ...);

int fclose(FILE *fp);

FILE *fdopen(int fd, const char *type);

int feof(FILE *fp);

int ferror(FILE *fp);

int fflush(FILE *fp);

int fgetc(FILE *fp);

int fgetpos(FILE *restrict fp, fpos_t *restrict pos);

char *fgets(char *restrict buf, int n, FILE *restrict fp);

int fileno(FILE *fp);

void flockfile(FILE *fp);

FILE *fmemopen(void *restrict buf, size_t size, const char *restrict type);

FILE *fopen(const char *restrict path, const char *restrict type);

int fprintf(FILE *restrict fp, const char *restrict format, ...);

int fputc(int c, FILE *fp);

int fputs(const char *restrict str, FILE *restrict fp);

size_t fread(void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);

FILE *freopen(const char *restrict path, const char *restrict type, FILE *restrict fp);

int fscanf(FILE *restrict fp, const char *restrict format, ...);

int fseek(FILE *fp, long offset, int whence);

int fseeko(FILE *fp, off_t offset, int whence);

int fsetpos(FILE *fp, const fpos_t *pos);

long ftell(FILE *fp);

off_t ftello(FILE *fp);

int ftrylockfile(FILE *fp);

void funlockfile(FILE *fp);

int fwide(FILE *fp, int mode);  // <wchar.h>

size_t fwrite(const void *restrict ptr, size_t size, size_t nobj, FILE *restrict fp);

int getc(FILE *fp);

int getchar(void);

int getchar_unlocked(void);

int getc_unlocked(FILE *fp);

char *gets(char *buf);

FILE *open_memstream(char **bufp, size_t *sizep);

int pclose(FILE *fp);

void perror(const char *msg);

FILE *popen(const char *cmdstring, const char *type);

int printf(const char *restrict format, ...);

int putc(int c, FILE *fp);

int putchar(int c);

int putchar_unlocked(int c);

int putc_unlocked(int c, FILE *fp);

int puts(const char *str);

int remove(const char *path);

int rename(const char *oldname, const char *newname);

int renameat(int oldfd, const char *oldname, int newfd, const char *newname);

void rewind(FILE *fp);

void setbuf(FILE *restrict fp, char *restrict buf);

int setvbuf(FILE *restrict fp, char *restrict buf, int mode, size_t size);

int snprintf(char *restrict buf, size_t n, const char *restrict format, ...);

int sprintf(char *restrict buf, const char *restrict format, ...);

int sscanf(const char *restrict buf, const char *restrict format, ...);

FILE *tmpfile(void);

char *tmpnam(char *ptr);

int ungetc(int c, FILE *fp);

int vdprintf(int fd, const char *restrict format, va_list arg);  // <stdarg.h>

int vfprintf(FILE *restrict fp, const char *restrict format, va_list arg);  // <stdarg.h>

int vfscanf(FILE *restrict fp, const char *restrict format, va_list arg);  // <stdarg.h>

int vprintf(const char *restrict format, va_list arg);  // <stdarg.h>

int vscanf(const char *restrict format, va_list arg);  // <stdarg.h>

int vsnprintf(char *restrict buf, size_t n, const char *restrict format, va_list arg);  // <stdarg.h>

int vsprintf(char *restrict buf, const char *restrict format, va_list arg);  // <stdarg.h>

int vsscanf(const char *restrict buf, const char *restrict format, va_list arg);  // <stdarg.h>


// <stdlib.h>

void abort(void);

int atexit(void);

void *calloc(size_t nobj, size_t size);

void _Exit(int status);

void exit(int status);

void free(void *ptr);

char *getenv(const char *name);

int grantpt(int fd);

void *malloc(size_t size);

char *mkdtemp(char *template);

int mkstemp(char *template);

int posix_openat(int oflag);  // <fcntl.h>

char *ptsname(int fd);

int putenv(char *str);

void *realloc(void *ptr, size_t newsize);

int setenv(const char *name, const char *value, int rewrite);

int system(const char *cmdstring);

int unlockpt(int fd);

int unsetenv(const char *name);


// <string.h>

int str2sig(const char *str, int *signop);

char *strerror(int errnum);

char *strsignal(int signo);


// <syslog.h>

void closelog(void);

void openlog(const char *ident, int option, int facility);

int setlogmask(int maskpri);

void syslog(int priority, char *format);

void vsyslog(int priority, const char *format, va_list arg);  // <stdarg.h>


// <sys/ioctl.h>

int ioctl(int fd, int request, ...);


// <sys/ipc.h>

key_t ftok(const char *path, int fd);


// <sys/mman.h>

void *mmap(void *addr, size_t len, int prot, int flag, int fd, off_t off);

int mprotect(void *addr, size_t len, int prot);

int msync(void *addr, size_t len, int flags);

int munmap(void *addr, size_t len);


// <sys/msg.h>

int msgget(key_t key, int flag);

ssize_t msgrcv(int msqid, void *ptr, size_t nbytes, long type, int flag);

int msgsnd(int msqid, const void *ptr, size_t nbytes, int flag);


// <sys/resource.h>

int getpriority(int which, id_t who);

int getrlimit(int resource, struct rlimit *rlptr);

int setpriority(int which, id_t who, int value);

int setrlimit(int resource, const struct rlimit *rlptr);


// <sys/select.h>

void FD_CLR(int fd, fd_set *fdset);

int FD_ISSET(int fd, fd_set *fdset);

void FD_SET(int fd, fd_set *fdset);

void FD_ZERO(fd_set *fdset);

int pselect(int maxfdp1, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict exceptfds, const struct timespec *restrict tsptr, const sigset_t *restrict sigmask);

int select(int maxfdp1, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict exceptfds, struct timeval *restrict tvptr);


// <sys/sem.h>

int semctl(int semid, int semnum, int cmd, ... /* union semun arg */);

int semget(key_t key, int nsems, int flag);

int semop(int semid, struct sembuf semoparray[], size_t nops);


// <sys/shm.h>

void *shmat(int shmid, const void *addr, int flag);

int shmctl(int shmid, int cmd, struct shmid_ds *buf);

int shmdt(const void *addr);

int shmget(key_t key, size_t size, int flag);


// <sys/socket.h>

int accept(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict len);

int access(const char *path, int mode);

int bind(int sockfd, const struct sockaddr *addr, socklen_t len);

unsigned char *CMSG_DATA(struct cmsghdr *cp);

struct cmsghdr *CMSG_FIRSTHDR(struct msghdr *mp);

unsigned int CMSG_LEN(unsigned int nbytes);

struct cmsghdr *CMSG_NXTHDR(struct msghdr *mp, struct cmsghdr *cp);

int connect(int sockfd, const struct sockaddr *addr, socklen_t len);

void freeaddrinfo(struct addrinfo *ai);  // <netdb.h>

int getaddrinfo(const char *restrict host, const char *restrict service, const struct addrinfo *restrict hint, struct addrinfo **restrict res);  // <netdb.h>

int getnameinfo(const struct sockaddr *restrict addr, sockelen_t alen, char *restrict host, socklen_t hostlen, char *restrict service, sockelen_t servlen, unsigned int flgas);  // <netdb.h>

int getpeername(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict alenp);

int getsockname(int sockfd, struct sockaddr *restrict addr, socklen_t *restrict alenp);

int getsockopt(int sockfd, int level, int option, void *restrict val, socklen_t *restrict lenp);

int listen(int sockfd, int backlog);

ssize_t recv(int sockfd, void *buf, size_t nbytes, int flags);

ssize_t recvfrom(int sockfd, void *restrict buf, size_t len, int flags, struct sockaddr *restrict addr, sockelen_t *restrict addrlen);

ssize_t recvmsg(int sockefd, struct msghdr *msg, int flags);

ssize_t send(int sockfd, const void *buf, size_t nbytes, int flags);

ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);

ssize_t sendto(int sockfd, const void *buf, size_t nbytes, int flags, const struct sockaddr *destaddr, socklen_t destlen);

int setsockopt(int sockfd, int level, int option, const void *val, socklen_t len);

int shutdown(int sockfd, int how);

int sockatmark(int sockfd);

int socket(int domain, int type, int protocol);

int socketpair(int domain, int type, int protocol);


// <sys/stat.h>

int chmod(const char *path, mode_t mode);

int fchmod(int fd, mode_t mode);

int fchmodat(int fd, const char *path, mode_t mode, int flag);

int fstat(int fd, struct stat *buf);

int fstatat(int fd, const char *restrict path, struct stat *restrict buf, int flag);

int futimens(int fd, const struct timespec times[2]);

int lstat(const char *restrict path, struct stat *restrict buf);

int mkdir(const char *path, mode_t mode);

int mkdirat(int fd, const char *path, mode_t mode);

int mkfifo(const char *path, mode_t mode);

int mkfifoat(int fd, const char *path, mode_t mode);

int stat(const char *restrict path, struct stat *restrict buf);

mode_t umask(mode_t cmask);

int utimensat(int fd, const char *path, const struct timespec times[2], int flag);


// <sys/time.h>

int clock_getres(clockid_t clock_id, struct timespec *tsp);

int clock_gettime(clockid_t clock_id, struct timespec *tsp);

int clock_settime(clockid_t clock_id, const struct timespec *tsp);

int gettimeofday(struct timeval *restrict tp, void *restrict tzp);

clock_t times(struct tms *buf);

int utimes(const char *path, const struct timeval times[2]);


// <sys/uio.h>

ssize_t readv(int fd, const struct iovec *iov, int iovcnt);


// <sys/utsname.h>

int uname(struct utsname *name);


// <sys/wait.h>

pid_t wait(int *statloc);

int waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options);

pid_t waitpid(pid_t pid, int *statloc, int options);

pid_t wait3(int *statloc, int options, struct rusage *rusage);  // <sys/types.h> <sys/time.h> <sys/resource.h>

pid_t wait4(pid_t pid, int *statloc, int options, struct rusage *rusage);  // <sys/types.h> <sys/time.h> <sys/resource.h>


// <time.h>

int clock_nanosleep(clockid_t clock_id, int flags, const struct timespec *reqtp, struct timespec *remtp);

struct tm **gmtime(const time_t *calptr);

struct tm *localtime(const time_t *calptr);

time_t mktime(struct tm *tmptr);

int nanosleep(const struct timespec *reqtp, struct timespec *remtp);

int sem_timedwait(sem_t *restrict sem, const struct timespec *restrict tsptr);

size_t strftime(char *restrict buf, size_t maxsize, const char *restrict format, const struct tm *restrict tmptr);

size_t strftime_l(char *restrict buf, size_t maxsize, const char *restrict format, const struct tm *restrict tmptr, locale_t locale);

char *strptime(const char *restrict buf, const char *restrict format, struct tm *restrict tmptr);

time_t time(time_t *calptr);


// <termios.h>

speed_t cfgetispeed(const struct termios *termptr);

speed_t cfgetospeed(const struct termios *termptr);

int cfsetispeed(struct termios *termptr, speed_t speed);

int cfsetospeed(struct termios *termptr, speed_t speed);

int tcdrain(int fd);

int tcflow(int fd, int action);

int tcflush(int fd, int action);

int tcgetattr(int fd, struct termios *termptr);

pid_t tcgetsid(int fd);

int tcsendbreak(int fd, int duration);

int tcsetattr(int fd, int opt, const struct termios *temptr);


// <unistd.h>

unsigned int alarm(unsigned int seconds);

int chdir(const char *path);

int chown(const char *path, uid_t owner, gid_t group);

int close(int fd);

int dup(int fd);

int dup2(int fd, int fd2);

int execl(const char *path, const char *arg0, ... /* (char *) 0 */);

int execle(const char *path, const char *arg0, ... /* (char *) 0, char *const env[] */);

int execlp(const char *filename, const char *arg0, ... /* (char *) 0 */);

int execv(const char *path, char *const argv[]);

int execve(const char *path, char *const argv[], char *const envp[]);

int execvp(const char *filename, char *const argv[]);

void _exit(int status);

int faccessat(int fd, const char *path, int mode, int flag);

int fchdir(int fd);

int fchown(int fd, uid_t owner, gid_t group);

int fchownat(int fd, const char *path, uid_t owner, gid_t group, int flag);

int fdatasync(int fd);

int fexecve(int fd, char *const argv[], char *const envp[]);

pid_t fork(void);

long fpathconf(int fd, int name);

int fsync(int fd);

int ftruncate(int fd, off_t length);

char *getcwd(char *buf, size_t size);

gid_t getegid(void);

uid_t geteuid(void);

gid_t getgid(void);

int getgroups(int gidsetsize, gid_t grouplist[]);

int gethostname(char *name, int namelen);

char *getlogin(void);

pid_t getpgid(pid_t pid);

pid_t getpgrp(void);

pid_t getpid(void);

pid_t getppid(void);

pid_t getsid(pid_t pid);

uid_t getuid(void);

int initgroups(const char *username, gid_t basegid);  /* <grp.h> Linux */

int isatty(int fd);

int lchown(const char *path, uid_t owner, gid_t group);

int link(const char *existingpath, const char *newpath);

int linkat(int fd, const char *existingpath, int nfd, const char *newpath, int flag);

off_t lseek(int fd, off_t offset, int whence);

int nice(int incr);

long pathconf(const char *path, int name);

int pause(void);

int pipe(int fd[2]);

ssize_t pread(int fd, void *buf, size_t nbytes, off_t offset);

ssize_t pwrite(int fd, const void *buf, size_t nbytes, off_t offset);

ssize_t read(int fd, void *buf, size_t nbytes);

ssize_t readlink(const char *restrict path, char *restrict buf, size_t bufsize);

ssize_t readlinkat(int fd, const char *restrict path, char *restrict buf, size_t bufsize);

int rmdir(const char *path);

int scanf(const char *restrict format, ...);

int setegid(gid_t gid);

int seteuid(uid_t uid);

int setgid(gid_t gid);

int setgroups(int ngroups, const gid_t grouplist[]);  /* <grp.h> Linux */

int setpgid(pid_t pid, pid_t pgid);

int setregid(gid_t rgid, gid_t egid);

int setreuid(uid_t ruid, gid_t euid);

pid_t setsid(void);

int setuid(uid_t uid);

unsigned int sleep(unsigned int seconds);

int symlink(const char *actualpath, const char *sympath);

int symlinkat(const char *actualpath, int fd, const char *sympath);

void sync(void);

long sysconf(int name);

pid_t tcgetpgrp(int fd);

int tcsetpgrp(int fd, pid_t pgrpid);

int truncate(const char *path, off_t length);

char *ttyname(int fd);

int unlink(const char *path);

int unlinkat(int fd, const char *path, int flag);

ssize_t write(int fd, const void *buf, size_t nbytes);

ssize_t writev(int fd, const struct iovec *iov, int iovcnt);


// <wchar.h>

int fwide(FILE *fp, int mode);  // <stdio.h>

FILE *open_wmemstream(wchar_t **bufp, size_t *sizep);

