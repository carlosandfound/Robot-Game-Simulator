### CSCI3081: Iteration3 Checklist

> The iteration is due on <del>Wednesday, December 13 at 11:55pm</del> THURSDAY, December 14 at 8:00am

### Compilation and Execution

- [ ] I cloned **fresh** from github onto cselabs machine to test compilation.
- [ ] Submission is on the _master_ branch.
- [ ] _/project/iteration3_ folder exists.
- [ ] _/build_ not in _iteration3_
- [ ] _/html_ not in _docs_
- [ ] **__`make` from src completes without error.__**
- [ ] `make` runs without warnings (partial credit for eliminating most warnings).
- [ ] `./build/bin/arenaviewer` executes without assert or seg fault.
- [ ] `doxygen docs/Doxyfile` compiles.
- [ ] `cpplint *.cc *.h` reports no errors except for rand.

### Primary Functionality

- [ ] _Robot_ avoids when appropriate.
- [ ] _Robot_ collides when appropriate (i.e. distress call sensed).
- [ ] _Robot_ freezes when collides with player.
- [ ] _Robot_ unfreezes only when collides with robot or superbot.
- [ ] _Robot_ turns into superbot when collides with homebase.
- [ ] _Player_ bounces.
- [ ] _Player_ freezes when collides with superbot.
- [ ] _Player_ unfreezes after some time has passed.
- [ ] _Player_ controlled with keypresses.
- [ ] _Player_ battery depletes.
- [ ] _Player_ battery recharged when collides with Station.
- [ ] _Superbot_ avoids when appropriate.
- [ ] _Superbot_ collides when appropriate (i.e. player in range).
- [ ] Game is won when all remaining robots frozen.
- [ ] Game is lost when all robots turn into superbots.
- [ ] Game is lost when battery is drained.

### Required Documents

- [ ] _refactor1.*_ exists in _docs_
- [ ] _refactor2.*_ exists in _docs_
- [ ] _refactor3.*_ exists in _docs_
- [ ] _PeerResponses.*_ exists in _docs_ (This is the file YOU completed. Do not include the one you received from your peer.)
- [ ] _BugReport.*_ exists in _docs_ OR generated in Doxygen documentation.

### Documentation

- [ ] I opened index.html in _docs/html_ folder.
- [ ] Front page has project description for programmer audience.
- [ ] _Classes_ list has documentation for each class.
- [ ] _Arena_ class methods are documented.
- [ ] _Robot_ class methods are documented.
- [ ] _Player_ class methods are documented.
- [ ] _SensorProximity_ class methods are documented.
- [ ] I perused other classes to spot check documentation.

### Branches

- [ ] Branch _refactor1/iter3_ exists.
- [ ] Branch _refactor2/iter3_ exists.
- [ ] Branch _refactor3/iter3_ exists.

## Ready For Submission

When everything above is as you want it or it is 11:55pm on Wednesday, it is time to tag.

- [ ] I did not change anything from when I checked compiliation on a cselabs machine using a fresh clone.
- [ ] The _master_ branch has been tagged _v.3.0_.
