##Final Project for CSCI 104

This program gives the ability for a user to enter a query and search through a list of text files to return files with that query.  The search result will also include referenced files within each files.  If a user clicks on a file, the program will open a new window with the file contents and all the incoming and outgoing links for that file.  Those links will be clickable and will refresh the window.

*Important to note that this is not the entire project.  It excludes the last two parts of a four part assignment which were worked on with different partners.  Due to the fact that not all of the code in the last two parts are my code, I have not it to committed to this repository.  However, if you would like to see what I specifically worked on, code for those parts are available upon request.

In part 3 of 4, I worked on a webcrawler, and a Google PageRank implementation

In part 4 of 4, I worked on creating a user account feature with the ability to add users, switch between users, and view search and ad history.
  
***

###Homework 6 Make Instructions:
####Part 1(Convert your ADTs to STL) and Part 2(Expand your WebPage class):

>`make` to make all parts

To test the search executable with given data sets:

`./search data/index.txt` or `./search data100/index.txt`

+ note that the executable has been renamed from HW4

####Part 3(Put a Qt frontend on it):

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
