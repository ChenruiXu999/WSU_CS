fof(a1, axiom,
    ? [X] : (Likes(X, Apples)) => Plays(John, Chess) & Plays(Mary, Chess)). 

fof(a2, axiom,
    ? [X] : (Likes(X, Oranges)) => Plays(John, Go) & Plays(Mary, Go)). 

fof(a3,axiom,
    ! [X] : (~(Likes(X,Oranges) & Likes(X,Apples)))).

fof(a4, axiom, Likes(John, Apples)).

fof(a5, axiom,
    ! [X] : (Likes(John, X) => ~ Likes(Mary, X))).

fof(c1, conjecture, Plays(Mary, Go)).
