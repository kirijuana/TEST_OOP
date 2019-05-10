#include "stdafx.h"
#include "Header.h"
using namespace std;
void container::In(ifstream &ReadFile)
{
	Node *temp;
	Node *Help = NULL;
	while (!ReadFile.eof()) {			
		
		temp = new Node;
		temp->info = shape::In(ReadFile);
		len++;

		if (head == NULL)
		{
			temp->next = temp;
			head = temp;
			Help = temp;
		}
		else
		{
			temp->next = head;
			Help->next = temp;                    
			Help = temp;                          
		}
	}
}

void container::Out(ofstream &WriteFile)
{
	Node *current = head;
	for (int i = 0; i < len; i++) {
		WriteFile << i + 1 << "\n";
		if (len > 0)
		{
			current->info->Out(WriteFile);
			current = current->next;
			if(i + 1 < len)
			{
				WriteFile << "\n";
			}
		}		
	}
}

void container::Clear()
{
	while (len > 0)
	{
		if (len == 1)
		{
			Node *temp = head;
			head = NULL;
			free(temp);
			len = len - 1;
			break;
		}
		Node *temp;
		temp = head->next;
		while (temp->next != head)
			temp = temp->next;

		temp->next = head->next;
		free(head);
		head = temp;
		len = len - 1;
	}
}

void container::Sorting()
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1; j++)
		{
			if (head->info->Perimeter() > head->next->info->Perimeter())
			{
				Node *first = head;

				while (first->next != head)
					first = first->next;

				Node *next1 = head->next;
				Node *next2 = head->next->next;

				next1->next = head;
				head->next = next2;
				first->next = next1;
				head = next1;
			}
			head = head->next;
		}
		head = head->next;
	}
}

container::container()
{
	head = NULL;
	len = 0;
}

shape* shape::In(ifstream &ReadFile)
{

	shape *temp;	//????????? ?????????
	int k;
	ReadFile >> k;
	switch (k) {
	case 1:
		temp = new rectangle;
		break;
	case 2:
		temp = new circle;
		break;
	case 3:
		temp = new triangle;
		break;
	default:
		return 0;
	}

	temp->InData(ReadFile);
	return temp;
}


void rectangle::InData(ifstream &ReadFile)
{
	ReadFile >> x;
	ReadFile >> y;
	ReadFile >> colour;
	ReadFile >> density;
}

void rectangle::Out(ofstream &WriteFile)
{
	WriteFile << x << " " << y << " " << colour << " " << density;
}

float rectangle::Perimeter()
{
	double Sort = 0;
	Sort = x + y;
	return Sort;
}


void circle::InData(ifstream &ReadFile)
{
	ReadFile >> x;
	ReadFile >> y;
	ReadFile >> R;
	ReadFile >> colour;
	ReadFile >> density;
}

void circle::Out(ofstream &WriteFile)
{
	WriteFile << x << " " << y << " " << R << " " << colour << " " << density;;
}

float circle::Perimeter()
{
	double Sort = 0;
	Sort = R * 2 * 3.1415;
	return Sort;
}

void container::FiltredOut(ofstream &WriteFile)
{
	Node *temp = head;
	WriteFile << "Only Rectangle:" << endl;
	for (int i = 0; i < len; i++)
	{
		temp->info->OutOnlyRectangle(WriteFile);
		temp = temp->next;
	}
}

void rectangle::OutOnlyRectangle(ofstream &WriteFile)
{
	Out(WriteFile);
}
void shape::OutOnlyRectangle(ofstream &WriteFile)
{
	
}

void triangle::InData(ifstream &ReadFile)
{
	ReadFile >> a;
	ReadFile >> b;
	ReadFile >> c;
	ReadFile >> colour;
	ReadFile >> density;
}

void triangle::Out(ofstream &WriteFile)
{
	WriteFile << a << " " << b << " " << c << " " << colour << " " << density;
}

float triangle::Perimeter()
{
	double Sort = 0;
	Sort = a + b + c;
	return Sort;
}