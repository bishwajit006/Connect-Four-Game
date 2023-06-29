#include<bits/stdc++.h>
using namespace std;
int player,choice,a=0;
int arr[7][6];
int d = 0;
void check(int x)
{
   if(arr[x-1][a] != 0 && a<6)
   {
       a++;
       check(x);
   }
   else if(player==1 && a<6)
   {
       arr[x-1][a]=1;
       a=0;
   }
   else if(player==2 && a<6)
   {
       arr[x-1][a]=2;
       a=0;
   }
   else
   {
      cout<<"WRONG !";
       a=0;
       player++;

   }
}
int draw()
{
    for(int i=0;i<9;i++)
    {
        if(i<2)
        {
            cout<<"-";
        }
        else if(i>7)
        {
            cout<<i-1<<"--"<<endl;
        }
        else
        {
           cout<<i-1<<"----";
        }
    }

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(arr[j][i]!=0)
            {
                if(arr[j][i]==1)
                    cout<<"| X |";
                else
                    cout<<"| O |";
            }
            else
               cout<<"|   |";
        }
        cout<<endl;
    }
    for(int i=0;i<35;i++)
    {
       cout<<"=";
    }
    cout<<endl;
}

int winner_check()
{
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            if(arr[j][i]==1 && arr[j+1][i+1]==1 && arr[j+2][i+2]==1 && arr[j+3][i+3]==1)
            {
               cout<<"PLAYER-1 WIN !"<<endl;
               d=1;
            }
           else if(arr[j][i]==1 && arr[j+1][i-1]==1 && arr[j+2][i-2]==1 && arr[j+3][i-3]==1)
           {
               cout<<"PLAYER-1 WIN !"<<endl;
               d=1;
           }
          else  if(arr[j][i]==1 && arr[j][i-1]==1 && arr[j][i-2]==1 && arr[j][i-3]==1)
          {
               cout<<"PLAYER-1 WIN !"<<endl;
               d=1;
          }
          else  if(arr[j][i]==1 && arr[j-1][i]==1 && arr[j-2][i]==1 && arr[j-3][i]==1)
          {
               cout<<"PLAYER-1 WIN !"<<endl;
               d=1;
          }


         else if(arr[j][i]==2 && arr[j+1][i+1]==2 && arr[j+2][i+2]==2 && arr[j+3][i+3]==2)
         {
                cout<<"PLAYER-2 WIN !"<<endl;
                d=1;
         }
           else if(arr[j][i]==2 && arr[j+1][i-1]==2 && arr[j+2][i-2]==2 && arr[j+3][i-3]==2)
           {
              cout<<"PLAYER-2 WIN !"<<endl;
              d=1;
           }
          else  if(arr[j][i]==2 && arr[j][i-1]==2 && arr[j][i-2]==2 && arr[j][i-3]==2)
          {
              cout<<"PLAYER-2 WIN !"<<endl;
              d=1;
          }

          else  if(arr[j][i]==2 && arr[j-1][i]==2 && arr[j-2][i]==2 && arr[j-3][i]==2)
          {
              cout<<"PLAYER-2 WIN !"<<endl;
              d=1;
          }
       }
    }
}


int player_choice()
{
    player=1;
    while( d != 1)
    {
       cout<<"PLAYER-"<<player<<" :";
        cin>>choice;
        if(choice>0 && choice<8)
        {
            check(choice);
            draw();
           if(player==1)
           {
               player++;
           }
           else
           {
               player--;
           }
        }
        else
        {
            cout<<"WRONG ANSWER !"<<endl;
        }
        winner_check();
    }
}
int main()
{
    cout<<"Group-LINUX"<<endl;
    cout<<"Instructor-FARIA NISHAT KHAN MA'AM"<<endl;
    cout<<"WELCOME TO CONNECT 4 GAME:"<<endl<<endl;
    draw();
    player_choice();


    return 0;
}
