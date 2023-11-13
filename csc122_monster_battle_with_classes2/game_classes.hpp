/**
 *  This is an example of a header file
 * 
 *  This file can be used create definitions 
 *  to be reused in other source code.
*/
// The following 3 lines mean "Only define these once in the executable"
// This means the compiler creates one set of instructions for this code
//   even if many source files include this code.
#pragma once
#ifndef __GAME_CLASSES_HPP__
#define __GAME_CLASSES_HPP__

#include <iostream>
#include <string>
#include <cstdlib>      // needed for rand()

class Dice
{
    private:
        int sides;

    public:
        // Default constructor
        Dice()
        {
            sides = 6;
        }
        
        // parameterize constructor
        Dice(int inSides)
        {
            sides = inSides;
        }

        // Destructor
        ~Dice(){}

        void setSides(int inSides)
        {
            if(inSides > 0)
            {
                sides = inSides;
            }
        }

        int getSides()
        {
            return sides;
        }

        int roll()
        {
            return (rand() % sides) + 1;
        }

        int rollN(int n)
        {
            if(n <= 0)
            {
                return roll();
            }
            else
            {
                int sum = 0;
                for(int i = 0; i < n; i++)
                {
                    sum += roll();
                }
                return sum;
            }
        }
}; // classes must end with a ';' semicolon.


/**
 * Complete the coin class to provide a 
*/
class Coin
{
    private:
        // private data
        Dice coinDice;

    public:
        // default consturctor
        Coin ()
        {
            coinDice = Dice(2);
        }
        // destructor
        ~Coin() {}
        /*
            Method: flip
            Get the result of a coin flip.

            Have the method return at random either true or false with equal probability. 
        */ 
        bool flip()
        {
            return coinDice.roll() == 1;
        }


};

class Monster
{
    private:
        std::string name;
        int healthPoints;
        Dice attackDice;
    public:
        /*
            Default Constructor
        */
        Monster()
        {
            name = "Default Monster";
            healthPoints = 100;
            attackDice = Dice();
        }

        /*
            Parameterized Constructor
        */
        Monster(std::string inName, int inHealth, Dice inDice)
        {
            name = inName;
            healthPoints = inHealth;
            attackDice = inDice;
        }

        /*
            Parameterized Constructor
        */
        Monster(std::string inName, Dice inDice)
        {
            name = inName;
            healthPoints = 100;
            attackDice = inDice;
        }

        /*
            descructor
            called anytime the object goes out of scope or is deleted.
            more on this later ...
        */
        ~Monster(){}

        /*----- Getters  -----*/

        /*
            Method: getName
        */
        std::string getName()
        {
                return name;
        }

        /*
            Method: getHealthPoints
        */ 
       int getHealthPoints()
       {
            return healthPoints;
       }

        /*
            Method: getAttackMax
            return the number of sides of the attackDice.

            TODO: complete the method
        */
       int getAttackMax()
       {
            return attackDice.getSides();
       }


        /*----- Setters  -----*/
        /* 
            Method: setName
            pass a string name
        */
        void setName(std::string inName)
        {
            name = inName;
        }

        /*
            Method: setHealthPoints
            Pass an int for the new health. 
            Do not allow negative health.

            TODO: complete the method
        */
       void setHealthPoints(int inHealth)
       {
            healthPoints = inHealth;
       }

        /* 
            Method: setAttackMax
            Pass an int max attack
            Use this value to update the number of sides for dice.
        */
       void setAttackMax(int newMax)
       {
            attackDice.setSides(newMax);
       }


        /*----- Instance Methods  -----*/

        /* 
            Method: attack
            Make an attack resulting in randomized damage.
        */
        int attack()
        {
            return attackDice.roll();
        }

        /* 
            Method: print
            Print a representation of the class
        */
        void print()
        {
            std::cout << "{" << name << " attack=" << attackDice.getSides();
            std::cout << ", Health=" << healthPoints << "}";
        }

        /* 
            Method: println
            Print a representation of the class with a newline at the end
        */
        void println()
        {
            print();
            std::cout << std::endl;
        }
        
        void subtractHealth (int amount)
        {
            healthPoints -= amount;
            
            if (healthPoints < 0)
            {
                healthPoints = 0;
            }
        }
        void addHealth (int amount)
        {
            healthPoints += amount;
        }
        bool isKOed ()
        {
            return healthPoints == 0;
        }
        void incrementAttackMax ()
        {
            attackDice.getSides()+1;
        }
        
}; // classes must end with a ';' semicolon.


#endif // end the definitions, skip over everything if they are already defined.