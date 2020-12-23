# Homework (Simulation) 

### Q1: To start things off, let’s learn how to use the simulator to study howto build an effective multi-processor scheduler. The first simulationwill run just one job, which has a run-time of 30, and a working-setsize of 200. Run this job (called job ’a’ here) on one simulated CPUas follows:./multi.py -n 1 -L a:30:200. How long will ittake to complete? Turn on the-cflag to see a final answer, and the-tflag to see a tick-by-tick trace of the job and how it is scheduled.

A1: 

### Q2: Now increase the cache size so as to make the job’s working set(size=200) fit into the cache (which, by default, is size=100); forexample, run./multi.py -n 1 -L a:30:200 -M 300. Canyou predict how fast the job will run once it fits in cache? (hint:remember the key parameter of the warmrate, which is set by the-r flag) Check your answer by running with the solve flag (-c) en-abled.

A2: 

### Q3: One cool thing aboutmulti.pyis that you can see more detailabout what is going on with different tracing flags. Run the samesimulation as above, but this time with timeleft tracing enabled(-T). This flag shows both the job that was scheduled on a CPUat each time step, as well as how much run-time that job has leftafter each tick has run. What do you notice about how that secondcolumn decreases?

A3: 

### Q4: 






