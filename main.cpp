#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Node
{
    char character;
    Node *horizontal;
    Node *vertical;
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void read_insert(vector<string> array)
    {
        int a = array[0].size();
        int b = array.size();
        int j = 0;
        while (j < a)
        {
            Node *newNode = new Node;
            newNode->character = array[0][j];
            newNode->horizontal = newNode->vertical = NULL;
            if (!root)
            {
                root = newNode;
            }
            else
            {
                Node *current = root;
                Node *parent = NULL;
                while (current != NULL)
                {
                    parent = current;
                    current = current->horizontal;
                }
                parent->horizontal = newNode;
            }
            j++;
        }
        j = 1;
        while (j < b)
        {
            Node *newNode = new Node;
            newNode->character = array[j][0];
            newNode->horizontal = newNode->vertical = NULL;
            if (!root)
            {
                root = newNode;
            }
            else
            {
                Node *current = root;
                Node *parent = NULL;
                while (current != NULL)
                {
                    parent = current;
                    current = current->vertical;
                }
                parent->vertical = newNode;
            }
            j++;
        }

        int c = 1;
        Node *temp = root;
        for (int i = 1; i < a; i++)
        {
            j = 1;
            while (temp->character != array[0][c])
            {
                temp = temp->horizontal;
            }
            if (array[0][c] == array[0][c - 1])
            {
                temp = temp->horizontal;
            }
            c++;
            Node *current = temp;
            Node *parent = current;
            while (current != NULL)
            {
                parent = current;
                current = current->vertical;
            }
            while (j < b)
            {
                Node *newNode = new Node;
                newNode->character = array[j][i];
                newNode->horizontal = newNode->vertical = NULL;
                parent->vertical = newNode;
                parent = parent->vertical;
                j++;
            }
        }
        c = 1;
        temp = root;
        for (int i = 1; i < b; i++)
        {
            j = 1;
            while (temp->character != array[c][0])
            {
                temp = temp->vertical;
            }
            if (array[c][0] == array[c - 1][0])
            {
                temp = temp->vertical;
            }
            c++;
            Node *current = temp;
            Node *parent = current;
            while (current != NULL)
            {
                parent = current;
                current = current->horizontal;
            }
            while (j < a)
            {
                Node *newNode = new Node;
                newNode->character = array[i][j];
                newNode->horizontal = newNode->vertical = NULL;
                parent->horizontal = newNode;
                parent = parent->horizontal;
                j++;
            }
        }
    }
    void search_hor(string s)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = root;
        int size = s.length();
        int i = 0;
        int j = 0;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->character == s[count])
            {
                count++;
            }
            else
            {
                if (temp->character != s[count - 1])
                {
                    count = 0;
                }
            }
            if (count == size)
            {
                output << endl
                       << s << " (" << i + 1 << "," << j + 2 - size << ")"
                       << ","
                       << "(" << i + 1 << "," << j + 1 << ")";
                count = 0;
            }
            temp = temp->horizontal;
            j++;
        }
        count = 0;
        i = 1;
        j = 0;
        Node *temp2 = root->vertical;
        temp = temp2;
        while (temp2 != NULL)
        {
            while (temp != NULL)
            {
                if (temp->character == s[count])
                {
                    count++;
                }
                else
                {
                    if (temp->character != s[count - 1])
                    {
                        count = 0;
                    }
                }
                if (count == size)
                {
                    output << endl
                           << s << " (" << i + 1 << "," << j + 2 - size << ")"
                           << ","
                           << "(" << i + 1 << "," << j + 1 << ")";
                    count = 0;
                }
                temp = temp->horizontal;
                j++;
            }
            temp2 = temp2->vertical;
            i++;
            j = 0;
            temp = temp2;
        }
        output.close();
    }
    void search_back_hor(string s)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = root;
        int size = s.length();
        string reversed = string(s.rbegin(), s.rend());
        int i = 0;
        int j = 0;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->character == reversed[count])
            {
                count++;
            }
            else
            {
                if (temp->character != reversed[count - 1])
                {
                    count = 0;
                }
            }
            if (count == size)
            {
                output << endl
                       << s << " (" << i + 1 << "," << j + 1 << ")"
                       << ","
                       << "(" << i + 1 << "," << j + 2 - size << ")";
                count = 0;
            }
            temp = temp->horizontal;
            j++;
        }
        count = 0;
        i = 1;
        j = 0;
        Node *temp2 = root->vertical;
        temp = temp2;
        while (temp2 != NULL)
        {
            while (temp != NULL)
            {
                if (temp->character == reversed[count])
                {
                    count++;
                }
                else
                {
                    if (temp->character != reversed[count - 1])
                    {
                        count = 0;
                    }
                }
                if (count == size)
                {
                    output << endl
                           << s << " (" << i + 1 << "," << j + 1 << ")"
                           << ","
                           << "(" << i + 1 << "," << j + 2 - size << ")";
                    count = 0;
                }
                temp = temp->horizontal;
                j++;
            }
            temp2 = temp2->vertical;
            i++;
            j = 0;
            temp = temp2;
        }
        output.close();
    }
    void search_ver(string s)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = root;
        int size = s.length();
        int i = 0;
        int j = 0;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->character == s[count])
            {
                count++;
            }
            else
            {
                if (temp->character != s[count - 1])
                {
                    count = 0;
                }
            }
            if (count == size)
            {
                output << endl
                       << s << " (" << i + 2 - size << "," << j + 1 << ")"
                       << ","
                       << "(" << i + 1 << "," << j + 1 << ")";
                count = 0;
            }
            temp = temp->vertical;
            i++;
        }
        count = 0;
        i = 0;
        j = 1;
        Node *temp2 = root->horizontal;
        temp = temp2;
        while (temp2 != NULL)
        {
            while (temp != NULL)
            {
                if (temp->character == s[count])
                {
                    count++;
                }
                else
                {
                    if (temp->character != s[count - 1])
                    {
                        count = 0;
                    }
                }
                if (count == size)
                {
                    output << endl
                           << s << " (" << i + 2 - size << "," << j + 1 << ")"
                           << ","
                           << "(" << i + 1 << "," << j + 1 << ")";
                    count = 0;
                }
                temp = temp->vertical;
                i++;
            }
            temp2 = temp2->horizontal;
            j++;
            i = 0;
            temp = temp2;
        }
        output.close();
    }
    void search_back_ver(string s)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = root;
        int size = s.length();
        string reversed = string(s.rbegin(), s.rend());
        int i = 0;
        int j = 0;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->character == reversed[count])
            {
                count++;
            }
            else
            {
                if (temp->character != reversed[count - 1])
                {
                    count = 0;
                }
            }
            if (count == size)
            {
                output << endl
                       << s << " (" << i + 1 << "," << j + 1 << ")"
                       << ","
                       << "(" << i + 2 - size << "," << j + 1 << ")";
                count = 0;
            }
            temp = temp->vertical;
            i++;
        }
        count = 0;
        i = 0;
        j = 1;
        Node *temp2 = root->horizontal;
        temp = temp2;
        while (temp2 != NULL)
        {
            while (temp != NULL)
            {
                if (temp->character == reversed[count])
                {
                    count++;
                }
                else
                {
                    if (temp->character != reversed[count - 1])
                    {
                        count = 0;
                    }
                }
                if (count == size)
                {
                    output << endl
                           << s << " (" << i + 1 << "," << j + 1 << ")"
                           << ","
                           << "(" << i + 2 - size << "," << j + 1 << ")";
                    count = 0;
                }
                temp = temp->vertical;
                i++;
            }
            temp2 = temp2->horizontal;
            j++;
            i = 0;
            temp = temp2;
        }
        output.close();
    }
    void search_main_diagonal(string s)
    {
        Node *temp = root;
        Node *temp2 = root;
        int i = 0;
        int j = 0;
        int counter = 0;
        while (temp != NULL)
        {
            temp2 = temp;
            counter = 0;
            j = 0;
            while (temp2 != NULL)
            {
                counter++;
                if (s[0] == temp2->character)
                {
                    temp2 = temp2->horizontal;
                    j++;
                    main_diagonal_search(s, temp->vertical, counter, 1, i, j);
                }
                else
                {
                    temp2 = temp2->horizontal;
                    j++;
                }
            }
            temp = temp->vertical;
            i++;
        }
    }
    void main_diagonal_search(string s, Node *r, int i, int count, int row, int column)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = r;
        int j = 0;
        int size = s.length();
        while (j < i && temp)
        {
            temp = temp->horizontal;
            j++;
        }
        if (!temp)
        {
            return;
        }
        if (temp->character == s[count])
        {
            if (count + 1 == s.length())
            {
                output << endl
                       << s << " (" << row + 1 << "," << column << ")"
                       << ","
                       << "(" << row + size << "," << column + size - 1 << ")";
                return;
            }
            else
            {
                main_diagonal_search(s, r->vertical, i + 1, count + 1, row, column);
            }
        }
        output.close();
    }
    void search_back_main_diagonal(string str)
    {
        string s = string(str.rbegin(), str.rend());
        Node *temp = root;
        Node *temp2 = root;
        int i = 0;
        int j = 0;
        int counter = 0;
        while (temp != NULL)
        {
            temp2 = temp;
            counter = 0;
            j = 0;
            while (temp2 != NULL)
            {
                counter++;
                if (s[0] == temp2->character)
                {
                    temp2 = temp2->horizontal;
                    j++;
                    main_diagonal_back_search(s, temp->vertical, counter, 1, i, j);
                }
                else
                {
                    temp2 = temp2->horizontal;
                    j++;
                }
            }
            temp = temp->vertical;
            i++;
        }
    }
    void main_diagonal_back_search(string s, Node *r, int i, int count, int row, int column)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = r;
        int j = 0;
        string str = string(s.rbegin(), s.rend());
        int size = s.length();
        while (j < i && temp)
        {
            temp = temp->horizontal;
            j++;
        }
        if (!temp)
        {
            return;
        }
        if (temp->character == s[count])
        {

            if (count + 1 == s.length())
            {
                output << endl
                       << str << " (" << row + size << "," << column + size - 1 << ")"
                       << ","
                       << "(" << row + 1 << "," << column << ")";
                return;
            }
            else
            {
                main_diagonal_back_search(s, r->vertical, i + 1, count + 1, row, column);
            }
        }
        output.close();
    }
    void search_counter_diagonal(string s)
    {
        int size = s.length();
        Node *temp = root;
        Node *temp2 = root;
        int i = 0;
        int j = 0;
        int counter = 0;
        while (temp != NULL)
        {
            temp2 = temp;
            counter = 0;
            j = 0;
            while (temp2 != NULL)
            {
                counter++;
                if (s[0] == temp2->character)
                {
                    temp2 = temp2->horizontal;
                    j++;
                    if (j >= size)
                    {
                        counter_diagonal_search(s, temp->vertical, counter - 1, 1, i, j);
                    }
                }
                else
                {
                    temp2 = temp2->horizontal;
                    j++;
                }
            }
            temp = temp->vertical;
            i++;
        }
    }
    void counter_diagonal_search(string s, Node *r, int i, int count, int row, int column)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = r;
        int j = 0;
        int size = s.length();
        while (j < i - 1 && temp)
        {
            temp = temp->horizontal;
            j++;
        }
        if (!temp)
        {
            return;
        }
        if (temp->character == s[count])
        {
            if (count + 1 == size)
            {
                output << endl
                       << s << " (" << row + 1 << "," << column << ")"
                       << ","
                       << "(" << row + size << "," << column - size + 1 << ")";
                return;
            }
            else
            {
                counter_diagonal_search(s, r->vertical, i - 1, count + 1, row, column);
            }
        }
        output.close();
    }
    void search_back_counter_diagonal(string str)
    {
        string s = string(str.rbegin(), str.rend());
        int size = s.length();
        Node *temp = root;
        Node *temp2 = root;
        int i = 0;
        int j = 0;
        int counter = 0;
        while (temp != NULL)
        {
            temp2 = temp;
            counter = 0;
            j = 0;
            while (temp2 != NULL)
            {
                counter++;
                if (s[0] == temp2->character)
                {
                    temp2 = temp2->horizontal;
                    j++;
                    if (j >= size)
                    {
                        counter_diagonal_back_search(s, temp->vertical, counter - 1, 1, i, j);
                    }
                }
                else
                {
                    temp2 = temp2->horizontal;
                    j++;
                }
            }
            temp = temp->vertical;
            i++;
        }
    }
    void counter_diagonal_back_search(string s, Node *r, int i, int count, int row, int column)
    {
        ofstream output("output.txt", std::ios_base::app);
        Node *temp = r;
        int j = 0;
        int size = s.length();
        string str = string(s.rbegin(), s.rend());
        while (j < i - 1 && temp)
        {
            temp = temp->horizontal;
            j++;
        }
        if (!temp)
        {
            return;
        }
        if (temp->character == s[count])
        {
            if (count + 1 == size)
            {
                output << endl
                       << str << " (" << row + size << "," << column - size + 1 << ")"
                       << ","
                       << "(" << row + 1 << "," << column << ")";
                return;
            }
            else
            {
                counter_diagonal_back_search(s, r->vertical, i - 1, count + 1, row, column);
            }
        }
        output.close();
    }
    void search(string s)
    {
        search_hor(s);
        search_back_hor(s);
        search_ver(s);
        search_back_ver(s);
        search_main_diagonal(s);
        search_back_main_diagonal(s);
        search_counter_diagonal(s);
        search_back_counter_diagonal(s);
        ofstream output("output.txt", std::ios_base::app);
        output << endl;
        output.close();
    }
    void hor_display(Node *t)
    {
        Node *temp = t;
        while (temp != NULL)
        {
            cout << temp->character << " ";
            temp = temp->horizontal;
        }
    }
    void ver_display(Node *t)
    {
        Node *temp = t;
        while (temp != NULL)
        {
            cout << temp->character << " ";
            temp = temp->vertical;
        }
    }
    void hor_display_all(Node *t)
    {
        while (t)
        {
            cout << endl;
            ver_display(t);
            t = t->horizontal;
        }
    }
    void ver_display_all(Node *t)
    {
        while (t)
        {
            cout << endl;
            hor_display(t);
            t = t->vertical;
        }
    }
    void display(Node *rt)
    {
        if (rt != NULL)
        {
            display(rt->horizontal);
            cout << rt->character << " ";
            display(rt->vertical);
        }
        else
        {
            return;
        }
    }
};

int main()
{
    Tree words;
    string str;

    // array in which you want to search
    vector<string> array = {
        "dogxbxxxnoon",
        "rhellotherex",
        "okciuqbrownm",
        "wxwgexlxhjij",
        "oozokvuxdrow",
        "rlxdrxextxja",
        "drowblonkgod"};
    words.read_insert(array);
    ofstream output("output.txt");
    output << "This File Contains words Found In 2-D Array through Tree";
    output << endl;
    output.close();
    // words.txt should contain words which you want to search
    ifstream input_file("words.txt");
    while (!input_file.eof())
    {
        input_file >> str;
        words.search(str);
    }
    input_file.close();
    system("cls");
    cout << endl
         << "PROCESS COMPLETED! Check output.txt for results\n";
    return 0;
}