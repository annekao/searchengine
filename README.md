##CSCI 104 Project Repository

###Student Information
  + Name: Anne Kao
  + USC Email: annekao@usc.edu
  + USC ID: 4737655845

###Homework 4 Make Instructions:
	This makefile makes three executables:
		settest (used in part 2 to test set.h)
		webpagetest (used in part 3 to test webpage.h)
		webpage (executable for part 4 that involves the user)
	<make all>
		to make all parts
	Enter one of the three commands below to run the executables.
		<./settest>
		<./webpagetest>
		<./webpage data/filename.txt>
			filename.txt is up to the user but it MUST be in data directory
			
			It is also important to note all the files listed in the main 	
			one is also part of the data directory (each file listed 		
			must start with data/)

###Homework 4 Known Errors:
	Memory Leaks!
	A reoccuring issue with me...Essentially when I delete things it can cause segmentation faults or aborts.  
	But if I don't delete them it causes lost memory..

	One Warning that a char* is uninitialized.  
	Not sure how to initialize it (initializing it to " " just outputs another warning) and is not really necessary to.

	**Did not check with a command file passed in**