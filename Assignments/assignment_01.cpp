#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

struct RacingTrack 
{
    int trackLength = 30;
};

struct car   
{
    int x;
    int points;
    RacingTrack lenghtOfTrack;
};

bool Draw(const car &C1 , const car &C2);
    
int main()
{
    car C1;
    car C2;
    //Setting car positions to be 1
    C2.x = 1;
    C1.x = 1;
    //Setting points to be 0
    C1.points = 0;
    C2.points = 0;

    cout<<"+-----------------------------------+\n"
        <<"| Controls:                         |\n"
        <<"|    - 1: 'a' (Left), 'd' (right)   |\n"
        <<"|    - 2: 'j' (left), 'l' (right)   |\n"
        <<"|    - Quit: 'q'                    |\n"
        << "+----------------------------------+"<<endl;

    Sleep(3000);
    system("cls");
    while (true)
    {
        bool status = Draw(C1, C2);

        if (!status)
        {
            Sleep(3000);
            system("cls");
            Beep(750, 300);
           cout << "\t\t\t\t\t\t\033\033[1;31m  ________                              ________                         \n"
            "\t\t\t\t\t\t /  _____/ _____     _____    ____      \\_____  \\ ___  __  ____ _______  \n"
            "\t\t\t\t\t\t/   \\  ___ \\__  \\   /     \\ _/ __ \\      /   |   \\  \\/ /_/ __ \\_  __ \\  \n"
            "\t\t\t\t\t\t\\    \\_\\  \\ / __ \\_|  Y Y  \\   ___/     /    |    \\   / \\  ___/ |  |\\/  \n"
            "\t\t\t\t\t\t \\______  /(____  /|__|_|  / \\___  >    \\_______  / \\_/   \\___ >|__|     \n"
            "\t\t\t\t\t\t        \\/      \\/       \\/      \\/             \\/            \\/          \033[0m" << endl;
            break;
        }
        char input = getch();   //To get input from keyboard
        //Switch statement for implementing player movement
        switch(input)
        {
            case 'a':
                C1.x--;
                C1.points++;
                break;
            case 'd':
                C1.x++;
                C1.points++;
                break;
            case 'l':
                C2.x++;
                C2.points++;
                break;
            case 'j':
                C2.x--;
                C2.points++;
                break;
            default:
                if (input != 'q')
                    cout<<"Invalid Input"<<endl;
        }

        if (input == 'q')  
        {
            cout<<endl;
            cout<<"Thanks for playing!"<<endl;
            break;
        }
    }
    
}

bool Draw(const car &C1 , const car &C2)
{
    system("cls");
    bool GameEnded = true;
    cout<<"\033[?25l";
    cout<<"+----------------------------+"<<endl;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < C1.lenghtOfTrack.trackLength; j++)
        {
            if (j == C1.x && i == 1)   //Prints the 1st car at the position x and in 2nd row
            {
                cout<<"1";
                if (j == 29)  //Preventing 1 to go out of bounds
                {
                    Sleep(500);
                    Beep(750, 300);
                    system("cls");
                   cout << "\033[1;33m" 
                        << "                                          ,----,\n"                                          
                        << "                                        ,/   .`|     ,----..\n"                              
                        << "                ,---,   ,----..       ,`   .'  :    /   /   \\   ,-.----.\n"                  
                        << "       ,---. ,`--.' |  /   /   \\    ;    ;     /   /   .     :  \\    /  \\           ,---,\n" 
                        << "      /__./| |   :  : |   :     : .'___,/    ,'   .   /   ;.  \\ ;   :    \\         /_ ./|\n" 
                        << " ,---.;  ; | :   |  ' .   |  ;. / |    :     |   .   ;   /  ` ; |   | .\\ :   ,---, |  ' :\n" 
                        << "/___/ \\  | | |   :  | .   ; /--`  ;    |.';  ;   ;   |  ; \\ ; | .   : |: |  /___/ \\ .  : |\n" 
                        << "\\   ;  \\ ' | '   '  ; ;   | ;     `----'  |  |   |   :  | ; | ' |   |  \\ :   .  \\  \\ ,' '\n" 
                        << " \\   \\  \\: | |   |  | |   : |         '   :  ;   .   |  ' ' ' : |   : .  /    \\  ;  `  ,'\n" 
                        << "  ;   \\  ' . '   :  ; .   | '___      |   |  '   '   ;  \\; /  | ;   | |  \\     \\  \\    '\n"  
                        << "   \\   \\   ' |   |  ' '   ; : .'|     '   :  |    \\   \\  ',  /  |   | ;\\  \\     '  \\   |\n"  
                        << "    \\   `  ; '   :  | '   | '/  :     ;   |.'      ;   :    /   :   ' | \\.'      \\  ;  ;\n"  
                        << "     :   \\ | ;   |.'  |   :    /      '---'         \\   \\ .'    :   : :-'         :  \\  \\\n" 
                        << "      '---\"  '---'     \\   \\ .'                      `---`      |   |.'            \\  ' ;\n" 
                        << "                        `---`                                   `---'               `--`\n"
                        << "Congratulations 1 Wins!\n"
                        << "\033[0m"; 

                    GameEnded = false;
                    break;
                }
            }
            else if (j == C2.x && i == 2)  //Prints the 2nd car at the position x and in 3nd row
            {
                cout<<"2";
                if (j == 29)  //Preventing 2 to go out of bounds
                {
                    Sleep(500);
                    Beep(750, 300);
                    system("cls");
                     cout << "\033[1;33m" 
                        << "                                          ,----,\n"                                          
                        << "                                        ,/   .`|     ,----..\n"                              
                        << "                ,---,   ,----..       ,`   .'  :    /   /   \\   ,-.----.\n"                  
                        << "       ,---. ,`--.' |  /   /   \\    ;    ;     /   /   .     :  \\    /  \\           ,---,\n" 
                        << "      /__./| |   :  : |   :     : .'___,/    ,'   .   /   ;.  \\ ;   :    \\         /_ ./|\n" 
                        << " ,---.;  ; | :   |  ' .   |  ;. / |    :     |   .   ;   /  ` ; |   | .\\ :   ,---, |  ' :\n" 
                        << "/___/ \\  | | |   :  | .   ; /--`  ;    |.';  ;   ;   |  ; \\ ; | .   : |: |  /___/ \\ .  : |\n" 
                        << "\\   ;  \\ ' | '   '  ; ;   | ;     `----'  |  |   |   :  | ; | ' |   |  \\ :   .  \\  \\ ,' '\n" 
                        << " \\   \\  \\: | |   |  | |   : |         '   :  ;   .   |  ' ' ' : |   : .  /    \\  ;  `  ,'\n" 
                        << "  ;   \\  ' . '   :  ; .   | '___      |   |  '   '   ;  \\; /  | ;   | |  \\     \\  \\    '\n"  
                        << "   \\   \\   ' |   |  ' '   ; : .'|     '   :  |    \\   \\  ',  /  |   | ;\\  \\     '  \\   |\n"  
                        << "    \\   `  ; '   :  | '   | '/  :     ;   |.'      ;   :    /   :   ' | \\.'      \\  ;  ;\n"  
                        << "     :   \\ | ;   |.'  |   :    /      '---'         \\   \\ .'    :   : :-'         :  \\  \\\n" 
                        << "      '---\"  '---'     \\   \\ .'                      `---`      |   |.'            \\  ' ;\n" 
                        << "                        `---`                                   `---'               `--`\n"
                        << "Congratulations 2 Wins!\n"
                        << "\033[0m"; 
                    GameEnded = false;
                    break;
                }
            }
            //Creating the remaining track
            else if ( j == 0 || j == C1.lenghtOfTrack.trackLength - 1)  
            {
                cout<<"\033[0m|";
            }
            else
            {
                cout<<"\033[0m ";
            }
        }
        if (!GameEnded)
        {
            break;
        }
        cout<<endl;
    }
    cout <<"+----------------------------+"<<endl;
    cout<<"Points of C1: "<<C1.points<<endl;
    cout<<"Points of C2  "<<C2.points;
    
    return GameEnded;
}
