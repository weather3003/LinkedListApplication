/*************************************************************************************
Class Name: List
Des: Allows users to crea
***************************************************************************************/

using std::string;

typedef struct ListType			 //change the name here-----|
{//															|
	string name;   //required								|
	//add other variables									|
//															|
} newName ; //     <-----------------------------------------

struct Node
{
	ListType data;
	Node* next;
};

class List
{
public:
	List();
	~List();
	bool Insert(ListType);
	bool Delete(string);
	bool Edit(string, ListType);
	void Print();
	bool Next(ListType&);
	bool Next(ListType&, int);
	
private:
	Node* head;
	Node* current;

};