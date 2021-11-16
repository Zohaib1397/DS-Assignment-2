#include<iostream>
#include<string>
using namespace std;
#define BRED "\033[31m"
#define Reset "\033[0m"
#define BCyan "\033[1m\033[36m"
class Student
{
public:
	string *name;
	string Reg_no;
	float CGPA;
	string program;
	Student()
	{
		name = new string;
		*name = '\0';
		Reg_no = '\0';
		CGPA = 0.0;
		program = '\0';
	}
	void operator=(Student& obj)
	{
		name = new string;
		*name = *obj.name;
		Reg_no = obj.Reg_no;
		CGPA = obj.CGPA;
		program = obj.program;
	}
	void setname(string* n)
	{
		*name = *n;
	}
	void setReg_no(string Reg_no)
	{
		this->Reg_no = Reg_no;
	}
	void setCGPA(float CGPA)
	{
		this->CGPA = CGPA;
	}
	void setprogram(string program)
	{
		this->program = program;
	}
	string getname()
	{
		return *name;
	}
	string getReg_no()
	{
		return Reg_no;
	}
	float getCGPA()
	{
		return CGPA;
	}
	string getprogram()
	{
		return program;
	}

};
class List
{
public:
	Student* list;
	int length;
	int front, rear;
	int count;
	int size;
	List(int size)
	{
		this->size = size;
		list = new Student[size];
		length = count = 0;
		front = rear = 0;
	}
	void operator=(List& obj)
	{
		list = new Student[size];
		*list = *obj.list;
	}
	void LSisfull()//L for List and S for stack,Queue will be circular but list and stack will be resized.
	{
		Student* temp;
		temp = new Student[size + 10];
		for (int i = 0; i < length; i++)
		{
			temp[i] = list[i];
		}
		delete[]list;
		list = temp;
		temp = NULL;
	}
	bool LSisempty()
	{
		if (length == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isfull()//For Queue
	{
		if (count == size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isempty()//For Queue
	{
		if (count == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void insert(Student S)//For list
	{
		if (length == size)//There is no check inside isfull function because it will only be called when this condition is applied.
		{
			LSisfull();
		}
		if (LSisempty())
		{
			list[length++] = S;

			front++;
			rear++;
			count++;
		}
		else
		{
			list[length++] = S;
			rear++;
			count++;
		}
	}
	void insert(Student S, int pos)//this will insert at the given position in list
	{
		if (length == size)
		{
			LSisfull();
		}
		if (LSisempty() || pos > length || pos < 0)
		{
			cout << "Insertion is not possible" << endl;
		}
		else
		{
			for (int i = length; i > pos; i--)
			{
				list[i] = list[i - 1];
			}
			list[pos] = S;
			length++;
			rear++;
			count++;
		}
	}
	void push(Student S)//For Stack
	{
		if (length == size)
		{
			LSisfull();
		}
		if (LSisempty())
		{
			list[length++] = S;
			front++;
			rear++;
			count++;
		}
		else
		{
			list[length++] = S;
			rear++;
			count++;
		}
	}
	void enqueue(Student S)//For queue
	{
		if (!isfull())
		{
			if (isempty())
			{
				list[++rear] = S;
				front++;
				count++;
				length++;
			}
			else
			{
				list[++rear] = S;
				count++;
				length++;
			}
		}
		else
		{
			cout << "Queue is full cannot add another student" << endl;
		}
	}
	void Cenqueue(Student S)//for circular queue
	{
		if (!isfull())
		{
			if (isempty())
			{
				rear = (rear + 1) % size;
				list[rear] = S;
				front++;
				count++;
				length++;
			}
			else
			{
				rear = (rear + 1) % size;
				list[rear] = S;
				count++;
				length++;
			}
		}
		else
		{
			cout << "List is full\n";
		}
	}
	void Penqueue(Student S, int pos)//for priority queue
	{
		if (!isfull())
		{
			if (isempty() || pos<0 || pos>rear)
			{
				cout << "Insertion is not position\n";
			}
			else
			{
				Student* temp;
				temp = new Student;
				list[++rear] = S;
				*temp = list[rear];
				for (int i = length; i > pos; i--)
				{
					list[i] = list[i - 1];
				}
				list[pos] = *temp;
				delete temp;
				length++;
				count++;
			}
		}
		else
		{
			cout << "Queue is full cannot insert\n";
		}
	}
	void deletion()//For List
	{
		if (!LSisempty())
		{
			if (count == 1)
			{
				length--;
				rear--;
				count--;
				front--;
			}
			else
			{
				length--;
				rear--;
				count--;
			}
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}
	void deletion(int pos)//for list, deletion from between list
	{
		if (!LSisempty())
		{
			if (pos <= 0 || pos > length)
			{
				cout << "Position is not right\n";
			}
			else
			{
				for (int i = pos; i < length; i++)
				{
					list[i] = list[i + 1];
				}
				length--;
				rear--;
				count--;
			}
		}
		else
		{
			cout << "List is empty\n";
		}
	}
	void pop()//for stack
	{
		if (!LSisempty())
		{
			if (count == 1)
			{
				length--;
				rear--;
				count--;
				front--;
			}
			else
			{
				length--;
				rear--;
				count--;
			}
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}
	Student Dequeue()//for queue
	{
		if (!isempty())
		{
			count--;
			return list[front++];
		}
	
	}
	void search()
	{
		if (!isempty())
		{
			cout << "Press" << BRED << " [1] " << Reset"if you want to search through name" << endl;
			cout << "Press" << BRED << " [2] " << Reset"if you want to search through Registration Number" << endl;
			cout << "Press" << BRED << " [3] " << Reset"if you want to search through CGPA" << endl;
			cout << "Press" << BRED << " [4] " << Reset"if you want to search through program" << endl;
		}
		else
		{
			cout << "list is empty\n";
		}
		

	}
	void LSdisplay()//for stack and queue
	{
		char ch;
		for (int i = front-1; i < length; i++)
		{
			cout << "Name of the student is " << *list[i].name << endl;
			cout << "Registration number of the student is " << list[i].Reg_no << endl;
			cout << "CGPA of the student is " << list[i].CGPA << endl;
			cout << "Choosen Program of the student is " << list[i].program << endl;
			cout << endl;
			cout << BCyan << "\nEnter choice" << Reset << endl;
			cin >> ch;
			system("CLS");
		}
	}
	void Qdisplay()//for displaying circular queue
	{
		
			if (isempty())
			{
				cout << "Queue is empty\n";
			}
			else
			{
				if (front < rear)
				{
					for (int i = front - 1; i < rear; i++)
					{
						cout << "Name of the student is " << *list[i].name << endl;
						cout << "Registration number of the student is " << list[i].Reg_no << endl;
						cout << "CGPA of the student is " << list[i].CGPA << endl;
						cout << "Choosen Program of the student is " << list[i].program << endl;
						cout << endl;
					}
				}
				else
				{
					for (int i = front - 1; i < size; i++)
					{
						cout << "Name of the student is " << *list[i].name << endl;
						cout << "Registration number of the student is " << list[i].Reg_no << endl;
						cout << "CGPA of the student is " << list[i].CGPA << endl;
						cout << "Choosen Program of the student is " << list[i].program << endl;
						cout << endl;
					}
					for (int i = 0; i < rear; i++)
					{
						cout << "Name of the student is " << *list[i].name << endl;
						cout << "Registration number of the student is " << list[i].Reg_no << endl;
						cout << "CGPA of the student is " << list[i].CGPA << endl;
						cout << "Choosen Program of the student is " << list[i].program << endl;
						cout << endl;
					}
				}
			}
		
	}

};
int main()
{
	List l(9);
	Student s;
	string* Name;
	string Reg_No;
	float CGPA;
	string program;
	Name = new string;
	char ch;
	int pos, priority;
	do
	{
		system("CLS");
	jump:
		cout << "Press" << BRED << " [1] " << Reset << "for List" << endl;
		cout << "Press" << BRED << " [2] " << Reset << "for Stack" << endl;
		cout << "Press" << BRED << " [3] " << Reset << "for Queue" << endl;
		cout << BCyan << "\nEnter choice" << Reset << endl;
		cin >> ch;
		system("CLS");
		switch (ch)
		{
		case'1':
			cout << "Press" << BRED << " [1] " << Reset << "for insertion of student" << endl;
			cout << "Press" << BRED << " [2] " << Reset << "for deletion of student" << endl;
			cout << "Press" << BRED << " [3] " << Reset << "for searching student" << endl;
			cout << "Press" << BRED << " [4] " << Reset << "for displaying student" << endl;
			cout << BCyan << "\nEnter choice" << Reset << endl;
			cin >> ch;
			system("CLS");
			if (ch == '1')
			{
				cout << "Press" << BRED << " [1] " << Reset << "for insertion of student at end" << endl;
				cout << "Press" << BRED << " [2] " << Reset << "for insertion of student at specific position" << endl;
				cout << BCyan << "\nEnter choice" << Reset << endl;
				cin >> ch;
				system("CLS");
				if (ch == '1')
				{
					cout << "Enter the name of student\n";
					cin.ignore();
					getline(cin, *Name);
					cout << "Enter Registration number of student\n";
					cin.ignore();
					getline(cin, Reg_No);
					cout << "Enter CGPA of student\n";
					cin >> CGPA;
					cout << "Enter Student program\n";
					cin.ignore();
					getline(cin, program);
					s.setname(Name);
					s.setReg_no(Reg_No);
					s.setCGPA(CGPA);
					s.setprogram(program);
					l.insert(s);
				}
				else if (ch == '2')
				{
					cout << "Enter the name of student\n";
					cin.ignore();
					getline(cin, *Name);
					cout << "Enter Registration number of student\n";
					cin.ignore();
					getline(cin, Reg_No);
					cout << "Enter CGPA of student\n";
					cin >> CGPA;
					cout << "Enter Student program\n";
					cin.ignore();
					getline(cin, program);
					s.setname(Name);
					s.setReg_no(Reg_No);
					s.setCGPA(CGPA);
					s.setprogram(program);
					cout << "Enter positon you want to insert the student at\n";
					cin >> pos;
					l.insert(s, pos);
				}
				else
				{
					cout << "Wrong choice entered\n";
					system("pause");
					goto jump;
				}


			}
			else if (ch == '2')
			{
				cout << "Press" << BRED << " [1] " << Reset << "for squential deletion" << endl;
				cout << "Press" << BRED << " [2] " << Reset << "for deletion of student at specific position" << endl;
				cout << BCyan << "\nEnter choice" << Reset << endl;
				cin >> ch;
				system("CLS");
				if (ch == '1')
				{
					l.deletion();
				}
				else if (ch == '2')
				{
					cout << "Enter postion you want to delete the student" << endl;
					cin >> pos;
					l.deletion(pos);
				}
				else
				{
					cout << "Wrong choice entered\n";
					system("pause");
					goto jump;
				}
			}
			else if (ch == '3')
			{
				l.search();
			}
			else if (ch == '4')
			{
				l.LSdisplay();
			}
			else
			{
				cout << "Wrong choice entered\n";
				system("pause");
				goto jump;
			}
			break;
		case '2':
			cout << "Press" << BRED << " [1] " << Reset << "for insertion of student" << endl;
			cout << "Press" << BRED << " [2] " << Reset << "for deletion of student" << endl;
			cout << "Press" << BRED << " [3] " << Reset << "for searching student" << endl;
			cout << "Press" << BRED << " [4] " << Reset << "for displaying student" << endl;
			cout << BCyan << "\nEnter choice" << Reset << endl;
			cin >> ch;
			system("CLS");
			if (ch == '1')
			{
				cout << "Enter the name of student\n";
				cin.ignore();
				getline(cin, *Name);
				cout << "Enter Registration number of student\n";
				cin.ignore();
				getline(cin, Reg_No);
				cout << "Enter CGPA of student\n";
				cin >> CGPA;
				cout << "Enter Student program\n";
				cin.ignore();
				getline(cin, program);
				s.setname(Name);
				s.setReg_no(Reg_No);
				s.setCGPA(CGPA);
				s.setprogram(program);
				l.push(s);
			}
			else if (ch == '2')
			{
				l.pop();
			}
			else if (ch == '3')
			{
				l.search();
			}
			else if (ch == '4')
			{
				l.LSdisplay();
			}
			else
			{
				cout << "Wrong choice entered\n";
				system("pause");
				goto jump;
			}
			break;
		case '3':
			cout << "Press" << BRED << " [1] " << Reset << "for insertion of student" << endl;
			cout << "Press" << BRED << " [2] " << Reset << "for deletion of student" << endl;
			cout << "Press" << BRED << " [3] " << Reset << "for searching student" << endl;
			cout << "Press" << BRED << " [4] " << Reset << "for displaying student" << endl;
			cout << BCyan << "\nEnter choice" << Reset << endl;
			cin >> ch;
			system("CLS");
			if (ch == '1')
			{
				cout << "Press" << BRED << " [1] " << Reset << "for insertion in linear Queue" << endl;
				cout << "Press" << BRED << " [2] " << Reset << "for insertion in circular Queue" << endl;
				cout << "Press" << BRED << " [3] " << Reset << "for insertion in priority Queue" << endl;
				cout << BCyan << "\nEnter choice" << Reset << endl;
				cin >> ch;
				system("CLS");
				if (ch == '1')
				{
					cout << "Enter the name of student\n";
					cin.ignore();
					getline(cin, *Name);
					cout << "Enter Registration number of student\n";
					cin.ignore();
					getline(cin, Reg_No);
					cout << "Enter CGPA of student\n";
					cin >> CGPA;
					cout << "Enter Student program\n";
					cin.ignore();
					getline(cin, program);
					s.setname(Name);
					s.setReg_no(Reg_No);
					s.setCGPA(CGPA);
					s.setprogram(program);
					l.enqueue(s);
				}
				if (ch == '2')
				{
					cout << "Enter the name of student\n";
					cin.ignore();
					getline(cin, *Name);
					cout << "Enter Registration number of student\n";
					cin.ignore();
					getline(cin, Reg_No);
					cout << "Enter CGPA of student\n";
					cin >> CGPA;
					cout << "Enter Student program\n";
					cin.ignore();
					getline(cin, program);
					s.setname(Name);
					s.setReg_no(Reg_No);
					s.setCGPA(CGPA);
					s.setprogram(program);
					l.Cenqueue(s);
				}
				else if (ch == '3')
				{
					cout << "Enter the name of student\n";
					cin.ignore();
					getline(cin, *Name);
					cout << "Enter Registration number of student\n";
					cin.ignore();
					getline(cin, Reg_No);
					cout << "Enter CGPA of student\n";
					cin >> CGPA;
					cout << "Enter Student program\n";
					cin.ignore();
					getline(cin, program);
					s.setname(Name);
					s.setReg_no(Reg_No);
					s.setCGPA(CGPA);
					s.setprogram(program);
					cout << "Enter priority of the queue\n";
					cin >> priority;
					l.Penqueue(s, priority);
				}
				else
				{
					cout << "Wrong choice entered\n";
					system("pause");
					goto jump;
				}

			}
			else if(ch == '2')
			{
				l.Dequeue();
			}
			else if (ch == '3')
			{
				l.search();
			}
			else if (ch == '4')
			{
				l.Qdisplay();
			}
			else
			{
				cout << "Wrong choice entered\n";
				system("pause");
				goto jump;
			}
			break;
		default:
			cout << "Wrong choice entered\n";
			system("pause");
			goto jump;
			break;

		}
		cout << "Press" << BRED << " [y] " << Reset << "to continue or anyother key to discontinue\n";
		cout << BCyan << "\nEnter choice" << Reset << endl;
		cin >> ch;
		ch = tolower(ch);
	} while (ch == 'y');
}