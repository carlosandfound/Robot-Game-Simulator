### Visitor Pattern Example

The visitors here want information from the ducks to generate a report.
However, they only need data from some of the types of ducks.

The ducks are oblivious to this distinction or even what specific information
the visitor wants from them. They need only to welcome the visitor (i.e. accept(Visitor)).

Notice that the visitor creates a visit() method for each type of Duck, this
way, ducks can be treated generically in some circumstances, but the visitor
can treat each type in a distinct way.

YOUR TASKS:

- create a decoy duck
- create a sea duck
- add these types, and a couple more of a type of your choosing to ducks[]
- view the reports

- create a visitor subclass that speeds up ducks (increases their mph), but only for those that are real.
- again generate a report of real ducks


> No claim that this is excellent, efficient code! Feel free to clean it up or add helper functions. 

