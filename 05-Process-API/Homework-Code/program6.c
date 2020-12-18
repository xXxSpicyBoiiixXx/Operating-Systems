/*
 * 6. Write a slight modification of the previous program, this time 
 * using waitpid() instead of wait(). When would waitpid() be useful?
 */

// wait() 
// wait blocks the caller until a child process terminates 
// if more than one child is running then wait() return the first 
// time one of the parent's offspring exits 
//

// waitpid() 
//
// waitpid can be either blocking or non-blocking 
// if oprtions is 0, then it is blocking
// if options is WNOHANG, then is it non-blocking 
//
// waitpid is more flexible 
//
// if pid == -1, it waits for any child process. In this respect,
// waitpid is equivalent to wait 
//
// if pid > 0, it waits for the child whose process ID equals pid 
//
// if pid == 0, it waits for any child whose process group ID 
// equals that of the calling process 
//
// if pid < -1 , it waits for any child whose process group ID equals that absolute value of pid.
