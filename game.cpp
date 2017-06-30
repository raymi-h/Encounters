#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<int, string> listOfStatNames = {{0,"str"},{1,"con"},{2,"dex"},{3,"int"},{4,"foc"},{5,"wit"},{6,"cha"},{7,"com"}};/*
    str     strength
    con     constitution
    dex     dexterity

    int     intelligence
    foc     focus
    wit     wit

    cha     charisma
    com     comliness
*/

class Actor {

    /*  Used for the player and monsters.

    */

    map<string, int> stats;
    string name;

    public:

    Actor(){}

    int getStat( string key ){

       return stats.find( key )->second;

    }

    void setStat( string key, int value ){

        stats[key] = value;

    }

    void writeSheetInteractive(){

        int statTotal;
        int currentStat;
        int counter;
        string answer;

        cout << "What is your name? > ";
        cin >> name;
        cout << "Please set your stats. ";
        do {
            counter = 0;
            statTotal = 0;
            cout << "Each stat has a max value of 15, and the total of all stats cannot exceed 80.\n\n";
            while (counter < 8){
                do {
                    cout << listOfStatNames.find(counter)->second << " [" << 80 - statTotal <<" pts left] > ";
                    cin >> currentStat;
                } while ( currentStat > 15 );
                setStat( listOfStatNames.find(counter)->second, currentStat );
                statTotal += currentStat;
                counter++;
            }
            
            cout << "Here is you character sheet:\n";
            cout << "Name: " << name << "\n";
            counter = 0;
            while (counter < 8){
                cout << listOfStatNames.find(counter)->second << ":  " << getStat(listOfStatNames.find(counter)->second) << "\n";
                counter++;
            }
            cout << "\n\nIs this okay? > ";
            cin >> answer;
            if (answer != "yes" && answer != "y")
                statTotal = 81;
        } while ( statTotal > 80 );

    }

};


int main(){

    Actor player;
    player.writeSheetInteractive();

}
