#include <iostream>

using namespace std;

// Compressed Sparse Row (CSR) Representation
struct CSRMatrix
{
    int rows, cols;
    int num;        // Total number of non-zero elements
    int *val;       // Non-zero values array (size = num)
    int *col_ind;   // Column indices array (size = num)
    int *row_ptr;   // Row pointer array (size = rows + 1)
};

void create(CSRMatrix *m)
{
    cout << "Enter dimensions (rows X cols): ";
    cin >> m->rows >> m->cols;
    cout << "Number of non-zero elements: ";
    cin >> m->num;

    m->val = new int[m->num];
    m->col_ind = new int[m->num];
    m->row_ptr = new int[m->rows + 1];

    cout << "Enter row pointers (" << m->rows + 1 << " values starting with 0): ";
    for (int i = 0; i <= m->rows; i++)
    {
        cin >> m->row_ptr[i];
    }

    cout << "Enter column indices (" << m->num << " values): ";
    for (int i = 0; i < m->num; i++)
    {
        cin >> m->col_ind[i];
    }

    cout << "Enter non-zero values (" << m->num << " values): ";
    for (int i = 0; i < m->num; i++)
    {
        cin >> m->val[i];
    }
}

void display(const CSRMatrix &m)
{
    cout << "\nReconstructed Matrix:\n";
    for (int i = 0; i < m.rows; i++)
    {
        int start = m.row_ptr[i];
        int end = m.row_ptr[i + 1];
        int k = start;

        for (int j = 0; j < m.cols; j++)
        {
            if (k < end && m.col_ind[k] == j)
            {
                cout << m.val[k++] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    CSRMatrix m;
    create(&m);
    display(m);

    delete[] m.val;
    delete[] m.col_ind;
    delete[] m.row_ptr;

    return 0;
}
