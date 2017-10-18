#ifndef DUCKS_EXERCISES_VISITOR_H_
#define DUCKS_EXERCISES_VISITOR_H_

class Duck;
class RubberDuck;
class Mallard;

class Visitor {
public:
  Visitor();
  virtual void visit( Duck * d );
  virtual void visit( RubberDuck * r );
  virtual void visit( Mallard * m );
};

class RealDuckReport : public Visitor {
public:
  void visit( RubberDuck * r );
  void visit( Mallard * m );
  void visit( Duck * d );
};

class FakeDuckReport : public Visitor {
public:
  void visit( RubberDuck * r );
  void visit( Mallard * m );
  void visit( Duck * d );
};

#endif
