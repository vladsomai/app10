﻿#include <iostream>
#include "Graf_matrix.h"


namespace matrix_graf
{

	void menu(shared_ptr<Graf>);

	
	//functie principala care va chema meniul
	void MatrixGraf_main(shared_ptr<Graf> matrix_graf)
	{

		menu(matrix_graf);

	}


	//functia de meniu graf reprezentat prin matrice
	void menu(shared_ptr<Graf> graf)
	{

		int optiune = 0;
		size_t dfsOption{};
		size_t bfsOption{};
		bool grafVid{};
		auto it = graf->getFirstNode();

		do
		{
			system("cls");
			cout << "\n\n======MENU======\n";

			cout << "1.Inserare nod.\n";
			cout << "2.Inserare arc.\n";

			cout << "3.Suprima nod\n";
			cout << "4.Suprima arc.\n";

			cout << "5.Graf vid.\n";
			cout << "6.Graf plin.\n";

			cout << "7.Afisare noduri graf.\n";
			cout << "8.Afisare matrice.\n";

			cout << "9. Cautare prin adancime - DFS.\n";
     		cout << "10.Cautare prin cuprindere - BFS.\n";

			cout << "0.Exit.\n";

			cout << "Optiunea dvs. : ";
			cin >> optiune;

			cout << "\n\n======OUTPUT======" << endl;
			switch (optiune)
			{
			case 0:
				cout << "\n\nExiting..." << endl;
				break;
			case 1:
				graf->InsertNode();
				cout << endl;
				break;
			case 2:
				graf->InsertArc(true);
				cout << endl;
				break;

			case 3:
				graf->SuprimNod();
				cout << endl;
				break;
			case 4:
				graf->InsertArc(false);
				cout << endl;
				break;

			case 5:
			    grafVid = graf->GrafVid();
				if (grafVid) cout << "True"; else cout << "False";
				cout << endl;
				break;
			case 6:
				graf->GrafPlin();
				cout << endl;
				break;
			case 7:
				graf->afisareNoduriGraf();
				cout << endl;
				break;
			case 8:
				graf->PrintMatrix();
				cout << endl;
				break;
			case 9:
				cout << "\n=======Cautare prin adancime=======" << endl;

				//tratam cazul in care dorim sa incepem de la un element mai mare ca si size-ul listei de noduri graf
				cout << "Introduceti al catelea element sa fie cel de start:"; cin >> dfsOption;
				if(dfsOption >= graf->sizeof_NoduriGraf())
				{
					
					cout << "Numarul introdus este mai mare decat marimea grafului" << endl;
					break;

				}

				graf->clearSearchedList();
				it = graf->getFirstNode();//resetam iteratorul la primul nod
				advance(it, dfsOption);//setam al catelea element din lista sa fie luat ca si parametru
				graf->DepthFirstSearch(*it);
				cout << endl;
				graf->PrintNodesSearchedInGraf();
				it = graf->getFirstNode();//resetam iteratorul la primul nod dupa ce am terminat executia
				cout << endl;
				break;
			case 10:
				cout << "\n=======Cautare prin cuprindere=======" << endl;

				//tratam cazul in care dorim sa incepem de la un element mai mare ca si size-ul listei de noduri graf
				cout << "Introduceti al catelea element sa fie cel de start: "; cin >> bfsOption;
				if (bfsOption >= graf->sizeof_NoduriGraf())
				{

					cout << "Numarul introdus este mai mare decat marimea grafului" << endl;
					break;

				}

				it = graf->getFirstNode();//folosim un iterator pentru a porni de la un nod dorit din lista de noduri
				advance(it, bfsOption);


				graf->BreadthFirstSearch(*it);
				cout << endl;
				break;

			default:
				cout << "Optiune gresita...\n";
				cout << endl;
				break;
			};

			system("pause");
		} while (optiune != 0);

	}

}