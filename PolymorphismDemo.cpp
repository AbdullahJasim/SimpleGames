#include <iostream>

using namespace std;

class Enemy {
public:
	Enemy(int damage = 10);
	virtual ~Enemy();
	void virtual Attack() const;
protected:
	int* m_pDamage;
};

Enemy::Enemy(int damage) {
	m_pDamage = new int(damage);
}

Enemy::~Enemy() {
	cout << "Deleting enemy...\n";
	delete m_pDamage;
	m_pDamage = nullptr;
}

void Enemy::Attack() const {
	cout << "An enemy attacks and inflicts " << *m_pDamage << " points of damage.\n";
}

class Boss : public Enemy {
public:
	Boss(int multiplier = 3);
	virtual ~Boss();
	void virtual Attack() const;
protected:
	int* m_pMultiplier;
};

Boss::Boss(int multiplier) {
	m_pMultiplier = new int(multiplier);
}

Boss::~Boss() {
	cout << "Deleting boss...\n";
	delete m_pMultiplier;
	m_pMultiplier = nullptr;
}

void Boss::Attack() const {
	cout << "The boss attacks and inflicts " << (*m_pMultiplier) * (*m_pDamage) << " points of damage.\n";
}

void RunPolyDemo() {
	cout << "Boss attacking!\n";
	Enemy* boss = new Boss();
	boss->Attack();

	delete boss;
	boss = nullptr;
}

//int main() {
//	RunPolyDemo();
//
//	return 0;
//}