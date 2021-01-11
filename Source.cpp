//Щепітки Соломії
//Варіант 23
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
	cout << "Введіть N: "; cin >> N;

	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);
	LineSearch(p, N);
	PhysicsSearch(p, N, k);
	cout << endl << "Кількість студентів, які отрималт 5 з фізики: " << k << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec1;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << " прізвище: "; cin >> p[i].prizv;
		cout << " рік нар.: "; cin >> p[i].rikNar;
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність(0 - Математика та економіка, 1 - Трудове навчання, 2 - Фізика та інформатика, 3 - Інформатика, 4 - Комп’ютерні науки): ";
		cin >> spec1;
		p[i].spec = (Spec)spec1;
		cout << " оцінка з фізики: "; cin >> p[i].physics;
		cout << " оцінка з математики: "; cin >> p[i].math;

		switch (p[i].spec)
		{
		case ME:
			cout << " оцінка з педагогіки : "; cin >> p[i].ped;
			break;

		case MF:
			cout << " оцінка з педагогіки : "; cin >> p[i].ped;
			break;

		case FI:
			cout << " оцінка з педагогіки : "; cin >> p[i].ped;
			break;

		case KN:
			cout << " оцінка з програмування : "; cin >> p[i].prog;
			break;

		case INF:
			cout << " оцінка з чисельних методів : "; cin >> p[i].cMethod;
			break;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "======================================================================================"
		<< endl;
	cout << "| № | Прізвище | Рік.нар. | Курс | Спеціальність | Фізика | Математика | 3тій предмет |"
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
	cout << "Прізвища студентів які вчаться без трійок: " << endl;

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