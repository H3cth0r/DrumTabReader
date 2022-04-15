<div style = "text-align: justify;">

# DrumTabReader
This is a small project that will be used on a bigger project, called "spaceDrummers".
Long-short story, the "spaceDrummers" project is a drum based videogame for the
*Percussion Arts Society*; for this project we require for a collection of song-beats that
will be used on the game. This project is intended to generate machine-readable drum tabs.
The project must take a txt file with some drum tabs as input, and as output it should 
generate a machine readable tab file. Because the intention of our game is identify rhythms and to follow a sequence of beats, but at the same time it should be intuitive and the controls should be easy to use, we'll be using easy kind of easy songs that dont require many drum-components.

## Input File structure
As said, the input is a txt file, that contains the tabs, with the following structure:
```
C |x---------------|----------------|----------------|----------------|
H |--x-x-x-x-x-x-x-|x-x-x-x-x-x-x-x-|x-x-x-x-x-x-x-x-|x-x--x--x--x----|
S |----o-------o---|----o-------o---|----o-------o---|----o--o--o--oo-|
B |o-------o-------|o-------o-------|o-------o-------|o----o--o--o----|
```

## Output File structure
As always, it is important to think about time complexity and to create solutions that will 
reduce time complexity. For this reason, for this solution, the output should only be a txt 
file with comma separated combinations, that will work as some kind of identificator(ID).
The txt file tab output looks like this, using the example from the input file, the "T" is the separating line:
```
CB, H, HS, H, HB, H, HS, H, T
```
This way, on the C# implementation of the videogame, we will create an ordered hash map, that will contain all the posible tab combinations as a key and as a value the method or operation that will generate some action on the videogame; this way, the time complexity for looking or generating some combination on the video game will be O(1).

</div>