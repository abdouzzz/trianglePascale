#include<iostream>

using namespace std;

const int N = 200; 

void afficheTab(int t[], int taille) {
	for (int i = 0; i < taille; i++) {
		cout << t[i] << "\t";  
	cout << endl;
}

void recopieTab(int tInit[], int tDest[], int taille) {
	for (int i = 0; i < taille; i++)
		tDest[i] = tInit[i];
}

void methode1(int n) {
	int t[N], t2[N];
	t[0] = 1;
	for (int i = 1; i < N; i++) {
		t[i] = 0;
	}
	afficheTab(t, 1);
	
	for (int i = 2; i <= n; ++i) {
		
		t2[0] = 1;
		for (int j = 1; j < i; j++) { 
			t2[j] = t[j] + t[j - 1];
		}
		
		recopieTab(t2, t, i);
		
		afficheTab(t, i);
	}
}


void methode2(int n) {
	int t[N];
	
	t[0] = 1;
	for (int i = 1; i < N; i++) {
		t[i] = 0;
	}
	afficheTab(t, 1);
	
	for (int i = 2; i <= n; ++i) {
		for (int j = i - 1; j > 0; j--) { 
			t[j] = t[j] + t[j - 1];
		}
		
		afficheTab(t, i);
	}
}

int main() {
	int nbre;

	cout << "Donnez un nombre (<" << N << "): ";
	cin >> nbre;
	if (nbre < N) {
		methode1(nbre);
		cout << "- - - - -" << endl; 
		methode2(nbre);
	}else{
		cout << "Votre nombre n'est pas <" << N << endl;
	}

	return 0;
}
