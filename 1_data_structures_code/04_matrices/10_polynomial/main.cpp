#include <iostream>
#include <algorithm>

using namespace std;

struct Term
{
    int coeff, exp;
};

bool compare(const Term &t1, const Term &t2)
{
    return t1.exp > t2.exp;
}

class Polynomial
{
    private:
        int n;
        Term *t;

    public:
        Polynomial(int terms)
        {
            n = terms;
            t = new Term[n];
        }
        
        //copy constructor
        Polynomial(const Polynomial &other)
        {
            n = other.n;
            t = new Term[n];

            for (int i = 0; i < n; i++)
            {
                t[i] = other.t[i];
            }
        }

        void set() 
        {   
            cout << "Enter the terms' coefficient and exponent: ";
            for (int i = 0; i < n; i++)
            {
                cin >> t[i].coeff >> t[i].exp;
            }
            std::sort(t, t + n, compare);
        }

        void display() const
        {
            for (int i = 0; i < n; i++)
            {
                if (t[i].exp == 0)
                {
                    cout << t[i].coeff;
                    continue;
                }
                if (t[i].exp == 1)
                {
                    cout << t[i].coeff << "x";
                    if (i < n - 1)
                    {
                        cout << " + ";
                    } 
                    continue;
                }
                
                
                cout << t[i].coeff << "x^" << t[i].exp;
                if (i < n - 1)
                {
                    cout << " + ";
                }
            }
            cout << endl;
        }

        // copy assignment operator 
        Polynomial& operator=(Polynomial &other)
        {
            if (this == &other)
            {
                return *this;
            }

            delete[] t;

            n = other.n;
            t = new Term[n];

            for (int i = 0; i < n; i++)
            {
                t[i] = other.t[i];
            }
            
            return *this;
        }

        Polynomial operator+(Polynomial other)
        {
            Polynomial result(this->n + other.n);
            int i = 0, j = 0, k = 0;

            while (i < n && j < other.n)
            {
                if (compare(t[i], other.t[j]))
                {
                    result.t[k++] = t[i++];
                }
                else if (compare(other.t[j], t[i]))
                {
                    result.t[k++] = other.t[j++];
                }
                else
                {
                    result.t[k].coeff = t[i].coeff + other.t[j].coeff;
                    result.t[k].exp = t[i].exp;
                    k++;
                    i++;
                    j++;
                }
            }
            while (i < n)
            {
                result.t[k++] = t[i++];
            }
            while (j < other.n)
            {
                result.t[k++] = other.t[j++];
            }
            
            result.n = k;
            return result;
        }

        ~Polynomial()
        {
            delete[] t;
            t = nullptr;
        }
};

int main()
{
    int n1, n2;
    cout << "Enter the number of terms you want in the first polynomial: ";
    cin >> n1;
    cout << "Enter the number of terms you want in the second polynomial: ";
    cin >> n2;
    Polynomial p1(n1), p2(n2);
    p1.set();
    cout << "The polynomial entered is: ";
    p1.display();
    p2.set();
    cout << "The polynomial entered is: ";
    p2.display();

    cout << "The sum of the two polynomials is: ";
    Polynomial result = p1 + p2;
    result.display();
    return 0;
}
