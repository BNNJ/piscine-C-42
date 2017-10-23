
#include <iostream>

using namespace std;

int main()

{
	int n, i, j, k, r;
	k=0;
	while (k==0)
	{
		cout << "Avec combien de batons veux-tu jouer ? Rappel : on peut retirer uniquement entre 1 et 3 batons "  << endl ;
		cin>>n ;
		cout << "qui commence ? Ordinateur : 0, toi : 1" << endl ;
		cin>>i ;
		while (n>5)
		{
			if (i%2==0)
			{
				if ((n-5)%4>0)
				{
					i++;
					cout<<"j'ai retire "<<(n-5)%4<< " batons"<< endl;
					n = n-(n-5)%4;
					cout <<"il reste "<< n<< " batons" << endl;
				}
				else
				{
					i++;
					cout <<"j'ai retire 1 baton"<< endl ;
					n = n-1;
					cout << "il reste "<<n<<" batons"<< endl;
				}
			}
			else
			{
				cout<<"combien de batons veux-tu retirer ?" << endl;
				cin>>j;
				if (j>3)
				{
					cout << "entre un nombre entre 1 et 3"<< endl;
				}
				else
				{
					i++;
					n=n-j;
					cout<<"il reste " <<n<< " batons" << endl ;
				}
			}
		}
		while (n>0 && n<6)
		{
			if (n==5)
			{
				if (i%2==1)
				{
					cout<<"combien de batons veux-tu retirer ?" << endl;
					cin>>j;
					if (j>3)
					{
						cout << "entre un nombre entre 1 et 3"<< endl;
					}
					else
					{
						i++;
						n=n-j;
						cout<<"il reste " <<n<< " batons" << endl ;
					}
				}
				else
				{
					i++;
					cout <<"j'ai retire 1 baton"<< endl ;
					n = n-1;
					cout << "il reste "<<n<<" batons"<< endl;
				}
			}
			else
			{
				if (n>2 && n<5)
				{
					if (i%2==0)
					{
						i++ ;
						cout <<"j'ai retire "<<n -1<< " batons, il en reste 1"<< endl;
						n=1;
					}
					else
			   		{
						cout<<"combien de batons veux-tu retirer ?" << endl;
						cin>>j;
						if (j>3)
						{
							cout << "entre un nombre entre 1 et 3"<< endl;
						}
						else
						{
							i++;
							n=n-j;
							cout << "il reste "<< n << " batons"<< endl;
						}
					}
				}
				else
				{
					if (n==2)
					{
						if (i%2==1)
						{
							cout<<"combien de batons veux-tu retirer ?" << endl;
							cin>>j;
							if (j>3)
							{
								cout << "entre un nombre entre 1 et 3"<< endl;
							}
							else
							{
								i++;
								n=n-j;
								if (n==1)
							{
								i++;
								cout<<"il reste " <<n<< " batons" << endl ;
							}
							else
							{
								cout <<"tu as perdu !!!"<<endl;
							}
						}
					}
					else
					{
						i++;
						cout <<"j'ai retire 1 baton"<< endl ;
						n = n-1;
						cout << "il reste "<<n<<" batons"<< endl;
					}
				}
				if (n==1)
				{
					if (i%2 == 1)
		   			{
						n=n-1;
						cout << "tu es oblige de retirer le dernier baton : tu as perdu !!!";
					}
					else
					{
						n=n-1;
						cout << "j'ai ete oblige de retirer le dernier baton : tu as gagne, bravo !!!" << endl;
					}
				}
			}
		}
	}
	cout <<"Tape 0 pour rejouer, 1 pour t'arreter ! "<< endl;
	cin >>r;
	while (r>1)
	{
		cout <<"c'est si dur de choisir entre deux nombres??? " <<endl;
		cout <<"Tape 0 pour rejouer, 1 pour t'arreter ! "<< endl;
		cin >>r;
	}
	k=r;
	}
	if (k==1)
	{
		cout <<" merci d'avoir joue, au revoir ! "<< endl;
	}
	return 0 ;
}