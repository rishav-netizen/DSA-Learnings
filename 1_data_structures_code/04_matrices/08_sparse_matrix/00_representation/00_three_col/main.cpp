#include <iostream>

using namespace std;

struct Element
{
    int i, j, x;
};

struct Sparse
{
    int rows, cols, nums;
    Element *ele;
    
};

void create(Sparse *s)
{
    cout << "Enter the dimensions(rows X cols): ";
    cin >> s->rows >> s->cols;
    cout << "Number of non zeroes: ";
    cin >> s->nums;

    s->ele = new Element[s->nums];
    cout << "Enter all non zero elements(row, col, val): ";
    for (int index = 0; index < s->nums; ++index)
    {
        cin >> s->ele[index].i >> s->ele[index].j >> s->ele[index].x;
    }
}

void display(Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.rows; i++)
    {
        for (int j = 0; j < s.cols; j++)
        {
            if (k < s.nums && s.ele[k].i == i && s.ele[k].j == j)
            {   
                cout << s.ele[k++].x << " ";
            }
            else
            {
                cout << '0' << " ";
            }
        }
        cout << endl;
    }
    
}

int main(){
    Sparse s;
    create(&s);
    display(s);
    delete[] s.ele;
    return 0;
}
