/*
 * 5. Now write a progrma that uses wait() to wait for the child proces
 * to finish in the parent. What does wait() return? What happens if 
 * you use wait() in the child?
 */

// If wait() is used for the child process to finish in the parent then
// this will return the pid of the terminated child. 
//
// If using wait() in the child, it will immediatley return -1
