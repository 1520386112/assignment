#include  "iostream" 
using  namespace  std;

class vehicle {
public:
	vehicle(int maxspeed, int weight) {
		m_maxspeed = maxspeed;
		m_weight = weight;
		cout << "vehicle constructor called. maxspeed:" << maxspeed << "; weight" << weight << endl;
	}
	~vehicle() {
		cout << "vehicle destructor called. maxspeed:" << m_maxspeed << "; weight" << m_weight << endl;
	}
	void run() {
		cout << "vehicle run" << endl;
	}
	void stop() {
		cout << "vehicle stop" << endl;
	}
private:
	int m_maxspeed;
	int m_weight;
};

class bicycle:public virtual vehicle {
public:
	bicycle(int height, int maxspeed, int weight):vehicle(maxspeed, weight){
		m_height = height;
		cout << "bicycle constructor called. height:" << m_height << endl;
	}
	~bicycle() {
		cout << "bicycle destructor called. height:" << m_height << endl;
	}
private:
	int m_height;
};

class motorcar :public virtual vehicle {
public:
	motorcar(int seatnum, int maxspeed, int weight):vehicle(maxspeed, weight) {
		m_seatnum = seatnum;
		cout << "motorcar constructor called. seatnum:" << m_seatnum << endl;
	}
	~motorcar() {
		cout << "motorcar destructor called. seatnum:" << m_seatnum << endl;
	}
private:
	int m_seatnum;
};

class motorcycle : public bicycle, public motorcar {
public:
	motorcycle(int height, int seatnum, int maxspeed, int weight) :
		vehicle(maxspeed, weight),
		bicycle(height, maxspeed, weight),
		motorcar(seatnum, maxspeed, weight)
	{
		cout << "motorcycle constructor called" << endl;
	}
	~motorcycle() {
		cout << "motorcycle destructor called" << endl;
	}
};

int  main(int  argc, char* argv[])
{
	motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
	m.run();
	m.stop();
	return 0;
}