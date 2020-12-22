# Homework (Simulation)

### Q1: Compute the response time and turnaround time when running three jobs of length 200 with the SJF and FIFO schedulers.

A1:

./scheduler.py -p SJF -j 3 -s 200 -c 
Job 0 -- Response: 0.00 Turnaround 1.00 Wait 0.00
Job 1 -- Response: 1.00 Turnaround 4.00 Wait 1.00 
Job 2 -- Response: 4.00 Turnaround 12.00 Wait 4.00 

Average -- Response: 1.67 Turnaround 5.67 Wait 1.67

./scheduler.py -p FIFO -j 3 -s 200 -c 
Job 0 -- Response: 0.00 Turnaround 1.00 Wait 0.00
Job 1 -- Response: 1.00 Turnaround 4.00 Wait 1.00 
Job 2 -- Response: 4.00 Turnaround 12.00 Wait 4.00 

Average -- Response: 1.67 Turnaround 5.67 Wait 1.67

### Q2: Now do the same but with jobs of different lengths: 100, 200, and 300.

A2:

### Q3: Now do the same, but also with the RR scheduler and a time-slice of 1.

A3:

### Q4: For what types of workloads SJF deliver the same turnaround times as FIFO?

A4:

### Q5: For what types of workloads and quantum lengths does SJF deliver the same response times as RR?

A5:

### Q6: What happens to response time with SJF as job lengths increase? Can you use the simulator to demonstrate the trend? 

A6: 

### Q7: What happens to response time with RR as quantum length increrase? Can you write an equation that gives the worst-case response time, given N jobs? 

A7:
