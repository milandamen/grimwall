class AUnit{
public:
	virtual void accept() = 0;
	virtual void damage(int amount);
private:
	int health;
};