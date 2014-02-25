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
	Memory Leaks fixed Feb 23, 2014 (most of the problem came from list.h).
	Recently found a new bug-that was fixed.  Segfaults when there is no intersection.
	
	New Errors Post-Debugging (Feb 23):
		Since fixing the memory leaks, webpage.cpp segfaults more often.  Will fix when there is time.

	**Did not check with a command file passed in**
