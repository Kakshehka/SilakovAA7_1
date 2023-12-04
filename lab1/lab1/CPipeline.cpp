#include "HPipe.h"
#include "Proverka.h"
#include <iostream>
#include <string>

using namespace std;

int Pipeline::newPipeID = 0;

std::ostream& operator << (std::ostream& out, const Pipeline& P)
{
	if (P.Name.empty())
	{
		cout << "Íåò äîñòóïíûõ òðóá äëÿ âçàèìîäåéñòâèÿ" << endl;
	}
	else
	{
		cout << "Íàçâàíèå òðóáû: " << P.Name << "\n" << "Äëèíà òðóáû: " << P.Length <<
			"\n" << "Äèàìåòð òðóáû: " << P.Diameter << "\n" << "Ñîñòîÿíèå òðóáû: " << P.Repairing << "\n";
	}
	return out;
}

Pipeline::Pipeline()
{
	id = newPipeID++;
}

int Pipeline::getPipeID() const
{
	return id;
}

void Pipeline::readPipe(ifstream& in)
{
	getline(in >> ws, Name);
	in >> Length;
	in >> Diameter;
	in >> Repairing;
}

Pipeline Pipeline::AddNewPipe()
{
	Pipeline P;
	cout << "Äîáàâëåíèå íîâîé òðóáû\n" << "Ââåäèòå íàçâàíèå òðóáû:\n";
	P.Name = readLine();
	cout << "Ââåäèòå äëèíó òðóáû:\n";
	getCorrect(P.Length);
	cout << "Ââåäèòå äèàìåòð òðóáû:\n";
	getCorrect(P.Diameter);
	cout << "Âûáåðèòå ñîñòîÿíèå òðóáû, ãäå 0 - òðóáà ðàáîòàåò, 1 - òðóáà íàõîäèòñÿ â ñîñòîÿíèè ðåìîíòà.\n";
	P.Repairing = getInRange(0, 1);
	cout << "Ïðîâåðüòå êîððåêòíîñòü ââåä¸ííûõ äàííûõ:\n";
	cout << P;
	return P;
}

void Pipeline::EditPipe()
{
	if (Name.empty())
	{
		cout << "Íåò äîñòóïíûõ òðóá äëÿ âçàèìîäåéñòâèÿ" << endl;
	}
	else
	{
		cout << "Âûáåðèòå ñîñòîÿíèå òðóáû, ãäå 0 - òðóáà ðàáîòàåò, 1 - òðóáà íàõîäèòñÿ â ñîñòîÿíèè ðåìîíòà." << "\n";
		Repairing = getInRange(0, 1);
		cout << "Òðóáà óñïåøíî îòðåäàêòèðîâàíà";
	}
}

void Pipeline::sohraneniePipe(ofstream& f, Pipeline& item)
{
	f << "Pipeline_flag" << "\n"
		<< item.Name << "\n"
		<< item.Length << "\n"
		<< item.Diameter << "\n"
		<< item.Repairing << "\n";
}