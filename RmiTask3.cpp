#include <iostream>
#include <queue>
using namespace std;
class operations
{
    priority_queue<int, vector<int>,std::greater<int> > q;
    int length;
public:
    operations()
    {
        length = 0;
    }
    int enqueue(int element)
    {
        q.push(element);
        length++;
        return 1;
    }
    void print()
    {
        if(length == 0)
        {
            cout<<"\nNo element is present";
        }
        else
        {
            int a[length];
            int i=0;
            while(!q.empty())
            {
                a[i++] = q.top();
                q.pop();
            }
            cout<<"\nThe current sorted array is \n";
            for(int i=0; i<length; ++i)
            {
                cout<<a[i]<<" ";
                q.push(a[i]);
            }
        }
    }
    ~operations()
    {
        while(!q.empty())
        {
            q.pop();
        }
    }
};

int main()
{
    int choice;
    operations op;
    do
    {
        cout<<"\nEnter Choice [1:Enter List; 2:Print Array; 3:Insert Element; 4:Quit] ";
        cin>>choice;
        switch (choice)
        {
            case 3:
                int element;
                cout<<"\nEnter a element to push: ";
                cin>>element;
                if(op.enqueue(element)) cout<<"\nInsertion was successful";
                break;

            case 2:
                op.print();
                break;

            case 1:
                int p;
                cout<<"\nEnter the number of elements in the list :";
                cin>>p;
                cout<<"\nEnter "<<p<<" elements 1 by 1 \n";
                int q;
                for(int i=0; i<p; ++i)
                {
                    cin>>q;
                    op.enqueue(q);
                }
                cout<<"\nInsertion of list was successful";
                break;


            case 4:
                cout<<"\nThanks for using my program ";
                break;

            default:
                cout<<"\nThe choice entered was wrong ";
                break;
        }
    }while(choice!=4);
    return 0;
}
