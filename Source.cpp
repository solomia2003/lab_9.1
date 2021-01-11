//������ ����쳿
//������ 23
//lab-9.1

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { ME, MF, FI, INF, KN };

struct Student
{
	string prizv;
	unsigned rikNar;
	int kurs;
	Spec spec;
	int physics;
	int math;

	union
	{
		int prog;
		int cMethod;
		int ped;
	};
};

void Print(Student* p, const int N);
void Create(Student* p, const int N);
void LineSearch(Student* p, const int N);
void PhysicsSearch(Student* p, const int N, int& k);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int k;
	int N;
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	LineSearch(p, N);
	PhysicsSearch(p, N, k);
	cout << endl << "ʳ������ ��������, �� �������� 5 � ������: " << k << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec1;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " �������: "; cin >> p[i].prizv;
		cout << " �� ���.: "; cin >> p[i].rikNar;
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������(0 - ���������� �� ��������, 1 - ������� ��������, 2 - Գ���� �� �����������, 3 - �����������, 4 - ��������� �����): ";
		cin >> spec1;
		p[i].spec = (Spec)spec1;
		cout << " ������ � ������: "; cin >> p[i].physics;
		cout << " ������ � ����������: "; cin >> p[i].math;

		switch (p[i].spec)
		{
		case ME:
			cout << " ������ � ��������� : "; cin >> p[i].ped;
			break;

		case MF:
			cout << " ������ � ��������� : "; cin >> p[i].ped;
			break;

		case FI:
			cout << " ������ � ��������� : "; cin >> p[i].ped;
			break;

		case KN:
			cout << " ������ � ������������� : "; cin >> p[i].prog;
			break;

		case INF:
			cout << " ������ � ��������� ������ : "; cin >> p[i].cMethod;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "======================================================================================"
		<< endl;
	cout << "| � | ������� | г�.���. | ���� | ������������ | Գ���� | ���������� | 3�� ������� |"
		<< endl;
	cout << "--------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].rikNar << " "
			<< "| " << setw(11) << left << p[i].kurs
			<< "| " << setw(11) << left << p[i].spec
			<< "| " << setw(11) << left << p[i].physics
			<< "| " << setw(11) << left << p[i].math;
		switch (p[i].spec)
		{
		case ME:
			cout << "| " << setw(9) << setprecision(2) << fixed << left
				<< p[i].ped << " |" << endl;
			break;
		case MF:
			cout << "| " << setw(9) << setprecision(2) << fixed << left
				<< p[i].ped << " |" << endl;
			break;
		case FI:
			cout << "| " << setw(9) << setprecision(2) << fixed << left
				<< p[i].ped << " |" << endl;
			break;
		case INF:
			cout << "| " << setw(9) << setprecision(2) << fixed << left
				<< p[i].cMethod << " |" << endl;
			break;
		case KN:
			cout << "| " << setw(9) << setprecision(2) << fixed << left
				<< p[i].prog << " |" << endl;
			break;
		}
	}
	cout << "======================================================================================"
		<< endl;
	cout << endl;
}


void LineSearch(Student* p, const int N)
{
	cout << "������� �������� �� ������� ��� �����: " << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].physics > 3)
		{
			if (p[i].math > 3)
			{
				if (p[i].cMethod > 3 || p[i].prog > 3 || p[i].ped > 3)
				{

					cout << setw(3) << right
						<< p[i].prizv << endl;
				}
			}
		}
	}
}

void PhysicsSearch(Student* p, const int N, int& k)
{
	k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 5)
			k++;
	}

}