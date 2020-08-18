#include <iostream>
#include <string>

using namespace std;

typedef long long llint;
class Node
{
    public:
    int containings;
    Node* next[10];
    Node()
    {
        containings = 0;

    }
};

string normalize_string(string s)
{
    string result = "0000000000";
    for(int i = 10 - s.length(); i < 10; i++)
    {
        result[i] = s[i - 10 + s.length()];
    }
    return result;
}

string find_the_xth_number(Node* t, llint x)
{
    string result = "0000000000";
    int counter = 0;
    for(int i = 0; i < 10; i++)
    {
        int j = 0;
        for(j = 0; j < 10; j++)
        {
            if(t->next[j] != NULL)
            {
                if(counter + t->next[j]->containings >= x)
                {
                    result[i] = j + '0';
                    t = t->next[j];
                    break;
                }
                else
                {
                    counter += t->next[j]->containings;
                }
            }
        }
    }
    return result;
}

int to_int(string s)
{
    int r = 1, result = 0;
    for(int i = 9; i >= 0; i--)
    {
        result += r * (s[i] - '0');
        r *= 10;
    }
    return result;
}

void add_number(Node* t, string new_value)
{
    Node* p = t;
    for(int i = 0; i < new_value.length(); i++)
    {
        int new_digit = new_value[i] - '0';
        if(p->next[new_digit] == NULL)
        {
            p->next[new_digit] = new Node();
        }
        p = p->next[new_digit];
        p->containings++;
    }
}

void delete_number(Node* t, string new_value)
{
    Node* p = t;
    for(int i = 0; i < new_value.length(); i++)
    {
        int new_digit = new_value[i] - '0';
        p = p->next[new_digit];
        p->containings--;
    }
}

int Medians[100000], dd = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    int trie_size = 0;
 //   root = new Node;
    Node* t = new Node;
    int n;
    string m;
    int type;
    cin >> n;
    int x1 , x2;
    for( int i = 0; i < n; i++)
    {
        cin >> type;
     //   t = root;

        if(type == 1)
        {
            cin >> m;
            string normalized = normalize_string(m);
          //  cerr << normalized << endl;
            add_number(t, normalized);
         //   cerr << "man injaam!" << endl;
            trie_size++;
        }


        else
        {

            if(trie_size % 2 == 1)
            {
                Medians[dd] = to_int(find_the_xth_number(t, (trie_size + 1) / 2));
                delete_number(t, find_the_xth_number(t, (trie_size + 1)/ 2));
                trie_size--;
                dd = dd+1;
            }
            else
            {

                x1 = to_int(find_the_xth_number(t, (trie_size)/ 2));
                x2 = to_int(find_the_xth_number(t, (trie_size + 2)/ 2));
                if(x2<=x1){
                    Medians[dd] = x2;
                    dd = dd+1;
                    delete_number(t, find_the_xth_number(t, (trie_size + 2)/ 2));
                    trie_size--;

                }
                else{

                    Medians[dd] =  x1;
                    dd =dd + 1;
                    delete_number(t, find_the_xth_number(t, (trie_size)/ 2));
                    trie_size--;

                }

            }
        }
    }
    for (int i = 0; i<dd ;i++)
    {
        cout << Medians[i] << "\n";
    }

}
