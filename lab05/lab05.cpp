#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <climits>

using namespace std;

class Book {
	protected:
		string title;
	
	public:			
		Book(string title) {
			this->title = title;
		}
		
		string getTitle() {
			return title;
		}
		
		virtual string getType() const = 0;
};

class Novel : public Book {

	public:	
		Novel(string title) : Book(title) {}
		
		string getType() const {
			return "powiesc";
		}
	
};

class Comic : public Book {
	
	public:
		Comic(string title) : Book(title) {}
		
		string getType() const
		{
			return "komiks";
		}
};

class Textbook : public Book{
	
	public:
		Textbook(string title) : Book(title) {}
		
		string getType() const
		{
			return "podrecznik";
		}
};

class Library {
	public:
		vector<Novel> novels;
		vector<Comic> comics;
		vector<Textbook> textbooks;
		
		Library* addNovel(Novel novel) {
			this->novels.push_back(novel);
			return this;
		}
		
		Library* addComic(Comic comic)
		{
			this->comics.push_back(comic);
			return this;
		}
		
		Library* addTextbook(Textbook textbook)
		{
			this->textbooks.push_back(textbook);
			return this;
		}
		
		vector<Novel> getNovels() {
			return novels;
		}
		
		vector<Comic> getComics()
		{
			return comics;
		}
		
		vector<Textbook> getTextbooks()
		{
			return textbooks;
		}
};

int PrintBooks()
{
	int choice;
	cout<<"Would you like to print out contents of the library?:"<<endl;
	cout<<"1.Novels\n2.Comics\n3.Textbooks\n4.All\n0.Exit\n";
	cin>>choice;
	while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n'); 
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> choice;
    }
    if(choice!=0)
	{
    switch(choice)
    {
		case 1:
			return 1;
			break;
		case 2:
			return 2;
			break;
		case 3:
			return 3;
			break;
		case 4:
			return 4;
			break;			
	}
	}
	return 0;
}



int main() {
	setlocale(LC_ALL, "pl_PL.UTF-8");
	string book;
	
	Library library = Library();
	library.addNovel(Novel("Wektor pierwszy"));
	library.addNovel(Novel("Gwiazda po gwiezdzie"));
	library.addNovel(Novel("Jednocz1ca Moc"));
	for(int i=1;i!=0;i)
	{
	cout<<"What kind of book would you like to add?:"<<endl;
	cout<<"1.Novel"<<endl;
	cout<<"2.Comic"<<endl;
	cout<<"3.Textbook"<<endl;
	cout<<"0.Exit"<<endl;
	cin>>i;
	while (cin.fail())
    {
        cin.clear(); 
        cin.ignore(INT_MAX, '\n'); 
        cout << "You can only enter numbers.\n";
        cout << "Enter a number.\n";
        cin >> i;
    }
	if(i!=0)
	{
		cout<<"Type name of the book:";
		cin>>book;	
	}
	switch(i)
	{
	case 1:
		library.addNovel(Novel(book));
		break;
	case 2:
		library.addComic(Comic(book));
		break;
	case 3:
		library.addTextbook(Textbook(book));
		break;
	}
	}

	switch(PrintBooks())
	{
		case 1:
			for(int i = 0; i < library.novels.size(); i++) 
	{
		Novel novel = library.getNovels().at(i);
		cout << novel.getType() << " || " << novel.getTitle() << endl;
	}
			break;
		case 2:
			for(int i=0;i<library.comics.size();i++)
	{
		Comic comic=library.getComics().at(i);
		cout<<comic.getType()<<" || "<<comic.getTitle()<<endl;
	 }
			break;
		case 3:
			for(int i=0;i<library.textbooks.size();i++)
	{
		Textbook textbook=library.getTextbooks().at(i);
		cout<<textbook.getType()<<" || "<<textbook.getTitle()<<endl;
	}
			break;
		case 4:
			for(int i = 0; i < library.novels.size(); i++) 
	{
		Novel novel = library.getNovels().at(i);
		cout << novel.getType() << " || " << novel.getTitle() << endl;
	}
			for(int i=0;i<library.comics.size();i++)
	{
		Comic comic =library.getComics().at(i);
		cout<<comic.getType()<<" || "<<comic.getTitle()<<endl;
	 }
			for(int i=0;i<library.textbooks.size();i++)
	{
		Textbook textbook=library.getTextbooks().at(i);
		cout<<textbook.getType()<<" || "<<textbook.getTitle()<<endl;
	};
	}
	
	
	return 0;
}