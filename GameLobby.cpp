//A linked list structure for players in a lobby / queue type

#include <iostream>
#include <string>

using namespace std;

class GameLobbyPlayer {
public:
	GameLobbyPlayer(const string& name = "");
	string GetName() const;
	GameLobbyPlayer* GetNext() const;
	void SetNext(GameLobbyPlayer* next);

private:
	string m_Name;
	GameLobbyPlayer* m_pNext;
};

GameLobbyPlayer::GameLobbyPlayer(const string& name) :
	m_Name(name),
	m_pNext(0)
{}

string GameLobbyPlayer::GetName() const {
	return m_Name;
}

GameLobbyPlayer* GameLobbyPlayer::GetNext() const {
	return m_pNext;
}

void GameLobbyPlayer::SetNext(GameLobbyPlayer* next) {
	m_pNext = next;
}

//--------------------- end of player class ---------------------//

class Lobby {
	friend ostream& operator<<(ostream& os, const Lobby& aLobby);

public:
	Lobby();
	~Lobby();
	void AddPlayer();
	void RemovePlayer();
	void Clear();

private:
	GameLobbyPlayer* m_pHead;
};

Lobby::Lobby() {
	m_pHead = nullptr;
}

Lobby::~Lobby() {
	Clear();
}

void Lobby::AddPlayer() {
	cout << "Choose a name for the player: ";
	string name;
	cin >> name;

	GameLobbyPlayer* p = new GameLobbyPlayer(name);

	if (m_pHead == nullptr) {
		m_pHead = p;
	} else {
		GameLobbyPlayer* iter = m_pHead;

		while (iter->GetNext() != nullptr) iter = iter->GetNext();

		iter->SetNext(p);
	}
}

void Lobby::RemovePlayer() {
	if (m_pHead == nullptr) {
		cout << "Lobby is empty." << endl;
		return;
	}

	GameLobbyPlayer* temp = m_pHead;
	m_pHead = m_pHead->GetNext();

	delete temp;
}

void Lobby::Clear() {
	while (m_pHead != nullptr) RemovePlayer();
}

ostream& operator<<(ostream& os, const Lobby& aLobby) {
	GameLobbyPlayer* iter = aLobby.m_pHead;

	if (iter == nullptr) {
		os << "No players in lobby.\n";
		return os;
	}

	os << "Players in queue:\n";
	while (iter != nullptr) {
		os << iter->GetName() << endl;
		iter = iter->GetNext();
	}

	return os;
}

void RunGameLobby() {
	Lobby lobby;
	int choice;

	do {
		cout << lobby;
		cout << "\nWelcome to the Lobby!\n";
		cout << "0 - Exit\n";
		cout << "1 - Add Player\n";
		cout << "2 - Remove Player\n";
		cout << "3 - Clear Lobby\n";

		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Good bye!\n";
			break;

		case 1:
			lobby.AddPlayer();
			break;

		case 2:
			lobby.RemovePlayer();
			break;

		case 3:
			lobby.Clear();
			break;
		}

	} while (choice != 0);
}

//int main() {
//	RunGameLobby();
//
//	return 0;
//}