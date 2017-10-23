#include <iostream>
using namespace std;

void 	play_game()
{
	int n, i, j;

	cout << "Avec combien de batons veux-tu jouer ?" << endl;
	cout << "Rappel : on peut retirer uniquement entre 1 et 3 batons" << endl;
	cin >> n;
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
			if (n >= 5 )
			{
				if ((n - 5) % 4 > 0)
				{
					cout << "J'ai retire " << (n - 5) % 4 << " batons" << endl;
					n -= (n - 5) % 4;
					cout << "Il reste " << n << " batons" << endl;
				}
				else
				{
					cout << "J'ai retire 1 baton" << endl;
					--n;
					cout << "Il reste " << n << " batons" << endl;
				}
			}
			else if (n >= 2)
			{
				cout << "J'ai retire " << n - 1 << " batons" << endl;
				n = 1;
			}
		}
		else
		{
			cout << "Combien de batons veux-tu retirer ?" << endl;
			j = 0;
			while (j < 1 || j > 3)
            {
                cout << "Entre un chiffre entre 1 et 3" << endl;
                cin >> j;
            }
			n -= j;
			cout << "Il reste " << n << " batons" << endl;
		}
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