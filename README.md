# Shreypardy

To run this, you need to have both SDL2 and SLD2_image which can be found here, https://www.libsdl.org/download-2.0.php. Ensure the repository for the game has access to these files!

This drinking game was made for my frined's birthday, and it unfortunately gave him alcohol poisoning, please don't play it with vodka, and stay safe!

The constants found in RenderWindow.cpp dictate the size of the screen (screenWidth and screenHeight) and the size of the questions (qWidth, qHeight) appearing on the screen, changing these will preserve the formatting of the game, however, they are currently at the recommended sizes. You will also find constant defining the size of the spaces between the quesiton cards, these are automatic, although they can also be changed if desired. You can add different sets of graphics which can be easily interchanged by changing the constant setnum to the number of the directory. In order to load graphics, you need the following paths:

	- /graphics/set(number)/Background.png ~ stores the background in the front page, should be sized to the screen size of choice (in px)
	- /graphics/set(number)/Score.png ~ stores the screen displaying message to choose player's score, should be sized to the screen size of choice (in px)
	- /graphics/set(number)/Cards/Players/Player(number).png ~ you can have up to 8 players, card should be size to quesiton card sie (in px)
	- /graphics/set(number)/Cards/QuestionBack/QuestionBack(number).png ~ 0 <= number < 30, card should be size to quesiton card sie (in px)
	- /graphics/set(number)/Cards/QuestionFront/QuestionFront(number).png ~ 0 <= number < 30, card should be size to quesiton card sie (in px)
	- /graphics/set(number)/Cards/Values/Value(number).png ~ you can add as many values as you want, just make sure to account for the values in AllQuestions.cpp, card should be size to quesiton card sie (in px)
	- /graphics/set(number)/Headers/Header(number).png ~ each of these headers are part of an animation, you can also just add one header which will then note animate, but make sure to scan main.cpp for the loops that animate the header in order to change it, also look out for the boolean animated!


******************************************************
	         !!!  SHREYPARDY RULES !!!
******************************************************

	This game is a mixture of jeopardy and cards against humanity. 
	On a player's turn, they choose an points card from the screen, 
	a quantity of shots will appear on the screen associated with the
	 card, this is important to remember for later!
	 
	The question will then appear on the screen, the players write 
	down their best answer (whether it be accurate or funny is up to the players!). 
	If two people have the same answer at any point in the game, then that means Shrey 
	is too predictable and has to be punished, he takes a shot.

	Once everyone is done, Shrey choose his favourite or the best answer. 
	Shrey then guesses whose answer it was, if he is correct, then the winning 
	player takes the number of shots indicated on the card, otherwise, Shrey fills 
	his cup with 1/2 the amount of shots indicated.
	
	The player whose answer it was receives the points from the round, 
	and if they had chosen the question initially, they receive 1.5X the points.
	
	Finally, if Shrey's cup fills up he has to chug it, if his cup doesn't fill 
	up by the end of the game, he still has to chug it because it's more fun that way.	
	
	The game finishes once all the questions have been answered, and the 
	winning player is revealed. The winning player receives a prize!
