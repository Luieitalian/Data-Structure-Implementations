#include "LinkedList.cpp"
using namespace std;


int main()
{
    LinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    cout<<list.value_n_from_end(2)<<endl;

    list.print();

    std::cin.get();
    
}
