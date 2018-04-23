#include<iostream>
#include<cstdlib>

using namespace std;

void conjunction(int x,int y);
void disjunction(int x,int y);
void exOr(int x,int y);
void Conditional(int x,int y);
void Biconditional(int x,int y);
void exNor(int x,int y);
void Negation(int x,int y);
void Nand(int x,int y);
void Nor(int x,int y);

int main()
{
    int choice,x,y;
    cout<<"Enter x: ";
    cin>>x;
    cout<<"Enter y: ";
    cin>>y;
    while(true)
    {
        system("clear");
        cout<<"MENU"<<endl<<endl;
        cout<<"1- Conjunction"<<endl;
        cout<<"2- Disjunction"<<endl;
        cout<<"3- Exclusive Or"<<endl;
        cout<<"4- Conditional"<<endl;
        cout<<"5- BiConditional"<<endl;
        cout<<"6- Exclusive Nor"<<endl;
        cout<<"7- Negation"<<endl;
        cout<<"8- NAND"<<endl;
        cout<<"9- NOR"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                return 1;
            case 1:
                conjunction(x,y);
                break;
            case 2:
                disjunction(x,y);
                    break;
            case 3:
                exOr(x,y);
                break;
            case 4:
                Conditional(x,y);
                break;
            case 5:
                Biconditional(x,y);
                break;
            case 6:
                exNor(x,y);
                break;
            case 7:
                Negation(x,y);
                break;
            case 8:
                Nand(x,y);
                break;
            case 9:
                Nor(x,y);
                break;
            default:
                cout<<"Wrong Choice try again"<<endl;
        }
        cout<<"Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
    return 0;
}

void conjunction(int x,int y)
{
    cout<<"---------------------------"<<endl;
    cout<<"| x | y | x Conjunction y |"<<endl;
    cout<<"| 0 | 0 |        0        |"<<endl;
    cout<<"| 0 | 1 |        0        |"<<endl;
    cout<<"| 1 | 0 |        0        |"<<endl;
    cout<<"| 1 | 1 |        1        |"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x conjunction y = "<<(x&&y)<<endl;
}

void disjunction(int x,int y)
{
    cout<<"---------------------------"<<endl;
    cout<<"| x | y | x Disjunction y |"<<endl;
    cout<<"| 0 | 0 |        0        |"<<endl;
    cout<<"| 0 | 1 |        1        |"<<endl;
    cout<<"| 1 | 0 |        1        |"<<endl;
    cout<<"| 1 | 1 |        1        |"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x disjunction y = "<<(x||y)<<endl;
}

void exOr(int x,int y)
{
    cout<<"---------------------------"<<endl;
    cout<<"| x | y | x ExclusiveOR y |"<<endl;
    cout<<"| 0 | 0 |        0        |"<<endl;
    cout<<"| 0 | 1 |        1        |"<<endl;
    cout<<"| 1 | 0 |        1        |"<<endl;
    cout<<"| 1 | 1 |        0        |"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x ExclusiveOR y = "<<(x^y)<<endl;
}

void Conditional(int x,int y)
{
    cout<<"---------------------------"<<endl;
    cout<<"| x | y | x Conditional y |"<<endl;
    cout<<"| 0 | 0 |        1        |"<<endl;
    cout<<"| 0 | 1 |        1        |"<<endl;
    cout<<"| 1 | 0 |        0        |"<<endl;
    cout<<"| 1 | 1 |        1        |"<<endl;
    cout<<"---------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x Conditional y = "<<!(x==1&&y==0)<<endl;
}

void Biconditional(int x,int y)
{
    cout<<"-----------------------------"<<endl;
    cout<<"| x | y | x BiConditional y |"<<endl;
    cout<<"| 0 | 0 |          1        |"<<endl;
    cout<<"| 0 | 1 |          0        |"<<endl;
    cout<<"| 1 | 0 |          0        |"<<endl;
    cout<<"| 1 | 1 |          1        |"<<endl;
    cout<<"-----------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x BiConditional y = "<<(x==y)<<endl;
}

void exNor(int x,int y)
{
    cout<<"----------------------------"<<endl;
    cout<<"| x | y | x ExclusiveNOR y |"<<endl;
    cout<<"| 0 | 0 |        1         |"<<endl;
    cout<<"| 0 | 1 |        0         |"<<endl;
    cout<<"| 1 | 0 |        0         |"<<endl;
    cout<<"| 1 | 1 |        1         |"<<endl;
    cout<<"----------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x ExclusiveNOR y = "<<!(x^y)<<endl;
}

void Negation(int x,int y)
{
    cout<<"----------"<<endl;
    cout<<"| x | !x |"<<endl;
    cout<<"| 0 |  1 |"<<endl;
    cout<<"| 1 |  0 |"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"!x = "<<!x<<" & !y = "<<!y<<endl;
}

void Nand(int x,int y)
{
    cout<<"----------------------------"<<endl;
    cout<<"| x | y | x     NAND     y |"<<endl;
    cout<<"| 0 | 0 |        1         |"<<endl;
    cout<<"| 0 | 1 |        1         |"<<endl;
    cout<<"| 1 | 0 |        1         |"<<endl;
    cout<<"| 1 | 1 |        0         |"<<endl;
    cout<<"----------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x NAND y = "<<!(x&&y)<<endl;
}

void Nor(int x,int y)
{
    cout<<"----------------------------"<<endl;
    cout<<"| x | y | x     NOR      y |"<<endl;
    cout<<"| 0 | 0 |        1         |"<<endl;
    cout<<"| 0 | 1 |        0         |"<<endl;
    cout<<"| 1 | 0 |        0         |"<<endl;
    cout<<"| 1 | 1 |        0         |"<<endl;
    cout<<"----------------------------"<<endl;

    cout<<"x = "<<x<<" & y = "<<y<<endl;
    cout<<"x ExclusiveNOR y = "<<!(x||y)<<endl;
}