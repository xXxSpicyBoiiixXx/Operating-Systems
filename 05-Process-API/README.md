# Homework (Simulation)

### Q1: Run ./fork.py -s 10 and see which actions are taken. Can you predict what the process tree looks like at each step? Use the -c flag to check your answers. Try some different random seeds (-s) or add more actions (-a) to get the hang of it.

A1: If it forks a certain parent node then it will fork it if it Exits it will exit it.

### Q2: One control the simulator gives you is the fork_precentage, controlled by the -f flag. The higher it is, the more likely the next action is a fork; the lower it is, the more likely the action is to exit. Run the simulator with a large number of actions (e.g., -a 100) and vary the fork_percentage from 0.1 to 0.9. What do you think the resulting final process trees will look like as the percentage changes? Check your answer with -c.

A2: 

### Q3: Now, switch the output by using the -t flag (e.g., run ./fork.py -t). Given a set of process trees, can you tell which actions were taken?

A3:

### Q4: One interesting thing to note is what happens when a child exits; what happens to its children in the process tree? To study this, let's create a specific example: ./fork.py -A a+b, b+c, c+d, c+e, c-. This example has process 'a' create 'b', which in turn creates 'c', which then creates 'd' and 'e'. However, then, 'c' exits. Wat do you think the process tree should like after the exit? What if you use the -R flag? Learn more about what happens to orphaned processes on your own to add more context. 

A4:

### Q5: One last flag to explore is the -F flag, which skips intermediate steps and only asks to fill in the final process tree. Run ./fork.py -F and see if you can write down the final tree by looking at the series of actions generated. Use differnet random seeds to try this a few times.

A5:

### Q6: Finally, use both -t and -F together. This shows the final process tree, but then asks you to fill in the actions that took place. By looking at the tree, can you determine the exact actions that took place? In which cases can you tell? In which can't you tell? Try some different random seeds to delve into this question. 

A6: 
