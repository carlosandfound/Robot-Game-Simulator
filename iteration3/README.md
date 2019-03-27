# Robot Simulator: Iteration 3

DUE: <del>Wednesday, December 13 at 11:55pm</del> Thursday, December 14 at 8:00am

Submit via Github
- iteration3 folder in your master branch
- tag with v.3.0

**Late assignments will not be accepted**

You can convert this requirements document to pdf using this tool: http://www.markdowntopdf.com/

<hr>

#### Create iteration3 Folder

In the non-academic world, one would not copy code into a new directory and continue development in this new folder, because that is not using Git as it was intended (which was designed so that you don't have to copy code). However, we need to grade this and not everyone successfully merged and tagged, so to keep a convenient record of work, please create an iteration3 folder using the following:

```
git checkout devel
cd project
mkdir iteration3
cp -r iteration2/* iteration3/.
git add iteration3
git commit -m "starting iteration3"
```

<hr>

#### Deliverables and Submission Process

Everything will be submitted via Github. We will pull your repository at the specified due dates and grade according to the contents at that time.

> Please verify that your submission compiles on a cselabs machine and it is complete.

<hr>

## Functional Requirements

There are no additional functional requirements for iteration 3. Your primary code task is to have fully functional code for the iteration 2 requirements. As with iteration 2, any non-functional portion must be reported in your BugReport.md or through Doxygen @bug and @todo.

### No Warnings

Please fix your code so that there are no warnings during compilation.

### No CPPLINT Errors

We will not test compliance beyond cpplint.

## Refactoring Requirements

This portion of iteration 3 will allow you to refactor your iteration 2 code.  Because we want you to do the refactoring independently of completing the priorities of iteration 2, you will need to complete the following steps for each refactor.

After creating the iteration3 folder ...

Create a new branch for each refactoring task. You must follow the naming conventions for these branches since we will be checking only these branches for your work. Create the following three branches in your repository:  *_refactor1/iter3_*,  *_refactor2/iter3_*, and  *_refactor3/iter3_*.  You will only do one task in each branch.  You are **not expected** to merge these branches with your master after you complete this portion of iteration 3.  Please be mindful that you must follow the naming conventions set forth in the following instructions since we will not search for your documents if they are not in these locations with the required names. Follow the git-usage document to create a substantial commit message when pushing the refactor branch.

Normally, you would not refactor unless your code was fully functional, but for the purpose of this assignment to give everyone an opportunity to refactor regardless of the state of iteration 2, you can refactor code prior to it being bug-free. We do not expect you to merge the refactor. This leaves open the possibility that you _may_ merge the refactor with devel as you fix your iteration 2 bugs, but again, this is not required. We will not look in devel for the refactoring -- only in the _refactor#/iter3_ branches.

<hr>

### Refactor 1 : Replace Temp With Query

Your first refactoring task will be to complete a *_Replace Temp with Query_* refactor. This will be completed in the *_refactor1/iter3_* branch. Look through your code and identify a temporary variable that is reference multiple times and holds the result of an expression. Create a function that evaluates the expression and replace all references to the temp with this function call. Complete the following tasks:

1. IN THE BRANCH *_refactor1/iter3_*, refactor the code in your iteration3 source code (/project/iteration3/src).

2. Create a text or web-viewable document called _refactor1.xxx_ in the /docs directory, that contains these:
  - A list of the files and methods added and/or changed.
  - The code, filename, and line number where the temporary variable was defined.
  - The name of the new method you created and where it is located. Identify clearly also where any changes were made to call the new function.  
  - A brief explanation of what behavior this is replacing. What does the new function specifically do?  (No more than one paragraph.)

Ensure that the refactor1.xxx document is located in the /project/iteration3/docs/ directory.

<hr>

### Refactor 2 : Change Variable and/or Method Names

Your second refactoring task will be to complete a *_Change Variable or Method Names_* refactor. This will be completed in the *_refactor2/iter3_* branch. Look through your code and identify two names (either class variables or methods) that do not provide meaningful information about the data they store or their functionality, respectively. Update your variable and/or method names and make all necessary naming changes. Complete the following tasks:

1. IN THE BRANCH *_refactor2/iter3_*, refactor the code in the original file(s) in your iteration 3 source code (/project/iteration3/src).

2. Create a text or web-viewable document called refactor2.xxx in your /docs folder, that contains:
  - A list of the files and methods where you are making your changes.
  - The original variable and/or method names that you are changing and what their new names are called after the refactor.
  - A brief explanation of how your new names are better than the old ones (no more than one paragraph.)

Ensure that the refactor2.xxx document is located in the /project/iteration3/docs directory.  

<hr>

### Refactor 3 : Extract Method Refactor

Your third refactoring task will be to complete an *_Extract Method_* refactor.  This will be completed in the *_refactor3/iter3_* branch. Look through your code and identify a method that is too long and extract at least one method from this. Be sure to update all method calls as needed.  Look at Lab09 if you get stuck on how to approach this. Complete the following tasks:

1. IN THE BRANCH *_refactor3/iter3_*, refactor the code in the original file(s) in your iteration 3 source code (/project/iteration3/src).

2. Create a text or web-viewable document called refactor3.xxx in your /docs folder that contains:

  - A list of the files and the method(s) you are changing.
  - The location of the changes.  Be sure you explain briefly what you are doing at each location.
  - A brief explanation of how this improves your code (no more than one paragraph.)

Ensure that the refactor3.xxx document is located in the /project/iteration3/docs directory.  

<hr>

## Documentation Requirements

Documentation requirements include Doxygen with mainpage, the bug report, and the Peer Reflection as described below. You do not need to provide any other documentation for this iteration.

### Peer Reflection

1. Find 1-4 persons in the class and exchange documentation so that everyone will receive 1 peer reflection.

2. Obtain the UML and html folder from the author. The author can email, share on google drive, or upload to her/his cselabs web page.

3. Answer the questions in the PeerResponseWorksheet.md. You will be graded on the quality of your response with respect to analysis and writing. Title your response document _PeerResponses.*_. You can use any text or web-viewable format for this document.

4. Give your responses to the author.

5. Place your answers in your _project/iteration3/docs_ folder.

### Bug Report

Continue to maintain your bug report. The expectation for this iteration is that there are no known bugs. If there are no known bugs, then please report that. If you have one or two minor bugs and you list them, we will not deduct any points.  

<hr>

## Assessment

- 30% Fully functional requirements of iteration 2.
- 20% Refactoring (3 branches)
- 05% No Warnings During compilation
- 05% Submission, File Structure, File Names
- 20% Peer Response Worksheet
- 10% Doxygen
- 05% cpplint Error Free
- 05% Bug Report
