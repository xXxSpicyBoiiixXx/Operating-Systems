# Homework (Simulation) 

### Q1: Run process-run.py with the following flags: -l 5:100,5:100. What should the CPU utilizations be (e.g. the percent of time the CPU is in use?) Why do you know this? Use the -c and -p flags to see if you were right. 

A1: The CPU utilizationg will be used 100% of the time, this is due to that each process has 5 insturctions with a 100% chance of using the CPU. For process 0 it will run on the CPU while process 1 will stay in the state READY. Proess 1 will wait until process 0 is done. When process 0 gets in the DONE state then process 1 will run. When process 1 is compelted then the trace will be done.  

### Q2: Now run with these flags: ./process-run.py -l 4:100, 1:0. These flags specify one process with 4 instructions (all to use the CPU), and one that simply issues an I/O and waits for it to be done. How long does it take to complete both processes? Use -c and -p to find out if you were right.

A2: The CPU will take 5 ticks due to the 4 instructions given my process 0 and the 1 instruction given my process 1. This will give the CPU ticks. The I/O will stay busy for 4 ticks as the default is set to 5 to wait until its compelete. This leads to the CPU to be busy for 50% and the I/O being busy 40%.  

### Q3: Switch the order of the processes: -l 1:0,4:100. What happens now? Does switching the order matter? Why? (As always, use -c and -p to see if you were right)

A3: The total number of ticks will be 6. This is due to the instructions being implemented first. Switching the order will shorten the total time due to the fact that process 0 will have 1 instruction to be given and the I/O will be waiting while the CPU can work on process 1 while its waiting for the other process. This will make the CPU busy for 5/6 while the I/O being busy for 4/6. 

### Q4: We'll now explore some of the other flags. One important flag is -S, which determines how the system reacts when a process issues an I/O. With the flag set to SWITCH_ON_END, the system will NOT switch to another process while one is doing I/O, instead wiating until the process is compeltely finished. What happens when you run the following two processes (-1 1:0,4:100 -c -S SWITCH_ON_END), one doing I/O and the other doing CPU work? 

A4: By ading this flag with the flag set to SWITCH_ON_END this will ultimately not run process 1 until process 0 is set to DONE. Hence we will get 5 insturction for process 0 and 4 insturctions for process 1. This makes the utlization of the CPU at 5/9 and IO 4/9. 

### Q5: Now, run the same processes, but with the switching behavior set to switch to another process whenever on is WAITING for I/O (-l 1:0,4:100 -c -S SWITCH_ON_IO). What happens now? Use -c and -p to confirm that you are right?

A5: Doing the following command we get the same result as the answer to question3 as process 0 is waiting process 1 will be running. 

### Q6: One other important behavior is what to do when an I/O completes. With -I IO_RUN_LATER, when an I/O completes, the process that issued it is not necessarily run right away; rather, whatever was running at the time keeps running. What happens when you run this combination of processes? (Run ./process-run.py -l 3:0,5:100,5:100,5:100 -S SWITCH_ON_IO -I IO_RUN_LATER -c -p) Are system resources being effectively utilized?

A6: Process 0 will run one instruction and then run process 1 as it is waiting. Since we have the flag to run the I/O later, we will have to process all the other processes before we can get back to process 0 to run the 2 remaining instructions for the I/O. This leads to the total time to be 27 with 18/27 being utilzing the CPY while 12/27 to be by the I/O

### Q7: Now run the same processes, but with -I IO_RUN_IMMEDIATE set, which immediately runs the process that issued the I/O. How does this behavior differ? Why might running a process that just completed an I/O again be a good idea?

A7: Running this in comparison will run process 0 while other process are still runnining since we are not waiting for the I/O to execute. Hecne our total time is 18 with 18/18 meaning 100% utilizing the CPU and 12/18 to be utilized by I/O.

### Q8: Now run with some randomly generated processes: -s 1 -l 3:50, 3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,3:50. See if you can predict how the trace will turn out. what happens when you use the flag -I IO_RUN_IMMEDIATE vs -I IO_RUN_LATER? What happens when you use -S SWITCH_ON_IO vs -S SWITCH_ON_END?

A8: Ask Kyle About

