#include <iostream>
using namespace std;

void 	play_game()
{
	int n, i, j, k;

	cout << "Avec combien de batons veux-tu jouer ?" << endl;
	cout << "Rappel : on peut retirer uniquement entre 1 et 3 batons" << endl;
	n = 6;
	do
	{
		if (n < 6)
			cout << "Pas assez de baton, tricheur !" << endl;
		cin >> n;
	} while (n < 6);
	cout << "qui commence ? Ordinateur : 0, toi : 1" << endl;
	cin >> i;

	while (n > 0)
	{
		if (n == 1)
		{
			if (i % 2 == 0)
				cout << "J'ai ete oblige de retirer le dernier baton, tu as gagne !" << endl;
			else
				cout << "Tu es obligé de retirer le dernier baton, j'ai gagné !" << endl;
            return;
		}
		if (i % 2 == 0)
		{
			if (n >= 5)
				if ((n - 5) % 4 > 0)
					k = (n - 5) % 4;
				else
					k = 1;
			else if (n >= 2)
				k = 1;
			cout << "J'ai retire " << k << " batons" << endl;
			n -= k;
		}
		else
		{
			cout << "Combien de batons veux-tu retirer ?" << endl;
			j = 2;
            cout << "Entre un chiffre entre 1 et 3" << endl;
			do
			{
            	if (j < 1 || j > 3)
            		cout << "Entre 1 et 3 on a dit (tocard)" << endl;
            	cin >> j;
			} while (j < 1 || j > 3);
			n -= j;
			if (n < 1)
			{
				cout << "T'as volontairement pris le dernier baton, t'es con et t'as perdu" << endl;
				return;
			}
		}
		cout << "Il reste " << n << " batons" << endl;
		++i;
	}
}

int		main()
{
	int k;

	k = 0;
	while (k == 0)
	{
		play_game();
		cout << "Tape 0 pour rejouer, 1 pour  t'arreter !" << endl;
		cin >> k;
	}
	cout << "Merci d'avoir joue, au revoir !" << endl;
	return 0;
}
