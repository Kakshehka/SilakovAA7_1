#include "HKS.h"
#include "Proverka.h"
#include <iostream>
#include <string>


using namespace std;

int KStation::newKSID = 100;

std::ostream& operator << (std::ostream& out, const KStation& K)
{
	if (K.Name.empty())
	{
		cout << "Íåò äîñòóïíûõ ÊÑ äëÿ âçàèìîäåéñòâèÿ" << endl;
	}
	else
	{
		cout << "Íàçâàíèå ÊÑ: " << K.Name << "\n" << "Êîëè÷åñòâî öåõîâ: " << K.NWorkshops <<
			"\n" << "Êîëè÷åñòâî öåõîâ â ðàáîòå: " << K.WorkingWorkshops << "\n" << "Êîýôôèöèåíò ýôôåêòèâíîñòè: " << K.Efficiency << "\n";
	}
	return out;
}

KStation::KStation()
{
	id = newKSID++;
}

int KStation::getKSID() const
{
	return id;
}

void KStation::readKS(ifstream& in)
{
	getline(in >> ws, Name);
	in >> NWorkshops;
	in >> WorkingWorkshops;
	in >> Efficiency;
}

KStation KStation::AddNewKS()
{
	KStation K;
	cout << "Äîáàâëåíèå íîâîé ÊÑ\n" << "Ââåäèòå íàçâàíèå ÊÑ:\n";
	K.Name = readLine();
	cout << "Ââåäèòå êîëè÷åñòâî öåõîâ:\n";
	getCorrect(K.NWorkshops);
	cout << "Ââåäèòå êîëè÷åñòâî ðàáîòàþùèõ öåõîâ:\n";
	K.WorkingWorkshops = getInRange(0, K.NWorkshops);
	cout << "Ââåäèòå êîýôôèöèåíò ýôôåêòèâíîñòè:\n";
	getCorrect(K.Efficiency);
	cout << "Ïðîâåðüòå êîððåêòíîñòü ââåä¸ííûõ äàííûõ:\n";
	cout << K;
	return K;
}

void KStation::EditKS()
{
	if (Name.empty())
	{
		cout << "Íåò äîñòóïíûõ ÊÑ äëÿ âçàèìîäåéñòâèÿ" << endl;
	}
	else
	{
		cout << "Ââåäèòå êîëè÷åñòâî ðàáîòàþùèõ öåõîâ, ÷èñëî íå äîëæíî ïðåâûøàòü " << NWorkshops << ":\n";
		WorkingWorkshops = getInRange(0, NWorkshops);
		cout << "ÊÑ óñïåøíî îòðåäàêòèðîâàíà";
	}

}

void KStation::sohranenieKS(ofstream& f, KStation& item)
{
	f << "KStation_flag" << "\n"
		<< item.Name << "\n"
		<< item.NWorkshops << "\n"
		<< item.WorkingWorkshops << "\n"
		<< item.Efficiency << "\n";
}