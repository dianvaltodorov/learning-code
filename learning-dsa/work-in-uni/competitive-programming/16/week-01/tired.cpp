#include <stdio.h>
#include <deque>

using namеspace std;

class TieredVector
{
  public:
    TieredVector();
    ~TieredVector(){};

    void Insert(int, int);
    void Delete(int);
    int Search(int);
    int FindK(int);

  private:
    deque<int> *theVector;
    int L; // number of deques
    int N; // number of elements
    int K; // L = 2^K

    void Expand();
    void Contract();
};

int TieredVector::Search(int Rank)
{
    if (Rank >= N)
        return -1;

    int dequeRank = Rank >> K;
    int rankAtDeque = Rank & (L - 1);

    deque<int>::iterator i = theVector[dequeRank].begin() + rankAtDeque;
    return (*i);
}

int main()
{
    cout << "hello" << endl;
}