# Report on the implementation of blackjack
This is a report describing the implementation of Alfred Bratterud´s design for a casino framework. This implementation of the casino framework is about blackjack.

## Description on the implementation
The implementation uses the predefined layout of the casino framework. It uses a deck of cards, or multiple decks, and couple all the logic together in blackjackGame.
The only headerfile that has been changed since the layout of the framework is *class_blackjackGame.h*. The difference here is the addition of functions for calculation of points in a blackjack hand.
Evry function defined in the header files is implemented as far as it is resonable, but there are multiple values, or methods that are not beeing used, and will not be used in a local term game of blackjack.

There has been some difficulties with the usage and getting to know the framework (casino). As mentioned there is many functions which is not beeing used, or are intended perpose is badly documented which has resulted in meny overhead hours of implementation.
### Highlights - What I think
 - Intresting implementation of heritage when dereferencing base pointers to point to child class objects.
 - Logicaly implementing the relationship between blackjackGame -> gambler -> blackjackState -> blackjackAction and int turn passing the right type of values between these.
 - Intresting to try different types of casting while working with pointers
 - Dificulty in stopping memory leaks without the posibility to implement destructors. A special case of this is the gambler and the gamblers strategies. Since these are added in the game constructor, there are no other locigal place to delete than in the destructor.
 - Implemeting sanity checks to compensate for bad imput, has been intresting and I think I have learned som new things here.


One of the most difficult part of this task has been to do the *right* thing in the *right* place. This means placing the instructions at the intended place for the posibility of the application to work together. 

### Some drawbacks
 - Not posible to assign values to *gameType* in *class_gameState* or *class_strategy* and thus not a right polimorphic implementation.
 - No deconstructor to free memory from e.g gamblers strategies

