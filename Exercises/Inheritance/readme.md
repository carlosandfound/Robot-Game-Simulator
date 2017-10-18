### _ComposedClass_
<ol>

<li> Uncomment each of the 'cout' statements, explain why it doesn't compile:
<ul>
<li> privateVar </li>
<li> protectedVar </li>
<li> object.privateVar </li>
<li> object.protectedVar </li>
    </ul>    
<li> Uncomment the declaration of privateVar and protectedVar inside the ComposedClass definition.
    <ul><li>
    Which of the 'cout' statements can now be successfully compiled? Why?
    </ul>
<li> ComposedClass probably needs to interact with _object_ members. How will you give it access?

</ol>

### DerivedClass

<ol>
<li> Uncomment each of the 'cout' statements, determine which successfully compiles and explain why or why not:
  <ul>
    <li> privateVar
    <li> protectedVar
    <li> ObjectClass::privateVar 
    <li> ObjectClass::protectedVar
    </ul>
    
<li> How is it that you redefined _print()_ in the derived class, and yet you can still call _print()_ in the ObjectClass?

<li> In main, the declaration of isAobject_4_5(4,5) is commented out because it will not compile. Why not? There isn't a constructor for DerivedClass with no parameters and that works.

<li> Uncomment the DerivedClass constructor that has no parameters (i.e. 'DerivedClass() :' ).
  - Determine which of the cout statements compiles and explain why.

<li> Uncomment the members privateVar and protectedVar in DerivedClass, and modify comments in the code so that DerivedClass() : sets those vars to 20 and 25.
  <ul><li>
  Report the values for each 'cout' in Derived and explain the results.
  </ul>
<li> In main, now fix DerivedClass so that the statement 'DerivedClass isAobject_4_5(4,5)' works.
</ol>
