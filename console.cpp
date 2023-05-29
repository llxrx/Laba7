#include <iostream>
#include <fstream>

using namespace std;

const unsigned N = 100;

struct strm {
	char Mark;
	char lim;
	char Arr[N + 1];
};
class strL {
	char Arr[N];
	char lim1;
	int L;
public:
	void InArrver3(ifstream& f3, fstream& out, char lim) { // Writing data from file in.
		int sum = 0;
		out << "Version - 3\n\n";
		out << "Sentence: " << '"';
		if (!f3.is_open()) cout << "File didn't open.";
		else {
			f3 >> lim1;
			cout << lim1 << "\n";
			for (int i = 0; i < N; i++) {
				f3.unsetf(ios::skipws);
				f3 >> Arr[i];
				if (Arr[i] == lim1) break;
				//if (f3.eof()) break;
				cout << Arr[i];
				out << Arr[i];
				sum += sizeof(Arr[i]);
			}
		}
		out << '"';
		L = sum;
		out << "\n\n" << "Number of character: " << L;
		//cout << sum;
	}
	void OutResultver3(ifstream& f3, fstream& out, int p) {
		int sum = 0;
		//out << "Limiter - " << "'" << "*" << "'";
		//out << "Sentence: ";
		for (int i = 0; i < L; i++) {
			f3.unsetf(ios::skipws);
			if (Arr[i] == '.')++p;
		}
		cout << "\n";
		out << "\n\n" << "Amount of sentence: " << p << "\n\n";


	}
	void processver3(fstream& out) {
		int y = 1;
		cout << "\n";
		int start = 0;
		for (int i = 0; i < L; i++) {
			if (Arr[i] == L) break;
			if (Arr[i] == '.') {
				cout << "Number of characters in" << " " << y << " " << "sentence: " << (i - start + 1) << endl;
				out << "Number of characters in" << " " << y << " " << "sentence: " << (i - start + 1) << endl;
				y++;
				start = i + 1;
			}
		}
		cout << "\n";
	}

	void InArrver4(ifstream& f4, fstream& out, int* p, int* sum) { // Writing data from file in.
		if (!f4.is_open()) cout << "File didn't open.";
		else {
			f4 >> L;
			out << "Version - 4\n\n";
			cout << "The number of characters - " << L << "\n\n";
			out << "The number of characters - " << "'" << L << "'" << "\n\n";
			out << "Sentence: ";
			for (int i = 0; i < L; i++) {
				f4.unsetf(ios::skipws);
				f4 >> Arr[i];
				if (f4.eof()) break;
				if (Arr[i] == '.')++* p;
				*sum += sizeof(Arr[i]);
				cout << Arr[i];
				out << Arr[i];
			}
			cout << "\n\n" << "Sum = " << *sum << "\n";
		}
	}
	void OutResultver4(ifstream& f4, fstream& out, int* p, int* sum) {
		out << "\n\n" << "Sum = " << *sum;
		out << "\n\n";
		out << "Amount of sentence: " << *p << "\n\n";
	} 
	void processver4(fstream& out) {
		int y = 1;
		for (int i = 0; i < L; i++) {
			if ((i - 1) == L) break;
		}
		cout << "\n";
		int start = 0;
		for (int i = 0; i < L; i++) {
			if (Arr[i] == '.') {
				cout << "Number of characters in" << " " << y << " " << "sentence: " << (i - start + 1) << endl;
				out << "Number of characters in" << " " << y << " " << "sentence: " << (i - start + 1) << endl;
				y++;
				start = i + 1;
			}
		}
		//cout << "\n";
	}
};

void version(int *ver) {
	cout << "What version do you want to start? - ";
	cin >> *ver;
	if (*ver > 4 || *ver <= 0) {
		cout << "\n************************\n" << "*" << "\t\t       *";
		cout << "\n" << "*" << "  " << "Incorrect version!" << "  " << "*" << "\n";
		cout << "*" << "\t\t       *" << "\n************************\n";
		exit(0);
	}
	cout << "Version: " << *ver << "\n";
}

void InArrver1(ifstream& f1, strm* a, int* p, int* space) { // Writing data from file in.
	if (!f1.is_open()) cout << "File didn't open.";
	else {
		f1 >> a->Mark;
		f1 >> a->lim;
		for (int i = 0; i < N; i++) {
			f1.unsetf(ios::skipws);
			f1 >> a->Arr[i];
			if (a->Arr[i] == '.')++* p;
			if (a->Arr[i] == ' ')++* space;
			if (a->Arr[i] == a->lim) break;
			cout << a->Arr[i];
		}
	}
}
void OutResultver1(ifstream& f1, fstream& out, strm* a, int p, int space) {
	int sum = 0;
	out << "Version - 1\n\n";
	out << "Marker - " << "'" << a->Mark << "'" << "\n" << "Limiter - " << "'" << a->lim << "'" << "\n\n";
	out << "Sentence: ";
	for (int i = 0; i < N; i++) {
		f1.unsetf(ios::skipws);
		if (a->Arr[i] == a->lim) break;
		out << a->Arr[i];
	}
	cout << "\n";
	out << "\n\n" << "Amount of sentence: " << p << "\n\n";


}
void processver1(fstream& out, strm* a) {
	int y = 1;
	for (int i = 0; i < N; i++) {
		if (a->Arr[i] == a->lim) break;
	}
	cout << "\n";
	int start = 0;
	for (int i = 0; i < N; i++) {
		if (a->Arr[i] == a->lim) break;
		if (a->Arr[i] == '.') {
			cout << "Number of characters in" << " " << y << " " << "sentence: " << (i - start - 1) << endl;
			out << "Number of characters in" << " " << y << " " << "sentence: " << (i - start - 1) << endl;
			y++;
			start = i;
		}
	}
	cout << "\n";
}

void InArrver2(ifstream& f2, fstream& out, strm* a, int* p, int* space, int* num) { // Writing data from file in.
	int poi = 0;
	int sum = 0;
	if (!f2.is_open()) cout << "File didn't open.";
	else {
		f2 >> a->Mark;
		f2 >> *num;
		out << "Version - 2\n\n";
		out << "Marker - " << "'" << a->Mark << "'" << "\n" << "Limiter - " << "'" << *num << "'" << "\n";
		cout << "The number of characters - " << *num << "\n";
		for (int i = 0; i < *num; i++) {
			f2.unsetf(ios::skipws);
			f2 >> a->Arr[i];
			if (f2.eof()) break;
			if (a->Arr[i] == a->Mark)++* p;
			if (a->Arr[i] == ' ')++* space;
			sum += sizeof(a->Arr[i]);
			cout << a->Arr[i];
			out << a->Arr[i];
		}
		out << "\n\n";
		out << "Amount of sentence: " << *p << "\n\n";
		cout << "\n\n" << "Sum = " << sum << "\n";
	}
}
void processver2(fstream& out, strm* a, int* num) {
	int y = 1;
	for (int i = 0; i < *num; i++) {
		if ((i - 1) == *num) break;
	}
	cout << "\n";
	int start = 0;
	for (int i = 0; i < *num; i++) {
		//cout << a->Arr[i];
		if (a->Arr[i] == '.') {
			cout << "Number of characters in" << " " << y << " " << "sentence: " << (i - start - 1) << endl;
			out << "Number of characters in" << " " << y << " " << "sentence: " << (i - start - 1) << endl;
			y++;
			start = i;
		}
	}
	//cout << "\n";
}

int main() {
	system("color F0");
	int sum = 0, num = 0, ver = 0, space = 0, p = 0;
	char lim = 0;
	strm a;
	strL a1, a2;
	ifstream f1, f2, f3, f4;
	fstream out;
	f1.open("ver1.txt");
	f2.open("ver2.txt");
	f3.open("ver3.txt");
	f4.open("ver4.txt");
	out.open("out.txt", ios::out);

	version(&ver);

	if (ver == 1) {
		InArrver1(f1, &a, &p, &space);
		OutResultver1(f1, out, &a, p, space);
		processver1(out, &a);
	}
	if (ver == 2) {
		InArrver2(f2, out, &a, &p, &space, &num);
		processver2(out, &a, &num);
	}
	if (ver == 3) {
		a1.InArrver3(f3, out, lim); // если нужно использовать а2 и а3 вносим их в класс и тогда -> (a1.process(a2,a3);)
		a1.OutResultver3(f3, out, p);
		a1.processver3(out);
	}
	if (ver == 4) {
		a2.InArrver4(f4, out, &p, &sum);
		a2.OutResultver4(f4, out, &p, &sum);
		a2.processver4(out);
	}

	f1.close();
	f2.close();
	f3.close();
	f4.close();
	out.close();
	return 0;
}