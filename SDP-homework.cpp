

#include "Browser.h"
int main()
{

	Browser s;
	//char str1[]= "www.google.bg / search ? q = google + plz + help + me + solve + my + data + structures + task";
	//char str2[] = "www.9gag.com / gag / aAV83g9 / when - you - realise - today - isthe - homework - assignment - deadline";
	//char str3[] = "www.en.wikipedia.org / wiki / Data_structure";
	//char str4[] = "www.wikihow.com / Deal - With - Tons - of - Homework";
	//char str5[] = "www.susi.uni - sofia.bg";
	//char str6[] = "www.youtube.com/watch?v=dQw4w9WgXcQ";
	//s.Go(str6);
	//s.Insert(str1);
	//s.Insert(str2);
	//s.Insert(str3);
	//s.Back();
	//s.Back();
	//s.Remove();
	//s.Print();
	//cout << endl;
	//s.Remove();
	//s.Go(str4);
	//s.Forward();
	//s.Go(str5);
	//s.Print();

	cout << "You can choose from the following commands:" << endl;
	cout << "// GO // INSERT // REMOVE // FORWARD // BACK // PRINT // EXIT //" << endl;
	cout << "ENTER YOUR COMMAND" << endl;

	while (1) {
		cout << "ENTER YOUR COMMAND" << endl;
		char answer[8];
		cin.getline(answer, 8);
		if (strcmp(answer, "GO") == 0) {
			cout << "ENTER THE UTL:";
			char* UTL1 = new char[sizeof(UTL1) + 1];
			cin.getline(UTL1, strlen(UTL1));
			s.Go(UTL1);
		}
		else if (strcmp(answer, "INSERT") == 0) {
			cout << "ENTER THE UTL:";
			char* UTL2 = new char[sizeof(UTL2) + 1];
			cin.getline(UTL2, strlen(UTL2));
			s.Insert(UTL2);
		}
		else if (strcmp(answer, "REMOVE") == 0) {
			s.Remove();

		}
		else if (strcmp(answer, "FORWARD") == 0) {
			s.Forward();

		}
		else if (strcmp(answer, "BACK") == 0) {
			s.Back();

		}
		else if (strcmp(answer, "PRINT") == 0) {
			s.Print();
		}
		else if (strcmp(answer, "EXIT") == 0) {
			return 0;
		}
		else {
			cout << "INVALID COMMAND" << endl;
		}
	}
}




