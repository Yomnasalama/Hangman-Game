#include <bits/stdc++.h>
using namespace std;
string word;
string words [] = {"apple","orange","banana","strawberry","grapes","watermelon","pineapple","pear","mango","cherry"};
string s = "----------";
int x = 0;
string w[4] = {};
void clear_game()
{
    x = 0;
    s = "----------";
}
void select_word()
{
    srand(time(0));
	int n = rand()% 10;
	word = words[n];
}
void put_letters()
{
    for(int i = 0; i < word.size(); i++)
    {
         cout<<s[i]<<" ";
    }
    cout<<endl;
}
void check_right(char l)
{
    bool b = false;
    for(int i = 0; i < word.size(); i++)
    {
        if(l == word[i])
        {
            s[i] = l;
            b = true;
        }
    }
    if(!b)
        x++;
}
void print(int position)
{

     switch(position)
     {
     case 0:
        cout << " ___________"<<endl;
        cout << " |          "<<endl;
        cout << " |         " <<endl;
        cout << "_|______________"<<endl;
     break;
     case 1:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |         " <<endl;
            cout << "_|______________"<<endl;
     break;
     case 2:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\  " <<endl;
            cout << "_|______________"<<endl;
     break;
     case 3:       cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\ | " <<endl;
            cout << "_|______________"<<endl;
     break;
     case 4:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\ | /" <<endl;
            cout << "_|______________"<<endl;
     break;
     case 5:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\ | /" <<endl;
            cout << " |         |"<<endl;
            cout << "_|______________"<<endl;
     break;
     case 6:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\ | /" <<endl;
            cout << " |         |"<<endl;
            cout << " |        /  "<<endl;
            cout << "_|______________"<<endl;
     break;
     case 7:
            cout << " ___________"<<endl;
            cout << " |         0"<<endl;
            cout << " |       \\ | /" <<endl;
            cout << " |         |"<<endl;
            cout << " |        / \\ "<<endl;
            cout << "_|______________"<<endl;
     }
}

bool win_lose()
{
    if(x == 7)
    {
        cout<<"YOU LOSE :("<<endl;
        print(x);
        return true;
    }
    else
    {
        for(int i = 0; i < word.size(); i++)
        {
             if(s[i] == '-')
                return false;
        }
    }
    cout<<"YOU WIN :)"<<endl;
    cout <<word << endl;
    return true;
}
bool check_input(char l)
{
    if (int(l) >= 97 && int(l) <= 122)
        return true;
    return false;
}
int read_input(string &l)
{
    cout<<"GUESS A LETTER: ";
    cin>> l;
    cout<<endl;
    while (!check_input(l[0]))
    {
        cout<<"Enter a valid input: "<<endl;
        cin >>l;
        cout<<endl;
    }
}
void play()
{
    cout<<"Hangman Game....."<<endl;
    cout<<"GUESS a fruit name !!"<<endl;
    while(true)
    {
        print(x);
        put_letters();
        string i;
        read_input(i);
        check_right(i[0]);
        if(win_lose())
        {

            break;
        }

    }
}
int main()
{
    while(true)
  {
      clear_game();
      select_word();
      play();
      char c;
      cout<<"Play Again [Y/N]";
      cin>>c;
      if(c != 'y' && c!= 'Y')
        break;
 }

}
