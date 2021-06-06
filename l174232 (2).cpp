#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

class Facebook;
class Object;
class Posts;
class Users;
class Pages;
class Date;
class Comments;



class Object
{
private:
	char* ID;
public:
	Object(char*id = 0)
	{
		if (id != 0)
		{
			ID = new char[strlen(id) + 1];
			int i = 0;
			for (; id[i] != 0; i++)
			{
				ID[i] = id[i];
			}
			ID[i] = 0;
		}
		else
			ID = id;
	}
	~Object()
	{
		delete[] ID;
	}
	char* GetID()
	{
		return ID;
	}
	void PrintID()
	{
		cout << ID;
	}
	void SetID(char* id)
	{
		if (ID != '\0')
		{
			delete[] ID;
			ID = new char[strlen(id) + 1];
			int i = 0;
			for (; id[i] != 0; i++)
			{
				ID[i] = id[i];
			}
			ID[i] = 0;
		}
		else
		{
			ID = new char[strlen(id) + 1];
			int i = 0;
			for (; id[i] != 0; i++)
			{
				ID[i] = id[i];
			}
			ID[i] = 0;
		}
	}
	virtual void PrintName() = 0;
};
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int d = 0, int m = 0, int y = 0)
	{
		day = d;
		month = m;
		year = y;
	}
	void SetDay(int d)
	{
		day = d;
	}
	void SetMonth(int m)
	{
		month = m;
	}
	void SetYear(int y)
	{
		year = y;
	}
	void PrintDate()
	{
		cout << day << "/" << month << "/" << year << endl;
	}
	int GetDay()
	{
		return day;
	}
	int GetMonth()
	{
		return month;
	}
	int GetYear()
	{
		return year;
	}
	~Date()
	{ }
	void PrintName()
	{

	}
	bool CompareDates(Date date)
	{
		if (date.day == this->day && date.month == this->month && date.year == this->year)
			return true;
		else
			return false;
	}
};

class Pages :public Object
{
private:
	char *title;
	Posts** pageTimeline;
	int likeCount;
public:
	Pages()
	{
		likeCount = 0;
		title = 0;
		pageTimeline = 0;
	}
	void SetTitle(char* _name)
	{
		title = new char[strlen(_name) + 1];
		int j = 0;
		for (; j < strlen(_name); j++)
		{
			title[j] = _name[j];
		}
		title[j] = 0;
	}
	void ReadPages(ifstream& fin)
	{
		char buffer[80];
		fin >> buffer;
		SetID(buffer);
		fin.getline(buffer, 80, '\t');
		fin.getline(buffer, 80);
		SetTitle(buffer);
	}
	void printAllPages()  //Extra Function just to check whether the data is loaded accurately
	{
		cout << GetID() << "\t " << title << endl;
	}
	void PrintName()
	{
		cout << title;
	}
	void PrintListView()
	{
		cout << GetID() << "-\t" << title << endl;
	}
	void CreateTimeLine() //Allocating space for posts
	{
		if (pageTimeline == 0)
		{
			pageTimeline = new Posts*[10];
			for (int i = 0; i < 10; i++)
				pageTimeline[i] = 0;
		}
	}
	void SetTimeline(Posts * postNo)  //Linking posts and Pages
	{
		for (int i = 0; i < 10; i++)
		{
			if (pageTimeline[i] == 0)
			{
				pageTimeline[i] = postNo;
				break;
			}
		}
	}
	void Search(char* text)
	{
		char temp[100];
		for (int i = 0; i<strlen(title);)
		{
			int k = 0;
			while (title[i] != 32)
			{
				if (title[i] != 0)
					temp[k] = title[i];  //making substrings to make the searching process easy
				k++;
				i++;
				if (title[i] == 0)
					break;
			}
			i++;
			temp[k] = 0;
			if (strcmp(text, temp) == 0)
			{
				cout << "---";
				this->PrintListView();
			}
		}
	}
	~Pages()
	{
		delete[] title;
		if (pageTimeline != 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (pageTimeline[i] != 0)
					delete[] pageTimeline[i];
			}
			delete[] pageTimeline;
		}
	}
	void ViewLatestPosts(Date currentDate);
	void viewTimeLine();
};
class Users :public Object
{
private:
	char* firstName;
	char* lastName;
	int friendCount;
	int pageCount;
	Users** friendList;
	Pages** likedPages;
	Posts** userTimeline;
	char** friendListTemp;
public:
	Users()
	{
		friendCount = 0;
		pageCount = 0;
		firstName = 0;
		lastName = 0;
		friendList = 0;
		likedPages = 0;
		userTimeline = 0;
		friendListTemp = 0;
	}
	void Search(char* text)
	{
		if (strcmp(text, firstName) == 0 || strcmp(text, lastName) == 0)
		{
			cout << "---";
			this->PrintID();
			cout << "-";
			this->PrintName();
			cout << endl;
		}
	}
	void SetTimeline(Posts * postNo)
	{

		for (int i = 0; i < 10; i++)
		{
			if (userTimeline[i] == 0)
			{
				userTimeline[i] = postNo;
				break;
			}
		}
	}
	~Users()
	{
		delete[] firstName;
		delete[] lastName;
		if (friendListTemp != 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (friendListTemp[i] != 0)
					delete[] friendListTemp[i];
			}
			delete[] friendListTemp;
		}

		if (userTimeline != 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (userTimeline[i] != 0)
					delete[] userTimeline[i];
			}
			delete[] userTimeline;
		}
	}
	void SetFname(char* buffer)
	{
		int	sizeOfFname = strlen(buffer);
		firstName = new char[sizeOfFname + 1];
		for (int i = 0; i < sizeOfFname; i++)
			firstName[i] = buffer[i];
		firstName[sizeOfFname] = 0;
	}
	void SetLname(char* buffer)
	{
		int	sizeOfLname = strlen(buffer);
		lastName = new char[sizeOfLname + 1];
		for (int i = 0; i < sizeOfLname; i++)
			lastName[i] = buffer[i];
		lastName[sizeOfLname] = 0;
	}
	void ReadUser(ifstream &fin)
	{
		char buffer[80];
		fin >> buffer;
		SetID(buffer);
		fin >> buffer;
		SetFname(buffer);
		fin >> buffer;
		SetLname(buffer);
		fin >> buffer;
		if (*buffer != '-')
		{
			friendListTemp = new char*[10];  //a user can have 10 friends maximum
			for (int i = 0; i < 10; i++)
				friendListTemp[i] = 0;
			for (int i = 0; *buffer != '-'; i++)
			{
				friendListTemp[i] = new char[strlen(buffer) + 1];
				int j = 0;
				for (; j <= strlen(buffer); j++)
					friendListTemp[i][j] = buffer[j];
				friendCount++;
				fin >> buffer;
			}
		}
	}
	void SetPagesList(ifstream& fin, Pages** allPages)
	{
		char buffer[80];
		fin >> buffer;
		if (*buffer != '-')
		{
			likedPages = new Pages*[10];

			for (int s = 0; *buffer != '-'; s++)
			{
				int index = GetIndex(buffer);
				likedPages[s] = allPages[index - 1];
				pageCount++;
				fin >> buffer;
			}
		}
		else
			likedPages = 0;
	}
	void CreateTimeLine()
	{
		if (userTimeline == 0)
		{
			userTimeline = new Posts*[10];
			for (int i = 0; i < 10; i++)
				userTimeline[i] = 0;
		}
	}
	Users** GetFriends()
	{
		return friendList;
	}
	void SetFriendList(Users**allUsers)
	{
		if (friendListTemp != 0)
		{
			friendList = new Users*[10];
			for (int i = 0; i < friendCount; i++)
			{
				if (friendListTemp[i] != 0)
				{
					int index = GetIndex(friendListTemp[i]);
					friendList[i] = allUsers[index - 1];
				}
			}
		}
	}
	int GetIndex(char*buffer) //Helper function that gives index of position on which specific data is located
	{
		int size = strlen(buffer);
		if (strlen(buffer) == 2)
			return buffer[1] - 48;
		else if (strlen(buffer) == 3)
		{
			int temp = (buffer[2] - 48) + 10 * (buffer[1] - 48);
			return temp;
		}
		return 0;
	}
	void PrintListView()
	{
		cout << GetID() << "- \t";
		PrintName();
		cout << endl;
	}
	void ViewFriendList()
	{
		PrintName();
		cout << " -Friends List:" << endl << endl;
		for (int i = 0; i < friendCount; i++)
			friendList[i]->PrintListView();
	}
	void ViewLikedPages()
	{
		PrintName();
		cout << " -Liked Pages:" << endl << endl;
		for (int i = 0; i < pageCount; i++)
			likedPages[i]->PrintListView();
	}
	void printCurrentUser()
	{
		PrintName();
		cout << " is successfully set as current user" << endl;
	}
	void PrintName()
	{
		cout << firstName << " " << lastName;
	}
	void viewHomePage(Date currentDate)
	{
		this->PrintName();
		cout << " - Home Page " << endl << endl;
		for (int i = 0; i < friendCount; i++)
		{
			friendList[i]->ViewLatestPosts(currentDate);
		}
		for (int i = 0; i < pageCount; i++)
		{
			likedPages[i]->ViewLatestPosts(currentDate);
		}
	}
	void AddPost(Date currentDate, Posts* postNo, int);
	void ViewLatestPosts(Date currentDate);
	void viewTimeLine();
};

class Comments :public Object
{
private:
	char* text;
	Object* commentBy;
public:
	Comments()
	{
		text = 0;
		commentBy = 0;
	}
	void SetText(char* _text)
	{
		text = new char[strlen(_text) + 1];
		text[strlen(_text)] = 0;
		for (int i = 0; i < strlen(_text); i++)
			text[i] = _text[i];
	}
	void SetCommentBy(Object* obj)
	{
		commentBy = obj;
	}
	void PrintComments()
	{
		cout << "\t";
		commentBy->PrintName();
		cout << " wrote: \"" << text << "\"";
	}
	void PrintName()
	{

	}
	char* GetText()
	{
		return text;
	}
	void CreateComments(Comments** obj) //Allocating space for comments
	{
		if (obj == 0)
		{
			obj = new Comments*[10];
			for (int i = 0; i < 10; i++)
				obj[i] = 0;
		}
	}
	void UpdateID(int n) //update or set ID for new comment
	{
		char temp[4];
		temp[0] = 'c';
		if (n < 9)
		{
			temp[1] = n;
			temp[2] = 0;
		}
		else if (n >= 9 || n <= 99)
		{
			int k = n;
			k = n / 10;
			temp[1] = k + 48;
			temp[2] = n % 10 + 48;

		}
		temp[3] = 0;
		this->SetID(temp);
	}
	~Comments()
	{
		delete[] text;
	}
};



class Posts :public Object
{
private:
	char* description;
	int noOfLikes;
	Object** likedBy;
	Object* shareby;
	Date date;
	Comments ** comment;
	int noOfComments;
public:
	Posts()
	{
		description = 0;
		noOfLikes = 0;
		likedBy = 0;
		shareby = 0;
		date = 0;
		comment = 0;
		noOfComments = 0;
	}

	void UpdateID(int n) // update or set ID for new comment
	{
		char temp[7];
		temp[0] = 'p';
		temp[1] = 'o';
		temp[2] = 's';
		temp[3] = 't';
		if (n < 9)
		{
			temp[4] = n;
			temp[5] = 0;

		}
		else if (n >= 9 || n <= 99)
		{
			int k = n;
			k = n / 10;
			temp[4] = k + 48;
			temp[5] = n % 10 + 48;

		}
		temp[6] = 0;
		this->SetID(temp);
	}


	int GetnoOfComments()
	{
		return  noOfComments;;
	}
	void Search(char* text)
	{
		char temp[100];
		for (int i = 0; i < strlen(description);)
		{
			int k = 0;
			while (description[i] != 32)
			{
				if (description[i] != 0)

					temp[k] = description[i];
				k++;
				i++;
				if (description[i] == 0)
					break;
			}
			i++;
			temp[k] = 0;
			if (strcmp(text, temp) == 0)
			{
				cout << "---";
				this->PrintID();
				cout << "-";
				this->PrintName();
				cout << endl;
				return;
			}
		}
	}
	void SetShareBy(Object* obj)
	{
		shareby = obj;
	}
	void PrintHome(Date);

	void SetComments(Comments*obj, Object*currentUser)
	{
		comment[noOfComments] = new Comments;
		comment[noOfComments]->SetID(obj->GetID());
		comment[noOfComments]->SetText(obj->GetText());
		comment[noOfComments]->SetCommentBy(currentUser);
		noOfComments++;
	}
	char* GetDescription()
	{
		return description;
	}
	void CreateCommentList()
	{
		if (comment == 0)
		{
			comment = new Comments*[10];
			for (int i = 0; i < 10; i++)
				comment[i] = 0;
		}
	}
	void PrintName()
	{
		shareby->PrintName();
		cout << " Shared ";
		cout << "----\"" << description << "\"...";
	}
	Object** GetLikedBy()
	{
		return likedBy;
	}
	int GetNoOFLikes()
	{
		return noOfLikes;
	}
	void SetDescription(char* _description)
	{
		description = new char[strlen(_description) + 1];
		description[strlen(_description)] = 0;
		for (int i = 0; i < strlen(_description); i++)
			description[i] = _description[i];
	}
	void SetDate(Date *currentdate)
	{
		date.SetDay(currentdate->GetDay());
		date.SetMonth(currentdate->GetMonth());
		date.SetYear(currentdate->GetYear());
	}

	void PrintPost();
	void IncreaseNoOFLikes()
	{
		noOfLikes++;
	}
	void IncreaseNoOfComments()
	{
		noOfComments++;
	}
	void ReadPosts(ifstream& fin)
	{
		char buffer[100];
		fin.getline(buffer, 100, '\n');
		fin >> buffer;
		SetID(buffer);
		int tempDate;
		fin >> tempDate;
		date.SetDay(tempDate);
		fin >> tempDate;
		date.SetMonth(tempDate);
		fin >> tempDate;
		date.SetYear(tempDate);
		fin.getline(buffer, 100);
		fin.getline(buffer, 100);
		SetDescription(buffer);
	}
	int GetIndex(char*buffer)
	{
		int size = strlen(buffer);
		if (strlen(buffer) == 2)
			return buffer[1] - 48;
		else if (strlen(buffer) == 3)
		{
			int temp = (buffer[2] - 48) + 10 * (buffer[1] - 48);
			return temp;
		}
	}
	void SetData(ifstream &fin, Users** allUsers, Pages**allPages) //linking posts with pages or users
	{
		char buffer[80];
		fin >> buffer;
		if (buffer[0] == 'u')
		{
			shareby = allUsers[GetIndex(buffer) - 1];
			allUsers[GetIndex(buffer) - 1]->CreateTimeLine();
			allUsers[GetIndex(buffer) - 1]->SetTimeline(this);
		}
		else
		{
			shareby = allPages[GetIndex(buffer) - 1];
			allPages[GetIndex(buffer) - 1]->CreateTimeLine();
			allPages[GetIndex(buffer) - 1]->SetTimeline(this);
		}
		fin.getline(buffer, 100);
		fin >> buffer;
		if (*buffer != '-')
			likedBy = new Object*[10];
		for (int k = 0; *buffer != '-'; k++)
		{
			if (buffer[0] == 'p')
			{
				likedBy[k] = allPages[GetIndex(buffer) - 1];
				noOfLikes++;
			}
			else
			{
				likedBy[k] = allUsers[GetIndex(buffer) - 1];
				noOfLikes++;
			}
			fin >> buffer;
		}
		fin.getline(buffer, 100, '\n');
	}

	Date GetDate()
	{
		return Date();
	}
	void PrintLikedBy()
	{
		cout << "Post liked By:" << endl;
		for (int i = 0; i < noOfLikes; i++)
		{
			likedBy[i]->PrintID();
			cout << "\t";
			likedBy[i]->PrintName();
			cout << endl;
		}
	}
	~Posts()
	{
		delete[] description;
		delete[] comment;
	}
	void AddComment(char* text, Object* currentUser, int commentNo);
	void ViewPost();
};

void Posts::AddComment(char* text, Object* currentUser, int commentNo)
{
	for (int i = 0; i < 10; i++)
	{
		if (comment == 0)
			CreateCommentList();
		if (comment[i] == 0)
		{
			comment[i] = new Comments;
			comment[i]->UpdateID(commentNo);
			comment[i]->SetCommentBy(currentUser);
			comment[i]->SetText(text);

			break;
		}

	}
}

void Posts::ViewPost()
{
	shareby->PrintName();
	cout << " Shared ";
	cout << "----\"" << description << "\"...";
	date.PrintDate();
	if (comment != 0)
	{
		for (int i = 0; i < noOfComments; i++)
		{
			comment[i]->PrintComments();
			cout << endl;
		}
	}
	cout << endl;
}

void Posts::PrintPost()
{
	cout << "----\"" << description << "\"...";
	date.PrintDate();
	for (int i = 0; i < noOfComments; i++)
	{
		comment[i]->PrintComments();
		cout << endl;
	}
	cout << endl;
}
void Pages::ViewLatestPosts(Date currentDate)
{
	if (pageTimeline != 0)
	{
		cout << "- - -";
		PrintName();
		cout << " Shared ";
		for (int i = 0; i <10; i++)
		{
			if (pageTimeline[i] != 0)
				pageTimeline[i]->PrintHome(currentDate);
		}
	}
}
void Users::ViewLatestPosts(Date currentDate)
{
	if (userTimeline != 0)
	{
		cout << "- - -";
		PrintName();
		cout << " Shared ";
		for (int i = 0; i <friendCount; i++)
		if (userTimeline[i] != 0)
			userTimeline[i]->PrintHome(currentDate);
	}
}

void Posts::PrintHome(Date currentDate)
{
	Date previousDay(currentDate.GetDay() - 1, currentDate.GetMonth(), currentDate.GetYear());
	if (date.CompareDates(currentDate) == true || date.CompareDates(previousDay) == true)
	{
		cout << "----\"" << description << "\"" << endl;
		for (int i = 0; i < GetnoOfComments(); i++)
		{
			comment[i]->PrintComments();
			cout << endl;
		}
		cout << endl;
	}
}

void Pages::viewTimeLine() //Page's Timeline having all posts since date created
{
	if (pageTimeline != 0)
	{
		cout << "- - -";
		PrintName();
		cout << " Shared ";
		for (int i = 0; i <10; i++)
		if (pageTimeline[i] != 0)
			pageTimeline[i]->PrintPost();
	}
}

void Users::viewTimeLine() //User's Timeline having all posts since date created
{
	if (userTimeline != 0)
	{
		for (int i = 0; i < friendCount; i++)
		if (userTimeline[i] != 0)
			userTimeline[i]->PrintPost();
	}
}

void Users::AddPost(Date currentDate, Posts* postNo, int PostNo)
{
	for (int i = 0; i < 10; i++)
	{
		if (userTimeline == 0)
			CreateTimeLine();
		if (userTimeline[i] == 0)
		{
			userTimeline[i] = new Posts;
			userTimeline[i]->SetShareBy(this);
			userTimeline[i]->SetDescription(postNo->GetDescription());
			userTimeline[i]->SetDate(&currentDate);
			userTimeline[i]->UpdateID(PostNo);
			break;
		}
	}
}




class Facebook
{
private:
	Users** allUsers;
	Pages** allPages;
	Posts** allPosts;
	Users* currentUser;
	Date currentDate;
	int userCount;
	int pagesCount;
	int postsCount;
	int commentsCount;
public:
	Facebook()
	{
		allUsers = 0;
		allPages = 0;
		allPosts = 0;
		currentUser = 0;
		currentDate = 0;
		userCount = 0;
		pagesCount = 0;
		postsCount = 0;
	}
	~Facebook()
	{
		for (int i = 0; i < userCount; i++)
			delete allUsers[i];
		delete[] allUsers;

		for (int i = 0; i < pagesCount; i++)
			delete allPages[i];
		delete[] allPages;
		delete[] allPosts;
	}
	int GetIndex(char*buffer)
	{
		int size = strlen(buffer);
		if (strlen(buffer) == 2)
			return buffer[1] - 48;

		else if (strlen(buffer) == 3)
		{
			int temp = (buffer[2] - 48) + 10 * (buffer[1] - 48);
			return temp;
		}
		else if (strlen(buffer) == 5)
		{
			int temp = buffer[4] - 48;
			return temp;
		}
		else if (strlen(buffer) == 6)
		{
			int temp = (buffer[5] - 48) + 10 * (buffer[1] - 48);
			return temp;
		}
	}

	void LoadData()
	{
		//Loading Pages
		char buffer[150];
		ifstream fin;
		fin.open("Project-SocialNetworkPages.txt");
		if (fin.is_open())
		{
			fin >> pagesCount;
			allPages = new Pages*[pagesCount];
			fin.getline(buffer, 150, '\n');
			for (int i = 0; i < pagesCount; i++)
			{
				allPages[i] = new Pages;
				allPages[i]->ReadPages(fin);
			}
			fin.close();
		}
		else
			cout << "Error file not found." << endl;

		//Loading Users
		fin.open("Project-SocialNetworkUers.txt");
		if (fin.is_open())
		{
			fin >> userCount;
			allUsers = new Users*[userCount];
			fin.getline(buffer, 150, '\n');
			for (int i = 0; i < userCount; i++)
			{
				allUsers[i] = new Users;
				allUsers[i]->ReadUser(fin);
				allUsers[i]->SetPagesList(fin, allPages); //Linking Pages
			}
			for (int i = 0; i < userCount; i++)
			{
				allUsers[i]->SetFriendList(allUsers); //Linking Friends
			}
			fin.close();
		}
		else
			cout << "Error file not found." << endl;

		//Loading posts
		fin.open("Project-SocialNetworkPosts.txt");
		if (fin.is_open())
		{
			fin >> postsCount;
			allPosts = new Posts*[postsCount];
			for (int i = 0; i < 7; i++)
				fin.getline(buffer, 150);

			for (int i = 0; i < postsCount; i++)
			{
				allPosts[i] = new Posts;
				allPosts[i]->ReadPosts(fin);
				allPosts[i]->SetData(fin, allUsers, allPages); //Linking posts
			}
			fin.close();
		}
		else
			cout << "Error file not found." << endl;

		//Loading Comments
		fin.open("Project-SocialNetworkComments.txt");
		if (fin.is_open())
		{
			fin >> commentsCount;
			fin.getline(buffer, 150);
			fin.getline(buffer, 150);
			for (int i = 0; i < commentsCount; i++)
			{
				char obj;
				int commenter;
				fin >> buffer;
				Comments temp;
				temp.SetID(buffer);
				fin >> buffer;
				int index = GetIndex(buffer) - 1;
				allPosts[index]->CreateCommentList();
				fin >> buffer;
				if (buffer[0] == 'u')
				{
					temp.SetCommentBy(allUsers[GetIndex(buffer) - 1]);
					commenter = GetIndex(buffer) - 1;
					obj = 'u';
				}
				else if (buffer[0] == 'p')
				{
					temp.SetCommentBy(allPages[GetIndex(buffer) - 1]);
					commenter = GetIndex(buffer) - 1;
					obj = 'p';
				}
				fin.getline(buffer, 150, '\t');
				fin.getline(buffer, 150);
				temp.SetText(buffer);
				if (obj == 'u')
				{
					allPosts[index]->SetComments(&temp, allUsers[commenter]);
				}
				else if (obj == 'p')
				{
					allPosts[index]->SetComments(&temp, allPages[commenter]);
				}

			}
			fin.close();
		}
		else
			cout << "Error file not found." << endl;

	}
	void SetCurrentUser(char* userId)
	{
		for (int i = 0; i < userCount; i++)
		{
			if (strcmp(userId, allUsers[i]->GetID()) == 0)
			{
				currentUser = &*allUsers[i];
				currentUser->printCurrentUser();
				return;
			}
		}
		cout << userId << " not found in the list.\n";
	}
	void Search(char * find)
	{
		cout << "Users" << endl;
		for (int i = 0; i < userCount; i++)
		{
			allUsers[i]->Search(find);
		}
		cout << "Pages" << endl;
		for (int i = 0; i < pagesCount; i++)
		{
			allPages[i]->Search(find);
		}
		cout << "Posts" << endl;
		for (int i = 0; i < postsCount - 1; i++)
		{
			allPosts[i]->Search(find);
		}
	}
	void SetCurrentDate(int d, int m, int y)
	{
		currentDate.SetDay(d);
		currentDate.SetMonth(m);
		currentDate.SetYear(y);
	}
	int GetUsersCount()
	{
		return userCount;
	}
	void viewPage(char* page)
	{
		allPages[GetIndex(page) - 1]->viewTimeLine();
	}
	void ViewPost(char* post)
	{
		allPosts[GetIndex(post) - 1]->ViewPost();
	}
	void likePosts(char* post)
	{
		for (int i = 0; i < postsCount; i++)
		if (strcmp(allPosts[i]->GetID(), post) == 0)
		{
			allPosts[i]->IncreaseNoOFLikes();
			int index = allPosts[i]->GetNoOFLikes();
			allPosts[i]->GetLikedBy()[index - 1] = currentUser;
			return;
		}
	}
	void PostComment(char* post, char* text)
	{
		allPosts[GetIndex(post) - 1]->AddComment(text, currentUser, commentsCount + 1);
		allPosts[GetIndex(post) - 1]->IncreaseNoOfComments();
		commentsCount++;
	}
	void SharePost(char* postNo)
	{
		int index = GetIndex(postNo);
		currentUser->AddPost(currentDate, allPosts[index - 1], postsCount + 1);
		postsCount++;
	}
	void ViewLikedList(char* post)
	{
		allPosts[GetIndex(post) - 1]->PrintLikedBy();
	}
	void Run()
	{
		cout << "***********************************Welcome To FaceBook***********************************" << endl << endl;
		cout << "Command:Set current user \"u7\"" << endl << endl;
		SetCurrentUser("u7");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:Set current System Date 15 11 2017" << endl << endl;
		SetCurrentDate(15, 11, 2017);
		cout << "SytemDate is:\t";
		currentDate.PrintDate();
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:View Friend List" << endl << endl;
		currentUser->ViewFriendList();
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Comand:View Liked Pages" << endl << endl;
		currentUser->ViewLikedPages();
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:View Home" << endl << endl;
		currentUser->viewHomePage(currentDate);
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:View TimeLine" << endl << endl;
		currentUser->viewTimeLine();
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:ViewLikedList(post5)" << endl << endl;
		ViewLikedList("post5");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:LikePost(post5)" << endl << endl;
		likePosts("post5");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:ViewLikedList(post5)" << endl << endl;
		ViewLikedList("post5");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command:PostComment(post4, Good Luck for your Result)" << endl << endl;
		PostComment("post4", "Good Luck for your Result");
		cout << "Command : ViewPost(post4)" << endl << endl;
		ViewPost("post4");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command : PostComment(post8, Thanks for the wishes)" << endl << endl;
		PostComment("post8", "Thanks for the wishes");
		cout << "Command : ViewPost(post8)" << endl << endl;
		ViewPost("post8");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command: SharePost(post5)" << endl << endl;
		SharePost("post5");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command : View TimeLine" << endl << endl;
		currentUser->viewTimeLine();
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command : ViewPage(p1)" << endl << endl;
		viewPage("p1");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command: Search(\"Birthday\")" << endl << endl;
		Search("Birthday");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
		cout << "Command : Search(\"Ali\")" << endl << endl;
		Search("Ali");
		cout << "-----------------------------------------------------------------------------------------" << endl << endl;
	}
};
void main()
{
	Facebook fb;
	fb.LoadData();
	fb.Run();
	_getch();
}

