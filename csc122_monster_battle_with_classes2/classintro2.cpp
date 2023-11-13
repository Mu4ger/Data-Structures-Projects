/**
 *  A program to explore classes in C++: Part 2
 * 
 *  Classes are placed in a separate file
 * 
 * Inspired by a popular videogame in which, 
 * players strive to be the very best (like no one ever was).
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>                // use < ... > for includes in the include path (most bulit-in includs)

#include "game_classes.hpp"     // use " ..."  for includes in the same current directory as the source code.

using namespace std;

// ** Forward Declarations ** 
// These tell the compiler the name and formate, but define it later.
void testDiceCode();
void testMonsterCode();

// TODO: create a monster battle function
bool battle(Monster &player, Monster &rival);


/**
 * Main function
*/
int main()
{
    // initialize random number generator with time.
    // make it seem more random
    srand(time(0));

    // Dice code testing
    // call our test code, comment out to ignore.
    testDiceCode();

    // Monster code testing.
    // call our test code, comment out to ignore.
    testMonsterCode();

    //|---------- Monster Battle Simulator ----------|
    cout << endl; // add an extra space
    cout << "|---------- Monster Battle Simulator ----------|" << endl;

    // create an array of 3 monsters.
    Monster monsters[3];        // to create an array of classes, you must have a default constructor.

    // Initilaize the array by calling the constructor.
    //            Monster(name, HP, attackDice)
    monsters[0] = Monster("Pikachu", 20, Dice(6));
    monsters[1] = Monster("Bulbasaur", 25, Dice(4));
    monsters[2] = Monster("Charizard", 15, Dice(3));
    // add more if you want ...

    // game variables
    int playerIndex = 0;

    // cycle through the monsters, counting down.
    for(int i = 2; i > 0; i--)
    {
        // battle!
        if(battle(monsters[playerIndex], monsters[i]))
        {
            // battle won!
            cout << "You defeated " << monsters[i].getName() << "!" << endl;

            // add 15 health points to your character.
            // increase attack max by 1.
        }
        else
        {
            // battle lost ...
            break;
        }
    }
    return 0;
}

/**
 * A function to test use example of our Dice class
*/
void testDiceCode()
{
    // dice code testing
    Dice d6 = Dice();
    cout << "d6 roll = " << d6.roll() << endl;
    int nRolls = 3;
    cout << nRolls << "-d6 roll = " << d6.rollN(nRolls) << endl;
}

/**
 * A function to test use example of our Monster class
*/
void testMonsterCode()
{
    Monster pika = Monster();
    pika.setName("Pikachu");
    pika.println();

    Monster bulba = Monster();
    bulba.setName("Bulbasaur");
    bulba.println();

    int attack1 = pika.attack();
    bulba.setHealthPoints(bulba.getHealthPoints() - attack1);
    pika.print();
    cout << " | ";
    bulba.println();
}


/**
 * This function will cause two Monsters to battle
 * The parameters are pass-by-reference
 * 
*/
bool battle(Monster &player, Monster &rival)
{
    Coin coin = Coin();
        if (coin.flip())
            {
                cout << player.getName()<< "goes first"<< endl;
                while (!player.isKOed() && !rival.isKOed())
                {
                    int attack = player.attack();
                    rival.subtractHealth(attack);
                    if (!rival.isKOed())
                    {
                        attack = rival.attack();
                        player.subtractHealth(attack);
                    }
                }
                
            }
            else
            {
                cout << rival.getName()<< "goes first"<< endl;
                while (!player.isKOed() && !rival.isKOed())
                {
                    int attack = rival.attack();
                    player.subtractHealth(attack);
                    if (!player.isKOed())
                    {
                        attack = player.attack();
                        rival.subtractHealth(attack);
                    }
                }
                
            }
    return true;
}

