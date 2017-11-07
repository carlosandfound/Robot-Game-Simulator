## Dynamic Allocation and Class destructor

The ArrayPointerTest class has a collection of 4 arrays of Duck and Duck pointers.
main() calls a helper function in which it declares an instance of this class.
Then displaycontents is called, which simply makes every duck in every array
PerformQuack(). Upon exit of the helper, everything is destroyed (or is it!).

Note that there are print statements inside the destructors to better understand when things are called. To make things even more evident, you can print the name of the duck before you destroy it.

Here is your assignment:

- Copy to a git repo of someone in your group.
- Put the name of eveyone in your group at the top of this readme!
- Fill in the initialization of all duck arrays in the constructor.
- Make all the ducks quack in DisplayContents().
- Fix the delete's where appropriate in the destructor.
- Answer the following questions directly in the readme in your git repo:
  1. Decide which of these you think is correct and briefly justify:
  ```C++
  printf("Initializing ducks1\n");
  ducks1_[0].SetName("angel");
  ```
  ```C++
  printf("Initializing ducks1\n");
  ducks1_[0] = Duck("angel");
  ```
  2. In the destructor, there are 2 lines with the comment "WILL NOT COMPILE". Explain why these will not compile.
  3. For each delete statement that is insufficient, explain how you fixed it.

- Push to git.
