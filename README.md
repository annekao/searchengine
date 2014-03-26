##CSCI 104 Project Repository

###Student Information
  + Name: Anne Kao
  + USC Email: annekao@usc.edu
  + USC ID: 4737655845
  
***

###Homework 6 Make Instructions:
####Part 1(Convert your ADTs to STL) and Part 2(Expand your WebPage class):

>`make` to make all parts

To test the search executable with given data sets:
`./search data/index.txt` or `./search data100/index.txt`

+ note that the executable has been renamed from HW4
+
###Part 3(Put a Qt frontend on it):

>Enter the correct subfolder cd qtsrc

>`qmake -project`

>`qmake`

>`make`

>enter `./qtsrc data/index.txt` or `./qtsrc data100/index.txt`

+ Note that the files are within the qtsrc folder AS WELL AS the project folder.  If using own test files to test qt interface it is best to save them inside qtsrc/.
+ Functionality is straight forward
+ Search by hitting the search button or using the enter key
+ Double-click in the list-box to open the new window
+ Double-click incoming/outgoing links to refresh the window
+ Search queries must be alphanumeric
+ Errors such as "no results" or "invalid input" open up a message box
