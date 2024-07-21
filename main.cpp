#include <ctime>
#include <iostream>
using namespace std;
void gameStory()
{
    system("clear");
    cout << "| Vengeance of the Spartan: A Battle for Redemption |";
    cout << "\n---------------------------------------------------\n";
    cout << "There was a Spartan warrior named Kratos who had a beautiful "
            "family.\n";
    cout << "\nDuring a war, when he was nearly defeated, he asked the God of "
            "War for help and, in return, offered himself to the god.\n";
    cout << "\nThe God of War entered the battlefield and destroyed Kratos's "
            "enemies.\n";
    cout << "\nHe started using Kratos as a tool, giving him more powerful "
            "weapons and strength, making him an undefeated warrior.\n";
    cout << "\nTo make Kratos even more powerful, the God of War decided to "
            "eliminate all his weaknesses, including his family.\n";
    cout << "\nUsing Kratos himself as a weapon, the God of War made him destroy "
            "his own family.\n";
    cout << "\nAfter realizing what he had done, Kratos now seeks vengeance.";
    cout << "\n---------------------------------------------------\n";
}

class Player
{

private:
    int health;
    int minAttackDamage;
    int maxAttackDamage;
    int minHealingPower;
    int maxHealingPower;

public:
    Player(int health, int minAttackDamage, int maxAttackDamage,
           int minHealingPower, int maxHealingPower)
    {
        this->health = health;
        this->minAttackDamage = minAttackDamage;
        this->maxAttackDamage = maxAttackDamage;
        this->minHealingPower = minHealingPower;
        this->maxHealingPower = maxHealingPower;

        cout << "\n\nI am Kratos, the Spartan warrior. \n\nAres, you dared to "
                "destroy "
                "my "
                "family. Now, I challenge you to a fight to the death. \n\nPrepare "
                "yourself, God of War your end is near!\n";
    }

    void printStats()
    {
        cout << "\nCurrent Stats";
        cout << "\n-----------------\n";
        cout << "Kratos's Health is " << this->health << endl;
        cout << "Kratos's Attack Damage is between " << this->minAttackDamage
             << " and " << this->maxAttackDamage << endl;
        cout << "Kratos's Healing Power is between " << this->minHealingPower
             << " and " << this->maxHealingPower << endl;
    }

    int getHealth() { return health; } // returns current health

    int giveDamage()
    { // give damage to enemy
        int randomDamage =
            minAttackDamage + (rand() % (maxAttackDamage - minAttackDamage + 1));
        if (randomDamage == maxAttackDamage)
        {
            cout << "Keep it up, Kratos! it was a critical hit\n";
        }
        cout << "Kratos gave a damage of " << randomDamage << " to the enemy\n";
        return randomDamage;
    }

    void takeDamage(int damage)
    { // taking damage from enemy
        if (health != 0)
        {
            int afterDamage = health - damage;
            if (afterDamage <= 0)
            {
                health = 0;
            }
            else
            {
                health = afterDamage;
            }
        }
        if (damage >= 50)
        {
            cout << "Oh no! a  critical hit to Kratos\n";
        }
        cout << "Enemy is dealing damage of " << damage << " to Kratos\n";
        cout << "\nKratos health after damage is " << health << endl;
    }

    void heal()
    { // healing the health of player
        int randomHeal =
            minHealingPower + (rand() % (maxHealingPower - minHealingPower + 1));
        health += randomHeal;
        cout << "\nKratos Healed by " << randomHeal << endl;
        cout << "Kratos's Current Health is " << health << endl;
    }
};

class Enemy
{
private:
    int health;
    int minAttackDamage;
    int maxAttackDamage;

public:
    Enemy(int health, int minAttackDamage, int maxAttackDamage)
    {
        this->health = health;
        this->minAttackDamage = minAttackDamage;
        this->maxAttackDamage = maxAttackDamage;
        cout << "\n\nI am Ares, the God of War.\n";
        cout << "\nKratos, you dare to challenge me? Your quest for vengeance "
                "ends here.\n\nPrepare to face my wrath and meet your death. If "
                "you want to fight, get ready for your demise.\n";
    }

    int getHealth() { return health; } // returns current health

    int giveDamage()
    { // give damage to enemy
        int randomDamage =
            minAttackDamage + (rand() % (maxAttackDamage - minAttackDamage + 1));
        return randomDamage;
    }

    void takeDamage(int damage)
    { // taking damage from enemy
        if (health != 0)
        {
            int afterDamage = health - damage;
            if (afterDamage <= 0)
            {
                health = 0;
            }
            else
            {
                health = afterDamage;
            }
        }
        cout << "\nAres health after damage is " << health << endl;
    }
};

void battleLoop(Player &player, Enemy &enemy)
{
    char playerInput;
    bool isPlayerTurn = true;
    do
    {
        if (isPlayerTurn)
        {
            isPlayerTurn = false;
            cout << "\n\n------------- Kratos Turn --------------\n";

            cout << "\nPress A to attack or H to heal : " << endl;
            cin >> playerInput;

            if (playerInput == 'A' || playerInput == 'a')
            {
                enemy.takeDamage(player.giveDamage());
            }
            else if (playerInput == 'H' || playerInput == 'h')
            {
                player.heal();
            }
            else
            {
                cout << "\nInvalid Action\n";
            }
        }
        else
        {
            isPlayerTurn = true;
            cout << "\n\n------------- Ares Turn --------------\n";
            player.takeDamage(enemy.giveDamage());
        }

    } while (player.getHealth() > 0 && enemy.getHealth() > 0);
}

int main()
{
    char startInput;
    gameStory();
    do
    {
        cout << "\nPress S to start the game or any other key to exit : ";
        cin >> startInput;
        if (startInput == 'S' || startInput == 's')
        {
            cout << "\n--------------------------------------------------------\n";
            Player *player = new Player(100, 10, 30, 10, 25);
            player->printStats();
            cout << "\n---------------------------------------------------------\n";
            Enemy *enemy = new Enemy(100, 10, 30);
            cout << "\n---------------------------------------------------------\n";
            battleLoop(*player, *enemy);

            if (player->getHealth() == 0)
            {
                cout << "\n\nKratos has been defeated by Ares\n";
                cout << "\nGame Over";
            }
            else
            {
                cout << "\n\nKratos Won\nKratos defeated Ares and become the new God "
                        "of War\n";
                cout << "\nGame Over\n\n";
            }
        }
        else
        {
            cout << "\nThanks for playing the God of War\n";
        }
    } while (startInput == 'S' || startInput == 's');
}