// ********************************************************* 
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: T11L 
// Names: CHEW SHEN | TEOH KAI LOON | DYLAN TARUN CHOO SHAO LOON 
// IDs: 1211101589 | 1211101582 | 1211103428 
// Emails: 1211101589@student.mmu.edu.my | 1211101582@student.mmu.edu.my | 121110103428@student.mmu.edu.my
// Phones: 012-9387921 | 011-60704897 | 012-6128052
// ********************************************************* 

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }

int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(__linux__) || defined(__APPLE__)
            return std::system("clear");
        #endif
    }

class Mars
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_; 
    int nozombie;           // to indicate private data
public:
    Mars(int dimX = 15, int dimY = 5, int setnozombie=1);
    void init(int dimX, int dimY, int setnozombie);
    void display(int &dimX, int &dimY, int &setnozombie) ;
    void boardsetting(int dimX, int dimY, int setnozombie);
};

Mars::Mars(int dimX, int dimY, int setnozombie)
{
    init(dimX, dimY, setnozombie);
}

void Mars::init(int dimX, int dimY, int setnozombie)
{
    dimX_ = dimX;
    dimY_ = dimY;
    nozombie = setnozombie;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', '<', '>', 'v', 'h', 'p', 'r'};
    char zombie[] = {'Z'};
    char alien[] = {'A'};
    int noOfObjects = 13; // number of objects in the objects array
    // create dynamic 2D array using vector
    //int setnozombie = 1;
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }
    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
    for (int k = 0; k < nozombie; ++k)
        
    {
        int i = rand() % dimX;
        int j = rand() % dimY;
        map_[j][i] = zombie[0];
    }

    int m;
    int n;
    if (dimX_ % 2 == 0 and dimY_ % 2 == 0)
    {
        m = (dimX_) / 2;
        n = (dimY_) / 2;
        map_[n][m] = alien[0];
    }
    else
    {
        m = (dimX_ - 1) / 2;
        n = (dimY_ - 1) / 2;
        map_[n][m] = alien[0];
    }
}

void Mars::display(int &dimX, int &dimY, int &setnozombie) 
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << "  -------------------------------------" << endl;
    cout << "  | Curiosity, Welcome to Alien Path! |" << endl;
    cout << "  -------------------------------------" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "--";
        }
        cout << "-" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "--";
    }
    cout << "-" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10; 
    }
    cout << endl
         << endl;
}
void test1_1(int dimX_,int dimY_,int setnozombie)
{
    Mars mars;
    mars.display(dimX_,dimY_,setnozombie);
}

void boardsetting(int &dimX, int &dimY, int &setnozombie)
{
    cout << "Board Settings" << endl;
    cout << "--------------" << endl;
    cout << "Enter rows => ";
    cin >> dimX;
    cout << "Enter columns => ";
    cin >> dimY;

    cout << "Zombie settings" << endl;
    cout << "---------------" << endl;
    cout << "Enter number of zombie => ";
    cin >> setnozombie;
    Mars mars;
    mars.init(dimX, dimY, setnozombie);
    mars.display(dimX,dimY, setnozombie);
}


void Menus()
{
    Pause();
    char response;
    int dimX_=15;
    int dimY_=5;
    int setnozombie=1;

    cout << " -------------------------------------" << endl;
    cout << " |           Game Setting             |" << endl;
    cout << " -------------------------------------" << endl;
    cout << "Board Rows: " << dimX_ << endl;
    cout << "Board Columns: " << dimY_ << endl;
    cout << "Zombie Count: " << setnozombie << endl;
    cout << "Do you wish to change the game settings (y/n)? => " ;
    cin >> response;
    response = toupper(response);

    if (response == 'Y')
    {
        boardsetting(dimX_,dimY_, setnozombie);
    }

    else if(response == 'N')
    {
        srand(time(NULL));
        test1_1(dimX_,dimY_, setnozombie);
    }

    else
    {
        cout << "Please insert y/n" << endl;
        return Menus();
    }
}

void helpguide()
{
    cout << "+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "+     Game Control    +" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " " << endl;
    cout << "1. Up - move upward" << endl;
    cout << "2. Down - move downward" << endl;
    cout << "3. Left - move left" << endl;
    cout << "4. Right - move right" << endl;
    cout << "5. Help - display movement control" << endl;
    cout << "6. arrow - Change the direction of an arrow" << endl;
    cout << "7. Save - save the current game progress" << endl;
    cout << "8. Load - load a game" << endl;
    cout << "9. Quit - quit the game" << endl;
    Pause();
}

int main()
{
    char ans;

    cout << "+-+-+-+-+-+-+-+-+" << endl;
    cout << "+     Menu      +" << endl;
    cout << "+-+-+-+-+-+-+-+-+" << endl;
    cout << "+               +" << endl;
    cout << "+ 1. Start Game +" << endl; 
    cout << "+ 2. Help       +" << endl;
    cout << "+ 3. Quit       +" << endl;
    cout << "+-+-+-+-+-+-+-+-+" << endl << endl;

    cout << "command:";
    cin >> ans;

    if (ans == '1')
    {
        Menus();
    }
    else if (ans == '2')
    {
        helpguide();
        return main();
    }

    else if (ans == '3')
    {
       cout << "Bye Bye\n";
       Pause();
       ClearScreen();
    }

    else
    {
        cout << "Please insert the correct input" << endl;
        Pause();
        return main();

    }
}

