# Event Driven Simulation

Update some of the data structures and implement a small event-driven simulation of a fast food restaurant. The simulation will allow us to play “what if” games to see how a change could affect overall statistics for restaurant business. We will come up with a solution entirely on our own, including the planning, design, implementation, and testing. 

## Phase 1: update some of the data structures to be templated

- To be associated with a generic data type using C++ templates such that the data structures are able to hold more data types than just integers, the SortedListClass and the FIFOQueueClass must be modified to be templated classes. 

- Phase 1 should NOT result in writing much “new code”, except for developing test cases to make sure updated data structures work with different data types.

## Phase 2: develop an event driven simulation

- Create an event class that will be inserted into a SortedListClass in a sorted way based on the time that the event is scheduled to occur. Then, handle one event at a time, as discussed in lecture. As you handle certain events, new events will be generated to occur at a future time (randomly drawn from a specified distribution), and the simulation will advance much like the airport example demonstrated in class. 

- The simulation to implement will be a server simulation at a fast food restaurant. Some important requirements or additional information about the simulation are:
  - Customers come into the restaurant on a pseudo-random basis, where each customer enters the restaurant some amount of time after the previous customer. The amount of time between customers should be drawn from a uniform distribution, which has specified min and max values.
  
  - The restaurant will have only a single server, in order to make things much simpler. If the server is not currently waiting on a customer, a newly arriving customer can immediately start being served. Otherwise, the customer will have to wait in a first-in-first-out queue and wait their turn.

  - The amount of time it takes for the server to wait on a customer will be drawn from a normal distribution with a specified mean and standard deviation.
  
  - Some customers don’t like to wait in line. If this kind of customer arrives at the restaurant and sees a long line, they leave the restaurant and go to one of our competitors instead (that is, they do not get in line, and they do not get served, etc.). This will be described at run time using two values – the percentage of customers that don’t like excessively long lines, and the length of the line to be considered excessively long. For example, we might say “40% of our customers won’t wait in excessively long lines, and they consider a line of more than 10 people as excessively long”. When a customer arrives, if they are a customer that doesn’t like long lines (40% chance in this example) and the line is seen to be excessively long (greater than 10 customers long in this example), the new customer will leave.

  - The restaurant will close at some specified time. We are nice restaurant owners, though, and will continue to serve anyone who is waiting in line after closing time. That is, anyone who is already in line at closing time will get served, but no additional customers will be allowed to get in line after the closing time.

## Additional requests for simulation
Following are some important requirements about how the simulation itself must work:
- The SortedListClass will contain events and act as a priority queue that contains your “event list” as described in lecture
- When the server is busy, you must utilize a FIFOQueueClass to allow a line to form
- You must generate new objects only when you need them. That is, do NOT generate a full list of customers and their arrival times at the beginning of the simulation. Instead, generate a single customer to arrive at a determined time to start off the simulation. Then, when handling that arrival event, determine when the next customer will arrive and generate a new arrival event. That is (please note!):
  - There must only be at most one customer arrival event in the event list at any given moment
  - At the time you handle a customer's arrival event, determine how far in the future the next arrival event occurs using BOTH a minimum and a maximum (do NOT assume a minimum of 0).
  
- For example, if a customer's arrival time is 100, then, when you are handling that event, you will generate the next arrival event. If the uniform distribution has a min of 10 and a max of 20, then the next arrival event must be within the range 110 to 120 (as opposed to 100 to 120).
- Similarly, do not compute a customer's service time until that customer begins being served (in other words, do not compute all the timing for a customer right when the customer is first created – instead, compute the duration of the customer's service time only when the customer reaches the front of the line and you're able to compute when the time the service will end).
- Your simulation must provide enough output to allow a user to easily follow and understand what is happening at the restaurant. For example, you should print a description when a customer enters the restaurant, whether the customer is served or has to wait in line or leaves due to excessive line length, how many people are in front of the customer in the line, when the server finished serving a customer, etc., etc., etc. I should be able to look at your simulation's output and "see" what is happening in the restaurant and follow a customer through the process. The simulation should run from time = 0 until all events are handled, after which the simulation ends and maintained statistics are output.
- You must maintain data to output some important statistics upon completion of the simulation. The following statistics are required to be output:

## Some statistics to report
- Total number of customers that showed up
- Percentage of time the server was busy helping customers
- Percentage of customers had to wait in line
- The number of customers that arrived, but left due to excessive line length
- The longest the line was throughout the simulation
- Come up with at least 2 more statistics you think might be interesting and include them in your output. Your statistics must be different than the above required statistics.

