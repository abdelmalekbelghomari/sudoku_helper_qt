# Instructiosn for implementing the sudoku project 

### Presentation of the project :
* A first welcome window should appear at the start which allows the player to choose a difficulty
* the different levels should be displayed with a maximum score saved for each level
* after the player chooses the level , he can check which options he wants to use to help him out , he can also choose them midgame by going through the options menu
* the best score will be displayed next to the levels
  

### Architecture of the project :
* An obvious Design Pattern that would be implemented would be an MVP ( Model View Presentation) to separate the roles and make the developping part easier
* An observer should be implemented to keep track of the player's moves and help him out by sending notifications
* A strategy pattern will be implemented to generate hints and solve the game
* the pattern Command will be useful for the undo redo option
* the Memento pattern will allow the game to be saved 
* The Factory pattern will be useful to generate different boards ( boards of the same difficulty will have the same amount of empty boxes)

### Options to help out the player :
* INEVITABLE : a filter on the possible options in a box has to be implmented throughout the observer pattern
* the player can request a hint at anytime and it will show him the next number he should look for but it will remove 1 point from his score

### scoring system :
* the score will start as the number of empty cases * 2
* Whenever the player requests a hint , it will take out 1 point from his score
* Whenever the player requests help after requesting a hint, it will take out one more point